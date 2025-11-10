#include <WiFi.h>
#include <FirebaseESP32.h>

#define WIFI_SSID       "Reshu"
#define WIFI_PASSWORD   "123456790"
#define FIREBASE_HOST   "https://ultraaa-default-rtdb.firebaseio.com/"
#define FIREBASE_AUTH   "zXdVz80R3QMRYYjqVQI7yytjxrJXkbf1zNrCRFH"

const int trigPin = 5;
const int echoPin = 18;

FirebaseData fb;

void setup() {
  Serial.begin(115200);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) delay(200);

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void loop() {
  // Trigger pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read echo
  long duration = pulseIn(echoPin, HIGH);
  float distance = duration * 0.034 / 2;   // in cm

  // Upload to Firebase
  Firebase.setFloat(fb, "/SENSE/distance", distance);

  delay(1000);
}
