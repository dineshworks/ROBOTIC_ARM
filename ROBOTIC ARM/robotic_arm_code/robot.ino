#include <Servo.h>

Servo servo1; //BASE MOTOR 
Servo servo2; //ARM 1 
Servo servo3; //ARM2
Servo servo4; //GRIPPER


const int irsensor = 6;
int object=0;
int val;

void setup() {

  Serial.begin(9600);
  servo1.attach(2);
  servo2.attach(3);
  servo3.attach(4);
  servo4.attach(5);
  
  pinMode(irsensor, INPUT);
 
}

void loop() {

val=digitalRead(irsensor);

if (val== LOW){
  capture();

}
if (val== HIGH){
  normal();
}
 
Serial.print("val: ");
Serial.print(val);
Serial.print(" No. of objects : ");
Serial.println(object);

}

void normal(){
  servo1.write(0);
  servo2.write(80);
  servo3.write(90);
  servo4.write(90);
     
}

void  capture(){

  object=object+1;
  servo1.write(0);
  servo2.write(110);
  servo3.write(90);
  servo4.write(150);
  delay(2000);
  ///////////////////////////////////////////
  servo1.write(185);
  servo2.write(80);
  for(int i =90;i>=45;i--){
  servo3.write(i);
  delay(50);
  }
  servo4.write(90);
  delay(2000);

  //////////////////////////////////////////
  servo1.write(0);
  servo2.write(80);
  for(int i =45;i<=90;i++){
  servo3.write(i);
  delay(50);
  }
  servo4.write(90);
  delay(1000);
 ////////////////////////////////////////// 




  
}
