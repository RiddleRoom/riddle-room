/*

this code is supposesd to utilize an old PS/2 keyboard, reading number keys
1-9 & 0. when a player presses the number keys, LEDs on mapped on the charlieplex
light up in a pattern. A compare and contrast memory game of sorts. The
current Charlieplex.h library does not work; I had been planning on switching
to the chaplex.h library until Kristina mentioned the LPD8806 LEDs.

*/





#include "PS2Keyboard.h"
#include "Chaplex.h"


byte ctrlpins[] = {13,12,11,10,9,8};
#define PINS 6 //define pins in the order you want to adress them

Chaplex myCharlie(ctrlpins, PINS);     //control instance

//individual 'pins' , adress charlieplex pins as you would adress an array
charlieLed myLeds[30] = {{ 0 , 1 }, //led1 is indicated by current flow from 12 to 13
                         { 1 , 0 },
                         { 1 , 2 },
                         { 2 , 1 },
                         { 2 , 3 },
                         { 3 , 2 },
                         { 3 , 4 },
                         { 4 , 3 },
                         { 4 , 5 },
                         { 5 , 4 },
                         { 0 , 2 },
                         { 2 , 0 },
                         { 1 , 3 },
                         { 3 , 1 },
                         { 2 , 4 },
                         { 4 , 2 },
                         { 3 , 5 },
                         { 5 , 3 },
                         { 0 , 3 },
                         { 3 , 0 },
                         { 1 , 4 },
                         { 4 , 1 },
                         { 2 , 5 },
                         { 5 , 2 },
                         { 0 , 4 },
                         { 4 , 0 },
                         { 1 , 5 },
                         { 5 , 1 },
                         { 0 , 5 },
                         { 5 , 0 }};

boolean singleOn = false;

const int DataPin = 2;
const int IRQpin =  3;

byte byteRead;

PS2Keyboard keyboard;

void setup() {
  keyboard.begin(DataPin, IRQpin);
  Serial.begin(9600);
  //Ethernet.begin(mac,ip);
  //Udp.begin(outPort);  
}

