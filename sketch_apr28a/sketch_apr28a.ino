#define trig 7 
#define echo 6
#define RightMotorForwardPin 5
#define RightMotorBackwardPin 4
#define LeftMotorForwardPin 3
#define LeftMotorBackwardPin 2

bool goesForward = false;
void setup() {
  Serial.begin(9600);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(RightMotorForwardPin, OUTPUT);
  pinMode(RightMotorBackwardPin, OUTPUT);
  pinMode(LeftMotorForwardPin, OUTPUT);
  pinMode(LeftMotorBackwardPin, OUTPUT);
}

void loop() {
  
 Serial.print(getDistance());


}

float getDistance()
{
  float distance, duration;
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo,HIGH);
  delay(100); 

  distance = duration / 29/ 2; //in cm
  return distance;
}

void moveForward() {
  if (!goesForward) {
    goesForward = true;
    digitalWrite(LeftMotorForwardPin, HIGH);
    digitalWrite(RightMotorForwardPin, HIGH);
    digitalWrite(LeftMotorBackwardPin, LOW);
    digitalWrite(RightMotorBackwardPin, LOW);
  }
}

void stop ()
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
  float distance = getDistance();

  if (distance <= 30){
    digitalWrite(LeftMotorForwardPin, LOW);
    digitalWrite(LeftMotorBackwardPin, LOW);

    digitalWrite(RightMotorForwardPin, LOW);
    digitalWrite(RightMotorBackwardPin, High);
  }
}
