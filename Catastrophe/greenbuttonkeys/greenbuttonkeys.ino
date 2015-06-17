#include <OSCMessage.h>

/*

Sends signals for two key switches and one big green button to the PC. The green button also
has an LED which blinks in different ways depending on how many times a group has pressed
the button

 */
#include <Ethernet.h>
#include <EthernetUdp.h>
#include <SPI.h>    
#include <OSCMessage.h>

EthernetUDP Udp;

//the Arduino's IP
IPAddress ip(192, 168, 0, 6);
//destination IP
IPAddress outIp(192, 168, 0, 1);
const unsigned int outPort = 50000;
unsigned int localPort = 8888;

 byte mac[] = {  
  0xDE, 0xAD, 0xAA, 0xAA, 0xBB, 0xBB
  }; // you can find this written on the board of some Arduino Ethernets or shields

// set pin numbers:
const int Key1= 7;     //key1
const int Key2= 8;     //key2
const int button= 9;     //greenbutton
const int LED = 6;
int buttonCount= 0;

// variables will change:
int key1State = 0;         // variable for reading the pushbutton status
int key2State = 0;
int buttonState = 0;


void setup() {
  Ethernet.begin(mac,ip);
    Udp.begin(localPort);
    Serial.begin(9600);
    
  // initialize the pushbutton pin as an input:
  pinMode(Key1, INPUT);
  pinMode(Key2, INPUT);
  pinMode(button, INPUT);
  pinMode(6, OUTPUT); 
}

void loop(){
  
  // read the state of the pushbutton value:
  key1State = digitalRead(Key1);
  key2State = digitalRead(Key2);
  buttonState = digitalRead(button);
  
  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (key1State == HIGH) {
//the message wants an OSC address as first argument
  OSCMessage msg("/Key1");
  msg.add(1);
  Serial.println("Yes, key1");
  
  Udp.beginPacket(outIp, outPort);
    msg.send(Udp); // send the bytes to the SLIP stream
  Udp.endPacket(); // mark the end of the OSC Packet
  msg.empty(); // free space occupied by message
  }
  
  else {
//the message wants an OSC address as first argument
  OSCMessage msg("/Key1");
  msg.add(0);
  Serial.println("no,key1");
  
  Udp.beginPacket(outIp, outPort);
    msg.send(Udp); // send the bytes to the SLIP stream
  Udp.endPacket(); // mark the end of the OSC Packet
  msg.empty(); // free space occupied by message
  }
  
    // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (key2State == LOW) {
//the message wants an OSC address as first argument
  OSCMessage msg("/Key2");
  msg.add(1);
  Serial.println("Yes, key2");
  
  Udp.beginPacket(outIp, outPort);
    msg.send(Udp); // send the bytes to the SLIP stream
  Udp.endPacket(); // mark the end of the OSC Packet
  msg.empty(); // free space occupied by message
  }
  
  else {
//the message wants an OSC address as first argument
  OSCMessage msg("/Key2");
  msg.add(0);
  Serial.println("no, key2");
  
  Udp.beginPacket(outIp, outPort);
    msg.send(Udp); // send the bytes to the SLIP stream
  Udp.endPacket(); // mark the end of the OSC Packet
  msg.empty(); // free space occupied by message
  }
  
    // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
//the message wants an OSC address as first argument
  OSCMessage msg("/greenbutton");
  msg.add(1);
  Serial.println("Yes, button");
  buttonCount++;
  
  Udp.beginPacket(outIp, outPort);
    msg.send(Udp); // send the bytes to the SLIP stream
  Udp.endPacket(); // mark the end of the OSC Packet
  msg.empty(); // free space occupied by message
  }
  
  else {
//the message wants an OSC address as first argument
  OSCMessage msg("/greenbutton");
  msg.add(0);
  Serial.println("no, button");
  
  Udp.beginPacket(outIp, outPort);
    msg.send(Udp); // send the bytes to the SLIP stream
  Udp.endPacket(); // mark the end of the OSC Packet
  msg.empty(); // free space occupied by message
  }
  
  if (buttonCount == 1) {
  slowblink();
  }
  else if (buttonCount == 0) {
   blinky();
  }
    else if (buttonCount>1) {
      Serial.println("replay sending");
  OSCMessage msg("/replay");
  msg.add(1);
  
  Udp.beginPacket(outIp, outPort);
    msg.send(Udp); // send the bytes to the SLIP stream
  Udp.endPacket(); // mark the end of the OSC Packet
  msg.empty(); // free space occupied by message
  
  delay(500);
  
  msg.add(0);
  
  Udp.beginPacket(outIp, outPort);
    msg.send(Udp); // send the bytes to the SLIP stream
  Udp.endPacket(); // mark the end of the OSC Packet
  msg.empty(); // free space occupied by message
  buttonCount = 1;
  digitalWrite(6, LOW);
    delay(25000);
  Serial.println("replay sent");
  } 
}

void blinky() {
    digitalWrite(6, HIGH);
    delay(100);
    digitalWrite(6, LOW);
    delay(100); 
}
void slowblink() {
    digitalWrite(6, HIGH);
    delay(500);
    digitalWrite(6, LOW);
    delay(500);
}
