//5 LEDs in one Button
int led1=4;
int led2=5;
int led3=6;
int led4=7;
int led5=8;
int btn1 = 2;
int btn2 = 3;
boolean btn1g = true;
boolean btn2g = true;

void setup(){
  Serial.begin(9600);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(led5,OUTPUT);
  pinMode(btn1, INPUT_PULLUP);
  pinMode(btn1, INPUT_PULLUP);
}

void loop(){
  //button 1 is on
  if(btn1g) {
    if(digitalRead(btn1) == LOW){
      digitalWrite(led1, HIGH);
      digitalWrite(led1, LOW);
      digitalWrite(led2, HIGH);
      digitalWrite(led2, LOW);
      digitalWrite(led3, HIGH);
      digitalWrite(led3, LOW);
      digitalWrite(led4, HIGH);
      digitalWrite(led4, LOW);
      digitalWrite(led5, HIGH);
      digitalWrite(led5, LOW);
      digitalWrite(led4, HIGH);
      digitalWrite(led4, LOW);
      digitalWrite(led3, HIGH);
      digitalWrite(led3, LOW);
      digitalWrite(led2, HIGH);
      digitalWrite(led2, LOW);
      digitalWrite(led1, HIGH);
      Serial.print("button 1: ");
      Serial.println(1);
      btn1g = false;
    }
  }
  //button 1 is off
  if(!btn1g) {
    if(digitalRead(btn1) == HIGH){
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
      digitalWrite(led5, LOW);
      Serial.print("button 1: ");
      Serial.println(0);
      btn1g = true;
    }
  }

   //button 2 is on
  if(btn2g) {
    if(digitalRead(btn2) == LOW){
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, HIGH);
      digitalWrite(led5, HIGH);
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
      digitalWrite(led5, LOW);
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, HIGH);
      digitalWrite(led5, HIGH);
      Serial.print("button 2: ");
      Serial.println(1);
      btn2g = false;
      
    }
  }
  //button 2 is off
  if(!btn2g) {
    if(digitalRead(btn2) == HIGH){
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
      digitalWrite(led5, LOW);
      Serial.print("button 2: ");
      Serial.println(0);
      btn2g = true;
    }
  }
  delay(15);
  
}
