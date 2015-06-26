/*

This puzzle works like an old-timey phone switch board; plug in a 1/4" jack,
it lights up an LED and sends an OSC signal to the computer. For the puzzle,
players are supposed to read a vague and incredibly wordy "guide" that tells
them the sequence to plug in the 1/4" jacks. All this code needs to do is send
the signals and make LEDs light up I think; unless we can easily program
a "lock" code, similar to the Pinpads?

*/


#include <OSCMessage.h>
#include <Ethernet.h>
#include <EthernetUdp.h>
#include <SPI.h>    
#include <OSCMessage.h>

EthernetUDP Udp;

//the Arduino's IP
IPAddress ip(192, 168, 0, 10);
//destination IP
IPAddress outIp(192, 168, 0, 5);
const unsigned int outPort = 10000;

 byte mac[] = {  
  0xDE, 0xAD, 0xAA, 0xAA, 0xAA, 0xAB }; // you can find this written on the board of some Arduino Ethernets or shields


//Mux control pins
int s0 = 6;
int s1 = 7;
int s2 = 8;
int s3 = 9;

//Mux in "SIG" pin
int SIG_pin = A0;

const int C0 = 5;    // the number of the pushbutton pin
const int C1 = 3;
const int C3 = 2;
const int C4 = A4;
const int C5 = A3;
const int C7 = A2;
const int C8 = A1;


void setup(){
  pinMode(s0, OUTPUT); 
  pinMode(s1, OUTPUT); 
  pinMode(s2, OUTPUT); 
  pinMode(s3, OUTPUT); 
  
  pinMode(C0, OUTPUT);
  pinMode(C1, OUTPUT);
  pinMode(C3, OUTPUT);
  pinMode(C4, OUTPUT);
  pinMode(C5, OUTPUT);
  pinMode(C7, OUTPUT);
  pinMode(C8, OUTPUT);

  digitalWrite(s0, HIGH);
  digitalWrite(s1, HIGH);
  digitalWrite(s2, HIGH);
  digitalWrite(s3, HIGH);

  Serial.begin(9600);
  Ethernet.begin(mac,ip);
    Udp.begin(outPort);
}

