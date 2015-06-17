/*

Sends on/off states for 16 hall effect switches via OSC/ethernet to the PC.
The current switches will be replaced due to structural integrity issues.
considering something like this: https://www.sparkfun.com/products/13247
Would be difficult to make the "isolenear chips" as distinct this way;
previously magnets and sensorswere placed in 4 distinct locations, creating
4 types of chips. The puzzles is essentially sodoku.

*/


#include <OSCMessage.h>
#include <Ethernet.h>
#include <EthernetUdp.h>
#include <SPI.h>    
#include <OSCMessage.h>

EthernetUDP Udp;

//the Arduino's IP
IPAddress ip(192, 168, 0, 11);
//destination IP
IPAddress outIp(192, 168, 0, 1);
const unsigned int outPort = 10;
unsigned int localPort = 8888;

 byte mac[] = {  
  0xDE, 0xAD, 0xEE, 0xEE, 0xEE, 0xEE }; // you can find this written on the board of some Arduino Ethernets or shields

const int C0= 23;
const int C1= 25;
const int C2= 27;
const int C3= 29;
const int C4= 31;
const int C5= 33;
const int C6= 35;
const int C7= 37;
const int C8= 39;
const int C9= 41;
const int C10= 43;
const int C11= 45;
const int C12= 47;
const int C13= 49;
const int C14= 44;
const int C15= 46;

int C0State = 0;
int C1State = 0;
int C2State = 0;
int C3State = 0;
int C4State = 0;
int C5State = 0;
int C6State = 0;
int C7State = 0;
int C8State = 0;
int C9State = 0;
int C10State = 0;
int C11State = 0;
int C12State = 0;
int C13State = 0;
int C14State = 0;
int C15State = 0;

void setup() {
  Ethernet.begin(mac,ip);
  Udp.begin(localPort);
  Serial.begin(9600);
  
  pinMode(C0, INPUT); 
  pinMode(C1, INPUT); 
  pinMode(C2, INPUT); 
  pinMode(C3, INPUT);
  pinMode(C4, INPUT);
  pinMode(C5, INPUT);
  pinMode(C6, INPUT);
  pinMode(C7, INPUT);
  pinMode(C8, INPUT); 
  pinMode(C9, INPUT); 
  pinMode(C10, INPUT); 
  pinMode(C11, INPUT);
  pinMode(C12, INPUT);
  pinMode(C13, INPUT);
  pinMode(C14, INPUT);
  pinMode(C15, INPUT); 
}

