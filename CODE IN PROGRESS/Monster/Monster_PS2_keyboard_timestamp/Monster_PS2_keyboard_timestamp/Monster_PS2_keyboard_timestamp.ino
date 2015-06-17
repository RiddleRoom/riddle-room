/*

this code is supposesd to utilize an old PS/2 keyboard, reading number keys
1-9 & 0. when a player presses the number keys, LEDs on mapped on the charlieplex
light up in a pattern. A compare and contrast memory game of sorts. The
current Charlieplex.h library does not work; I had been planning on switching
to the chaplex.h library until Kristina mentioned the LPD8806 LEDs.

*/





#include <PS2Keyboard.h>
#include <Charlieplex.h>

#define NUMBER_OF_PINS 6
//define pins in the order you want to adress them
byte pins[] = {A0,A1,A2,A3,A4,A5};
/* const int A0 = 0
const int A1 = 1
const int A2 = 2
const int A3 = 3
const int A4 = 4
const int A5 = 5
*/


//initialize object
Charlieplex charlieplex = Charlieplex(pins,NUMBER_OF_PINS);

//individual 'pins' , adress charlieplex pins as you would adress an array
charliePin led1 = { 0 , 1 }; //led1 is indicated by current flow from 12 to 13
charliePin led2 = { 1 , 0 };
charliePin led3 = { 1 , 2 };
charliePin led4 = { 2 , 1 };
charliePin led5 = { 2 , 3 };
charliePin led6 = { 3 , 2 };
charliePin led7 = { 3 , 4 };
charliePin led8 = { 4 , 3 };
charliePin led9 = { 4 , 5 };
charliePin led10 = { 5 , 4 };
charliePin led11 = { 0 , 2 };
charliePin led12 = { 2 , 0 };
charliePin led13 = { 1 , 3 };
charliePin led14 = { 3 , 1 };
charliePin led15 = { 2 , 4 };
charliePin led16 = { 4 , 2 };
charliePin led17 = { 3 , 5 };
charliePin led18 = { 5 , 3 };
charliePin led19 = { 0 , 3 };
charliePin led20 = { 3 , 0 };
charliePin led21 = { 1 , 4 };
charliePin led22 = { 4 , 1 };
charliePin led23 = { 2 , 5 };
charliePin led24 = { 5 , 2 };
charliePin led25 = { 0 , 4 };
charliePin led26 = { 4 , 0 };
charliePin led27 = { 1 , 5 };
charliePin led28 = { 5 , 1 };
charliePin led29 = { 0 , 5 };
charliePin led30 = { 5 , 0 };

boolean singleOn = false;

const int DataPin = 2;
const int IRQpin =  3;

byte byteRead;

PS2Keyboard keyboard;

void setup() {
  keyboard.begin(DataPin, IRQpin);
  //Ethernet.begin(mac,ip);
  //Udp.begin(outPort);  
}