void loop(){
      
    if (readMux(0) == 1){
      digitalWrite(C0, HIGH);
    OSCMessage msg("/0");
    msg.add(1);
    Udp.beginPacket(outIp, outPort);
    msg.send(Udp); // send the bytes to the SLIP stream
    Udp.endPacket(); // mark the end of the OSC Packet
    msg.empty(); // free space occupied by message
    Serial.print("on");
    }
    else if (readMux(0) == 0) {
      digitalWrite(C0, LOW);
    OSCMessage msg("/0");
    msg.add(0);
    Udp.beginPacket(outIp, outPort);
    msg.send(Udp); // send the bytes to the SLIP stream
    Udp.endPacket(); // mark the end of the OSC Packet
    msg.empty(); // free space occupied by message
    Serial.print("off");
    }
    
    if (readMux(1) == 1){
      digitalWrite(C1, HIGH);
    OSCMessage msg("/1");
    msg.add(1);
    Udp.beginPacket(outIp, outPort);
    msg.send(Udp); // send the bytes to the SLIP stream
    Udp.endPacket(); // mark the end of the OSC Packet
    msg.empty(); // free space occupied by message
    Serial.println("on");
    }
    else if (readMux(1) == 0){
      digitalWrite(C1, LOW);
    OSCMessage msg("/1");
    msg.add(0);
    Udp.beginPacket(outIp, outPort);
    msg.send(Udp); // send the bytes to the SLIP stream
    Udp.endPacket(); // mark the end of the OSC Packet
    msg.empty(); // free space occupied by message
    Serial.println("off");
    }

    if (readMux(2) == 1){
    OSCMessage msg("/2");
    msg.add(1);
    Udp.beginPacket(outIp, outPort);
    msg.send(Udp); // send the bytes to the SLIP stream
    Udp.endPacket(); // mark the end of the OSC Packet
    msg.empty(); // free space occupied by message
    }
    else if (readMux(2) == 0){
    OSCMessage msg("/2");
    msg.add(0);
    Udp.beginPacket(outIp, outPort);
    msg.send(Udp); // send the bytes to the SLIP stream
    Udp.endPacket(); // mark the end of the OSC Packet
    msg.empty(); // free space occupied by message
    }
    
    if (readMux(3) == 1){
      digitalWrite(C3, HIGH);
    OSCMessage msg("/3");
    msg.add(1);
    Udp.beginPacket(outIp, outPort);
    msg.send(Udp); // send the bytes to the SLIP stream
    Udp.endPacket(); // mark the end of the OSC Packet
    msg.empty(); // free space occupied by message
    }
    else if (readMux(3) == 0){
      digitalWrite(C3, LOW);
    OSCMessage msg("/3");
    msg.add(0);
    Udp.beginPacket(outIp, outPort);
    msg.send(Udp); // send the bytes to the SLIP stream
    Udp.endPacket(); // mark the end of the OSC Packet
    msg.empty(); // free space occupied by message
    }
    
    if (readMux(4) == 1){
      digitalWrite(C4, HIGH);
    OSCMessage msg("/4");
    msg.add(1);
    Udp.beginPacket(outIp, outPort);
    msg.send(Udp); // send the bytes to the SLIP stream
    Udp.endPacket(); // mark the end of the OSC Packet
    msg.empty(); // free space occupied by message
    }
    else if (readMux(4) == 0){
      digitalWrite(C4, LOW);
    OSCMessage msg("/4");
    msg.add(0);
    Udp.beginPacket(outIp, outPort);
    msg.send(Udp); // send the bytes to the SLIP stream
    Udp.endPacket(); // mark the end of the OSC Packet
    msg.empty(); // free space occupied by message
    }
    
    if (readMux(5) == 1){
      digitalWrite(C5, HIGH);
    OSCMessage msg("/5");
    msg.add(1);
    Udp.beginPacket(outIp, outPort);
    msg.send(Udp); // send the bytes to the SLIP stream
    Udp.endPacket(); // mark the end of the OSC Packet
    msg.empty(); // free space occupied by message
    Serial.println("5 on");
    }
    else if (readMux(5) == 0){
      digitalWrite(C5, LOW);
    OSCMessage msg("/5");
    msg.add(0);
    Udp.beginPacket(outIp, outPort);
    msg.send(Udp); // send the bytes to the SLIP stream
    Udp.endPacket(); // mark the end of the OSC Packet
    msg.empty(); // free space occupied by message
    Serial.print("5 off");
    }
    
    if (readMux(6) == 1){
    OSCMessage msg("/6");
    msg.add(1);
    Udp.beginPacket(outIp, outPort);
    msg.send(Udp); // send the bytes to the SLIP stream
    Udp.endPacket(); // mark the end of the OSC Packet
    msg.empty(); // free space occupied by message
    }
    else if (readMux(6) == 0){
    OSCMessage msg("/6");
    msg.add(0);
    Udp.beginPacket(outIp, outPort);
    msg.send(Udp); // send the bytes to the SLIP stream
    Udp.endPacket(); // mark the end of the OSC Packet
    msg.empty(); // free space occupied by message
    }
    
    if (readMux(7) == 1){
      digitalWrite(C7, HIGH);
    OSCMessage msg("/7");
    msg.add(1);
    Udp.beginPacket(outIp, outPort);
    msg.send(Udp); // send the bytes to the SLIP stream
    Udp.endPacket(); // mark the end of the OSC Packet
    msg.empty(); // free space occupied by message
    }
    else if (readMux(7) == 0){
      digitalWrite(C7, LOW);
    OSCMessage msg("/7");
    msg.add(0);
    Udp.beginPacket(outIp, outPort);
    msg.send(Udp); // send the bytes to the SLIP stream
    Udp.endPacket(); // mark the end of the OSC Packet
    msg.empty(); // free space occupied by message
    }
    
    if (readMux(8) == 1){
      digitalWrite(C8, HIGH);
    OSCMessage msg("/8");
    msg.add(1);
    Udp.beginPacket(outIp, outPort);
    msg.send(Udp); // send the bytes to the SLIP stream
    Udp.endPacket(); // mark the end of the OSC Packet
    msg.empty(); // free space occupied by message
    }
    else if (readMux(8) == 0){
      digitalWrite(C8, LOW);
    OSCMessage msg("/8");
    msg.add(0);
    Udp.beginPacket(outIp, outPort);
    msg.send(Udp); // send the bytes to the SLIP stream
    Udp.endPacket(); // mark the end of the OSC Packet
    msg.empty(); // free space occupied by message
    }
    
    if (readMux(9) == 1){
    OSCMessage msg("/9");
    msg.add(1);
    Udp.beginPacket(outIp, outPort);
    msg.send(Udp); // send the bytes to the SLIP stream
    Udp.endPacket(); // mark the end of the OSC Packet
    msg.empty(); // free space occupied by message
    }
    else if (readMux(9) == 0){
    OSCMessage msg("/9");
    msg.add(0);
    Udp.beginPacket(outIp, outPort);
    msg.send(Udp); // send the bytes to the SLIP stream
    Udp.endPacket(); // mark the end of the OSC Packet
    msg.empty(); // free space occupied by message
    }

}


int readMux(int channel){
  int controlPin[] = {s0, s1, s2, s3};

  int muxChannel[16][4]={
    {0,0,0,0}, //channel 0
    {1,0,0,0}, //channel 1
    {0,1,0,0}, //channel 2
    {1,1,0,0}, //channel 3
    {0,0,1,0}, //channel 4
    {1,0,1,0}, //channel 5
    {0,1,1,0}, //channel 6
    {1,1,1,0}, //channel 7
    {0,0,0,1}, //channel 8
    {1,0,0,1}, //channel 9
    {0,1,0,1}, //channel 10
    {1,1,0,1}, //channel 11
    {0,0,1,1}, //channel 12
    {1,0,1,1}, //channel 13
    {0,1,1,1}, //channel 14
    {1,1,1,1}  //channel 15
  };

  //loop through the 4 sig
  for(int i = 0; i < 4; i ++){
    digitalWrite(controlPin[i], muxChannel[channel][i]);
  }

  //read the value at the SIG pin
  int val = digitalRead(SIG_pin);

  //return the value
  return val;
}

