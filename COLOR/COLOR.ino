#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 8

#define LedRed    12
#define LedGreen  11
#define LedBlue   10

const int ldrPin = A0;
const int ldrPin2 = A1;
const int ldrPin3 = A2;
const int ldrPin4 = A3;

const int ledPin = 13;
const int ledPin2 = 11;
const int ledPin3 = 10;
const int ledPin4 = 12;

int R=0,G=0,B =0 ,c=0;
void setup() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  
  pinMode(ledPin, OUTPUT);
  pinMode(ldrPin, INPUT);

  pinMode(ledPin2, OUTPUT);
  pinMode(ldrPin2, INPUT);
  
  pinMode(ledPin3, OUTPUT);
  pinMode(ldrPin3, INPUT);
  
  pinMode(ledPin4, OUTPUT);
  pinMode(ldrPin4, INPUT);
  
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  
  Serial.begin(9600);
}
void loop() {
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
 
  R = pulseIn(sensorOut, LOW);

  Serial.print("R= ");
  Serial.print(R);
  Serial.print("  ");
  c++;
  delay(100);
  
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  
  G = pulseIn(sensorOut, LOW);
 
  Serial.print("G= ");
  Serial.print(G);
  Serial.print("  ");
  c++;
  delay(100);
  
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
 
  B = pulseIn(sensorOut, LOW);
  
  Serial.print("B= ");
  Serial.print(B);
  Serial.println("  ");
  c++;
  delay(100);
  
//----------------------------------------------------------Detect colors based on sensor values

  if(Serial.read()=='1')
  {
  if (R>=67 && R<=68 && G>=84 && G<=85 && B>=24 && B<=25){       // to detect red
    digitalWrite(LedRed, HIGH);
    
      Serial.println("50000");
    int ldrStatus3 = analogRead(ldrPin3);
    if(ldrStatus3>=400)
    {
      digitalWrite(ledPin3, LOW);
      digitalWrite(ledPin, HIGH);
      digitalWrite(ledPin2, HIGH);
      digitalWrite(ledPin4, HIGH);
      delay(100);
    }
    else
    {
      digitalWrite(ledPin3, HIGH);
      digitalWrite(ledPin, LOW);
      digitalWrite(ledPin2, LOW);
      digitalWrite(ledPin4, LOW);
    }
  }
  
  else if (R>=69 && R<=70 && G>=87 && G<=89 && B>=26 && B<=27){  // to detect green
    digitalWrite(LedGreen, HIGH);
    
      Serial.println("5000");
    int ldrStatus2 = analogRead(ldrPin2);
    if(ldrStatus2>=400)
    {
      digitalWrite(ledPin2, LOW);
      digitalWrite(ledPin, HIGH);
      digitalWrite(ledPin3, HIGH);
      digitalWrite(ledPin4, HIGH);
      delay(100);
    }
    else
    {
      digitalWrite(ledPin2, HIGH);
      digitalWrite(ledPin, LOW);
      digitalWrite(ledPin3, LOW);
      digitalWrite(ledPin4, LOW);
    }
  }
  else if (R>=81 && R<=82 && G>=84 && G<=85 && B>=24 && B<=25){  // to detect blue
    digitalWrite(LedBlue, HIGH);
    
      Serial.println("1000");
    int ldrStatus = analogRead(ldrPin);
    if(ldrStatus>=400)
    {
      digitalWrite(ledPin, LOW);
      digitalWrite(ledPin2, HIGH);
      digitalWrite(ledPin3, HIGH);
      digitalWrite(ledPin4, HIGH);
      delay(100);
    }
    else
    {
      digitalWrite(ledPin, HIGH);
      digitalWrite(ledPin2, LOW);
      digitalWrite(ledPin3, LOW);
      digitalWrite(ledPin4, LOW);
    }
  }
  // else if (R>9 && R<14 && G>15 && G<22 && B>7 && B<12){  // to detect blue
   // digitalWrite(LedYellow, HIGH);
  //}
  else{
    digitalWrite(ledPin, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin4, LOW);
  }
  }
  //----------------------------------------------------------

  
}