void loop() {
  if (keyboard.available()) {
    
    // read the next key
    char c = keyboard.read();
    
    // check for some of the special keys
    if (c == '1') {
        myCharlie.ledWrite(myLeds[1], ON);
        myCharlie.ledWrite(myLeds[26], ON);
        myCharlie.ledWrite(myLeds[4], ON);
        myCharlie.ledWrite(myLeds[22], ON);
        myCharlie.ledWrite(myLeds[3], ON);
        myCharlie.ledWrite(myLeds[25], ON);
        myCharlie.ledWrite(myLeds[7], ON);
        myCharlie.ledWrite(myLeds[23], ON);
        myCharlie.ledWrite(myLeds[15], ON);
        myCharlie.ledWrite(myLeds[17], ON);
        Serial.println("Time Stamp 1");
      }
      
    else if (c == '2') {
        myCharlie.ledWrite(myLeds[0], ON);
        myCharlie.ledWrite(myLeds[28], ON);
        myCharlie.ledWrite(myLeds[2], ON);
        myCharlie.ledWrite(myLeds[24], ON);
        myCharlie.ledWrite(myLeds[8], ON);
        myCharlie.ledWrite(myLeds[22], ON);
        myCharlie.ledWrite(myLeds[9], ON);
        myCharlie.ledWrite(myLeds[21], ON);
        myCharlie.ledWrite(myLeds[14], ON);
        myCharlie.ledWrite(myLeds[17], ON);
        Serial.println("Time Stamp 2");
      }
      
    else if (c == '3') {
        myCharlie.ledWrite(myLeds[1], ON);
        myCharlie.ledWrite(myLeds[26], ON);
        myCharlie.ledWrite(myLeds[0], ON);
        myCharlie.ledWrite(myLeds[29], ON);
        myCharlie.ledWrite(myLeds[2], ON);
        myCharlie.ledWrite(myLeds[24], ON);
        myCharlie.ledWrite(myLeds[7], ON);
        myCharlie.ledWrite(myLeds[23], ON);
        myCharlie.ledWrite(myLeds[9], ON);
        myCharlie.ledWrite(myLeds[21], ON);
        myCharlie.ledWrite(myLeds[13], ON);
        myCharlie.ledWrite(myLeds[19], ON);
        Serial.println("Time Stamp 3");      
      }
      
    else if (c == '4') {
        myCharlie.ledWrite(myLeds[4], ON);
        myCharlie.ledWrite(myLeds[23], ON);
        myCharlie.ledWrite(myLeds[5], ON);
        myCharlie.ledWrite(myLeds[25], ON);
        myCharlie.ledWrite(myLeds[11], ON);
        myCharlie.ledWrite(myLeds[18], ON);
        myCharlie.ledWrite(myLeds[10], ON);
        myCharlie.ledWrite(myLeds[19], ON);
        myCharlie.ledWrite(myLeds[14], ON);
        myCharlie.ledWrite(myLeds[16], ON);
        Serial.println("Time Stamp 4");
      }
      
    else if (c == '5') {
        myCharlie.ledWrite(myLeds[1], ON);
        myCharlie.ledWrite(myLeds[26], ON);
        myCharlie.ledWrite(myLeds[0], ON);
        myCharlie.ledWrite(myLeds[28], ON);
        myCharlie.ledWrite(myLeds[4], ON);
        myCharlie.ledWrite(myLeds[22], ON);
        myCharlie.ledWrite(myLeds[15], ON);
        myCharlie.ledWrite(myLeds[16], ON);
        Serial.println("Time Stamp 5");
      }

    else if (c == '6') {
        myCharlie.ledWrite(myLeds[7], ON);
        myCharlie.ledWrite(myLeds[23], ON);
        myCharlie.ledWrite(myLeds[8], ON);
        myCharlie.ledWrite(myLeds[20], ON);
        myCharlie.ledWrite(myLeds[12], ON);
        myCharlie.ledWrite(myLeds[19], ON);
        myCharlie.ledWrite(myLeds[14], ON);
        myCharlie.ledWrite(myLeds[15], ON);
        myCharlie.ledWrite(myLeds[16], ON);
       Serial.println("Time Stamp 6"); 
      }
      
    else if (c == '7') {
        myCharlie.ledWrite(myLeds[0], ON);
        myCharlie.ledWrite(myLeds[29], ON);
        myCharlie.ledWrite(myLeds[9], ON);
        myCharlie.ledWrite(myLeds[21], ON);
        myCharlie.ledWrite(myLeds[14], ON);
        myCharlie.ledWrite(myLeds[17], ON);
        Serial.println("Time Stamp 7");
      }
      
    else if (c == '8') {
        myCharlie.ledWrite(myLeds[0], ON);
        myCharlie.ledWrite(myLeds[28], ON);
        myCharlie.ledWrite(myLeds[5], ON);
        myCharlie.ledWrite(myLeds[25], ON);
        myCharlie.ledWrite(myLeds[10], ON);
        myCharlie.ledWrite(myLeds[19], ON);
        myCharlie.ledWrite(myLeds[15], ON);
        myCharlie.ledWrite(myLeds[27], ON);
        Serial.println("Time Stamp 8");
      }  
      
    else if (c == '9') {
        myCharlie.ledWrite(myLeds[1], ON);
        myCharlie.ledWrite(myLeds[26], ON);
        myCharlie.ledWrite(myLeds[3], ON);
        myCharlie.ledWrite(myLeds[25], ON);
        myCharlie.ledWrite(myLeds[5], ON);
        myCharlie.ledWrite(myLeds[11], ON);
        myCharlie.ledWrite(myLeds[18], ON);
        myCharlie.ledWrite(myLeds[12], ON);
        myCharlie.ledWrite(myLeds[20], ON);
        myCharlie.ledWrite(myLeds[15], ON);
        myCharlie.ledWrite(myLeds[16], ON);
        Serial.println("Time Stamp 9");
      }
  
       /*   else if (c == 'KEY') {
        digitalWrite(A1, LOW);
        digitalWrite(A2, LOW);
        digitalWrite(A3, LOW);
        digitalWrite(A4, LOW);
        digitalWrite(A5, LOW);
        digitalWrite(led#, HIGH);
      }
      */
     
  }
}
