/* License
 * --------------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <yenchang.lin@gmail.com>  wrote this program.  As long as you retain this notice
 * you can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return.  Andrew Lin
 * --------------------------------------------------------------------------------
 *
 *  HC-SR501 PIR Motion Detector setup
 *  --Jumper Set         : use H (Repeat Trigger)
 *  --Sensitivity Adjust : Anti C.W to the end (Low, about 3 meters)
 *  --Time-delay  Adjust : Anti C.W to the end (Shorten, 5 sec)
 */

#include "config.h"

int sensor_data                 = 0;
uint16 detect_count             = 0;
uint16 no_detect_count          = 0;
uint16 max_no_detect_count      = 0;

unsigned long start_chktime     = 0;
period_stat_t period_st         = CHK_NONE;
uint16 detect_count_in_perid    = 0;

uint8 is_presented              = 0;


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
  pinMode(PIROUT_PIN, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  ledBlink();

  Serial.begin(115200);
  delay(100);

  Serial.println();
  Serial.print("HC-SR501 initializing...(");
  Serial.print(PIR_INIT_TIME_MS/1000);
  Serial.println("sec)");
  delay(PIR_INIT_TIME_MS);
}

void update_sensor_data() {
  sensor_data = digitalRead(PIROUT_PIN);

  if (sensor_data == HIGH)
  {
    //Serial.println("ON");
    if (is_presented != 1) {
      ledON();
    }
    detect_count++;

#if CFG_IGNORE_NOISES
    if ((period_st == CHK_NONE) &&
        (detect_count <= IGNORE_NOISES_NUM)) {
      /* ignore noises */
      return;
    }
#endif

    no_detect_count = 0;

    if (period_st == CHK_NONE) {
      period_st = CHK_START;
      start_chktime = millis();
    }

    if (period_st > CHK_START) { /* CHK_IN_PERID, CHK_END */
      detect_count_in_perid++;

      if (detect_count_in_perid >= THRESHOLD_PRESENT) {
        /* That means the system recognizes that someone really exists there */
        is_presented = 1;
        ledON();
      }
    }
  }
  else
  {
    //Serial.println("OFF");
    if (is_presented != 1) {
      ledOFF();
    }
    no_detect_count++;
    detect_count = 0;

    if (no_detect_count >= THRESHOLD_LEAVE) {
      /* That means the system recognizes that someone leaves already */
      is_presented = 0;
      ledOFF();
    }

    if (no_detect_count >= 65535) {
      no_detect_count = 0;
      max_no_detect_count = 0;
    }

    if (no_detect_count > max_no_detect_count) {
      max_no_detect_count = no_detect_count;
    }
  }

  if ((period_st == CHK_IN_PERID) &&
      (millis() - start_chktime > CHK_PERIOD_TIME)) {
    period_st = CHK_END;
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

#if CFG_SHOW_SEC
  Serial.print("  ");
  Serial.print((max_no_detect_count * LOOP_INTERVAL_MS) / 1000);
  Serial.print("sec");
#endif

  if (is_presented == 1) {
    Serial.print(" ... [O]");
  } else {
    Serial.print(" ... [X]");
  }

  if (period_st == CHK_START)
  {
    Serial.print(" --* (");
    Serial.print(CHK_PERIOD_TIME / 1000);
    Serial.println("sec)");
    period_st = CHK_IN_PERID;
  }
  else if (period_st == CHK_IN_PERID)
  {
    Serial.print("   | ");
    Serial.println(detect_count_in_perid);
  }
  else if (period_st == CHK_END)
  {
    Serial.print(" __x ");
    Serial.println(detect_count_in_perid);
    period_st = CHK_NONE;
    detect_count_in_perid = 0;

    // reset counter
    //detect_count = 0;
    //no_detect_count = 0;
  }
  else
  {
    Serial.println();
  }
}

void loop() {
  update_sensor_data();
  show_summary();
  delay(LOOP_INTERVAL_MS);
}
