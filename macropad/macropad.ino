/* 
Written by Steve Kraynov, based off of https://www.instructables.com/Programmable-Keypad-1/
(August, 2021)
*/

#include "Keyboard.h"
#include <Encoder.h>
#include <Keypad.h>

/*        Arduino Pro Micro Pinout
           (PWM pins in brackets)
  
                   |﹉﹉|   
  TX    1     O--------------O RAW
  RX    0     O              O GND
          GND O              O RST
          GND O              O VCC
  SDA(B)2     O              O      21    A3
  SCL  (3)    O              O      20    A2
  A6 (A)4     O              O      19    A1    
       (5)    O              O      18    A0
  A7   (6)    O              O      15    SCLK
        7     O              O      14    MISO
  A8    8     O   Pro Micro  O      16    MOSI
  A9   (9)    O______________O     (10)   A10
*/


Encoder encoder(4, 2);    // rotary encoder pin A and B
long old_position  = -999;     // for rotary encoder


const byte ROWS = 4;
const byte COLS = 4;

char keys[COLS][ROWS] = { // Note: These are the transposed positions 
  {'c', 'd', 'e', 'f'},
  {'8', '9', 'a', 'b'},
  {'4', '5', '6', '7'},
  {'0', '1', '2', '3'}
};

/* Actual layout!
{'c', '8', '4', '0'},
{'d', '9', '5', '1'},
{'e', 'a', '6', '2'},
{'f', 'b', '7', '3'}

*/

byte rowPins[ROWS] = {18, 15, 14, 16}; // Reversed order of row pins 
byte colPins[COLS] = {7, 8, 9, 10}; 
Keypad kpd = Keypad(makeKeymap(keys), colPins, rowPins, ROWS, COLS);

void setup() { }

void loop() {
  

  // Read encoder position 
  long new_position = encoder.read();
  
  // Check for encoder rotation 
  // Serial.println(new_position);

  char key = kpd.getKey();
  if(key) {
    switch (key) {
      case '0':
        Keyboard.press(KEY_LEFT_GUI);
        Keyboard.press(KEY_LEFT_SHIFT);
        Keyboard.press('4');
        Keyboard.releaseAll();
        break;
      case '4':
        Keyboard.press(KEY_LEFT_GUI);
        Keyboard.press(' ');
        delay(5);
        Keyboard.releaseAll();
        Keyboard.println("Screenshots");
        Keyboard.releaseAll();
        delay(30);
        Keyboard.press(KEY_RETURN);
        Keyboard.releaseAll();
        break;
      case '8':
        Keyboard.press(KEY_LEFT_GUI);
        Keyboard.press('w');
        delay(5);
        Keyboard.releaseAll();
        break;
      case 'c':
        Keyboard.press(KEY_ESC);
        Keyboard.releaseAll();
        break;

      // Row 2 
      case '1': 
        Keyboard.press(KEY_LEFT_GUI);
        Keyboard.press(KEY_LEFT_ALT);
        Keyboard.press(KEY_RIGHT_ARROW);
        delay(25);
        Keyboard.releaseAll();
      case '5': 
        Keyboard.press(KEY_LEFT_GUI);
        Keyboard.press(KEY_LEFT_ALT);
        Keyboard.press(KEY_LEFT_ARROW);
        delay(25);
        Keyboard.releaseAll();
//
//      case '5':
//        Keyboard.press(KEY_LEFT_GUI);
//        Keyboard.press(KEY_LEFT_ALT);
//        Keyboard.press(KEY_LEFT_ARROW);
//        Keyboard.releaseAll();
//        Serial.println(key);
//      case '9':
//        Keyboard.press(KEY_LEFT_GUI);
//        Keyboard.press('t');
//        Keyboard.releaseAll();
//        Serial.println(key);
//      case 'd':
//        Keyboard.press(KEY_LEFT_CTRL);
//        Keyboard.press(KEY_UP_ARROW);
//        Keyboard.releaseAll();
//        Serial.println(key);




      // Bottom Row 
      case 'f':
        Keyboard.press(KEY_LEFT_GUI);
        Keyboard.press('c');
        Keyboard.releaseAll();
        break;  
      case 'b':
        Keyboard.press(KEY_LEFT_GUI);
        Keyboard.press('v');
        Keyboard.releaseAll();
        break;  
      case '7':
        Keyboard.press(KEY_LEFT_GUI);
        Keyboard.press('a');
        Keyboard.releaseAll();
        break;  
      
      default:
        Serial.println(key);
    }
  }

  // delay(50);
}
