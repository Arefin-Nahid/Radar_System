# Radar System Prototype

This repository contains the Arduino code and design files for the Radar System Prototype, a simple yet effective radar capable of detecting stationary and moving objects using ultrasonic sensors. The system is designed to be educational and accessible, utilizing commonly available hardware components.

## Project Description

The Radar System Prototype aims to provide a practical demonstration of radar technology using an Arduino UNO, multiple ultrasonic sensors, a servo motor, an LCD display, a buzzer, and LEDs. It is designed to scan and detect objects within a 250 cm range and provide real-time feedback on an LCD display, accompanied by audible alerts for close-range detections.

## Hardware Requirements

- Arduino UNO
- Ultrasonic Sensors x 4
- Servo Motor
- LCD Display (I2C Interface)
- Buzzer
- LED
- Connecting Wires

## Software Dependencies

- Arduino IDE
- `NewPing` library for ultrasonic sensors
- `Servo` library to control the servo motor
- `LiquidCrystal_I2C` library for the LCD display

## Installation

1. **Set up Arduino IDE:** Download and install the Arduino IDE from [Arduino Website](https://www.arduino.cc/en/software).
2. **Install Libraries:** Open the Arduino IDE, go to Sketch > Include Library > Manage Libraries. Search for `NewPing`, `Servo`, and `LiquidCrystal_I2C`, and install these libraries.
3. **Clone the Repository:** Clone this repository to your local machine or download the ZIP file and extract it.
4. **Upload the Sketch:** Open the `RadarSystemPrototype.ino` file with Arduino IDE, connect your Arduino UNO via USB, select the correct board and port under Tools, and upload the sketch.

## Usage

Once the sketch is uploaded and the hardware is set up:
- Power the Arduino UNO.
- The servo motor will start to sweep the ultrasonic sensors from 0° to 180° and back.
- Observe the LCD display; it will show the distance and angle of detected objects.
- The buzzer will sound if an object is detected within 5 cm.

## Contributing

Contributions to this project are welcome! Please follow these steps to contribute:
1. Fork the repository.
2. Create a new branch for your feature (`git checkout -b feature/AmazingFeature`).
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`).
4. Push to the branch (`git push origin feature/AmazingFeature`).
5. Open a pull request.

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE) file for details.

## Acknowledgments

- Thanks to the Arduino community for their invaluable resources and support.
- Special thanks to everyone who has contributed to testing and refining this prototype.

## Contact

For any inquiries or issues, please open an issue on GitHub or contact the repository owner directly through GitHub.

Enjoy building and experimenting with your Radar System Prototype!
