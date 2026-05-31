/////////////////////////////////////////////////
// Modified from:     ESP-NOW Broadcast Master / Lucas Saavedra Vaz - 2024
// Modified for:      Team Voltage 386
// Date:              2026/04/26
/////////////////////////////////////////////////
/*
    ESP-NOW Broadcast Master
    Lucas Saavedra Vaz - 2024

    This sketch demonstrates how to broadcast messages to all devices within the ESP-NOW network.
    This example is intended to be used with the ESP-NOW Broadcast Slave example.

    The master device will broadcast a message every 5 seconds to all devices within the network.
    This will be done using by registering a peer object with the broadcast address.

    The slave devices will receive the broadcasted messages and print them to the Serial Monitor.
*/
#include <ESPNowMasterSubsystem.h>

ESP_NOW_Broadcast_Peer::ESP_NOW_Broadcast_Peer(uint8_t channel, wifi_interface_t iface, const uint8_t *lmk) : ESP_NOW_Peer(ESP_NOW.BROADCAST_ADDR, channel, iface, lmk) {}

bool ESP_NOW_Broadcast_Peer::begin() {
  if (!ESP_NOW.begin() || !add()) {
     log_e("Failed to initialize ESP-NOW or register the broadcast peer");
     return false;
  }
  return true;   
}

// Function to send a message to all devices within the network
bool ESP_NOW_Broadcast_Peer::send_message(const uint8_t *data, size_t len) {
  if (!send(data, len)) {
     log_e("Failed to broadcast message");
     return false;
  }
  return true;
}

// <<constructor>>
ESPNowMasterSubsystem::ESPNowMasterSubsystem() : broadcast_peer(ESPNOW_WIFI_CHANNEL, WIFI_IF_STA, nullptr)
{
  prevMillis = 0;
  currMillis = 0;
  subsystemInterval = 250;
 
  msg_count = 0;
}

// <<constructor>>
ESPNowMasterSubsystem::ESPNowMasterSubsystem(unsigned long interval) : broadcast_peer(ESPNOW_WIFI_CHANNEL, WIFI_IF_STA, nullptr)
{
  prevMillis = 0;
  currMillis = 0;
  subsystemInterval = interval;
 
  msg_count = 0;
}

// Call this in setup() function
void ESPNowMasterSubsystem::setup() { 
  Serial.begin(115200);

  // Initialize the Wi-Fi module
  WiFi.mode(WIFI_STA);
  WiFi.setChannel(ESPNOW_WIFI_CHANNEL);
  while (!WiFi.STA.started()) {
     delay(100);
  }

  Serial.println("ESP-NOW Example - Broadcast Master");
  Serial.println("Wi-Fi parameters:");
  Serial.println("  Mode: STA");
  Serial.println("  MAC Address: " + WiFi.macAddress());
  Serial.printf("  Channel: %u\n", ESPNOW_WIFI_CHANNEL);

  // Register the broadcast peer
  if (!broadcast_peer.begin()) {
     Serial.println("Failed to initialize broadcast peer");
     Serial.println("Reebooting in 5 seconds...");
     delay(5000);
     ESP.restart();
  }

  Serial.printf("ESP-NOW version: %d, max data length: %d\n", ESP_NOW.getVersion(), ESP_NOW.getMaxDataLen());

  Serial.println("Setup complete. Broadcasting messages every 5 seconds.");
}

// Call this in loop() function
void ESPNowMasterSubsystem::loop()
{
  // save the current ms step count
  currMillis = millis();

  // if curr - prev is greater or equal to blink interval, blink
  if (currMillis - prevMillis >= subsystemInterval)
  {
    prevMillis = currMillis;

    // Broadcast a message to all devices within the network
    char data[32];
    snprintf(data, sizeof(data), "Charge Up! #%" PRIu32, msg_count++);

    Serial.printf("Broadcasting message: %s\n", data);

    if (!broadcast_peer.send_message((uint8_t *)data, sizeof(data))) {
      Serial.println("Failed to broadcast message");
    }
  }
}
