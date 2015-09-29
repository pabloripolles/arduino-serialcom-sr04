/// Serial communication using HC-SR04 distance sensor.

/** This allows to read data from Arduino and send it to Processing using ASCII
  * based serial communication.
  *
  * Pablo Ripolles @ Birmingham, 2015-09-30
  */

void setup()
{
  // Open serial monitor at 115200 baud to see ping results.
  Serial.begin(115200);
  establishContact();
}

void loop()
{
  // If we get a valid byte,
  if (Serial.available() > 0) {
    // get incoming byte to empty the buffer:
    int inByte = Serial.read();
    ping();
  }
}
