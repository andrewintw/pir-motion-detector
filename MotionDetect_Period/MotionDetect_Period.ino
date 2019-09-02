/*
  HC-SR501 PIR Motion Detector setup
  --Jumper Set         : use H (Repeat Trigger)
  --Sensitivity Adjust : Anti C.W to the end (Low, about 3 meters)
  --Time-delay  Adjust : Anti C.W to the end (Shorten, 5 sec)
*/
#include "config.h"

int sensor_data                 = 0;
uint16 detect_count             = 0;
uint16 no_detect_count          = 0;
uint16 max_no_detect_count      = 0;

unsigned long start_chktime     = 0;
chk_period_t chk_period         = CHK_NONE;
uint16 detect_count_in_perid    = 0;


void _print2digit(int t) {
  if (t < 10) Serial.print('0');
  Serial.print(t);
}

void print_timestamp() {
  unsigned long now_ms = millis() / 1000;
  int t_sec = now_ms % 60;
  int t_min = (now_ms / 60) % 60;
  int t_hor = (now_ms / 3600) % 24;
  _print2digit(t_hor); Serial.print(':');
  _print2digit(t_min); Serial.print(':');
  _print2digit(t_sec);
}

void setup() {
  Serial.begin(115200);
  delay(100);

  /* HC-SR501 requires some time to acclimatize to the infrared energy in the room.
     This takes 60 seconds when the sensor is first powered up.
  */
  Serial.println();
  Serial.println("HC-SR501 initializing...(60sec)");
  delay(60 * 1000);

  pinMode(PIROUT_PIN, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  ledOFF();
}

void update_detect_counter() {
  sensor_data = digitalRead(PIROUT_PIN);

  if (sensor_data == HIGH)
  {
    //Serial.println("ON");
    ledON();
    no_detect_count = 0;
    detect_count++;

    if (chk_period == CHK_NONE) {
      chk_period = CHK_START;
      start_chktime = millis();
    }

    if (chk_period > CHK_START) { /* CHK_IN_PERID, CHK_END */
      detect_count_in_perid++;
    }
  }
  else
  {
    //Serial.println("OFF");
    ledOFF();
    detect_count = 0;
    no_detect_count++;

    if (no_detect_count >= 65535) {
      no_detect_count = 0;
      max_no_detect_count = 0;
    }

    if (no_detect_count > max_no_detect_count) {
      max_no_detect_count = no_detect_count;
    }
  }

  if ((chk_period == CHK_IN_PERID) &&
      (millis() - start_chktime > CHK_PERIOD_TIME)) {
    chk_period = CHK_END;
  }
}

void show_summary() {
  print_timestamp();

  Serial.print("  pv:");
  Serial.print(sensor_data);
  Serial.print(" dc:");
  Serial.print(detect_count);
  Serial.print("\tndc:");
  Serial.print(no_detect_count);
  Serial.print("\tMax(ndc):");
  Serial.print(max_no_detect_count);
  Serial.print("  ");
  Serial.print((max_no_detect_count * DET_INTERVAL_MS) / 1000);
  Serial.print("sec");

  if (chk_period == CHK_START)
  {
    Serial.print(" --* (");
    Serial.print(CHK_PERIOD_TIME / 1000);
    Serial.println("sec)");
    chk_period = CHK_IN_PERID;
  }
  else if (chk_period == CHK_IN_PERID)
  {
    Serial.print("   | ");
    Serial.println(detect_count_in_perid);
  }
  else if (chk_period == CHK_END)
  {
    Serial.print(" __x ");
    Serial.println(detect_count_in_perid);
    chk_period = CHK_NONE;
    detect_count_in_perid = 0;
  }
  else
  {
    Serial.println();
  }
}

void loop() {
  update_detect_counter();
  show_summary();
  delay(DET_INTERVAL_MS);
}
