// Define the pins for the ultrasonic sensor
const int trigPin = 2; // Trigger pin
const int echoPin = 3; // Echo pin

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);

  // Set the trigger pin as an OUTPUT
  pinMode(trigPin, OUTPUT);
  // Set the echo pin as an INPUT
  pinMode(echoPin, INPUT);
}

void loop() {
  // Send a 10us HIGH pulse to trigger the sensor
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the time it takes for the echo to return
  long duration = pulseIn(echoPin, HIGH);

  // Calculate the distance in centimeters (cm)
  // Speed of sound is approximately 343 meters per second
  // Divide by 2 for a one-way trip, and convert to cm
  float distance_cm = (duration / 2.0) * 0.0343;

  // Print the distance to the serial monitor
  Serial.print("Distance: ");
  Serial.print(distance_cm);
  Serial.println(" cm");
  if(distance_cm>=50)
      digitalWrite(LED_BUILTIN, HIGH);
  else
      digitalWrite(LED_BUILTIN, LOW);
  // Wait for a short delay before taking another reading
  delay(1000); // Adjust this value to control the update rate
}