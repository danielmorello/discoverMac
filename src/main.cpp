#include <WiFi.h>

// Declaração da variável no escopo global
String macAP;
#define LED_PIN 2

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  // Aguarde a inicialização do Serial
  while (!Serial) {
    delay(10);
  }

  // Inicializa o Wi-Fi em modo AP para obter o endereço MAC do AP
  WiFi.mode(WIFI_AP);
  macAP = WiFi.macAddress(); // Atribui o endereço MAC à variável global

  // Mostra o endereço MAC no Monitor Serial
  Serial.print("Endereço MAC em modo AP: ");
  Serial.println(macAP);
}

void loop() {
  delay(1000);
  digitalWrite(LED_PIN, HIGH);
  Serial.print("Repetindo o endereço MAC em modo AP: ");
  Serial.println(macAP);
  delay(1000);
  digitalWrite(LED_PIN, LOW);
}
