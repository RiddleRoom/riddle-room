/*

Another simple Pinpad code device

*/


#include <Ethernet.h>
#include <EthernetUdp.h>
#include <SPI.h>    
#include <OSCMessage.h>

#include <Password.h>
#include <Wire.h>
#include <Adafruit_MCP23017.h>
#include <Adafruit_RGBLCDShield.h>
#include <Keypad.h>

EthernetUDP Udp;
//the Arduino's IP
IPAddress ip(192, 168, 0, 7);
//destination IP
IPAddress outIp(192, 168, 0, 1);
const unsigned int outPort = 10010;

 byte mac[] = {  
  0xDE, 0xAD, 0xAA, 0xAA, 0xAB, 0xBB };

Adafruit_RGBLCDShield lcd = Adafruit_RGBLCDShield();
Password password = Password("6806");
int pos = 0;
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keys[ROWS][COLS] =
 {{'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0',' ','D'}};
byte colPins[COLS] = {5, 2, A1, A0}; //connect to the row pinouts of the keypad
byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the column pinouts of the keypad

int OSCState = 0;

// Create the Keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
    Ethernet.begin(mac,ip);
    Udp.begin(7000);
lcd.begin(16, 2);
Serial.begin(9600);
keypad.addEventListener(keypadEvent); //add an event listener for this keypad
keypad.setDebounceTime(250);
lcd.setCursor(0,0);
lcd.print("EnterCoordinates");
lcd.setCursor(2,1);
}

void loop(){
keypad.getKey();
  
  if (OSCState>0) {
    OSCSender();
  }
  else {
      OSCMessage msg("/StarCharts");
        msg.add(0);
      Udp.beginPacket(outIp, outPort);
      msg.send(Udp); // send the bytes to the SLIP stream
      Udp.endPacket(); // mark the end of the OSC Packet
      msg.empty(); // free space occupied by message
  }  
}

//take care of some special events
void keypadEvent(KeypadEvent eKey){
  
  switch (keypad.getState()){
  case PRESSED:
  lcd.print(eKey);

    switch (eKey){
      case ' ': guessPassword(); break;
      default:
      password.append(eKey);
    }
  }
}

void guessPassword(){
  if (password.evaluate()){
     lcd.clear();
     lcd.setCursor(0,0);
     lcd.print("Coordinates Set ");
     OSCState++;
  }

  else {
     lcd.clear();
     lcd.setCursor(0,0);
     lcd.print("Insufficient");
     lcd.setCursor(0,1);
     lcd.print("Fuel");  
     delay(2000);
     lcd.clear();
     lcd.print("EnterCoordinates");
     lcd.setCursor(2,1);
     password.reset(); //resets password after INCORRECT entry 
  }
}

void OSCSender() {
     OSCMessage msg("/StarCharts");
       msg.add(1);
     Udp.beginPacket(outIp, outPort);
     msg.send(Udp); // send the bytes to the SLIP stream
     Udp.endPacket(); // mark the end of the OSC Packet
     msg.empty(); // free space occupied by message

}
