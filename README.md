Arduino gameport adapter
========================

Copy from https://github.com/MHeironimus/ArduinoJoystickLibrary
and modified for my purposes, which is an adapter for old ianalog gameport joystick.

I used this Arduino board:
http://www.aliexpress.com/item/FREE-SHIPPING-1PCS-ATMega-32U4-pro-micro-leonardo-For-Arduino-Compatible-pro-mini-usb-control-board/32276461676.html

Add pulldown resistors to all analog inputs, like seen here:
http://www.built-to-spec.com/blog/2009/09/10/using-a-pc-joystick-with-the-arduino/
No need for pull up resistors for button inputs, since the atmega 32u4 has an internal pull-up.

Connect joystick pins to any inputsi (minding analog and digital, of course), and fix the code to match the inputs.
