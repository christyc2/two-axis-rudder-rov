#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SoftwareSerial.h> 
#define OLED_RESET 4  /*OLED Screen*/
#define button1 8     /*blue button*/
#define button2 7     /*red button*/
#define button3 11    /*yellow button*/
#define button4 6     /*green button*/
/*9rx connected to AS32 TX，10TX connected to AS32 RX*/
SoftwareSerial AS32(9, 10);
/*OLED initialization*/
Adafruit_SSD1306 display(128, 32, &Wire, OLED_RESET);
/*received signals via bluetooth*/  
int val;
/*ps joystick input*/                  
int valueX=0;int valueY=0;

void setup() {
  Serial.begin(9600);
  AS32.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.setTextColor(WHITE);
  display.clearDisplay();
  pinMode(button1,INPUT);
  pinMode(button2,INPUT);
  /*#define button1 8   
    #define button2 7   
    #define button3 11 
    #define button4 6 */  
}
 
void loop() {
  int a = digitalRead(button1);  //blue
  int b = digitalRead(button2);  //red
  int c = digitalRead(button3);  //yellow
  int d = digitalRead(button4);  //green
  valueX = analogRead(A2);
  valueY=analogRead(A3);  /*ps2 xy axes*/

//ps2遥感控制机器人运动
  if(350<valueX && valueX<650 && 750<valueY && valueY<1050){
    Serial.print("FORWARD");AS32.println("1");/*forward，output“1”*/
    display.clearDisplay();display.setTextSize(2); display.setCursor(0, 8);/*set display size, position*/
    display.println("FORWARD");display.display(); /*display*/}
  if(350<valueX && valueX<650 && -50<valueY && valueY<150){
    Serial.print("BACK");AS32.println("2");/*backward，output“2”*/
    display.clearDisplay();display.setTextSize(2); display.setCursor(0, 8);
    display.println("BACK");display.display();}
  if(-50<valueX && valueX<150 && 350<valueY && valueY<650){
    Serial.print("LEFT");AS32.println("3");/*turn left，output“3”*/
    display.clearDisplay();display.setTextSize(2); display.setCursor(0, 8);
    display.println("LEFT");display.display();}
  if(750<valueX && valueX<1050 && 350<valueY && valueY<650){
    Serial.print("RIGHT");AS32.println("4");/*turn right，output“4”*/
    display.clearDisplay();display.setTextSize(2); display.setCursor(0, 8);
    display.println("RIGHT");display.display();}

// buttons control the three servos
  if(a){
    Serial.print("蓝色按键");AS32.println("5");/*blue button pressed，output“5”*/
    display.clearDisplay();display.setTextSize(2); display.setCursor(0, 8);/*set display size, position*/
    display.println("BLUE");display.display();/*display*/}
  if(b){
    Serial.print("红色按键");AS32.println("6");/*red button pressed，output“6”*/ 
    display.clearDisplay();display.setTextSize(2); display.setCursor(0, 8);
    display.println("RED");display.display();}
  if(c){
    Serial.print("黄色按键");AS32.println("6");/*yellow button pressed，output“7”*/ 
    display.clearDisplay();display.setTextSize(2); display.setCursor(0, 8);
    display.println("YELLOW");display.display();}
  if(b){
    Serial.print("绿色按键");AS32.println("6");/*red button pressed，output“8”*/ 
    display.clearDisplay();display.setTextSize(2); display.setCursor(0, 8);
    display.println("GREEN");display.display();}
  delay(100);
}
