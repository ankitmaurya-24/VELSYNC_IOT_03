#define BLYNK_TEMPLATE_ID "TMPL6x789_EXAMPLE"
#define BLYNK_TEMPLATE_NAME "SmartHomeAutomation"
#define BLYNK_AUTH_TOKEN "ABC123_DUMMY_TOKEN_XYZ"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "YourWiFiName";
char pass[] = "YourPassword";

// Relay Pins mapping for ESP8266
#define Relay1 D1 
#define Relay2 D2
#define Relay3 D5
#define Relay4 D6

BLYNK_WRITE(V1) { digitalWrite(Relay1, param.asInt()); }
BLYNK_WRITE(V2) { digitalWrite(Relay2, param.asInt()); }
BLYNK_WRITE(V3) { digitalWrite(Relay3, param.asInt()); }
BLYNK_WRITE(V4) { digitalWrite(Relay4, param.asInt()); }

void setup() {
  pinMode(Relay1, OUTPUT);
  pinMode(Relay2, OUTPUT);
  pinMode(Relay3, OUTPUT);
  pinMode(Relay4, OUTPUT);

  // Initial state: OFF
  digitalWrite(Relay1, HIGH); 
  digitalWrite(Relay2, HIGH);
  digitalWrite(Relay3, HIGH);
  digitalWrite(Relay4, HIGH);

  Blynk.begin(auth, ssid, pass);
}

void loop() {
  Blynk.run();
}