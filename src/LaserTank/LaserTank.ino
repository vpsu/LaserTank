/*
 * Laser Tank
 */

#include <LaserTank.h>

const String tankName = "СЛУ-01";

const byte PIN_LED = 13;

const long BT_SPEED = 38400;
const long BT_TIMEOUT = 100;

LaserTank tank(tankName);

void setup() {
  tank.setDriverPins(2, 3, 4, 5);
  tank.setLaserPin(PIN_LED);
  tank.setHealthPins(A0, A1, A2, A3);
  tank.reset();

  Serial.begin(BT_SPEED);
  Serial.setTimeout(BT_TIMEOUT);
}

void loop() {
  if (Serial.available() > 0)
    tank.dispatch(Serial.read());

  delay(10);
}

/* vim: set ft=arduino et sw=2 ts=2: */

