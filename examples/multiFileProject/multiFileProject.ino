/****************************************************************************************************************************
  multiFileProject.ino

  Dead simple AsyncHTTPRequest for Teensy41 QNEthernet

  For Teensy41 with QNEthernet

  AsyncHTTPRequest_Teensy41 is a library for Teensy41 with QNEthernet

  Based on and modified from

  1. asyncHTTPrequest Library         (https://github.com/boblemaire/asyncHTTPrequest)
  2. AsyncHTTPRequest_Generic Library (https://github.com/khoih-prog/AsyncHTTPRequest_Generic)

  Built by Khoi Hoang https://github.com/khoih-prog/AsyncHTTPRequest_Teensy41
*****************************************************************************************************************************/

// To demo how to include files in multi-file Projects

#if !( defined(CORE_TEENSY) && defined(__IMXRT1062__) && defined(ARDUINO_TEENSY41) )
  #error Only Teensy 4.1 supported
#endif

#define ASYNC_HTTP_REQUEST_TEENSY41_VERSION_MIN_TARGET      "AsyncHTTPRequest_Teensy41 v1.10.0"
#define ASYNC_HTTP_REQUEST_TEENSY41_VERSION_MIN             1010000

// Uncomment for certain HTTP site to optimize
//#define NOT_SEND_HEADER_AFTER_CONNECTED        true

// Level from 0-4
#define ASYNC_HTTP_DEBUG_PORT     Serial
#define _ASYNC_HTTP_LOGLEVEL_     2

// Seconds for timeout, default is 3s
#define DEFAULT_RX_TIMEOUT           10

#include "multiFileProject.h"

// Can be included as many times as necessary, without `Multiple Definitions` Linker Error
#include "AsyncHTTPRequest_Teensy41.h"

void setup()
{
  Serial.begin(115200);

  while (!Serial && millis() < 5000);

  Serial.println("\nStart multiFileProject");
  Serial.println(ASYNC_HTTP_REQUEST_TEENSY41_VERSION);

#if defined(ASYNC_HTTP_REQUEST_TEENSY41_VERSION_MIN)

  if (ASYNC_HTTP_REQUEST_TEENSY41_VERSION_INT < ASYNC_HTTP_REQUEST_TEENSY41_VERSION_MIN)
  {
    Serial.print("Warning. Must use this example on Version equal or later than : ");
    Serial.println(ASYNC_HTTP_REQUEST_TEENSY41_VERSION_MIN_TARGET);
  }

#endif
}

void loop()
{
  // put your main code here, to run repeatedly:
}
