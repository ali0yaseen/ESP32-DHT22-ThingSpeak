#include <DHT.h>

// #define DHTPIN 15
// #define DHTTYPE DHT22
// DHT22 is a digital sensor, not an analog sensor.
DHT sensor(15, DHT22);

const int ledPin = 23;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200);
  sensor.begin();
}

void loop() {
  float temperature = sensor.readTemperature();
  float humidity = sensor.readHumidity();

  Serial.print("Temperature: ");
  Serial.println(temperature);

  Serial.print("Humidity: ");
  Serial.println(humidity);

  if (temperature > 30) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  delay(2000);
}
