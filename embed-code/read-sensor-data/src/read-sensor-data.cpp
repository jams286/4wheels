/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "d:/Documents/Proyecto2023/4wheels/embed-code/read-sensor-data/src/read-sensor-data.ino"
/*
 * Project read-sensor-data
 * Description: Get sensor data from hc-sr04
 * Author: Jams
 * Date: 06-04-2023
 */
// Libraries 
#include <MQTT.h>
#include "HC_SR04.h"

// Sensor1
void setup();
void loop();
#line 12 "d:/Documents/Proyecto2023/4wheels/embed-code/read-sensor-data/src/read-sensor-data.ino"
int trigPin = D4;
int echoPin = D5;
HC_SR04 rangefinder = HC_SR04(trigPin, echoPin, 5.0, 50.0);

// Mqtt 
// Broker IP
byte server[] = {192,168,68,119};
MQTT client(server, 1883, NULL);
const char* mqtt_topic = "sensor1";

// Loop variables
unsigned long previousMillis = 0;
const long interval = 100;

// Global variables
double cm = 0.0;


// setup() runs once, when the device is first turned on.
void setup() {
  // Put initialization like pinMode and begin functions here.
  client.connect("Jams3_" + System.deviceID());
  if (client.isConnected()) {
    client.publish("Twitter","Init..." );//publishing a data "hello" to the topic "fun"
  }
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    cm = rangefinder.getDistanceCM();
    // The core of your code will likely live here.
  if (client.isConnected()){
    client.publish(mqtt_topic,String(cm).c_str());
    client.loop();
  }
  }
}