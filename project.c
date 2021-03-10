#include <SoftwareSerial.h>

#define m1 5  //Right Motor MA1
#define m2 4  //Right Motor MA2
#define m3 3  //Left Motor MB1
#define m4 2  //Left Motor MB2
#define e1 6  //Right Motor Enable Pin EA
#define e2 10 //Left Motor Enable Pin EB

//Channel IR Sensor
#define ir1 A0
#define ir2 A1
#define ir3 A2
#define ir4 A3
#define ir5 A4

SoftwareSerial BT(11, 12);
String voice;

void setup() {
  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  pinMode(m3, OUTPUT);
  pinMode(m4, OUTPUT);
  pinMode(e1, OUTPUT);
  pinMode(e2, OUTPUT);
  pinMode(ir1, INPUT);
  pinMode(ir2, INPUT);
  pinMode(ir3, INPUT);
  pinMode(ir4, INPUT);
  pinMode(ir5, INPUT);

  BT.begin(9600);
  Serial.begin(9600);
}

void loop() {
  //Reading Sensor Values
  int s1 = digitalRead(ir1);  //Left Most Sensor
  int s2 = digitalRead(ir2);  //Left Sensor
  int s3 = digitalRead(ir3);  //Middle Sensor
  int s4 = digitalRead(ir4);  //Right Sensor
  int s5 = digitalRead(ir5);  //Right Most Sensor

  while (BT.available()) {
    delay(10);
    char c = BT.read();
    voice += c;
  }
  Serial.println("debug");
  Serial.println(voice);
  
  if (voice[voice.length()-1] == 'o'){
  //if only middle sensor detects black line
  if((s1 == 1) && (s2 == 1) && (s3 == 0) && (s4 == 1) && (s5 == 1))
  {
    //going forward
    analogWrite(e1, 90);
    analogWrite(e2, 90);
    //right motor clockwise motion
    digitalWrite(m1, HIGH);
    digitalWrite(m2, LOW);
    //left motor clockwise motion
    digitalWrite(m3, HIGH);
    digitalWrite(m4, LOW);
  }
  
  //if only left sensor detects black line
  if((s1 == 1) && (s2 == 0) && (s3 == 1) && (s4 == 1) && (s5 == 1))
  {
    //going right 
    analogWrite(e1, 90);
    analogWrite(e2, 90);
    //right motor clockwise
    digitalWrite(m1, HIGH);
    digitalWrite(m2, LOW);
    //left motor low
    digitalWrite(m3, LOW);
    digitalWrite(m4, LOW);
  }
  
  //if only left most sensor detects black line
  if((s1 == 0) && (s2 == 1) && (s3 == 1) && (s4 == 1) && (s5 == 1))
  {
    //going right
    analogWrite(e1, 90);
    analogWrite(e2, 90);
    //right motor clockwise motion
    digitalWrite(m1, HIGH);
    digitalWrite(m2, LOW);
    //left motor counter clockwise motion
    digitalWrite(m3, LOW);
    digitalWrite(m4, HIGH);
  }

  //if only right sensor detects black line
  if((s1 == 1) && (s2 == 1) && (s3 == 1) && (s4 == 0) && (s5 == 1))
  {
    //going left
    analogWrite(e1, 90);
    analogWrite(e2, 90);
    //right motor low
    digitalWrite(m1, LOW);
    digitalWrite(m2, LOW);
    //left motor clockwise motion
    digitalWrite(m3, HIGH);
    digitalWrite(m4, LOW);
  }

  //if only right most sensor detects black line
  if((s1 == 1) && (s2 == 1) && (s3 == 1) && (s4 == 1) && (s5 == 0))
  {
    //going left
    analogWrite(e1, 90);
    analogWrite(e2, 90);
    //right motor counter clockiwse motion
    digitalWrite(m1, LOW);
    digitalWrite(m2, HIGH);
    //left motor clockwise motion
    digitalWrite(m3, HIGH);
    digitalWrite(m4, LOW);
  }

  //if middle and right sensor detects black line
  if((s1 == 1) && (s2 == 1) && (s3 == 0) && (s4 == 0) && (s5 == 1))
  {
    //going left
    analogWrite(e1, 90);
    analogWrite(e2, 90);
    //right motor low
    digitalWrite(m1, LOW);
    digitalWrite(m2, LOW);
    //left motor counter clockwise motion
    digitalWrite(m3, HIGH);
    digitalWrite(m4, LOW);
  }

  //if middle and left sensor detects black line
  if((s1 == 1) && (s2 == 0) && (s3 == 0) && (s4 == 1) && (s5 == 1))
  {
    //going right
    analogWrite(e1, 90);
    analogWrite(e2, 90);
    //right motor clockwise motion 
    digitalWrite(m1, HIGH);
    digitalWrite(m2, LOW);
    //left motor low
    digitalWrite(m3, LOW);
    digitalWrite(m4, LOW);
  }

  //if middle, left and left most sensor detects black line
  if((s1 == 0) && (s2 == 0) && (s3 == 0) && (s4 == 1) && (s5 == 1))
  {
    //going right
    analogWrite(e1, 90);
    analogWrite(e2, 90);
    digitalWrite(m1, HIGH);
    digitalWrite(m2, LOW);
    digitalWrite(m3, LOW);
    digitalWrite(m4, LOW);
  }

  //if middle, right and right most sensor detects black line
  if((s1 == 1) && (s2 == 1) && (s3 == 0) && (s4 == 0) && (s5 == 0))
  {
    //going left
    analogWrite(e1, 90);
    analogWrite(e2, 90);
    //right motor low
    digitalWrite(m1, LOW);
    digitalWrite(m2, LOW);
    //left motor clockwise motion
    digitalWrite(m3, HIGH);
    digitalWrite(m4, LOW);
  }

  //if all sensors are on a black line
  if((s1 == 0) && (s2 == 0) && (s3 == 0) && (s4 == 0) && (s5 == 0))
  {
    //stop
    digitalWrite(m1, LOW);
    digitalWrite(m2, LOW);
    digitalWrite(m3, LOW);
    digitalWrite(m4, LOW);
  }
  }
  else if (voice[voice.length()-1] == 'p') {
    //stop
    digitalWrite(m1, LOW);
    digitalWrite(m2, LOW);
    digitalWrite(m3, LOW);
    digitalWrite(m4, LOW);
   
  } 
}