#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "DHT.h"

// ======================
// DHT22 SETUP
// ======================
#define DHTPIN 4
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

// ======================
// Simulated Second Sensor (e.g., light)
// ======================
int lightSensorPin = 34; // analog pin for simulated light

// ======================
// OLED SETUP
// ======================
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// ======================
// Timing
// ======================
unsigned long previousMillis = 0;
const long interval = 2000; // 2 seconds

void setup() {
  Serial.begin(115200);
  dht.begin();

  // Initialize OLED
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("SSD1306 allocation failed");
    for(;;);
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);
  display.println("Sensor Data Logger");
  display.display();

  Serial.println("Time(s),Temp(C),Hum(%),Light(ADC)"); // CSV header
}

void loop() {
  unsigned long currentMillis = millis();
  if(currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    // Read DHT22
    float temperature = dht.readTemperature();
    float humidity = dht.readHumidity();

    // Read second sensor (simulated analog light value)
    int lightValue = analogRead(lightSensorPin);

    // Check DHT reading
    if (isnan(temperature) || isnan(humidity)) {
      Serial.println("Failed to read from DHT sensor!");
      return;
    }

    // ======================
    // UART Output (CSV)
    // ======================
    Serial.print(currentMillis / 1000.0, 2); // Time in seconds
    Serial.print(",");
    Serial.print(temperature, 2);
    Serial.print(",");
    Serial.print(humidity, 2);
    Serial.print(",");
    Serial.println(lightValue);

    // ======================
    // OLED Display
    // ======================
    display.clearDisplay();
    display.setCursor(0,0);
    display.println("Sensor Data Logger");
    display.println("-----------------");
    display.print("Time: "); display.print(currentMillis / 1000.0, 1); display.println(" s");
    display.print("Temp: "); display.print(temperature, 1); display.println(" C");
    display.print("Hum: "); display.print(humidity, 1); display.println(" %");
    display.print("Light: "); display.println(lightValue);
    display.display();
  }
}
