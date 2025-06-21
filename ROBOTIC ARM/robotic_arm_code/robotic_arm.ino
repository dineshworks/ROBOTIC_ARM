#include <Servo.h>


Servo servo2; //ARM 1 
Servo servo3; //ARM2
Servo servo4; //GRIPPER
int object = 0;
const int m1=6;
const int m2=7;

  int dx= 10000;




const int irsensor = 2;

int val;

void setup() {
   
  Serial.begin(9600);
  servo2.write(50);
  servo3.write(90);
  servo2.attach(3);
  servo3.attach(4);
  servo4.attach(5);
  
  pinMode(irsensor, INPUT);
  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
 
}

void loop() {

val=digitalRead(irsensor);

if (val== LOW){
 object=object+1;
  capture();
  

}
if (val== HIGH){
  normal();
}
 

Serial.print(" No. of objects : ");
Serial.println(object);
}

void normal(){

}

void  capture(){

 
  
  servo2.write(110);   // ARM1 
  delay(2000);
  servo3.write(45);    // ARM2 
  delay(2000);
  servo4.write(160);   // GRIPPER PICK
  delay(1000);

  
  ///////////////////////////////////////////


  
  servo2.write(50);   // ARM1 


  servo3.write(45);
   digitalWrite(m1, HIGH);   // BASE MOTOR
  digitalWrite(m2, LOW);    
  delay(dx);
  digitalWrite(m1, LOW);   // BASE MOTOR
  digitalWrite(m2, LOW);    
  delay(dx);
  servo4.write(90);   // GRIPPER DROP 
  delay(500);
 
//////////////////////////////

  
  servo2.write(50);
  servo3.write(45);
  servo4.write(100);       // GRIPPER OPEN
  delay(1000);
  servo3.write(90);
  digitalWrite(m1, LOW);   // BASE MOTOR
  digitalWrite(m2, HIGH);    
  delay(dx);
  digitalWrite(m1, LOW);   // BASE MOTOR
  digitalWrite(m2, LOW);    
  delay(dx);
  servo2.write(50);

 ////////////////////////////////////////// 


  
}
