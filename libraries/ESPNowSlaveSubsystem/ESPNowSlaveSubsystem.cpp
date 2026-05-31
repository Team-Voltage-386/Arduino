/////////////////////////////////////////////////
// Modified from:     ESP-NOW Broadcast Slave / Lucas Saavedra Vaz - 2024
// Modified for:      Team Voltage 386
// Date:              2026/04/26
/////////////////////////////////////////////////
/*
    ESP-NOW Broadcast Slave
    Lucas Saavedra Vaz - 2024

    This sketch demonstrates how to receive broadcast messages from a master device using the ESP-NOW protocol.

    The master device will broadcast a message every 5 seconds to all devices within the network.

    The slave devices will receive the broadcasted messages. If they are not from a known master, they will be registered as a new master
    using a callback function.
*/
#include <ESPNowSlaveSubsystem.h>

// List of all the masters. It will be populated when a new master is registered
// Note: Using pointers instead of objects to prevent dangling pointers when the vector reallocates
std::vector<ESP_NOW_Peer_Class *> masters;

// Callback called when an unknown peer sends a message
void register_new_master(const esp_now_recv_info_t *info, const uint8_t *data, int len, void *arg) {
  if (memcmp(info->des_addr, ESP_NOW.BROADCAST_ADDR, 6) == 0) {
    Serial.printf("Unknown peer " MACSTR " sent a broadcast message\n", MAC2STR(info->src_addr));
    Serial.println("Registering the peer as a master");

    ESP_NOW_Peer_Class *new_master = new ESP_NOW_Peer_Class(info->src_addr, ESPNOW_WIFI_CHANNEL, WIFI_IF_STA, nullptr);
    if (!new_master->add_peer()) {
      Serial.println("Failed to register the new master");
      delete new_master;
      return;
    }
    masters.push_back(new_master);
    Serial.printf("Successfully registered master " MACSTR " (total masters: %lu)\n", MAC2STR(new_master->addr()), (unsigned long)masters.size());
  } else {
    // The slave will only receive broadcast messages
    log_v("Received a unicast message from " MACSTR, MAC2STR(info->src_addr));
    log_v("Igorning the message");
  }
}

ESP_NOW_Peer_Class::ESP_NOW_Peer_Class(const uint8_t *mac_addr, uint8_t channel, wifi_interface_t iface, const uint8_t *lmk) : ESP_NOW_Peer(mac_addr, channel, iface, lmk) {}

// Function to register the master peer
bool ESP_NOW_Peer_Class::add_peer() {
  if (!add()) {
    log_e("Failed to register the broadcast peer");
    return false;
  }
  return true;
}

// Function to print the received messages from the master
void ESP_NOW_Peer_Class::onReceive(const uint8_t *data, size_t len, bool broadcast) {
  Serial.printf("Received a message from master " MACSTR " (%s)\n", MAC2STR(addr()), broadcast ? "broadcast" : "unicast");
  Serial.printf("  Message: %s\n", (char *)data);
  Serial.printf("  Reply  : Voltage!\n");
}

// <<constructor>>
ESPNowSlaveSubsystem::ESPNowSlaveSubsystem()
{
  prevMillis = 0;
  currMillis = 0;
  subsystemInterval = 10000;
}

// Call this in setup() function
void ESPNowSlaveSubsystem::setup() { 
  Serial.begin(115200);

  // Initialize the Wi-Fi module
  WiFi.mode(WIFI_STA);
  WiFi.setChannel(ESPNOW_WIFI_CHANNEL);
  while (!WiFi.STA.started()) {
    delay(100);
  }

  Serial.println("ESP-NOW Example - Broadcast Slave");
  Serial.println("Wi-Fi parameters:");
  Serial.println("  Mode: STA");
  Serial.println("  MAC Address: " + WiFi.macAddress());
  Serial.printf("  Channel: %u\n", ESPNOW_WIFI_CHANNEL);

  // Initialize the ESP-NOW protocol
  if (!ESP_NOW.begin()) {
    Serial.println("Failed to initialize ESP-NOW");
    Serial.println("Reeboting in 5 seconds...");
    delay(5000);
    ESP.restart();
  }

  Serial.printf("ESP-NOW version: %d, max data length: %d\n", ESP_NOW.getVersion(), ESP_NOW.getMaxDataLen());

  // Register the new peer callback
  ESP_NOW.onNewPeer(register_new_master, nullptr);

  Serial.println("Setup complete. Waiting for a master to broadcast a message...");
}

// Call this in loop() function
void ESPNowSlaveSubsystem::loop()
{
  // save the current ms step count
  currMillis = millis();

  // if curr - prev is greater or equal to blink interval, blink
  if (currMillis - prevMillis >= subsystemInterval)
  {
    prevMillis = currMillis;

    Serial.printf("Registered masters: %lu\n", (unsigned long)masters.size());
    for (size_t i = 0; i < masters.size(); i++) {
	  if (masters[i]) {
	    Serial.printf("  Master %lu: " MACSTR "\n", (unsigned long)i, MAC2STR(masters[i]->addr()));
      }
    }    
  }
}
