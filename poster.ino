#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>

const char *ssid = "";
const char *password = "";
const char *serverUrl = "http://your_server_ip:5000/update_data";

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  pinMode(2, OUTPUT);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
}

void loop() {
  WiFiClient client;  // Create a WiFiClient object
  HTTPClient http;
  http.begin(client, serverUrl);  // Use begin(WiFiClient, url) here
  http.addHeader("Content-Type", "application/json");

  String jsonData = "{\"value\": 1}";
  int httpCode = http.POST(jsonData);

  if (httpCode == HTTP_CODE_OK) {
    String payload = http.getString();
    Serial.println("Response from server: " + payload);
    digitalWrite(2, HIGH);
    
  } else {
    Serial.println("Failed to update data. HTTP code: " + String(httpCode));
  }

  http.end();

  delay(5000);
  digitalWrite(2, LOW);  // Adjust the delay according to your needs
}

