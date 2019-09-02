/*
 * --------------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <yenchang.lin@gmail.com>  wrote this program.  As long as you retain this notice
 * you can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return.  Andrew Lin
 * --------------------------------------------------------------------------------
 */
 
#define ledOFF()      digitalWrite(LED_BUILTIN, HIGH)
#define ledON()       digitalWrite(LED_BUILTIN, LOW)
#define ledBlink()    do { \
                          ledON();  delay(100); \
                          ledOFF(); delay(100); \
                          ledON();  delay(100); \
                          ledOFF(); \
                      } while (0)

typedef enum {
  CHK_NONE,
  CHK_START,
  CHK_IN_PERID,
  CHK_END,
} period_stat_t;


#define LOOP_INTERVAL_MS        (1 * 1000)
#define PIROUT_PIN              0             /* in my ESP-01 module, LED_BUILTIN is D2,
                                                 so don't use D2 if you want to use ESP-01 onboard LED */
#define PIR_INIT_TIME_MS        (60 * 1000)   /* HC-SR501 requires some time to acclimatize to the infrared energy in the room.
                                                 This takes 60 seconds when the sensor is first powered up. */

/* =================================================================
   According to your usage situation adjust the following parameters
   ================================================================= */

#define CHK_PERIOD_TIME         (60 * 1000)
#define THRESHOLD_PRESENT       10            /* detected counts in the detection period */
#define THRESHOLD_LEAVE         90            /* detected counts in the detection period */
#define CFG_IGNORE_NOISES       1
#define IGNORE_NOISES_NUM       2             /* for ignore noises */
