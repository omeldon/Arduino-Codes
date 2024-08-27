  #include <LiquidCrystal_I2C.h>
  #define echo 2
  #define trig 3
  #define outA 8// Red LED
  #define outB 9// Green LED
  #define outC 10// Buzzer
 
  float  duration; // time taken by the pulse to return back
  float  distance; // oneway distance travelled by the pulse
  const int intruderDistance = 10;  // the minimum distance upto which the sensor is able to sense any object
  
  LiquidCrystal_I2C lcd(0x27, 16, 2);
  
 void buzzeron(){
  lcd.init(); // initialize the lcd
  lcd.backlight();
  lcd.setCursor(0, 0);         // move cursor to   (0, 0)
  lcd.print("S");        // print message at (0, 0)
  lcd.setCursor(1, 0);        
  lcd.print("e"); 
  lcd.setCursor(2, 0);        
  lcd.print("c");
  lcd.setCursor(3, 0);        
  lcd.print("u");
  lcd.setCursor(4, 0);        
  lcd.print("r"); 
  lcd.setCursor(5, 0);        
  lcd.print("i");
  lcd.setCursor(6, 0);        
  lcd.print("t");
  lcd.setCursor(7, 0);        
  lcd.print("y");
  lcd.setCursor(9, 0);        
  lcd.print("A");
  lcd.setCursor(10, 0);        
  lcd.print("l"); 
  lcd.setCursor(11, 0);        
  lcd.print("e");
  lcd.setCursor(12, 0);        
  lcd.print("r");
  lcd.setCursor(13, 0);        
  lcd.print("t");
  lcd.setCursor(14, 0);        
  lcd.print("!");
  lcd.setCursor(15, 0);        
  lcd.print("!");}

  void buzzeroff(){ 
  lcd.init(); // initialize the lcd
  lcd.backlight();
  lcd.setCursor(0, 0);         // move cursor to   (0, 0)
  lcd.print("N");        // print message at (0, 0)
  lcd.setCursor(1, 0);        
  lcd.print("o"); 
  lcd.setCursor(3, 0);        
  lcd.print("I");
  lcd.setCursor(4, 0);        
  lcd.print("n"); 
  lcd.setCursor(5, 0);        
  lcd.print("t");
  lcd.setCursor(6, 0);        
  lcd.print("r");
  lcd.setCursor(7, 0);        
  lcd.print("u");
  lcd.setCursor(8, 0);        
  lcd.print("d");
  lcd.setCursor(9, 0);        
  lcd.print("e"); 
  lcd.setCursor(10, 0);        
  lcd.print("r");
  lcd.setCursor(11, 0);        
  lcd.print("!");
  lcd.setCursor(12, 0);        
  lcd.print("!");
  lcd.setCursor(13, 0);        
  lcd.print("!");}

  void setup() {
  
    pinMode(trig, OUTPUT);
    pinMode(echo, INPUT);
    
    pinMode(outA, OUTPUT);
    digitalWrite(outA, LOW);
    
    pinMode(outB, OUTPUT);
    digitalWrite(outB, LOW);
    pinMode(outC, OUTPUT);
    digitalWrite(outC, LOW);
    Serial.begin(9600); }
  
  void loop() {
      
    time_Measurement();
    distance = (float)duration * (0.0343) / 2;   // calculate the oneway distance travelled by the pulse
    Serial.println(distance);
    alarm_condition();}
  
  void time_Measurement(){ // function to measure the time taken by the pulse to return back
    digitalWrite(trig, LOW);
    delayMicroseconds(2);
  
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);
  
    duration = pulseIn(echo, HIGH);  }
 
  void alarm_condition(){ //function to execute the output commands based on the sensor input
    if(distance<=intruderDistance){
      digitalWrite(outA,HIGH);
      digitalWrite(outB,LOW);
      analogWrite(outC,100);
      buzzeron();
      delay(50);
      digitalWrite(outA,LOW);
      digitalWrite(outB,LOW);
      analogWrite(outC,0);
      delay(50);
      digitalWrite(outA,HIGH);
      digitalWrite(outB,LOW);
      analogWrite(outC,100);
      buzzeron();
      delay(50);
      digitalWrite(outA,LOW);
      digitalWrite(outB,LOW);
      analogWrite(outC,0);
      delay(50);
      digitalWrite(outA,HIGH);
      digitalWrite(outB,LOW);
      analogWrite(outC,100);
      buzzeron();
      delay(50);
      digitalWrite(outA,LOW);
      digitalWrite(outB,LOW);
      analogWrite(outC,0);
      delay(50);
      digitalWrite(outA,HIGH);
      digitalWrite(outB,LOW);
      analogWrite(outC,100);
      buzzeron();
      delay(50);
      digitalWrite(outA,LOW);
      digitalWrite(outB,LOW);
      analogWrite(outC,0);
      delay(50);
      digitalWrite(outA,HIGH);
      digitalWrite(outB,LOW);
      analogWrite(outC,100);
      buzzeron();
      }
      
   else{
       digitalWrite(outA,LOW);
       digitalWrite(outB,HIGH);
       analogWrite(outC,0);
       buzzeroff();}
       }
