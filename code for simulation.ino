const int trigPin =7;
const int echoPin =6;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
}

long readUltrasonicDistance(int trigger, int echo) {
  digitalWrite(trigger,LOW);
  delayMicroseconds(2);
  digitalWrite(trigger,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger,LOW);
  
  long duration=pulseIn(echo,HIGH);
  long distance= (duration*0.034)/2;
  
  Serial.println(duration);
  return distance;
}

void loop() {
  long cm= readUltrasonicDistance(trigPin,echoPin);
  
  Serial.print(cm);
  Serial.println("cm");
  
  if(cm>250){
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
  }
  
  if(cm<250 && cm>175){
    digitalWrite(3,HIGH);
    digitalWrite(3,LOW);
    digitalWrite(3,LOW);
  }
  
  if(cm<=175 && cm>100){
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
  }
  
  if(cm<=100) {
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
  }
  
  
  delay(100);
}