#include <WiFi.h>
#include <ThingSpeak.h>
#include <DHTesp.h>

const char* ssid = "Wokwi-GUEST";
const char* password = "";
unsigned long channelNumber = 3560245;
// Replace locally with your regenerated ThingSpeak Write API Key before running.
const char* writeAPIKey = "YOUR_WRITE_API_KEY";
const int DHT_PIN = 15;
const char* universityID = "12220489";

WiFiClient client;
DHTesp dhtSensor;

void setup() {
  Serial.begin(115200);
  dhtSensor.setup(DHT_PIN, DHTesp::DHT22);
  WiFi.begin(ssid, password, 6);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nStatus: Connected");
  Serial.print("Student ID: ");
  Serial.println(universityID);
  ThingSpeak.begin(client);
}

void loop() {
  TempAndHumidity data = dhtSensor.getTempAndHumidity();
  Serial.print("Temperature: ");
  Serial.println(data.temperature);
  Serial.print("Humidity: ");
  Serial.println(data.humidity);
  ThingSpeak.setField(1, data.temperature);
  ThingSpeak.setField(2, data.humidity);
  int status = ThingSpeak.writeFields(channelNumber, writeAPIKey);
  if (status == 200) {
    Serial.println("Data Sent to ThingSpeak");
  } else {
    Serial.print("Error Code: ");
    Serial.println(status);
  }
  delay(20000);
}
