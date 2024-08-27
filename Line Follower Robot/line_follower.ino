
int IRL = 13; //left IR sensor
int IRR = 12; //right IR sensor


void setup() {
    pinMode (IRL, INPUT);
    pinMode (IRR, INPUT);
    pinMode (9, OUTPUT);
    pinMode (6, OUTPUT);
    pinMode (5, OUTPUT);
    pinMode (3, OUTPUT);

}

void loop() {
  int SSensor1 = digitalRead(IRL);
  int SSensor2 = digitalRead(IRR);
  
  if (SSensor1 == 1 && SSensor2 == 1) //move both motors forward
  {
    digitalWrite(9,1);
    digitalWrite(6,0);
    digitalWrite(5,1);
    digitalWrite(3,0);
  }
  else if(SSensor1 == 0 && SSensor2 == 1) //move 1 motor forward and 1 motor backward
  {
    digitalWrite(9,1);
    digitalWrite(6,0);
    digitalWrite(5,0);
    digitalWrite(3,1);
  }
  else if((SSensor1 == 1) && (SSensor2 == 0))//move 1 motor forward and 1 motor backward
  {
    digitalWrite(9,0);
    digitalWrite(6,1);
    digitalWrite(5,1);
    digitalWrite(3,0);
  }
  else ////move both motors backward
  {
    digitalWrite(9,0);
    digitalWrite(6,1);
    digitalWrite(5,0);
    digitalWrite(3,1);
  }
}
