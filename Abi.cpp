#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h>

#define WIFI_SSID       "Uthai"
#define WIFI_PASSWORD   "redmi note 11"
#define FIREBASE_HOST   "https://soil-44c41-default-rtdb.firebaseio.com/"
#define FIREBASE_AUTH   "BY4LIDujqFMrCak6NQuTHbLSiywQPWqGujdxciSr"

const int sensor_pin = A0;
FirebaseData fbData;

void setup() {
  Serial.begin(115200);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("\nConnected to WiFi");
  Serial.println(WiFi.localIP());

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void loop() {
  float moisture = 100.0 - ((analogRead(sensor_pin) / 1023.0) * 100.0);
  Serial.printf("Soil Moisture: %.2f%%\n", moisture);
  Firebase.setFloat(fbData, "/SENSE/SOILDATA", moisture);
  delay(1000);
}
