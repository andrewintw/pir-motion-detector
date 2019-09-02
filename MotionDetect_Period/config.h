
#define ledOFF()    digitalWrite(LED_BUILTIN, HIGH)
#define ledON()     digitalWrite(LED_BUILTIN, LOW)

typedef enum {
  CHK_NONE,
  CHK_START,
  CHK_IN_PERID,
  CHK_END,
} chk_period_t;

#define PIROUT_PIN              0   /* in my ESP-01 module, LED_BUILTIN is D2,
                                       so don't use D2 if you want to use ESP-01 onboard LED */
#define DET_INTERVAL_MS         (1 * 1000)
#define CHK_PERIOD_TIME         (60 * 1000)
