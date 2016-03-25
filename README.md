Arduino gameport adapter
========================

Copy from https://github.com/MHeironimus/ArduinoJoystickLibrary
and modified for my purposes, which is an adapter for old analog gameport joystick.
My joystick has 4 buttons, X, Y and thrust or a hat switch, selected by a switch.
For unknown reason the fourth analog input was unused, and I connected the hat switch to that.

I used this Arduino board:
http://www.aliexpress.com/item/FREE-SHIPPING-1PCS-ATMega-32U4-pro-micro-leonardo-For-Arduino-Compatible-pro-mini-usb-control-board/32276461676.html

Add pulldown resistors to all analog inputs, like seen here:
http://www.built-to-spec.com/blog/2009/09/10/using-a-pc-joystick-with-the-arduino/
No need for pull up resistors for button inputs, since the atmega 32u4 has an internal pull-up.

Connect joystick pins to any inputs (minding analog and digital, of course), and fix the code to match the inputs.
