#define trig 5 
#define echo 6
#define RightMotorForwardPin 4
#define RightMotorBackwardPin 3
#define LeftMotorForwardPin 8
#define LeftMotorBackwardPin 7
#define ENA 10
#define ENB 11

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

  randomSeed(analogRead(A0));
}

void loop() {

  float distance = getDistance();

  if (distance <= 30)
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
  if (goesForward)
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
  if(!goesForward)
  {
    digitalWrite(LeftMotorForwardPin, LOW);
    digitalWrite(RightMotorForwardPin, LOW);
    digitalWrite(LeftMotorBackwardPin, LOW);
    digitalWrite(RightMotorBackwardPin, LOW);
    goesForward=false;
  }
}


void avoidObstacle(){
  stopCar();
  delay(250);

  digitalWrite(LeftMotorForwardPin, LOW);
  digitalWrite(LeftMotorBackwardPin, HIGH);
  digitalWrite(RightMotorForwardPin, LOW);
  digitalWrite(RightMotorBackwardPin, HIGH);

  delay(350);
  stopCar();
  delay(150);
  
  int direction = random(0,2);
  if(direction==0)
  {
    analogWrite(ENA, 255);  
    analogWrite(ENB, 100); 
  }
  else
  {
    analogWrite(ENA, 100);  
    analogWrite(ENB, 255);    
  }
  digitalWrite(LeftMotorForwardPin, HIGH);
  digitalWrite(LeftMotorBackwardPin, LOW);
  digitalWrite(RightMotorForwardPin, HIGH);
  digitalWrite(RightMotorBackwardPin, LOW);
  
  delay(400);
}