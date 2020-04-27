#include "WiFi.h"


const char *ssid = "DigitalSat_Elia";
const char *password = "29292929";


WiFiServer wifiServer(80);

const int analogInPin = 34;
int sensorValue = 0;
int Pin = 2;

void processReceivedValue(char command)
{
  if (command == '1') {
    digitalWrite(Pin, HIGH);
  }
  else if (command == '0') {
    digitalWrite(Pin, LOW);
  }
}


void setup()
{
  Serial.begin(115200);
  delay(1000);

  WiFi.begin(ssid, password);

  Serial.println("Connecting to WiFi..");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }

  Serial.println("Connected to the WiFi network");
  Serial.println(WiFi.localIP());

  wifiServer.begin();

  pinMode(Pin, OUTPUT);
  digitalWrite(Pin, LOW);
}

void loop() {

  int sensor = 0;
  digitalWrite(Pin, LOW);
  
  WiFiClient client = wifiServer.available();
  
  if (client) {

    while (client.connected()) 
    {
      while (client.available() > 0) 
      {
        //char c = client.read();
        digitalWrite(Pin, HIGH);
        //processReceivedValue(c);
        sensorValue = sensorHall(); 
        client.write(sensorValue);
        //Serial.println(sensorValue);
      }
      delay(10);
    }
    client.stop();
    Serial.println("Client disconnected");

  }
}



int sensorHall() {
  int v = hallRead();
  Serial.println("sensor: " + v);
  return v;
}


int sensorA()
{
  int outputValue;
  int finalvalue;

  outputValue = analogRead(analogInPin);
  finalvalue = map(outputValue, 0, 1023, 0, 255);

  return (finalvalue);
}
