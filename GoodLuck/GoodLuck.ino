#include <Servo.h>
const int motor1Pos = 4;
const int motor1Neg = 5;
const int motor2Pos = 2;
const int motor2Neg = 14; 

int buttonPin = 13;
int button2Pin = 15;

int ServoPin = 12;
Servo servo1;
int ServoPosition = 0;

void setup() {
  pinMode(motor1Pos, OUTPUT);
  pinMode(motor1Neg, OUTPUT);
  pinMode(motor2Pos, OUTPUT);
  pinMode(motor2Neg, OUTPUT);
  servo1.attach(ServoPin);
  servo1.write(ServoPosition);
  
  Serial.begin(9600);
}
void AndarFrente(){
  analogWrite(motor1Pos,255);
    analogWrite(motor2Pos, 255);
  
}
void AndarDireit(){
  analogWrite(motor1Pos,255);
    analogWrite(motor2Pos,127);
       
}
void AndarEsquerd(){
  analogWrite(motor1Pos,127);
    analogWrite(motor2Pos,255);
       
}
void Back(){
  analogWrite(motor1Neg,100);
    analogWrite(motor2Neg,100);
}
void BackDireit(){
  analogWrite(motor1Neg,125);
    analogWrite(motor2Neg,75);
}
void BackEsquerd(){
  analogWrite(motor1Neg,75);
    analogWrite(motor2Neg,125);
}
void Empilhadeira(){
  
  int buttonState = digitalRead(buttonPin);
  int button2State = digitalRead(button2Pin);
  
  if(buttonState == HIGH && ServoPosition <155) 
  {
     servo1.write(ServoPosition);
    ServoPosition++;
    delay(5);
  }
  else if(button2State == HIGH && ServoPosition >=30){
  servo1.write(ServoPosition);
    ServoPosition--;
    delay(5);
    
  }  
  
}

void loop() {
  // put your main code here, to run repeatedly:
Empilhadeira();
}