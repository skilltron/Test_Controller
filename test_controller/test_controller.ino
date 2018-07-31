// the setup function runs once when you press reset or power the board
  const int device = 13;  // output Pin used to turn the device on and off.
  const int potPin = A0;    // input pin for the potentiometer used to control the device
  int powerOn = 0; // sets initial condition of device to off.
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin device as an output.
    Serial.begin(9600);
    pinMode(device, OUTPUT);
    pinMode(potPin, INPUT);
}

// the loop function runs over and over again forever
void loop() {
  //reads value of device control potentiometer, 
  // make all connections with units unplugged
  //connect any value pot between pot pin defined above and 5v on the board
  powerOn = analogRead(potPin); //reads the value of the potentiometer (value between 0 and 1023)
  
  powerOn = map(powerOn, 0, 1023, 0, 1000);

  // creates a % of time each second that the device is allowed to turn on for.
  // make all connections with units unplugged
  // connect low power side of solid state relay to ground and device pin defined above
  // connect high power side of soid state relay to connect the device wire though it.
  digitalWrite(device, HIGH);   // turn the LED on (HIGH is the voltage level)
  Serial.println(powerOn);
  delay(powerOn);                // turns device on duration of powerOn in miliseconds (0 to 1000)
  digitalWrite(device, LOW);    // turn the LED off by making the voltage LOW
  delay(1000-powerOn);           // Off time for the remainder of the second
}
