#include "ThingSpeak.h"
#include <ESP8266WiFi.h>
#include <UniversalTelegramBot.h>
#include <AFMotor.h>
#define lefts A0
#define rights A1
  
//----------- Enter you Wi-Fi Details---------//
char ssid[] = "SBG6700AC-87708";//Enter your WIFI SSIS
char pass[] = "686e8cc4b2";//Enter your WIFI password
//-------------------------------------------//
#define BOTtoken "14aF2AD2a:1f224FGJ51fbBsXAD355dX1fqioQXrXgXXqq126"


int pinValue = 0;
int buzzer = D5;
int smoke = A0;
int sensorThres = 400;
AF_DCMotor motor1(1, MOTOR12_1KHZ); 
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);

WiFiClient  client;
UniversalTelegramBot bot(BOTtoken, client);
int botRequestDelay = 500;
unsigned long lastTimeBotRan;
unsigned long myChannelField = 1657054; // Channel ID
const int ChannelField = 1; // Which channel to write data
const char * myWriteAPIKey = "GWZJ76GJW7Q8VU2V"; // Your write API Key

void handleNewMessages(int numNewMessages) {
  Serial.println("handleNewMessages");
  Serial.println(String(numNewMessages));

  for (int i=0; i<numNewMessages; i++) {
    String chat_id = String(bot.messages[i].chat_id);
    String text = bot.messages[i].text;

    String from_name = bot.messages[i].from_name;
    if (from_name == "") from_name = "Guest";

    if (text == "/GAS") {
      D1Status = 1;
      bot.sendMessage(chat_id, "GAS LEAKAGE DETECTED", "");
    }
    

void setup()
{
  Serial.begin(9600);
   pinMode(buzzer, OUTPUT);
  pinMode(smoke, INPUT);
  motor1.setSpeed(100);
  motor2.setSpeed(100);
  motor3.setSpeed(100);
  motor4.setSpeed(100);
  //Declaring PIN input types
  pinMode(lefts,INPUT);
  pinMode(rights,INPUT);
  WiFi.mode(WIFI_STA);
  ThingSpeak.begin(client);
}
void loop()
{
  if (WiFi.status() != WL_CONNECTED)
  {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    while (WiFi.status() != WL_CONNECTED)
    {
      WiFi.begin(ssid, pass);
      Serial.print(".");
      delay(5000);
    }
    Serial.println("\nConnected.");
  }
  int analogSensor = analogRead(smoke);
  Serial.print("Pin A0: ");
  Serial.println(analogSensor);
  // Checks if it has reached the threshold value
  Serial.println(analogRead(lefts));
  Serial.println(analogRead(rights));
  //line detected by both
  if(analogRead(lefts)<=350 && analogRead(rights)<=350){
    //Forward
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
  }
  //line detected by left sensor
  else if(analogRead(lefts)<=350 && !analogRead(rights)<=350){
    //turn left
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(BACKWARD);
    motor4.run(BACKWARD);
    
  }
  //line detected by right sensor
  else if(!analogRead(lefts)<=350 && analogRead(rights)<=350){
    //turn right
    motor1.run(BACKWARD);
    motor2.run(BACKWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
   
  }
  //line detected by none
  else if(!analogRead(lefts)<=350 && !analogRead(rights)<=350){
    //stop
    motor1.run(RELEASE);
    motor2.run(RELEASE);
    motor3.run(RELEASE);
    motor4.run(RELEASE);
   
  }
  if (analogSensor > sensorThres)
  {
    tone(buzzer, 1000, 2000);
    
  }
  else
  {
    noTone(buzzer);
  }
  delay(100);
  ThingSpeak.writeField(myChannelField, ChannelField, analogSensor, myWriteAPIKey);
  delay(1000);
}
 
