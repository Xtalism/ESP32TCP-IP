# TCP-IP

This is a TCP/IP ESP32 protocol client that sends messages through the internet.

## Table of Contents

- [TCP-IP](#tcp-ip)
  - [Table of Contents](#table-of-contents)
  - [Description](#description)
  - [Installation](#installation)
  - [Usage](#usage)
  - [Documentation](#documentation)
  - [Contributing](#contributing)
  - [License](#license)

## Description

This project implements a TCP/IP client using the ESP32 microcontroller. The client establishes a connection to a specified server and sends messages over the internet. It is designed to be lightweight and efficient, making it suitable for IoT applications where reliable communication is essential. The project includes example code for setting up the ESP32, connecting to a Wi-Fi network, and sending data to a server.

You can use the [ESP32TCP-IP](https://github.com/Xtalism/ESP32TCP-IP) code from my repository to connect to the access point whenever you like. This code also works with multiple ESP32 devices. If you'd like to add more than two ESP32 devices, you need to modify the [ESP32AP](https://github.com/Xtalism/ESP32AP) code to support as many clients as you need.

## Installation

1. Clone the repository:
    ```sh
    git clone https://github.com/Xtalism/ESP32TCP-IP.git
    ```
2. Open the project in your preferred IDE (e.g., VS Code).
3. Install the necessary dependencies (e.g., ESP32 board support in Arduino IDE).

## Usage

1. Configure your Wi-Fi credentials in the code.
2. Upload the code to your ESP32 device.
3. Monitor the serial output to see the connection status and messages being sent.

## Documentation

You can look up the [WiFi API](https://docs.espressif.com/projects/arduino-esp32/en/latest/api/wifi.html) documentation which is the one I based my code on.

You can also see the [TCP/IP Adapter](https://docs.espressif.com/projects/esp-idf/en/release-v3.3/api-reference/network/tcpip_adapter.html) for more details.

## Contributing

Contributions are welcome! Please fork the repository and submit a pull request.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.