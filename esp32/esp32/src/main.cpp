#include <Arduino.h>
#include <WiFi.h>
#define LED 2

// put function declarations here:
int myFunction(int, int);
void initWifi();

WiFiServer server(80);

void setup() {
    // put your setup code here, to run once:
    int result = myFunction(2, 3);
    Serial.begin(9600);
    pinMode(LED, OUTPUT);
    initWifi();
    server.begin();
    Serial.println("Setup done");
}

void loop() {
    WiFiClient client = server.available();

    // Check request path
    if (client) {
        Serial.println("New client");
        // Print request path
        Serial.println(client.readStringUntil('\r'));

        // Answer with "Hello World"
        client.println("HTTP/1.1 200 OK");
        client.println("Content-type:text/html");
        client.println();
        client.println("<h1>Hello World</h1>");
        client.println("<p>Test</p>");
        client.println("<p>Test</p>");
        // End
        client.stop();
    }

    Serial.println("Hallo äöß");
    digitalWrite(LED, HIGH);
    delay(50);
    digitalWrite(LED, LOW);
    delay(50);
}

// put function definitions here:
int myFunction(int x, int y) {
    return x + y;
}

void initWifi() {
    WiFi.mode(WIFI_STA);
    WiFi.begin("HTLGuest", "5BHIF012345");
    Serial.println("Connecting to WiFi...");
    while (WiFi.status() != WL_CONNECTED) {
        Serial.print(".");
        delay(500);
    }
    Serial.println("Connected to the WiFi network");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
}