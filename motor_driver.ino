#define BaudRate 9600
#include<Servo.h>
char incomingOption;

Servo myservo;
Servo myservo2;

void setup() {
  // put your setup code here, to run once:
  myservo.attach(30);
  myservo2.attach(31);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(22,OUTPUT);
  pinMode(23,OUTPUT);
  pinMode(24,OUTPUT);
  pinMode(25,OUTPUT);
  pinMode(26,OUTPUT);
  pinMode(27,OUTPUT);
  pinMode(28,OUTPUT);
  pinMode(29,OUTPUT);
  Serial.begin(BaudRate);
}

void loop() {
  // put your main code here, to run repeatedly:
  incomingOption = Serial.read();
  switch(incomingOption)
  {
    case '1':
      myservo.write(155);
      break;
    case '0':
      myservo.write(92);
      break;
    case '2':
      myservo2.write(155);
      break;
    case '3':
      myservo2.write(92);
      break;
    case 'a':
      digitalWrite(22,HIGH);
      digitalWrite(23,LOW);
      analogWrite(2,70) ;
      Serial.println("sfsd");
      break;
    case 's':
      digitalWrite(22,LOW);
      digitalWrite(23,LOW);
      break;
    case 'd':
      digitalWrite(24,HIGH);
      digitalWrite(25,LOW); 
      analogWrite(3,75) ;
      Serial.println("qweq");
      break;
    case 'f':
      digitalWrite(24,LOW);
      digitalWrite(25,LOW);
      break;
    case 'z':
      digitalWrite(26,HIGH);
      digitalWrite(27,LOW);
      analogWrite(4,100) ;
      Serial.println("sfsd");
      break;
    case 'x':
      digitalWrite(26,LOW);
      digitalWrite(27,LOW);
      break;
    case 'c':
      digitalWrite(28,HIGH);
      digitalWrite(29,LOW); 
      analogWrite(5,80) ;
      Serial.println("qweq");
      break;
    case 'v':
      digitalWrite(28,LOW);
      digitalWrite(29,LOW);
      break;
  }
}
