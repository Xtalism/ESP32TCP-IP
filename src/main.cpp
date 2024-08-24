#include <Arduino.h>
#include <FS.h>
#include <WiFi.h>

const char *ssid = "ESP32-AP";
const char *password = "manuel123";

const char *serverIP = "192.168.4.1";
const uint16_t serverPort = 80;

// Forward declaration of the sendToServer function
void sendToServer(String message);

void setup()
{
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  Serial.printf("MAC address = %s\n", WiFi.softAPmacAddress().c_str());

  // while (WL_CONNECTED == WiFi.status())
  // {
  //   long rssi = WiFi.RSSI();
  //   Serial.print("Signal strength (RSSI): ");
  //   Serial.println(rssi);
  //   delay(3000);
  // }
}

void loop()
{
  if (Serial.available())
  {
    String message = Serial.readStringUntil('\n');
    sendToServer(message);
  }
}

void sendToServer(String message)
{
  WiFiClient client;

  if (client.connect(serverIP, serverPort))
  {
    Serial.println("Message Sent");

    String postRequest = "POST / HTTP/1.1\r\n";
    postRequest += "Host: " + String(serverIP) + "\r\n";
    postRequest += "Content-Type: text/plain\r\n";
    postRequest += "Content-Length: " + String(message.length()) + "\r\n";
    postRequest += "\r\n";
    postRequest += message;

    client.print(postRequest);

    while (client.available())
    {
      if (client.available())
      {
        String response = client.readStringUntil('\n');
        // Serial.println(response);
        Serial.println("Sent: " + message);
      }
    }
    client.stop();
  }
  else
  {
    Serial.println("Failed to connect to server");
  }
}