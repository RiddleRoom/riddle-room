/*

A simple game of Simon that plays the Xfiles themesong for the pattern.
test players have suggested more levels of difficulty, and have expressed
some frustration with the way the game blinks and loops at the beginning.

*/


#include "Tone.h"
#include <OSCMessage.h>
#include <OSCBundle.h>
#include <Ethernet.h>
#include <EthernetUdp.h>
#include <SPI.h>

EthernetUDP Udp;

//arduino IP
IPAddress ip(192, 168, 0, 9);
//deestination IP
IPAddress outIp(192, 168, 0, 1);
//OSC Port
const unsigned int outPort = 10000;
const unsigned int inPort = 90000;

 byte mac[] = {  
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED }; // MAC adddress will need to be unique for each module

const int button0 = 2 ;  //The five button input pins
const int button1 = A1;
const int button2 = A2;
const int button3 = A3;
const int button4 = A4;
const int ledpin2 = 8;  // LED pins
const int ledpin3 = 3;
const int ledpin4 = 4;
const int ledpin5 = 5;
const int ledpin6 = 6;
int xfiles [] = {NOTE_A3, NOTE_E4, NOTE_D4, NOTE_E4, NOTE_G4, NOTE_E4}; // x files theme
const int buttons = 6; //number of buttons to be pressed
int inputArray [buttons];
int buttonArray [6];
const int speaker = 7;
int buttonState = 0;
int buttonCount = 0;

void setup() {
  pinMode(speaker, OUTPUT); 
  pinMode(ledpin2, OUTPUT); // LED pins are outputs
  pinMode(ledpin3, OUTPUT);
  pinMode(ledpin4, OUTPUT);
  pinMode(ledpin5, OUTPUT);
  pinMode(ledpin6, OUTPUT);
  pinMode(button0, INPUT);  // button pins are inputs
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(button4, INPUT);
  Ethernet.begin(mac,ip);
  Udp.begin(outPort);
  attachInterrupt(0, count, CHANGE);
}

void loop(){      //main loop, checks button state, directs program
    buttonState = digitalRead(button0);
    if (buttonCount<1){  // if the buttonCount is greater that 1, we move onto the game
      themesong();       // if less than 1, move into default theme song loop
    }
    else if (buttonCount>1 && buttonCount != 20) {
      game();
    }
    else if (buttonCount == 20){
      digitalWrite(ledpin2, HIGH);
     OSCMessage msg("/SIMON");
    msg.add(1);
  
    Udp.beginPacket(outIp, outPort);
      msg.send(Udp); // send the bytes to the SLIP stream
    Udp.endPacket(); // mark the end of the OSC Packet
    msg.empty(); // free space occupied by message
    }
}
    
void themesong(){  // Plays xfiles theme, listens for a butoon press, proceeds to blinky program, returns to original loop
    buttonState = digitalRead(button0);
    for (int thisNote = 0; thisNote < 6; thisNote++) {
      tone(speaker, xfiles[thisNote], 900);
      if (thisNote==0){
        digitalWrite(ledpin3, HIGH);
      }
      if (thisNote==2){
        digitalWrite(ledpin6, HIGH);
      }
      if (thisNote==1 || thisNote==3 || thisNote==5){
        digitalWrite(ledpin5, HIGH);
      }
      if (thisNote==4){
        digitalWrite(ledpin4, HIGH);
      }
      int pauseBetweenNotes = 1000;
      delay(pauseBetweenNotes);
      noTone(speaker);  
      digitalWrite(ledpin3, LOW);
      digitalWrite(ledpin4, LOW);
      digitalWrite(ledpin5, LOW);
      digitalWrite(ledpin6, LOW);  
    }
    blinky(); 
}
    
   void blinky(){ //listens for button presses, blink main button LED 5 times, returns to main loop
      buttonState = digitalRead(button0);
      digitalWrite(ledpin2, HIGH);
      delay(500);
      digitalWrite(ledpin2, LOW);
      delay(500);
      digitalWrite(ledpin2, HIGH);
      delay(500);
      digitalWrite(ledpin2, LOW);
      delay(500);
      digitalWrite(ledpin2, HIGH);
      delay(500);
      digitalWrite(ledpin2, LOW);
      delay(500);
      digitalWrite(ledpin2, HIGH);
      delay(500);
      digitalWrite(ledpin2, LOW);
      delay(2000);
   }
   
   void game(){ // this is where the game coding will go
   int flag = 0;
    for (int x=0; x<6; x++) {
       int buttonArray [6] = {A1, A3, A4, A3, A2, A3}; //button array to check against input
       flag = 0;
       while(flag == 0){
         if(digitalRead(button1) == HIGH){
         digitalWrite(ledpin3, HIGH);
         tone(speaker, NOTE_A3, 500);
         delay(200);
         inputArray[x] = A1;
         flag = 1;
         delay(250);
         if (inputArray[x] != buttonArray[x]){
           loose();
           return;
         }
         digitalWrite(ledpin3, LOW);
       }
       if(digitalRead(button2) == HIGH){
         digitalWrite(ledpin4, HIGH);
         tone(speaker, NOTE_G4, 500);
         delay(200);
         inputArray[x] = A2;
         flag = 1;
         delay(250);
         if (inputArray[x] != buttonArray[x]){
           loose();
           return;
         }
         digitalWrite(ledpin4, LOW);
       }
       if(digitalRead(button3) == HIGH){
         digitalWrite(ledpin5, HIGH);
         tone(speaker, NOTE_E4, 500);
         delay(200);
         inputArray[x] = A3;
         flag = 1;
         delay(250);
         if (inputArray[x] != buttonArray[x]){
           loose();
           return;
         }
         digitalWrite(ledpin5, LOW);
       }
       if(digitalRead(button4) == HIGH){
         digitalWrite(ledpin6, HIGH);
         tone(speaker, NOTE_D4, 500);
         delay(200);
         inputArray[x] = A4;
         flag = 1;
         delay(250);
         if (inputArray[x] != buttonArray[x]){
           loose();
           return;
         }
         digitalWrite(ledpin6, LOW);
       }
      }
     }
      win();
   }
 
 void count(){   //records button presses
   buttonCount++;
 }
 
 void loose(){ //If the player fails to enter the correct button sequence, theis occurs
    digitalWrite(ledpin2, HIGH);
    digitalWrite(ledpin3, HIGH);
    digitalWrite(ledpin4, HIGH);
    digitalWrite(ledpin5, HIGH);
    digitalWrite(ledpin6, HIGH);
    tone(speaker, NOTE_D1, 500);
    delay(200);
    tone(speaker, NOTE_C1, 500);
    delay(200);
    digitalWrite(ledpin2, LOW);
    digitalWrite(ledpin3, LOW);
    digitalWrite(ledpin4, LOW);
    digitalWrite(ledpin5, LOW);
    digitalWrite(ledpin6, LOW);
    buttonCount = 0;
    delay(1000);
 }
 
 void win() {
   buttonCount = 20;
 }