void loop() {
  C0State = digitalRead(C0);
  C1State = digitalRead(C1);
  C2State = digitalRead(C2);
  C3State = digitalRead(C3);
  C4State = digitalRead(C4);
  C5State = digitalRead(C5);
  C6State = digitalRead(C6);
  C7State = digitalRead(C7);
  C8State = digitalRead(C8);
  C9State = digitalRead(C9);
  C10State = digitalRead(C10);
  C11State = digitalRead(C11);
  C12State = digitalRead(C12);
  C13State = digitalRead(C13);
  C14State = digitalRead(C14);
  C15State = digitalRead(C15);
  
    
    if (C15State == LOW) {
    OSCMessage msg("/C15");
    msg.add(1);
    
    Udp.beginPacket(outIp, outPort);
      msg.send(Udp); // send the bytes to the SLIP stream
    Udp.endPacket(); // mark the end of the OSC Packet
    msg.empty(); // free space occupied by message
    }
    
    else {
    OSCMessage msg("/C15");
    msg.add(0);
    
    Udp.beginPacket(outIp, outPort);
      msg.send(Udp); // send the bytes to the SLIP stream
    Udp.endPacket(); // mark the end of the OSC Packet
    msg.empty(); // free space occupied by message
    }
    
    if (C14State == LOW) {
    OSCMessage msg("/C14");
    msg.add(1);
    
    Udp.beginPacket(outIp, outPort);
    msg.send(Udp); // send the bytes to the SLIP stream
    Udp.endPacket(); // mark the end of the OSC Packet
    msg.empty(); // free space occupied by message
    }
    
    else {
    OSCMessage msg("/C14");
    msg.add(0);
    
    Udp.beginPacket(outIp, outPort);
      msg.send(Udp); // send the bytes to the SLIP stream
    Udp.endPacket(); // mark the end of the OSC Packet
    msg.empty(); // free space occupied by message
    }
    
        if (C13State == LOW) {
    OSCMessage msg("/C13");
    msg.add(1);
    
    Udp.beginPacket(outIp, outPort);
      msg.send(Udp); // send the bytes to the SLIP stream
    Udp.endPacket(); // mark the end of the OSC Packet
    msg.empty(); // free space occupied by message
    }
    
    else {
    OSCMessage msg("/C13");
    msg.add(0);
    
    Udp.beginPacket(outIp, outPort);
      msg.send(Udp); // send the bytes to the SLIP stream
    Udp.endPacket(); // mark the end of the OSC Packet
    msg.empty(); // free space occupied by message
    }
    
    if (C12State == LOW) {
    OSCMessage msg("/C12");
    msg.add(1);
    
    Udp.beginPacket(outIp, outPort);
      msg.send(Udp); // send the bytes to the SLIP stream
    Udp.endPacket(); // mark the end of the OSC Packet
    msg.empty(); // free space occupied by message
    }
    
    else {
    OSCMessage msg("/C12");
    msg.add(0);
    
    Udp.beginPacket(outIp, outPort);
      msg.send(Udp); // send the bytes to the SLIP stream
    Udp.endPacket(); // mark the end of the OSC Packet
    msg.empty(); // free space occupied by message
    }
    
    if (C11State == LOW) {
    OSCMessage msg("/C11");
    msg.add(1);
    
    Udp.beginPacket(outIp, outPort);
      msg.send(Udp); // send the bytes to the SLIP stream
    Udp.endPacket(); // mark the end of the OSC Packet
    msg.empty(); // free space occupied by message
    }
    
    else {
    OSCMessage msg("/C11");
    msg.add(0);
    
    Udp.beginPacket(outIp, outPort);
      msg.send(Udp); // send the bytes to the SLIP stream
    Udp.endPacket(); // mark the end of the OSC Packet
    msg.empty(); // free space occupied by message
    }
    
    if (C10State == LOW) {
    OSCMessage msg("/C10");
    msg.add(1);
    
    Udp.beginPacket(outIp, outPort);
      msg.send(Udp); // send the bytes to the SLIP stream
    Udp.endPacket(); // mark the end of the OSC Packet
    msg.empty(); // free space occupied by message
    }
    
    else {
    OSCMessage msg("/C10");
    msg.add(0);
    
    Udp.beginPacket(outIp, outPort);
      msg.send(Udp); // send the bytes to the SLIP stream
    Udp.endPacket(); // mark the end of the OSC Packet
    msg.empty(); // free space occupied by message
    }
    
    if (C9State == LOW) {
    OSCMessage msg("/C9");
    msg.add(1);
    
    Udp.beginPacket(outIp, outPort);
      msg.send(Udp); // send the bytes to the SLIP stream
    Udp.endPacket(); // mark the end of the OSC Packet
    msg.empty(); // free space occupied by message
    }
    
    else {
    OSCMessage msg("/C9");
    msg.add(0);
    
    Udp.beginPacket(outIp, outPort);
      msg.send(Udp); // send the bytes to the SLIP stream
    Udp.endPacket(); // mark the end of the OSC Packet
    msg.empty(); // free space occupied by message
    }
    
    if (C8State == LOW) {
    OSCMessage msg("/C8");
    msg.add(1);
    
    Udp.beginPacket(outIp, outPort);
      msg.send(Udp); // send the bytes to the SLIP stream
    Udp.endPacket(); // mark the end of the OSC Packet
    msg.empty(); // free space occupied by message
    }
    
    else {
    OSCMessage msg("/C8");
    msg.add(0);
    
    Udp.beginPacket(outIp, outPort);
      msg.send(Udp); // send the bytes to the SLIP stream
    Udp.endPacket(); // mark the end of the OSC Packet
    msg.empty(); // free space occupied by message
    }
    
    if (C7State == LOW) {
    OSCMessage msg("/C7");
    msg.add(1);
    
    Udp.beginPacket(outIp, outPort);
      msg.send(Udp); // send the bytes to the SLIP stream
    Udp.endPacket(); // mark the end of the OSC Packet
    msg.empty(); // free space occupied by message
    }
    
    else {
    OSCMessage msg("/C7");
    msg.add(0);
    
    Udp.beginPacket(outIp, outPort);
      msg.send(Udp); // send the bytes to the SLIP stream
    Udp.endPacket(); // mark the end of the OSC Packet
    msg.empty(); // free space occupied by message
    }
    
    if (C6State == LOW) {
    OSCMessage msg("/C6");
    msg.add(1);
    
    Udp.beginPacket(outIp, outPort);
    msg.send(Udp); // send the bytes to the SLIP stream
    Udp.endPacket(); // mark the end of the OSC Packet
    msg.empty(); // free space occupied by message
    }
    
    else {
    OSCMessage msg("/C6");
    msg.add(0);
    
    Udp.beginPacket(outIp, outPort);
      msg.send(Udp); // send the bytes to the SLIP stream
    Udp.endPacket(); // mark the end of the OSC Packet
    msg.empty(); // free space occupied by message
    }
    
    if (C5State == LOW) {
    OSCMessage msg("/C5");
    msg.add(1);
    
    Udp.beginPacket(outIp, outPort);
      msg.send(Udp); // send the bytes to the SLIP stream
    Udp.endPacket(); // mark the end of the OSC Packet
    msg.empty(); // free space occupied by message
    }
    
    else {
    OSCMessage msg("/C5");
    msg.add(0);
    
    Udp.beginPacket(outIp, outPort);
      msg.send(Udp); // send the bytes to the SLIP stream
    Udp.endPacket(); // mark the end of the OSC Packet
    msg.empty(); // free space occupied by message
    }
    
    if (C4State == LOW) {
    OSCMessage msg("/C4");
    msg.add(1);
    
    Udp.beginPacket(outIp, outPort);
      msg.send(Udp); // send the bytes to the SLIP stream
    Udp.endPacket(); // mark the end of the OSC Packet
    msg.empty(); // free space occupied by message
    }
    
    else {
    OSCMessage msg("/C4");
    msg.add(0);
    
    Udp.beginPacket(outIp, outPort);
      msg.send(Udp); // send the bytes to the SLIP stream
    Udp.endPacket(); // mark the end of the OSC Packet
    msg.empty(); // free space occupied by message
    }
    
    if (C3State == LOW) {
    OSCMessage msg("/C3");
    msg.add(1);
    
    Udp.beginPacket(outIp, outPort);
      msg.send(Udp); // send the bytes to the SLIP stream
    Udp.endPacket(); // mark the end of the OSC Packet
    msg.empty(); // free space occupied by message
    }
    
    else {
    OSCMessage msg("/C3");
    msg.add(0);
    
    Udp.beginPacket(outIp, outPort);
      msg.send(Udp); // send the bytes to the SLIP stream
    Udp.endPacket(); // mark the end of the OSC Packet
    msg.empty(); // free space occupied by message
    }
    
    if (C2State == LOW) {
    OSCMessage msg("/C2");
    msg.add(1);
    
    Udp.beginPacket(outIp, outPort);
      msg.send(Udp); // send the bytes to the SLIP stream
    Udp.endPacket(); // mark the end of the OSC Packet
    msg.empty(); // free space occupied by message
    }
    
    else {
    OSCMessage msg("/C2");
    msg.add(0);
    
    Udp.beginPacket(outIp, outPort);
      msg.send(Udp); // send the bytes to the SLIP stream
    Udp.endPacket(); // mark the end of the OSC Packet
    msg.empty(); // free space occupied by message
    }
    
    if (C1State == LOW) {
    OSCMessage msg("/C1");
    msg.add(1);
    
    Udp.beginPacket(outIp, outPort);
      msg.send(Udp); // send the bytes to the SLIP stream
    Udp.endPacket(); // mark the end of the OSC Packet
    msg.empty(); // free space occupied by message
    }
    
    else {
    OSCMessage msg("/C1");
    msg.add(0);
    Udp.beginPacket(outIp, outPort);
      msg.send(Udp); // send the bytes to the SLIP stream
    Udp.endPacket(); // mark the end of the OSC Packet
    msg.empty(); // free space occupied by message
    }
    
    if (C0State == LOW) {
    OSCMessage msg("/C0");
    msg.add(1);
    
    Udp.beginPacket(outIp, outPort);
      msg.send(Udp); // send the bytes to the SLIP stream
    Udp.endPacket(); // mark the end of the OSC Packet
    msg.empty(); // free space occupied by message
    }
    
    else {
    OSCMessage msg("/C0");
    msg.add(0);
    
    Udp.beginPacket(outIp, outPort);
      msg.send(Udp); // send the bytes to the SLIP stream
    Udp.endPacket(); // mark the end of the OSC Packet
    msg.empty(); // free space occupied by message
    }
}
