/****************************************************************************************************************************
  AsyncSimpleGET.ino - Dead simple AsyncHTTPRequest for Teensy41 QNEthernet

  For Teensy41 with QNEthernet

  AsyncHTTPRequest_Teensy41 is a library for Teensy41 with QNEthernet

  Based on and modified from

  1. asyncHTTPrequest Library         (https://github.com/boblemaire/asyncHTTPrequest)
  2. AsyncHTTPRequest_Generic Library (https://github.com/khoih-prog/AsyncHTTPRequest_Generic)

  Built by Khoi Hoang https://github.com/khoih-prog/AsyncHTTPRequest_Teensy41
 *****************************************************************************************************************************/

#include "defines.h"

// Select a test server address
//char GET_ServerAddress[]    = "ipv4bot.whatismyipaddress.com/";
char GET_ServerAddress[]    = "http://worldtimeapi.org/api/timezone/America/Toronto.txt";

#define ASYNC_HTTP_REQUEST_TEENSY41_VERSION_MIN_TARGET      "AsyncHTTPRequest_Teensy41 v1.10.0"
#define ASYNC_HTTP_REQUEST_TEENSY41_VERSION_MIN             1010000

// Uncomment for certain HTTP site to optimize
//#define NOT_SEND_HEADER_AFTER_CONNECTED        true

// Level from 0-4
#define ASYNC_HTTP_DEBUG_PORT     Serial
#define _ASYNC_HTTP_LOGLEVEL_     2

// 600s = 10 minutes to not flooding, 60s in testing
#define HTTP_REQUEST_INTERVAL_MS     60000  //600000

// Seconds for timeout, default is 3s
#define DEFAULT_RX_TIMEOUT           10

// To be included only in main(), .ino with setup() to avoid `Multiple Definitions` Linker Error
#include <AsyncHTTPRequest_Teensy41.h>             // https://github.com/khoih-prog/AsyncHTTPRequest_Teensy41

#include <Ticker.h>                             // https://github.com/sstaub/Ticker

AsyncHTTPRequest request;

void sendRequest();

// Repeat forever, millis() resolution
Ticker sendHTTPRequest(sendRequest, HTTP_REQUEST_INTERVAL_MS, 0, MILLIS);

void sendRequest()
{
  static bool requestOpenResult;

  if (request.readyState() == readyStateUnsent || request.readyState() == readyStateDone)
  {
    requestOpenResult = request.open("GET", GET_ServerAddress);

    if (requestOpenResult)
    {
      // Only send() if open() returns true, or crash
      request.send();
    }
    else
    {
      Serial.println("Can't send bad request");
    }
  }
  else
  {
    Serial.println("Can't send request");
  }
}

void requestCB(void *optParm, AsyncHTTPRequest *request, int readyState)
{
  (void) optParm;

  if (readyState == readyStateDone)
  {
    AHTTP_LOGDEBUG(F("\n**************************************"));
    AHTTP_LOGDEBUG1(F("Response Code = "), request->responseHTTPString());

    if (request->responseHTTPcode() == 200)
    {
      Serial.println(F("\n**************************************"));
      Serial.println(request->responseText());
      Serial.println(F("**************************************"));
    }
  }
}

void setup()
{
  Serial.begin(115200);

  while (!Serial && millis() < 5000);

  Serial.print("\nStart AsyncSimpleGET on ");
  Serial.println(BOARD_NAME);
  Serial.println(ASYNC_HTTP_REQUEST_TEENSY41_VERSION);

#if defined(ASYNC_HTTP_REQUEST_TEENSY41_VERSION_MIN)

  if (ASYNC_HTTP_REQUEST_TEENSY41_VERSION_INT < ASYNC_HTTP_REQUEST_TEENSY41_VERSION_MIN)
  {
    Serial.print("Warning. Must use this example on Version equal or later than : ");
    Serial.println(ASYNC_HTTP_REQUEST_TEENSY41_VERSION_MIN_TARGET);
  }

#endif

  delay(500);

#if USING_DHCP
  // Start the Ethernet connection, using DHCP
  Serial.print("Initialize Ethernet using DHCP => ");
  Ethernet.begin();
#else
  // Start the Ethernet connection, using static IP
  Serial.print("Initialize Ethernet using static IP => ");
  Ethernet.begin(myIP, myNetmask, myGW);
  Ethernet.setDNSServerIP(mydnsServer);
#endif

  if (!Ethernet.waitForLocalIP(5000))
  {
    Serial.println(F("Failed to configure Ethernet"));

    if (!Ethernet.linkStatus())
    {
      Serial.println(F("Ethernet cable is not connected."));
    }

    // Stay here forever
    while (true)
    {
      delay(1);
    }
  }
  else
  {
    Serial.print(F("Connected! IP address:"));
    Serial.println(Ethernet.localIP());
  }

#if USING_DHCP
  delay(1000);
#else
  delay(2000);
#endif

  request.setDebug(false);

  request.onReadyStateChange(requestCB);
  sendHTTPRequest.start(); //start the ticker.

  // Send first request now
  delay(10000);
  sendRequest();
}

void loop()
{
  sendHTTPRequest.update();
}
