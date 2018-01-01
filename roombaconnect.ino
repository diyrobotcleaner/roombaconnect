/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************
  This example runs directly on NodeMCU.

  Note: This requires ESP8266 support package:
    https://github.com/esp8266/Arduino

  Please be sure to select the right NodeMCU module
  in the Tools -> Board menu!

  For advanced settings please follow ESP examples :
   - ESP8266_Standalone_Manual_IP.ino
   - ESP8266_Standalone_SmartConfig.ino
   - ESP8266_Standalone_SSL.ino

  Change WiFi ssid, pass, and Blynk auth token to run :)
  Feel free to apply it to any other example. It's simple!
 *************************************************************/

/*
Roomba based nodemcu robot.

Pinout:
D0=16=IN4
D1=5=IN3
D2=4==IN2
D3=0==IN1
D4=2=STATUS LED
D5=14=FAN SIDE BRUSH
D6=12=RIGHT BUMP
D7=13=LEFT BUMP
D8=15=BRUSH PIN
A0=Analog voltage sensor

Movement: Random movement with bump sensor
 */




#define BLYNK_PRINT Serial
WidgetTerminal terminal(V1);


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

int leftbump=13;
int rightbump=12;
int voltagesensor=A0;
int IN1=16;
int IN2=5;
int IN3=4;
int IN4=0;
int brushpin=15;
int sidebrush=14;
int statusled=2;

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "YourAuthToken";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "SELCANERCAN";
char pass[] = "selcan1988";

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  
  
  //pinmodes
  
  pinMode(leftbump,INPUT);
  pinMode(rightbump,INPUT);
  pinMode(voltagesensor,INPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(brushpin,OUTPUT);
  pinMode(sidebrush,OUTPUT);
  pinMode(statusled,OUTPUT);

//all outputs are low
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
  digitalWrite(brushpin,LOW);
  digitalWrite(sidebrush,LOW);
  digitalWrite(statusled,LOW);

  terminal.println("Roomba uyanıyor...")
 }

void loop()
{
  Blynk.run();
}

