#define trig 12 
#define echo 8
#define RightMotorForwardPin 5
#define RightMotorBackwardPin 3
#define LeftMotorForwardPin 9
#define LeftMotorBackwardPin 6
#define ENA 10
#define ENB 11
#define maxSpeed 255

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
  analogWrite(ENA, maxSpeed);  
  analogWrite(ENB, maxSpeed);  

  randomSeed(analogRead(A0));

  delay(2000);
}

void loop() {
  
  delay (200);

  float distance = getDistance();

  if (distance > 70)
    moveForward();
  else{
    stopCar();
    delay(400);
    backWard();
    delay(400);
    stopCar();
    delay(400);
    avoidObstacle();
  }

  delay(200);
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
    Serial.println("Moving Forward");

  analogWrite(ENA, maxSpeed);  
  analogWrite(ENB, maxSpeed);   
  digitalWrite(LeftMotorForwardPin, HIGH);
  digitalWrite(RightMotorForwardPin, HIGH);
  digitalWrite(LeftMotorBackwardPin, LOW);
  digitalWrite(RightMotorBackwardPin, LOW);
    
}

void backWard()
{
   Serial.println("Moving Backward");
  analogWrite(ENA, maxSpeed);  
  analogWrite(ENB, maxSpeed);   
  digitalWrite(LeftMotorForwardPin, LOW);
  digitalWrite(RightMotorForwardPin, LOW);
  digitalWrite(LeftMotorBackwardPin, HIGH);
  digitalWrite(RightMotorBackwardPin, HIGH);
}

void stopCar()
{
  digitalWrite(LeftMotorForwardPin, LOW);
  digitalWrite(RightMotorForwardPin, LOW);
  digitalWrite(LeftMotorBackwardPin, LOW);
  digitalWrite(RightMotorBackwardPin, LOW); 
}

void avoidObstacle(){
  Serial.println("Avoiding Obstacle");
  int direction = random(0,2);
  if(direction==0)
  {
    analogWrite(ENA, maxSpeed);  
    analogWrite(ENB, maxSpeed); 
    digitalWrite(LeftMotorForwardPin, HIGH);
    digitalWrite(LeftMotorBackwardPin, LOW);
    digitalWrite(RightMotorForwardPin, LOW);
    digitalWrite(RightMotorBackwardPin, HIGH);
  }
  else
  {
    analogWrite(ENA, maxSpeed);  
    analogWrite(ENB, maxSpeed); 
    digitalWrite(LeftMotorForwardPin, LOW);
    digitalWrite(LeftMotorBackwardPin, HIGH);
    digitalWrite(RightMotorForwardPin, HIGH);
    digitalWrite(RightMotorBackwardPin, LOW);
  }
  
}
