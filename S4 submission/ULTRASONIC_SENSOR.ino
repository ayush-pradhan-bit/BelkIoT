const int trigPin = 23;
const int echoPin = 22;

float duration;
float distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
 Serial.begin(9600);
}

void loop() {
  //Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2000);

  //Sets the trigPin on HIGH state for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW); 

  //Reads the echoPin,  returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);

  Serial.println(duration);

  //Calculating the distance
  distance = (duration * 0.0034029) /   2; //340 m/s is cm/sec. Since the distance is 2 ways the division is by 2
  

  //Print
  Serial.print("Distance: ");
  Serial.println(distance);

  delay(1000);
}
