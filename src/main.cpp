#include <WiFi.h>
#include <FS.h>
#include <WebServer.h>

const char *ssid = "ESP32-AP";
const char *password = "manuel123";

const char *serverIP = "192.168.4.1";
const uint16_t serverPort = 80;

WebServer server(80);

void sendToServer(String message);

void handlePost()
{
  if (server.method() == HTTP_POST)
  {
    String message = server.arg("plain");
    Serial.println("Received message: " + message);
    server.send(200, "text/plain", "Message received: " + message);
  }
  else
  {
    server.send(405, "text/plain", "Method Not Allowed");
  }
}

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
  Serial.printf("MAC address = %s\n", WiFi.macAddress().c_str());

  server.on("/", HTTP_POST, handlePost);
  server.begin();
  Serial.println("HTTP server started");
}

void loop()
{
  server.handleClient();

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
    Serial.println("Connected to server");

    String postRequest = "POST / HTTP/1.1\r\n";
    postRequest += "Host: " + String(serverIP) + "\r\n";
    postRequest += "Content-Type: text/plain\r\n";
    postRequest += "Content-Length: " + String(message.length()) + "\r\n";
    postRequest += "\r\n";
    postRequest += message;

    client.print(postRequest);

    while (client.connected())
    {
      if (client.available())
      {
        String response = client.readStringUntil('\n');
        Serial.println("Response: " + response);
      }
    }
    client.stop();
  }
  else
  {
    Serial.println("Failed to connect to server");
  }
}