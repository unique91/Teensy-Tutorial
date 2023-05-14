#include <Wire.h>
#include <WireIMXRT.h>
#include <WireKinetis.h>

#define LED_PIN 13

const int MPU = 0x68;        // MPU6050 I2C address
const int PWR_MGMT = 0x6B;   // Configuration for power mode and clock source
const int CLKSEL = 0x00;     // Internal 8MHz oscillator
const int DLPF_CFG = 0x1A;   // Configuration for Digital Low Pass Filter (DLPF)
const int DLPF_BIT = 0x05;   // Set the resigter bit
const int GYRO_CFG = 0x1B;   // Configuration for Gyroscope
const int GYRO_BIT = 0x08;   // Set the register bit
const int GYRO_XOUT = 0x43;  // Configuration for Gyroscope Measurements
float rotX, rotY, rotZ;      // Rotation in Roll, Pitch and Yaw angle

void setup() {
 Serial.begin(19200);           // Initialize baudrate
 pinMode(LED_PIN, OUTPUT);      // Congigure Teensy LED-PIN 13
 digitalWrite(LED_PIN, HIGH);
 Wire.setClock(400000);         // Fast mode
 Wire.begin();
 delay(100);

 Wire.beginTransmission(MPU);
 Wire.write(PWR_MGMT);
 Wire.write(CLKSEL);
 Wire.endTransmission();
}

void loop() {
 Wire.beginTransmission(MPU);
 Wire.write(DLPF_CFG);
 Wire.write(DLPF_BIT);
 Wire.endTransmission();

 Wire.beginTransmission(MPU);
 Wire.write(GYRO_CFG);
 Wire.write(GYRO_BIT);
 Wire.endTransmission();

 Wire.beginTransmission(MPU);
 Wire.write(GYRO_XOUT);
 Wire.endTransmission();  

 Wire.requestFrom(MPU, 6);

 rotX = (float) (Wire.read() << 8 | Wire.read()) / 65.5;
 rotY = (float) (Wire.read() << 8 | Wire.read()) / 65.5;
 rotZ = (float) (Wire.read() << 8 | Wire.read()) / 65.5;

 // Display the output on serial monitor in Arduino IDE
 Serial.print("X-Axis = ");
 Serial.print(rotX);
 Serial.print(" Y-Axis = ");
 Serial.print(rotX);
 Serial.print(" Z-Axis = ");
 Serial.println(rotX);
 delay(100);
}
