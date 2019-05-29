/*
 * 
 * Configuration file
 * 
 */


#ifndef NodeDefinitions_h
#define NodeDefinitions_h

/*  *******************************************************************************************
 *                            MySensors Definitions
 *  *******************************************************************************************/
// Identification
#define MY_NODE_ID 102
#define SN "RS485 Unified Firmware"
#define SV "1.0"

// Selecting radio type and transmission settings
#define RS485_NODE
#ifdef RS485_NODE
  #define MY_RS485                              // Enable RS485 transport layer
  #define MY_RS485_DE_PIN 7                     // DE Pin definition
  #define MY_RS485_BAUD_RATE 57600              // Set RS485 baud rate to use
  #define MY_RS485_HWSERIAL Serial              // Enable for Hardware Serial
  #define MY_RS485_SOH_COUNT 3                  // Collision avoidance
#endif

// FOTA Feature
#define MY_OTA_FIRMWARE_FEATURE
//#define MY_OTA_FLASH_SS 10
//#define OTA_WAIT_PERIOD 300

// Other
#define MY_TRANSPORT_WAIT_READY_MS 60000      // Time to wait for gateway to respond at startup
//#define MY_REPEATER_FEATURE                 // Enable repeater functionality for this node (wireless only)

/*  *******************************************************************************************
 *                                   MCU Pin Definitions
 *  *******************************************************************************************/
// OUTPUT [RELAY / RGBW]
#define OUTPUT_PIN_1 5
#define OUTPUT_PIN_2 9
#define OUTPUT_PIN_3 6
#define OUTPUT_PIN_4 10

// INPUT [BUTTON / SENSOR]
// General input
#define INPUT_PIN_1 2
#define INPUT_PIN_2 3
#define INPUT_PIN_3 4
#define INPUT_PIN_4 A3

// Analog input
#define INPUT_PIN_5 A0
#define INPUT_PIN_6 A1
#define INPUT_PIN_7 A2
#define INPUT_PIN_8 A7

// Protocols
// 1-wire
#define ONE_WIRE_PIN A6

// I2C
#define I2C_PIN_1 A4
#define I2C_PIN_2 A5

/*  *******************************************************************************************
 *                           Custom Libraries Definitions
 *  *******************************************************************************************/
#define RELAY_ON HIGH
#define RELAY_OFF LOW
#define MAX_TEMPERATURE 85                  // Maximum temperature a module can achieve before reporting error
#define MAX_CURRENT 3                       // 2SSR - 3; 4RelayDin - 10 [A]
#define POWER_MEASURING_TIME 100
#define DIMMING_STEP 1
#define DIMMING_INTERVAL 20            

/*  *******************************************************************************************
 *                                   OUTPUT Config
 *  *******************************************************************************************/
// 2SSR Single relay 
//#define SINGLE_RELAY
#ifdef SINGLE_RELAY
	#define RELAY_ID_1 0
	#define RELAY_1 OUTPUT_PIN_1
	#define BUTTON_1 INPUT_PIN_1
	#define NUMBER_OF_RELAYS 1
#endif

// 2SSR DOUBLE_RELAY / Roller Shutter
#define DOUBLE_RELAY
#ifdef DOUBLE_RELAY
	#define RELAY_ID_1 0
	#define RELAY_ID_2 1
	#define RELAY_1 OUTPUT_PIN_1
	#define RELAY_2 OUTPUT_PIN_2
	#define BUTTON_1 INPUT_PIN_1
	#define BUTTON_2 INPUT_PIN_2
	#define NUMBER_OF_RELAYS 2
#endif

//#define ROLLER_SHUTTER
#ifdef ROLLER_SHUTTER
  #define RS_ID 0
  #define RELAY_ID_1 0
  #define RELAY_1 OUTPUT_PIN_1
  #define RELAY_2 OUTPUT_PIN_2
  #define BUTTON_1 INPUT_PIN_1
  #define BUTTON_2 INPUT_PIN_2
  #define NUMBER_OF_RELAYS 2
#endif

// 4RelayDin 4 Relay Output
//#define FOUR_RELAY
#ifdef FOUR_RELAY
	#define RELAY_ID_1 0
	#define RELAY_ID_2 1
	#define RELAY_ID_3 2
	#define RELAY_ID_4 3
	#define RELAY_1 OUTPUT_PIN_1
	#define RELAY_2 OUTPUT_PIN_2
	#define RELAY_3 OUTPUT_PIN_3
	#define RELAY_4 OUTPUT_PIN_4
	#define NUMBER_OF_RELAYS 4
#endif

// Dimmer / RGB / RGBW
//#define DIMMER
#ifdef DIMMER
  #define DIMMER_ID 0
  #define LED_PIN_1 OUTPUT_PIN_1
  #define NUMBER_OF_CHANNELS 1
#endif

//#define RGB
#ifdef RGB
  #define DIMMER_ID 0
  #define LED_PIN_1 OUTPUT_PIN_1
  #define LED_PIN_2 OUTPUT_PIN_2
  #define LED_PIN_3 OUTPUT_PIN_3
  #define NUMBER_OF_CHANNELS 3
#endif

