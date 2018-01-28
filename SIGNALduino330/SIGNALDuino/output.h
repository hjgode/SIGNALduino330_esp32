// output.h

#ifndef _OUTPUT_h
#define _OUTPUT_h
/*
#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
*/
#if defined (ETHERNET_PRINT)
    #define MSG_PRINTER Client // Not Implemented at this time
#elif defined (ESP32)
    #include <WiFi.h>
    extern WiFiClient myWifiClient;
    #define MSG_PRINTER myWifiClient
    #define MSG_PRINT( ... )   ( myWifiClient.print(__VA_ARGS__) )
    #define MSG_PRINTLN( ... ) ( myWifiClient.println(__VA_ARGS__) )
#else
#define MSG_PRINTER Serial
#endif

#ifdef ETHERNET_DEBUG
#define DBG_PRINTER Client // Not Implemented at this time
#else
#define DBG_PRINTER Serial
#endif

#ifndef ESP32
    #define MSG_PRINT(...) { MSG_PRINTER.print(__VA_ARGS__); }
    #define MSG_PRINTLN(...) { MSG_PRINTER.println(__VA_ARGS__); }
#endif
#define DBG_PRINT(...) { DBG_PRINTER.print(__VA_ARGS__); }
#define DBG_PRINTLN(...) { DBG_PRINTER.println(__VA_ARGS__); }



#endif

