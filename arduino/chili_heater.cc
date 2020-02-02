#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif 

const int kRelayPin = 11;
const int kThermistorPin = A0;
const float kLatchFactor = 0.01;

const double kR2 = 99500;
const double kThermistorA = 0.8285601674e-3;
const double kThermistorB = 2.086059927e-4;
const double kThermistorC = 0.8112077100e-7;

int readTemperatureCelsius(const int pin) {
  const int value = analogRead(pin);
  const int voltage = value * 5 / 1024;
  // voltage = 5 * r1 / (r1 + r2)
  // voltage * (r1 + r2) = 5 * r1
  // r1 * (5 - voltage) = r2 * voltage
  const double resistance = kR2 * voltage / (5.0 - voltage);
  const double log_resistance = log(resistance);
  const float one_over_temp =
    kThermistorA + kThermistorB * log_resistance + kThermistorC * log_resistance * log_resistance * log_resistance;
  return 1.0 / one_over_temp - 273;
}

void setup() {
  Serial.begin(9600);
  pinMode(kRelayPin, OUTPUT);
}

int target_temperature_celsius = 22;
void loop() {
  if (Serial.available() > 0) {
    const unsigned char incomingByte = Serial.read();
    target_temperature_celsius = incomingByte;
  }
  const int current_temperature_celsius = readTemperatureCelsius(kThermistorPin);
  if (current_temperature_celsius < target_temperature_celsius * (1.0 - kLatchFactor)) {
    digitalWrite(kRelayPin, LOW);
  } else if (current_temperature_celsius > target_temperature_celsius * (1.0 + kLatchFactor)) {
    digitalWrite(kRelayPin, HIGH);
  }
  delay(1000);
}
