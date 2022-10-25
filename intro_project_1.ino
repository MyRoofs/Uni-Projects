//project intro arduino 1
#include <Servo.h>
int PIRsensor = 2;              // the pin that the sensor is atteched to
int state = LOW;             // by default, no motion detected
int val = 0; 
int trigin=11;
int echoin=10;
int led = 13;

Servo myservo;  // create servo object to control a servo

//***********
void setup() {
Serial.begin(9600);  
myservo.attach(9);// attaches the servo on pin 9 to the servo object
pinMode(trigin,OUTPUT); 
pinMode(echoin,INPUT); 
pinMode(PIRsensor, INPUT);
pinMode(led, OUTPUT);

}
//************
void loop() {
myservo.writeMicroseconds(1496);  

long durationOne , distanceOne;
digitalWrite(trigin,LOW);
delayMicroseconds(2);
digitalWrite(trigin,HIGH);
delayMicroseconds(10);
digitalWrite(trigin, LOW);
durationOne = pulseIn(echoin, HIGH); 
distanceOne= durationOne*0.034/2;
//***********
if(distanceOne<=10){
  
  myservo.write(90);
  delay(2000);
  }
 
else if(distanceOne>=10){
    myservo.write(0);
    delay(2000);

}
 
//*************
  // put your main code here, to run repeatedly:
  val = digitalRead(PIRsensor);   // read sensor value
  if (val == HIGH) {           // check if the sensor is HIGH
    digitalWrite(led, HIGH);   // turn LED ON
    delay(2000);                // delay 100 milliseconds 
    
    if (state == LOW) {
      //Serial.println("Motion detected!"); 
      state = HIGH;       // update variable state to HIGH
    }
  } 
  else {
      digitalWrite(led, LOW); // turn LED OFF
      delay(200); }            // delay 200 milliseconds 
      
      if (state == HIGH){
        //Serial.println("Motion stopped!");
        state = LOW;       // update variable state to LOW
    }
  
//************


}
