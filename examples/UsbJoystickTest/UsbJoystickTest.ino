// Adapter for old gameport joystick
//
// Arduino Leonardo or Arduino Micro.
//
// Jarkko Sonninen
// 2016-03-22
//------------------------------------------------------------

#include "Joystick1.h"

#define D0 0
#define D1 1
#define D2 2
#define D3 3

const unsigned long gcCycleDelta = 100;

unsigned long gNextTime = 0;
unsigned int gCurrentStep = 0;

void setup() {
  Joystick.begin(false);
  
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A9, INPUT);
  pinMode(A10, INPUT);
  pinMode(A11, INPUT);
  pinMode(D0, INPUT_PULLUP);
  pinMode(D1, INPUT_PULLUP);
  pinMode(D2, INPUT_PULLUP);
  pinMode(D3, INPUT_PULLUP);
  pinMode(13, OUTPUT);

  //Serial.begin(9600);
}

unsigned long nextms = 1000;

static int ox, oy, othrottle, orudder, ob1, ob2, ob3, ob4;

static int adjust (int value) {
  value = 2 * 69000 / value - 2 * 100;
  if (value > 255) value = 255;
  if (value < 0) value = -128;
  return value;
}

void loop() {

  unsigned long ms = millis();
  if (ms < nextms) {  
    return;
  }
  nextms = ms + 100;

  // Turn indicator light on.
  //digitalWrite(13, 1);
  digitalWrite(13, 0);
    delay(1);
    int x = analogRead(A2);
    x = adjust(x) - 100;
    // 303 - 400 - 675
    delay(1);
    int y = analogRead(A1);
    // 310 - 410 - 675
    y = adjust(y) - 130;
    delay(1);
    int throttle = analogRead(A9);
    // 318 - 675
    throttle = adjust(throttle);
    delay(1);
    int rudder = analogRead(A0);
    // cap up = 665, down = 475, left = 416, right = 562
    //rudder = rudder - 300;
    rudder = adjust (rudder);
    rudder = (rudder + 20 ) / 45;
    //Serial.println(rudder);
    delay(1);
    int b1 = !digitalRead(D2);
    int b2 = !digitalRead(D1);
    int b3 = !digitalRead(D3);
    int b4 = !digitalRead(D0);
    if (x == ox && y == oy && throttle == othrottle && rudder == orudder 
      && b1 == ob1 && b2 == ob2 && b3 == ob3 && b4 == ob4) {
      return;
    }
    digitalWrite(13, 1);
    ox = x;
    oy = y;
    othrottle = throttle;
    orudder = rudder;
    ob1 = b1;
    ob2 = b2;
    ob3 = b3; 
    ob4 = b4;
    
    Joystick.setXAxis(x);
    Joystick.setYAxis(y);
    Joystick.setThrottle(throttle);
    Joystick.setRudder(rudder);

    Joystick.setButton(0, b1);
    Joystick.setButton(1, b2);
    Joystick.setButton(2, b3);
    Joystick.setButton(3, b4);

    for (int j = 0; j < 4; j++) {
      Joystick.setButton(4+j, rudder == j);
    }
    Joystick.setHatSwitch(rudder * 2);
    
    Joystick.sendState();
    //delay(200);
}

