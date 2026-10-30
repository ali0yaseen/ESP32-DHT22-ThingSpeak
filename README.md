# ESP32 → ThingSpeak: Temperature and Humidity Monitoring

**Student:** Ali Yaseen  
**University ID:** 12220489

## Description
ESP32 reads simulated temperature and humidity from a DHT22 sensor in Wokwi and uploads both readings to a public ThingSpeak channel every 20 seconds. The channel displays temperature and humidity in separate time-series charts.

## Links
- **Public ThingSpeak channel:** https://thingspeak.mathworks.com/channels/3560245
- **Wokwi project:** Add the saved project URL here.

## Components
- ESP32 Dev Board
- DHT22 temperature and humidity sensor
- Breadboard and jumper wires

## Wiring
| DHT22 pin | ESP32 connection |
|---|---|
| VCC (pin 1) | 3V3 |
| DATA (pin 2) | GPIO 15 |
| NC (pin 3) | Not connected |
| GND (pin 4) | GND |

## ThingSpeak fields
- Field 1: Temperature (°C)
- Field 2: Humidity (%)

## Run
1. Open the Wokwi simulation or create a Wokwi ESP32 project using `sketch.ino` and the required libraries in `libraries.txt`.
2. Set `writeAPIKey` to a newly generated ThingSpeak Write API Key **only in your private working copy**. Do not publish the key.
3. Run the simulation. Check the Serial Monitor for Wi-Fi connection, temperature, humidity, and HTTP success (`Data Sent to ThingSpeak`).
4. Visit the public ThingSpeak channel to view the charts.

## Evidence
Screenshots in `screenshots/` show the circuit, successful serial output, and ThingSpeak charts.

**Security note:** The API key is deliberately omitted from this public source code. Regenerate any key previously exposed in screenshots before reuse.
