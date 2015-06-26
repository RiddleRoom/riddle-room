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
byte pins[] = {13,12,11,10,9,8};
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

int stampCount = 0;

void setup() {
  keyboard.begin(DataPin, IRQpin);
  Serial.begin(9600); 
}

void loop() {
  if (keyboard.available()) {
    
    // read the next key
    char c = keyboard.read();
    
    // check for some of the special keys
    if (c == '1'){ 
      stampCount = 1;
      }
      
    else if (c == '2'){ 
      stampCount = 2;
      }
      
    else if (c == '3'){ 
      stampCount = 3;
      }
      
    else if (c == '4'){ 
      stampCount = 4;
      }
      
    else if (c == '5'){ 
      stampCount = 5;
      }

    else if (c == '6'){ 
      stampCount = 6;
      }
      
    else if (c == '7'){ 
      stampCount = 7;
      }
      
    else if (c == '8'){ 
      stampCount = 8;
      }

    else if (c == '9'){ 
      stampCount = 9;
      }
    else if (c == '0'){ 
      stampCount = 10;
      }
  }
  else if (stampCount==1) {
     timestamp1();
  }
  else if (stampCount==2) {
     timestamp2();
  }
  else if (stampCount==3) {
     timestamp3();
  }
  else if (stampCount==4) {
     timestamp4();
  }
  else if (stampCount==5) {
     timestamp5();
  }
  else if (stampCount==6) {
     timestamp6();
  }
  else if (stampCount==7) {
     timestamp7();
  }
  else if (stampCount==8) {
     timestamp8();
  }
  else if (stampCount==9) {
     timestamp9();
  }
  else if (stampCount==10) {
     timestamp0();
  }
}

void timestamp1() {
        charlieplex.clear();
        charlieplex.charlieWrite(led2, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led17, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led5, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led21, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led4, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led22, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led8, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led24, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led16, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led29, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led11, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led25, HIGH);
        singleOn=!singleOn;
}

void timestamp2() {
        charlieplex.clear();
        charlieplex.charlieWrite(led1, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led19, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led3, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led22, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led9, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led26, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led10, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led25, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led15, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led30, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led11, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led25, HIGH);
        singleOn=!singleOn;
}

void timestamp3() {
        charlieplex.clear();
        charlieplex.charlieWrite(led2, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led20, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led1, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led18, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led3, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led21, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led9, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led10, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led26, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led14, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led27, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led11, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led25, HIGH);
        singleOn=!singleOn;
}

void timestamp4() {
        charlieplex.clear();
        charlieplex.charlieWrite(led7, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led22, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led6, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led23, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led15, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led30, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led11, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led25, HIGH);
       singleOn=!singleOn;
        }
        
void timestamp5() {
        charlieplex.clear();
        charlieplex.charlieWrite(led2, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led20, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led1, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led18, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led7, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led23, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led16, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led30, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led11, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led25, HIGH);
        singleOn=!singleOn;
}

void timestamp6() {
        charlieplex.clear();
        charlieplex.charlieWrite(led8, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led25, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led9, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led24, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led13, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led27, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led15, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led29, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led30, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led11, HIGH);
       singleOn=!singleOn;
      }
      
void timestamp7() {
        charlieplex.clear();
        charlieplex.charlieWrite(led1, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led18, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led10, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led26, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led15, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led30, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led11, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led25, HIGH);
       singleOn=!singleOn;
      }
      
void timestamp8() {     
        charlieplex.clear();
        charlieplex.charlieWrite(led1, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led19, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led2, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led20, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led6, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led22, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led12, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led28, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led16, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led30, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led11, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led25, HIGH);
        singleOn=!singleOn;
      }  
      
void timestamp9() {     
        charlieplex.clear();
        charlieplex.charlieWrite(led2, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led20, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led4, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led26, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led6, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led12, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led19, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led13, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led19, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led16, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led29, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led11, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led25, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led22, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led21, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led28, HIGH);
        singleOn=!singleOn;
      }  
      
 void timestamp0() {
   charlieplex.clear(); 

        charlieplex.charlieWrite(led1, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led2, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led3, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led4, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led5, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led6, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led7, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led8, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led9, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led10, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led11, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led12, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led13, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led14, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led15, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led16, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led17, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led18, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led19, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led20, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led21, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led22, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led23, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led24, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led25, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led26, HIGH);      
        charlieplex.clear();
        charlieplex.charlieWrite(led27, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led28, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led29, HIGH);
        charlieplex.clear();
        charlieplex.charlieWrite(led30, HIGH);
        
        singleOn=!singleOn;
}
