#ifndef CONFIG_H
#define CONFIG_H

// Flash configuration settings. When adding new items always add them at the end and formulate
// them such that a value of zero is an appropriate default or backwards compatible. Existing
// modules that are upgraded will have zero in the new fields. This ensures that an upgrade does
// not wipe out the old settings.
typedef struct {
  uint32_t seq; // flash write sequence number
  uint16_t magic, crc;
  int8_t   reset_pin, isp_pin, conn_led_pin, ser_led_pin;
  int32_t  baud_rate;
  char     hostname[32];               // if using DHCP
  uint32_t staticip, netmask, gateway; // using DHCP if staticip==0
  uint8_t  log_mode;                   // UART log debug mode
  int8_t   swap_uart;                  // swap uart0 to gpio 13&15
  uint8_t  tcp_enable, rssi_enable;    // TCP client settings
  char     api_key[48];                // RSSI submission API key (Grovestreams for now)
  uint32_t nfc_counter;
  char     nfc_url[64], 
           nfc_device_id[48], 
           nfc_device_secret[48];
  char     sys_descr[129];             // system description
  int8_t   rx_pullup;                  // internal pull-up on RX pin
  char     sntp_server[32];
  char     syslog_host[32];
  uint16_t syslog_minheap;               // min. heap to allow queuing
  uint8_t  syslog_filter,                // min. severity
           syslog_showtick,              // show system tick (µs)
           syslog_showdate;              // populate SYSLOG date field
  uint8_t  mdns_enable;
  char     mdns_servername[32];           
  int8_t   timezone_offset;
	bool		 configMode;
} FlashConfig;
extern FlashConfig flashConfig;

bool configSave(void);
bool configRestore(void);
void configWipe(void);
const size_t getFlashSize();

#endif
