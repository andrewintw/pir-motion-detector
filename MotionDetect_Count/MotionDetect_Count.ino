/*
  HC-SR501 PIR Motion Detector setup
  --Jumper Set         : use H (Repeat Trigger)
  --Sensitivity Adjust : Anti C.W to the end (Low, about 3 meters)
  --Time-delay  Adjust : Anti C.W to the end (Shorten, 5 sec)
*/

#define ledOFF()    digitalWrite(LED_BUILTIN, HIGH)
#define ledON()     digitalWrite(LED_BUILTIN, LOW)

/* in my ESP-01 module, LED_BUILTIN is D2,
   so don't use D2 if you want to use ESP-01 onboard LED
*/
#define PIROUT_PIN          0
#define DET_INTERVAL_MS     (1 * 1000)

int sensor_data             = 0;
uint16 detect_count         = 0;
uint16 no_detect_count      = 0;
uint16 max_no_detect_count  = 0;

void _print2digit(int t) {
  if (t < 10) Serial.print('0');
  Serial.print(t);
}

void print_timestamp()
{
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
  Serial.println("\nHC-SR501 initializing...(60sec)");
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
}

void show_summary() {
  print_timestamp();

  Serial.print(" pv:");
  Serial.print(sensor_data);
  Serial.print(" dc:");
  Serial.print(detect_count);
  Serial.print("\tndc:");
  Serial.print(no_detect_count);
  Serial.print("\tMax(ndc):");
  Serial.print(max_no_detect_count);
  Serial.print("\t");
  Serial.print((max_no_detect_count * DET_INTERVAL_MS) / 1000);
  Serial.println("sec");
}

void loop() {
  update_detect_counter();
  show_summary();
  delay(DET_INTERVAL_MS);
}
