// Starting of Program
int m1a = 4;
int m1b = 5;
int m2a = 6;
int m2b = 7;
int buzz = 7;
char val;

#define TX 0
#define RX 1

#include<SoftwareSerial.h>

SoftwareSerial BTmodule(TX, RX);
int speed = 255;

void setup() 
{  
pinMode(m1a, OUTPUT);  // Digital pin 5 set as output Pin
pinMode(m1b, OUTPUT);  // Digital pin 4 set as output Pin
pinMode(m2a, OUTPUT);  // Digital pin 6 set as output Pin
pinMode(m2b, OUTPUT);  // Digital pin 7 set as output Pin
pinMode(buzz, OUTPUT); // Digital pin for buzzer
pinMode(3, OUTPUT);
pinMode(9, OUTPUT);
Serial.begin(9600);
  BTmodule.begin(9600);
  BTmodule.setTimeout(10);
}

void loop()
{
    String readString;
  
  while(BTmodule.available()) {
    readString = BTmodule.readString();
    Serial.print("Received: ");
    Serial.println(readString);
  }
  // analogWrite(3, 100);
  // analogWrite(9, 100);
  if(readString.toInt() > 0)
  {
    analogWrite(3, speed);
    Serial.println("speed on 3 and 9");
    analogWrite(9, speed);
  }

 if( val == 'V') // Horn on
    { 
      digitalWrite(buzz, HIGH);    
    }
 if( val == 'v') // Horn off
    {
     digitalWrite(buzz, LOW); 
    }
  if( val == 'F') // Forward
    {
      digitalWrite(m1a, LOW);
      digitalWrite(m1b, HIGH);
      digitalWrite(m2a, HIGH);
      digitalWrite(m2b, LOW);  
    }
  else if(val == 'B') // Backward
    {
      digitalWrite(m1a, HIGH);
      digitalWrite(m1b, LOW);
      digitalWrite(m2a, LOW);
      digitalWrite(m2b, HIGH);
    }
  
    else if(val == 'L') //Left
    {
      digitalWrite(m1a, HIGH);
      digitalWrite(m1b, LOW);
      digitalWrite(m2a, HIGH);
      digitalWrite(m2b, LOW);
    }
    else if(val == 'R') //Right
    {
      digitalWrite(m1a, LOW);
      digitalWrite(m1b, HIGH);
      digitalWrite(m2a, LOW);
      digitalWrite(m2b, HIGH);  
    }
    else if(val == 'S') //Stop
    {
    digitalWrite(m1a, LOW);
    digitalWrite(m1b, LOW);
    digitalWrite(m2a, LOW);
    digitalWrite(m2b, LOW); 
    }

   // SPEED
   if(readString.substring(0, 6) == "Speed:"){
    String val = readString.substring(readString.length()-3);
    if(val.substring(0, 1) == "d"){
      speed = val.substring(2).toInt();
    }
    else if(val.substring(0, 1) == ":"){
      speed = val.substring(1).toInt();
    }
    else{
      speed = val.toInt();
    }
    Serial.print("Speed: ");
    Serial.println(speed);
  }
}