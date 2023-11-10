#include <Arduino.h>
#include <WiFi.h>

#include "ESPAsyncWebServer.h"
#include "SPIFFS.h"

#define LED 2
#define BEEP 5

// put function declarations here:
int myFunction(int, int);
void initWifi();

String beepMessage = "";

const char* ascii_to_morse[] =
    {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.",  // 0...9
        0, 0, 0, 0, 0, 0, 0,
        ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.",
        "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..",  // A...Z
};

AsyncWebServer server(80);

void setup() {
    // put your setup code here, to run once:
    int result = myFunction(2, 3);
    Serial.begin(9600);
    pinMode(LED, OUTPUT);
    pinMode(BEEP, OUTPUT);
    initWifi();

    server.serveStatic("/", SPIFFS, "/data/");

    server.on("^\\/beep\\/([A-Z ]+)$", HTTP_GET, [](AsyncWebServerRequest* request) {
        String message = request->pathArg(0);
        String morse = "";
        // Iterate over chars and convert to morse
        for (int i = 0; i < message.length(); i++) {
            char c = message.charAt(i);
            if (c >= 'A' && c <= 'Z') {
                morse += ascii_to_morse[c];
            } else if (c == ' ') {
                morse += "  ";
            }
            morse += " ";
        }
        beepMessage = morse;
        request->send(200, "text/plain", morse);
    });

    server.begin();
    Serial.println("Setup done");
}

void loop() {
    // Get one char from beepMessage
    if (beepMessage.length() > 0) {
        char c = beepMessage.charAt(0);
        beepMessage = beepMessage.substring(1);
        if (c == '.') {
            digitalWrite(LED, HIGH);
            digitalWrite(BEEP, HIGH);
            delay(100);
            digitalWrite(LED, LOW);
            digitalWrite(BEEP, LOW);
            delay(100);
        } else if (c == '-') {
            digitalWrite(LED, HIGH);
            digitalWrite(BEEP, HIGH);
            delay(300);
            digitalWrite(LED, LOW);
            digitalWrite(BEEP, LOW);
            delay(100);
        } else if (c == ' ') {
            delay(400);
        }
    }
}

// put function definitions here:
int myFunction(int x, int y) {
    return x + y;
}

void initWifi() {
    WiFi.mode(WIFI_STA);
    WiFi.begin("SSID", "PASS");
    Serial.println("Connecting to WiFi...");
    while (WiFi.status() != WL_CONNECTED) {
        Serial.print(".");
        delay(500);
    }
    Serial.println("Connected to the WiFi network");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
}