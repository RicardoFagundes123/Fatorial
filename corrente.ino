#include <KNoTThing.h>
#include "EmonLib.h" 
#include <LiquidCrystal.h>

#define KNOT_BOARD_VXX_XX

#if defined (KNOT_BOARD_V01_02)
  #define LED_PIN             2
  #define SWITCH_PIN          3
#elif defined (KNOT_BOARD_V01_03)
  #define LED_PIN             5
  #define SWITCH_PIN          2
#else
  #define LED_PIN             3
  #define SWITCH_PIN          2
#endif

#define LED_ID              1
#define LED_NAME            "LED"
#define VAR                 "Var"
#define VAR_ID              2
#define THING_NAME          "HelloWorld KNoT"
#define PRINTING_TIME       5000

KNoTThing thing;
EnergyMonitor emon1;
int rede = 110.0;
int pino_sct = 1;
bool led_value = 0;
bool prev_switch_value = 0;
static void printTimestamp(void)
{
  static long current_millis = 0, print_millis = 0, hour = 0, minute = 0, sec = 0;
  if (millis()-current_millis >= 1000) {
    sec++;
    if (sec >= 60) {
      minute++;
      sec = 0;
      if (minute >= 60) {
        hour++;
        minute = 0;
      }
    }
    current_millis = millis();
  }
  if (millis()-print_millis >= PRINTING_TIME) {
    Serial.print(hour);
    Serial.print(":");
    Serial.print(minute);
    Serial.print(":");
    Serial.println(sec);
    print_millis = millis();
  }
}

static int led_read(uint8_t *val)
{
  *val = led_value;
  return 0;
}
static int var_read(int32_t *val, int32_t *multiplier)
{
  *val = emon1.calcIrms(1480);;
  *multiplier = 1;
  Serial.print("Corrente : ");
  Serial.print(Irms); // Irms
  Serial.print(" Potencia : ");
  Serial.println(Irms*rede);
  return 0;
}

static int led_write(uint8_t *val)
{
  led_value=*val;
  Serial.print(F("LED value: "));
  Serial.println(led_value);
  digitalWrite(LED_PIN, led_value);

  return 0;
}

void setup(void)
{
  Serial.begin(115200);
  emon1.current(pino_sct, 29);
  pinMode(LED_PIN, OUTPUT);
  pinMode(SWITCH_PIN, INPUT);
  thing.init(THING_NAME);
  thing.registerBoolData(LED_NAME, LED_ID, KNOT_TYPE_ID_SWITCH,
      KNOT_UNIT_NOT_APPLICABLE, led_read, led_write);
  thing.registerIntData(VAR, VAR_ID, KNOT_TYPE_ID_CURRENT,
      KNOT_UNIT_CURRENT_A, var_read, NULL);
  thing.registerDefaultConfig(LED_ID,
      KNOT_EVT_FLAG_TIME | KNOT_EVT_FLAG_CHANGE,
      30,0, 0, 0, 0);
  Serial.println(F(THING_NAME));
}

void loop(void)
{
  thing.run();
  if (digitalRead(SWITCH_PIN)) {
    if (prev_switch_value == 0) {
      led_value = !led_value;
      Serial.print(F("LED value: "));
      Serial.println(led_value);
    }
    prev_switch_value = 1;
  } else {
    prev_switch_value = 0;
  }

  digitalWrite(LED_PIN, led_value);
  printTimestamp();
}
