#include<SoftwareSerial.h>
#define ledpin 9
#include<Servo.h>
int pos=0;
char x=0;
const int servopin=3;
const int ledpin1=13;
const int ledpin2=12;
Servo servo;

void setup() {
  Serial.begin(9600);
 pinMode(ledpin,OUTPUT);
 pinMode(ledpin1, OUTPUT);
 pinMode(ledpin2,OUTPUT);
}

void loop() {
  if(Serial.available()>0)
    {
      x=Serial.read();
      Serial.print(x);
     
      if(x=='1')
          digitalWrite(ledpin,HIGH);

      else if(x=='0')
          digitalWrite(ledpin,LOW);
          
        
    
    if(x=='2' && pos==0)
    {
      servo.attach(servopin);
      digitalWrite(ledpin1,HIGH);
      digitalWrite(ledpin2,LOW);
      for(pos=0;pos<=100;pos++)
      {  servo.write(pos);
         delay(20);
      }
      pos=100;
      servo.detach();
    }  
      if(x=='3' && pos==100)
    {
      servo.attach(servopin);
      digitalWrite(ledpin2,HIGH);
      digitalWrite(ledpin1,LOW);
      for(pos=100;pos>=0;pos--)
      {  servo.write(pos);
         delay(20);
      }
      pos=0;
      servo.detach();
    }
   }  
  }


