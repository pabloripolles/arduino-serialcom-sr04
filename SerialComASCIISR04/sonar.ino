/// Serial communication using HC-SR04 distance sensor.

/** This allows to read data from Arduino and send it to Processing using ASCII
  * based serial communication.
  *
  * Pablo Ripolles @ Birmingham, 2015-09-30
  */

#include <NewPing.h>

// Arduino pin tied to trigger pin on the ultrasonic sensor.
#define TRIGGER_PIN  7
// Arduino pin tied to echo pin on the ultrasonic sensor.
#define ECHO_PIN     8
// Maximum distance we want to ping for (in centimeters).
// Maximum sensor distance is rated at 400-500cm.
#define MAX_DISTANCE 400

// NewPing setup of pins and maximum distance.
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void establishContact()
{
  while (Serial.available() <= 0) {
    // Send a string+'\n' to the computer, this will trigger the
    // serial event.
    Serial.println("0 ");
    delay(300);
  }
}

void ping()
{
  // Wait 50ms between pings (about 20 pings/sec).
  // The shortest delay between pings should be 29ms.
  delay(30);

  // Expect to read unsigned long integers.
  unsigned long outDec = sonar.ping_cm();

  // Send outgoing data:
  Serial.print(outDec, DEC);
  Serial.print(" ");
  Serial.println();
}
