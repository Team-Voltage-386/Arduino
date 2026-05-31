/////////////////////////////////////////////////
// Modified from:     ESP-NOW Broadcast Master / Lucas Saavedra Vaz - 2024
// Modified for:      Team Voltage 386
// Date:              2026/04/26
/////////////////////////////////////////////////
#ifndef ESPNOWMASTERSUBSYSTEM_H
#define ESPNOWMASTERSUBSYSTEM_H

#include <Arduino.h>
#include "ESP32_NOW.h"
#include "WiFi.h"
#include <esp_mac.h>  // For the MAC2STR and MACSTR macros

/* Definitions */
#define ESPNOW_WIFI_CHANNEL 6

// Creating a new class that inherits from the ESP_NOW_Peer class is required.

class ESP_NOW_Broadcast_Peer : public ESP_NOW_Peer
{
public:
  // Constructor of the class using the broadcast address
  ESP_NOW_Broadcast_Peer(uint8_t channel, wifi_interface_t iface, const uint8_t *lmk);

  // Function to properly initialize the ESP-NOW and register the broadcast peer
  bool begin();

  // Function to send a message to all devices within the network
  bool send_message(const uint8_t *data, size_t len);
};

class ESPNowMasterSubsystem
{
public:
  ESPNowMasterSubsystem();
  ESPNowMasterSubsystem(unsigned long interval);

  void setup();
  void loop();

private:
  unsigned long prevMillis;
  unsigned long currMillis;
  unsigned long subsystemInterval;

  uint32_t msg_count;
  ESP_NOW_Broadcast_Peer broadcast_peer;
  
};

#endif
