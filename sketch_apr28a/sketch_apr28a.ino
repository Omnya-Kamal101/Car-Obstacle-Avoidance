#define trig 7 
#define echo 6
#define RightMotorForwardPin 5
#define RightMotorBackwardPin 4
#define LeftMotorForwardPin 3
#define LeftMotorBackwardPin 2
#define ENA 9
#define ENB 10

bool goesForward = false;
void setup() {
  Serial.begin(9600);

  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);


  pinMode(RightMotorForwardPin, OUTPUT);
  pinMode(RightMotorBackwardPin, OUTPUT);
  pinMode(LeftMotorForwardPin, OUTPUT);
  pinMode(LeftMotorBackwardPin, OUTPUT);

  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);
  analogWrite(ENA,255);
  analogWrite(ENB,255);
}

void loop() {
  
 Serial.print(getDistance());

 if (getDistance() <= 30)
  avoidObstacle();
else
  moveForward();


}
float getDistance()
{
   float distance,duration;
   digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo,HIGH);
 

  distance = duration / 29/ 2; //in cm
  return distance;
}
void moveForward() {
  if (!goesForward)
   {
    analogWrite(ENA, 255);  
    analogWrite(ENB, 255);   
    digitalWrite(LeftMotorForwardPin, HIGH);
    digitalWrite(RightMotorForwardPin, HIGH);
    digitalWrite(LeftMotorBackwardPin, LOW);
    digitalWrite(RightMotorBackwardPin, LOW);
        goesForward = true;
  }
}

void stopCar()
{
  if(goesForward)
  {
     digitalWrite(LeftMotorForwardPin, LOW);
    digitalWrite(RightMotorForwardPin, LOW);
    digitalWrite(LeftMotorBackwardPin, LOW);
    digitalWrite(RightMotorBackwardPin, LOW);
    goesForward=false;
  }
}


void avoidObstacle(){
analogWrite(ENA, 100);  
analogWrite(ENB, 255);    
    digitalWrite(LeftMotorForwardPin, HIGH);
    digitalWrite(LeftMotorBackwardPin, LOW);
    digitalWrite(RightMotorForwardPin, HIGH);
    digitalWrite(RightMotorBackwardPin, LOW);
}

