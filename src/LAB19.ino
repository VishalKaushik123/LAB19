/*
 * Project LAB19
 * Description:
 * Author:
 * Date:
 */
#include "WatchDog_WCL.h"
#include "oled-wing-adafruit.h"

SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);

OledWingAdafruit display;
WatchDog wd;

void setup()
{
  pinMode(D5, INPUT);
  wd.initialize(5000);

  display.setup();
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);

  if (System.resetReason() == RESET_REASON_WATCHDOG)
  {
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0, 0);
    display.println("You didn't pet me");
    display.display();
  }
  else
  {
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0, 0);
    display.println("Normal");
    display.display();
  }
}

void loop()
{
  if (digitalRead(D5) == HIGH)
  {
    wd.pet();
  }
}