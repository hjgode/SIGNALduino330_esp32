// output.h

#ifndef _OUTPUT_h
#define _OUTPUT_h

#ifndef ESP32
  #if defined(ARDUINO) && ARDUINO >= 100
  	#include "arduino.h"
  #else
  	#include "WProgram.h"
  #endif
#endif

#if defined (ETHERNET_PRINT)
    #define MSG_PRINTER Client // Not Implemented at this time
#elif defined (ESP32)
    #include <WiFi.h>
    WiFiClient wifiClient;
    #define MSG_PRINTER wifiClient
    #define MSG_PRINT( ... )   ( wifiClient.print(__VA_ARGS__) )
    #define MSG_PRINTLN( ... ) ( wifiClient.println(__VA_ARGS__) )
#else
    #define MSG_PRINTER Serial
    #define MSG_PRINT( ... )   { Serial.print(__VA_ARGS__) }
    #define MSG_PRINTLN( ... ) { Serial.println(__VA_ARGS__) }
#endif

#ifdef ETHERNET_DEBUG
  #define DBG_PRINTER Client // Not Implemented at this time
#else
  #define DBG_PRINTER Serial
#endif

#define DBG_PRINT( ... ) { DBG_PRINTER.print(__VA_ARGS__); }
#define DBG_PRINTLN( ... ) { DBG_PRINTER.println(__VA_ARGS__); }



#endif

