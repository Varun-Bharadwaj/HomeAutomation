 #include <Servo.h>;
 int pos = 0;
 const int buttonpin1 = 8;
 const int buttonpin2 = 7;
 const int servopin = 3;
 const int ledpin1 = 13;
 const int ledpin2 = 12;          //introducing shit
 Servo servo;
 int buttonstate1=0;
 int buttonstate2=0; 
void setup()                       //setting up shit
{
  pinMode(buttonpin1, INPUT);
  pinMode(buttonpin2, INPUT);
  pinMode(ledpin1, OUTPUT); 
  pinMode(ledpin2, OUTPUT); 
}

void loop()                       // looping shit
{
  buttonstate1 = digitalRead(buttonpin1);
  buttonstate2 = digitalRead(buttonpin2);   
 if (buttonstate1== HIGH && pos==0)      //When button1 is pressed, curtain opens
 { 
    servo.attach (servopin);
    digitalWrite(ledpin1, HIGH);
    digitalWrite(ledpin2, LOW);  
   for( pos=0; pos<=180; pos++)
  {
    servo.write(pos);
    delay(20);
  } 
  pos=180;
    servo.detach();   
 }
 
 if (buttonstate2== HIGH && pos==180 )      // When button2 is pressed, curtain closes
  { 
    servo.attach (servopin);
    digitalWrite(ledpin2, HIGH);
    digitalWrite(ledpin1, LOW);  
   
    for( pos=180; pos>=0; pos--)
   {
    servo.write(pos);
    delay(20);
   }
   pos=0;
   servo.detach();   
  }
}
