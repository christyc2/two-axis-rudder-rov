#include <SoftwareSerial.h> 
#include <Wire.h>
SoftwareSerial AS32(10,11);
int LEFT1=6;
int LEFT2=7; 
int RIGHT1=9;
int RIGHT2=8;
int servopin1=2; 
int servopin2=3; 
int servopin3=4; 
int angle1=90,angle2=90,angle3=90;
int count=0;
int val=0,val1=0;      
void setup() {
 pinMode(servopin1, OUTPUT); 
 pinMode(servopin2, OUTPUT); 
 pinMode(servopin3, OUTPUT);
 Serial.begin(9600);
 AS32.begin(9600);
 pinMode(LEFT1,OUTPUT);  
 pinMode(LEFT2,OUTPUT); 
 pinMode(RIGHT1,OUTPUT);   
 pinMode(RIGHT2,OUTPUT);}
void loop(){
 if (AS32.available()){val = AS32.read();}
 if(val==49){forward();}
 if(val==50){back();}   
 if(val==51){left();}   
 if(val==52){right();}
 if(val!=val1){
   if(val==53)
   count++;
 }
 if(val==54){stop();}  
 val1=val;
 Serial.println(count);
 if(count%2==0){
  if(val==55){servopulse2(angle2);delay(10);angle2=angle2+10;}
  if(val==56){servopulse2(angle2);delay(10);angle2=angle2-10;}
  }
 else if(count%3==0){
  if(val==55){servopulse3(angle3);delay(10);angle3=angle3+10;}
  if(val==56){servopulse3(angle3);delay(10);angle3=angle3-10;}
 }
 else{
  if(val==55){servopulse1(angle1);delay(10);angle1=angle1+10;}
  if(val==56){servopulse1(angle1);delay(10);angle1=angle1-10;} 
  }
  
// if(val==53){servopulse1(angle1);delay(10);angle1=angle1+10;}
// if(val==54){servopulse1(angle1);delay(10);angle1=angle1-10;}     
// if(val==55){servopulse2(angle2);delay(10);angle2=angle2+10;}
// if(val==56){servopulse2(angle2);delay(10);angle2=angle2-10;}   

 }
void back()
{digitalWrite(LEFT1,250); digitalWrite(LEFT2,0);digitalWrite(RIGHT1,250); digitalWrite(RIGHT2,0);}
void forward()
{digitalWrite(LEFT1,0);digitalWrite(LEFT2,250);digitalWrite(RIGHT1,0); digitalWrite(RIGHT2,250);}
void right()
{digitalWrite(LEFT1,0); digitalWrite(LEFT2,250);digitalWrite(RIGHT1,250); digitalWrite(RIGHT2,0);}
void left()
{digitalWrite(LEFT1,250); digitalWrite(LEFT2,0);digitalWrite(RIGHT1,0); digitalWrite(RIGHT2,250);}
void stop()
{digitalWrite(LEFT1,0); digitalWrite(LEFT2,0);digitalWrite(RIGHT1,0); digitalWrite(RIGHT2,0);}
void servopulse1(int angle1)
{
  for (int i = 0; i < 50; i++) {
    int pulsewidth1 = (angle1 * 11) + 500; 
    digitalWrite(servopin1, HIGH);   
    delayMicroseconds(pulsewidth1); 
    digitalWrite(servopin1, LOW);    
    delayMicroseconds(20000 - pulsewidth1);
  }
}
void servopulse2(int angle2)
{
  for (int i = 0; i < 50; i++) {
    int pulsewidth2 = (angle2 * 11) + 500; 
    digitalWrite(servopin2, HIGH);   
    delayMicroseconds(pulsewidth2);  
    digitalWrite(servopin2, LOW);    
    delayMicroseconds(20000 - pulsewidth2);
  }
}
void servopulse3(int angle3)
{
  for (int i = 0; i < 50; i++) {
    int pulsewidth3 = (angle3 * 11) + 500; 
    digitalWrite(servopin3, HIGH);  
    delayMicroseconds(pulsewidth3);  
    digitalWrite(servopin3, LOW);    
    delayMicroseconds(20000 - pulsewidth3);
  }
}    
