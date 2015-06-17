/*
  Test sketch for the Adafruit Analog Light Sensor
  by Bill Earl
  for Adafruit Industries
  
  Connect sensor output to Analog Pin 0
  Connect 5v to VCC and GND to GND
  Connect 3.3v to the AREF pin 
  
  NOTES FROM ADAM:
  The bulk of this code was a copy/paste from the Adafruit archives for the
  sensor I'm using. Left to do:
  -add OSC signal send
  -install and calibrate the sensor in the actual space
  
 */
 
int sensorPin = A0;    // select the input pin for the potentiometer
 
float rawRange = 1024; // 3.3v
float logRange = 5.0; // 3.3v = 10^5 lux
 
void setup() 
{
  analogReference(EXTERNAL); //
  Serial.begin(9600);
  Serial.println("Adafruit Analog Light Sensor Test");
}
 
void loop() 
{
  // read the raw value from the sensor:
  
  int rawValue = analogRead(sensorPin);    
  
    if (rawValue >= 1000){
      Serial.print("WINING");
    }
  
  Serial.print("Raw = ");
  Serial.print(rawValue);
  Serial.print(" - Lux = ");
  Serial.println(RawToLux(rawValue)); 
  delay(1000);
}
 
float RawToLux(int raw)
{
  float logLux = raw * logRange / rawRange;
  return pow(10, logLux);
  
}
