# TCP-IP

This is a TCP/IP ESP32 protocol client that sends messages through the internet.

## Description

This project implements a TCP/IP client using the ESP32 microcontroller. The client establishes a connection to a specified server and sends messages over the internet. It is designed to be lightweight and efficient, making it suitable for IoT applications where reliable communication is essential. The project includes example code for setting up the ESP32, connecting to a Wi-Fi network, and sending data to a server.

You can use the [ESP32TCP-IP](https://github.com/Xtalism/ESP32TCP-IP) code from my repository to connect to the access point whenever you like. This code also works with multiple ESP32 devices. If you'd like to add more than two ESP32 devices, you need to modify the [ESP32AP](https://github.com/Xtalism/ESP32AP) code to support as many clients as you need.

## Documentation

You can look up the [WiFi API](https://docs.espressif.com/projects/arduino-esp32/en/latest/api/wifi.html) documentation which is the one I based my code on.

You can also see the [TCP/IP Adapter](https://docs.espressif.com/projects/esp-idf/en/release-v3.3/api-reference/network/tcpip_adapter.html) for more details.