//#define RGBW
#ifdef RGBW
  #define DIMMER_ID 0
  #define LED_PIN_1 OUTPUT_PIN_1
  #define LED_PIN_2 OUTPUT_PIN_2
  #define LED_PIN_3 OUTPUT_PIN_3
  #define LED_PIN_4 OUTPUT_PIN_4
  #define NUMBER_OF_CHANNELS 4
#endif

/*  *******************************************************************************************
 *                                   INPUT Config
 *  *******************************************************************************************/
// Digital input
//#define INPUT_1
#ifdef INPUT_1
	#define INPUT_ID_1 4
	#define PIN_1 INPUT_PIN_3
	#define PULLUP_1
	#define NUMBER_OF_INPUTS 1
#endif

//#define INPUT_2
#ifdef INPUT_2
	#define INPUT_ID_2 INPUT_ID_1+1
	#define PIN_2 INPUT_PIN_4
	#define PULLUP_2
	#define NUMBER_OF_INPUTS 2
#endif

//#define INPUT_3
#ifdef INPUT_3
  #define INPUT_ID_3 INPUT_ID_2+1
  #define PIN_3 INPUT_PIN_6
  #define PULLUP_3
	#define NUMBER_OF_INPUTS 3
#endif

//#define INPUT_4
#define INPUT_ID_4 INPUT_ID_3+1
#define PIN_4 INPUT_PIN_7
#define PULLUP_4
#ifdef INPUT_4
	#define NUMBER_OF_INPUTS 4
#endif

#if defined(NUMBER_OF_RELAYS) && !defined(NUMBER_OF_INPUTS)
  #define UI_SENSORS_NUMBER NUMBER_OF_RELAYS
#elif defined(NUMBER_OF_RELAYS) && defined(NUMBER_OF_INPUTS)
  #define UI_SENSORS_NUMBER NUMBER_OF_RELAYS+NUMBER_OF_INPUTS
#elif !defined(NUMBER_OF_RELAYS) && defined(INPUT_1)
  #define UI_SENSORS_NUMBER NUMBER_OF_INPUTS
#endif

// Special Button
#if defined(SINGLE_RELAY) || defined(DOUBLE_RELAY) || defined(ROLLER_SHUTTER)
	#define SPECIAL_BUTTON
	#define SPECIAL_BUTTON_ID 8
#endif
 
// ACS712 Power Sensor
#define POWER_SENSOR
#if defined(POWER_SENSOR) && !defined(FOUR_RELAY)
  #define PS_ID 9
  #define PS_PIN INPUT_PIN_5
#elif defined(POWER_SENSOR) && defined(FOUR_RELAY)
  #define PS_ID_1 4
  #define PS_ID_2 5
  #define PS_ID_3 6
  #define PS_ID_4 7
  #define PS_PIN_1 INPUT_PIN_5
  #define PS_PIN_2 INPUT_PIN_8
  #define PS_PIN_3 I2C_PIN_1
  #define PS_PIN_4 I2C_PIN_2
#endif

// Analog Internal Thermometer (Disable for 4RelayDin)
#define INTERNAL_TEMP
#ifdef INTERNAL_TEMP
	#define IT_ID 10
	#define IT_PIN INPUT_PIN_8
#endif

// 1wire external thermometer (e.g. DHT22)
//#define EXTERNAL_TEMP
#ifdef EXTERNAL_TEMP
	#define ETT_ID 11
	#define ETH_ID 12
	#define ET_PIN ONE_WIRE_PIN
#endif

// I2C 



/*  *******************************************************************************************
 *                                   ERROR REPORTING
 *  *******************************************************************************************/
#define ERROR_REPORTING
#ifdef ERROR_REPORTING
	#ifdef POWER_SENSOR
		#define ES_ID 13
	#endif
	#ifdef INTERNAL_TEMP
		#define TS_ID 14
	#endif
	#ifdef EXTERNAL_TEMP
		#define ETS_ID 15
	#endif
#endif

#define MY_DEBUG
#ifdef MY_DEBUG
	#define DEBUG_ID 16
#endif

/*  *******************************************************************************************
 *                                  EEPROM Definitions
 *  *******************************************************************************************/
#define SIZE_OF_INT 2
#define EEPROM_OFFSET 512                   // First eeprom address to use (MySensors uses prior addresses)
#define EEA_RS_TIME_DOWN EEPROM_OFFSET      // EEPROM address to save RShutter travel down time
#define EEA_RS_TIME_UP EEA_RS_TIME_DOWN+SIZE_OF_INT   // EEPROM address to save RShutter travel up time
#define EEA_RS_POSITION EEA_RS_TIME_UP+SIZE_OF_INT    // EEPROM address to save RShutter last known position


/*  *******************************************************************************************
 *                                  Other Definitions
 *  *******************************************************************************************/
// Heating system section thermometer
//#define HEATING_SECTION_SENSOR
#ifdef HEATING_SECTION_SENSOR
	#define MY_HEATING_CONTROLLER 1
#endif

#define INTERVAL 300000                     // Interval value for reporting certain sensors
#define LOOP_TIME 100                       // Main loop wait time


#endif
/*
 * 
 * EOF
 * 
 */