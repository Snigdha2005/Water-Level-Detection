/*
#include <ThingSpeak.h>

#include <DHT.h>
#include <DHT_U.h>

#include <ArduinoWiFiServer.h>
#include <BearSSLHelpers.h>
#include <CertStoreBearSSL.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiAP.h>
#include <ESP8266WiFiGeneric.h>
#include <ESP8266WiFiGratuitous.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266WiFiSTA.h>
#include <ESP8266WiFiScan.h>
#include <ESP8266WiFiType.h>
#include <WiFiClient.h>
#include <WiFiClientSecure.h>
#include <WiFiClientSecureBearSSL.h>
#include <WiFiServer.h>
#include <WiFiServerSecure.h>
#include <WiFiServerSecureBearSSL.h>
#include <WiFiUdp.h>*/

//#include <DHTesp.h>

/*#include <ESP8266WiFi.h>

const char *ssid ="OnePlus Nord 2T 5G";
const char *pass ="r9eayi68";

DHT dht(D6, DHT11);
 
WiFiClient client;
 
long myChannelNumber = 2389131;
const char myWriteAPIKey[] = "6OUVRRTIPHJZBC9E";
 */
void setup() {
  Serial.begin(9600);
  /*WiFi.begin(ssid, pass);
  while(WiFi.status() != WL_CONNECTED)
  {
    delay(200);
    Serial.print("..");
  }
  Serial.println();
  Serial.println("NodeMCU is connected!");
  Serial.println(WiFi.localIP());
  dht.begin();
  ThingSpeak.begin(client);*/
  pinMode(D1, OUTPUT);
  pinMode(D2, INPUT);
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);
  pinMode(D0, OUTPUT);
  pinMode(D4, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D8, OUTPUT);
  //pinMode(LED_BUILTIN, OUTPUT);

}
float r = 10;
float total_height = 10;
void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(D1, LOW);
  delayMicroseconds(2);
  digitalWrite(D1, HIGH);
  delayMicroseconds(10);
  digitalWrite(D1, LOW);//duty cycle - ton/(ton+toff) = 50%
  
  float duration = pulseIn(D2, HIGH);
  float distance = duration*0.034/2;
  /*if (distance > 100){
    digitalWrite(LED_BUILTIN, HIGH);
    int sensorValue = analogRead(A0);
    Serial.println("gas sensor");
    Serial.println(sensorValue);
    if (sensorValue > 290){
      for(int i = 0; i<=180;i++){
      myservo.write(i);}
    }
    else{
      for(int i = 180; i >= 0;i--){
        myservo.write(i);
      }
    }
  }
  else{
    digitalWrite(LED_BUILTIN, LOW);
    myservo.write(45);
  }*/
  if (distance < 5){
    digitalWrite(D5, HIGH);
    digitalWrite(D6, LOW);
    digitalWrite(D3, LOW);
    digitalWrite(D0, LOW);
    digitalWrite(D4, HIGH);
    digitalWrite(D8, HIGH);
  }
  else if (distance >= 5 && distance <= 10){
    digitalWrite(D5, LOW);
    digitalWrite(D6, HIGH);
    digitalWrite(D3, LOW);
    digitalWrite(D0, LOW);
    digitalWrite(D4, LOW);
    digitalWrite(D8, LOW);
  }
  else{
    digitalWrite(D5, LOW);
    digitalWrite(D6, LOW);
    digitalWrite(D3, HIGH);
    digitalWrite(D0, LOW);
    digitalWrite(D4, LOW);
    digitalWrite(D8, LOW);
  }
  Serial.println(distance);
  long water_volume = (total_height - distance)*3.14*r*r;
  Serial.println(water_volume);
  //ThingSpeak.writeField(myChannelNumber, 1, water_volume, myWriteAPIKey);
  delay(2000);
}