void loop() {
  if (keyboard.available()) {
    
    // read the next key
    char c = keyboard.read();
    
    // check for some of the special keys
    if (c == '1') {
        digitalWrite(A0, LOW);
        digitalWrite(A1, LOW);
        digitalWrite(A2, LOW);
        digitalWrite(A3, LOW);
        digitalWrite(A4, LOW);
        digitalWrite(A5, LOW);
        digitalWrite(led2, HIGH);
        digitalWrite(led27, HIGH);
        digitalWrite(led5, HIGH);
        digitalWrite(led23, HIGH);
        digitalWrite(led4, HIGH);
        digitalWrite(led26, HIGH);
        digitalWrite(led8, HIGH);
        digitalWrite(led24, HIGH);
        digitalWrite(led16, HIGH);
        digitalWrite(led18, HIGH);
      }
      
    else if (c == '2') {
        digitalWrite(A0, LOW);
        digitalWrite(A1, LOW);
        digitalWrite(A2, LOW);
        digitalWrite(A3, LOW);
        digitalWrite(A4, LOW);
        digitalWrite(A5, LOW);
        digitalWrite(led1, HIGH);
        digitalWrite(led29, HIGH);
        digitalWrite(led3, HIGH);
        digitalWrite(led25, HIGH);
        digitalWrite(led9, HIGH);
        digitalWrite(led21, HIGH);
        digitalWrite(led10, HIGH);
        digitalWrite(led22, HIGH);
        digitalWrite(led15, HIGH);
        digitalWrite(led18, HIGH);
      }
      
    else if (c == '3') {
        digitalWrite(A0, LOW);
        digitalWrite(A1, LOW);
        digitalWrite(A2, LOW);
        digitalWrite(A3, LOW);
        digitalWrite(A4, LOW);
        digitalWrite(A5, LOW);
        digitalWrite(led2, HIGH);
        digitalWrite(led27, HIGH);
        digitalWrite(led1, HIGH);
        digitalWrite(led30, HIGH);
        digitalWrite(led3, HIGH);
        digitalWrite(led25, HIGH);
        digitalWrite(led8, HIGH);
        digitalWrite(led24, HIGH);
        digitalWrite(led10, HIGH);
        digitalWrite(led22, HIGH);
        digitalWrite(led14, HIGH);
        digitalWrite(led20, HIGH);       
      }
      
    else if (c == '4') {
        digitalWrite(A0, LOW);
        digitalWrite(A1, LOW);
        digitalWrite(A2, LOW);
        digitalWrite(A3, LOW);
        digitalWrite(A4, LOW);
        digitalWrite(A5, LOW);
        digitalWrite(led5, HIGH);
        digitalWrite(led23, HIGH);
        digitalWrite(led6, HIGH);
        digitalWrite(led26, HIGH);
        digitalWrite(led12, HIGH);
        digitalWrite(led19, HIGH);
        digitalWrite(led11, HIGH);
        digitalWrite(led20, HIGH);
        digitalWrite(led15, HIGH);
        digitalWrite(led17, HIGH); 
      }
      
    else if (c == '5') {
        digitalWrite(A0, LOW);
        digitalWrite(A1, LOW);
        digitalWrite(A2, LOW);
        digitalWrite(A3, LOW);
        digitalWrite(A4, LOW);
        digitalWrite(A5, LOW);
        digitalWrite(led2, HIGH);
        digitalWrite(led27, HIGH);
        digitalWrite(led1, HIGH);
        digitalWrite(led29, HIGH);
        digitalWrite(led5, HIGH);
        digitalWrite(led23, HIGH);
        digitalWrite(led16, HIGH);
        digitalWrite(led17, HIGH);
      }

    else if (c == '6') {
        digitalWrite(A0, LOW);
        digitalWrite(A1, LOW);
        digitalWrite(A2, LOW);
        digitalWrite(A3, LOW);
        digitalWrite(A4, LOW);
        digitalWrite(A5, LOW);
        digitalWrite(led8, HIGH);
        digitalWrite(led24, HIGH);
        digitalWrite(led9, HIGH);
        digitalWrite(led21, HIGH);
        digitalWrite(led13, HIGH);
        digitalWrite(led20, HIGH);
        digitalWrite(led15, HIGH);
        digitalWrite(led16, HIGH);
        digitalWrite(led17, HIGH); 
      }
      
    else if (c == '7') {
        digitalWrite(A0, LOW);
        digitalWrite(A1, LOW);
        digitalWrite(A2, LOW);
        digitalWrite(A3, LOW);
        digitalWrite(A4, LOW);
        digitalWrite(A5, LOW);
        digitalWrite(led1, HIGH);
        digitalWrite(led30, HIGH);
        digitalWrite(led10, HIGH);
        digitalWrite(led22, HIGH);
        digitalWrite(led15, HIGH);
        digitalWrite(led18, HIGH); 
      }
      
    else if (c == '8') {
        digitalWrite(A0, LOW);
        digitalWrite(A1, LOW);
        digitalWrite(A2, LOW);
        digitalWrite(A3, LOW);
        digitalWrite(A4, LOW);
        digitalWrite(A5, LOW);
        digitalWrite(led1, HIGH);
        digitalWrite(led29, HIGH);
        digitalWrite(led6, HIGH);
        digitalWrite(led26, HIGH);
        digitalWrite(led11, HIGH);
        digitalWrite(led20, HIGH);
        digitalWrite(led16, HIGH);
        digitalWrite(led28, HIGH);
      }  
      
    else if (c == '9') {
        digitalWrite(A0, LOW);
        digitalWrite(A1, LOW);
        digitalWrite(A2, LOW);
        digitalWrite(A3, LOW);
        digitalWrite(A4, LOW);
        digitalWrite(A5, LOW);
        digitalWrite(led2, HIGH);
        digitalWrite(led27, HIGH);
        digitalWrite(led4, HIGH);
        digitalWrite(led26, HIGH);
        digitalWrite(led6, HIGH);
        digitalWrite(led12, HIGH);
        digitalWrite(led19, HIGH);
        digitalWrite(led13, HIGH);
        digitalWrite(led19, HIGH);
        digitalWrite(led16, HIGH);
        digitalWrite(led17, HIGH);
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
