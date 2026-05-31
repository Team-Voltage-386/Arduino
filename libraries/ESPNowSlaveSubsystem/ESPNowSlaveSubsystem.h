/////////////////////////////////////////////////
// Modified from:     ESP-NOW Broadcast Master / Lucas Saavedra Vaz - 2024
// Modified for:      Team Voltage 386
// Date:              2026/04/26
/////////////////////////////////////////////////
#ifndef ESPNOWSLAVESUBSYSTEM_H
#define ESPNOWSLAVESUBSYSTEM_H

#include <Arduino.h>
#include "ESP32_NOW.h"
#include "WiFi.h"
#include <esp_mac.h>  // For the MAC2STR and MACSTR macros
#include <vector>

/* Definitions */
#define ESPNOW_WIFI_CHANNEL 6

// Callback function
void register_new_master(const esp_now_recv_info_t *info, const uint8_t *data, int len, void *arg);

// Creating a new class that inherits from the ESP_NOW_Peer class is required.
class ESP_NOW_Peer_Class : public ESP_NOW_Peer
{
public:
  // Constructor of the class using the broadcast address
  ESP_NOW_Peer_Class(const uint8_t *mac_addr, uint8_t channel, wifi_interface_t iface, const uint8_t *lmk);

  // Function to register the master peer
  bool add_peer();

  // Function to print the received messages from the master
  void onReceive(const uint8_t *data, size_t len, bool broadcast);

};

/* Global Variables */

// List of all the masters. It will be populated when a new master is registered
// Note: Using pointers instead of objects to prevent dangling pointers when the vector reallocates
extern std::vector<ESP_NOW_Peer_Class *> masters;

class ESPNowSlaveSubsystem
{
public:
  ESPNowSlaveSubsystem();
  void setup();
  void loop();

private:
  unsigned long prevMillis;
  unsigned long currMillis;
  unsigned long subsystemInterval;
 
};

#endif
