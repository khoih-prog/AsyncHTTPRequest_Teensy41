# AsyncHTTPRequest_Teensy41

[![arduino-library-badge](https://www.ardu-badge.com/badge/AsyncHTTPRequest_Teensy41.svg?)](https://www.ardu-badge.com/AsyncHTTPRequest_Teensy41)
[![GitHub release](https://img.shields.io/github/release/khoih-prog/AsyncHTTPRequest_Teensy41.svg)](https://github.com/khoih-prog/AsyncHTTPRequest_Teensy41/releases)
[![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat)](#Contributing)
[![GitHub issues](https://img.shields.io/github/issues/khoih-prog/AsyncHTTPRequest_Teensy41.svg)](http://github.com/khoih-prog/AsyncHTTPRequest_Teensy41/issues)

<a href="https://www.buymeacoffee.com/khoihprog6" title="Donate to my libraries using BuyMeACoffee"><img src="https://cdn.buymeacoffee.com/buttons/v2/default-yellow.png" alt="Donate to my libraries using BuyMeACoffee" style="height: 50px !important;width: 181px !important;" ></a>
<a href="https://www.buymeacoffee.com/khoihprog6" title="Donate to my libraries using BuyMeACoffee"><img src="https://img.shields.io/badge/buy%20me%20a%20coffee-donate-orange.svg?logo=buy-me-a-coffee&logoColor=FFDD00" style="height: 20px !important;width: 200px !important;" ></a>

---
---

## Table of Contents

* [Why do we need the new Async AsyncHTTPRequest_Teensy41 library](#why-do-we-need-this-async-AsyncHTTPRequest_Teensy41-library)
  * [Features](#features)
  * [Supports](#supports)
  * [Principles of operation](#principles-of-operation)
  * [Currently supported Boards](#currently-supported-boards)
* [Changelog](changelog.md)
* [Prerequisites](#prerequisites)
* [Installation](#installation)
  * [Use Arduino Library Manager](#use-arduino-library-manager)
  * [Manual Install](#manual-install)
  * [VS Code & PlatformIO](#vs-code--platformio)
* [Packages' Patches](#packages-patches)
  * [1. For Teensy boards](#1-for-teensy-boards)
* [HOWTO Fix `Multiple Definitions` Linker Error](#howto-fix-multiple-definitions-linker-error)
* [Examples](#examples)
  * [1. AsyncCustomHeader](examples/AsyncCustomHeader)
  * [2. AsyncDweetGet](examples/AsyncDweetGet)
  * [3. AsyncDweetPost](examples/AsyncDweetPost)
  * [4. AsyncHTTPRequest](examples/AsyncHTTPRequest)
  * [5. AsyncSimpleGET](examples/AsyncSimpleGET)
  * [6. multiFileProject](examples/multiFileProject)
* [Example AsyncHTTPRequest](#example-asynchttprequest)
  * [1. File AsyncHTTPRequest.ino](#1-file-asynchttprequestino)
  * [2. File defines.h](#2-file-definesh) 
* [Debug Terminal Ouput Samples](#Debug-Terminal-Ouput-Samples)
  * [1. AsyncHTTPRequest on TEENSY 4.1](#1-AsyncHTTPRequest-on-TEENSY-41)
  * [2. AsyncCustomHeader on TEENSY 4.1](#2-AsyncCustomHeader-on-TEENSY-41)
  * [3. AsyncDweetGET on TEENSY 4.1](#3-AsyncDweetGET-on-TEENSY-41)
  * [4. AsyncDweetPOST on TEENSY 4.1](#4-AsyncDweetPOST-on-TEENSY-41)
  * [5. AsyncSimpleGET on TEENSY 4.1](#5-AsyncSimpleGET-on-TEENSY-41)
* [Debug](#debug)
* [Troubleshooting](#troubleshooting)
* [Issues](#issues)
* [TO DO](#to-do)
* [DONE](#done)
* [Contributions and Thanks](#contributions-and-thanks)
* [Contributing](#contributing)
* [License and credits](#license-and-credits)
* [Copyright](#copyright)

---
---


## Why do we need this Async [AsyncHTTPRequest_Teensy41 library](https://github.com/khoih-prog/AsyncHTTPRequest_Teensy41)

### Features

1. Asynchronous HTTP Request library for **Teensy 4.1 using built-in QNEthernet**
2. Providing a subset of HTTP.
3. Relying on [`Teensy41_AsyncTCP library`](https://github.com/khoih-prog/Teensy41_AsyncTCP)
4. Methods similar in format and usage to XmlHTTPrequest in Javascript.

### Supports

1. **GET, POST, PUT, PATCH, DELETE and HEAD**
2. Request and response headers
3. Chunked response
4. Single String response for short (<~5K) responses (heap permitting).
5. Optional onData callback.
6. Optional onReadyStatechange callback.

### Principles of operation

This library adds a simple HTTP layer on top of the [`Teensy41_AsyncTCP library`](https://github.com/khoih-prog/Teensy41_AsyncTCP) to **facilitate REST communication from a Client to a Server**. The paradigm is similar to the `XMLHttpRequest` in Javascript, employing the notion of a ready-state progression through the transaction request.

**Synchronization can be accomplished using callbacks on ready-state change, a callback on data receipt, or simply polling for ready-state change**. Data retrieval can be incremental as received, or bulk retrieved when the transaction completes provided there is enough heap to buffer the entire response.

The underlying buffering uses a new `xbuf` class. It handles both character and binary data. Class `xbuf` uses a chain of small (64 byte) segments that are allocated and added to the tail as data is added and de-allocated from the head as data is read, achieving the same result as a dynamic circular buffer, limited only by the size of heap. The `xbuf` implements `indexOf` and `readUntil` functions.

For short transactions, buffer space should not be an issue. In fact, it can be more economical than other methods that use larger fixed length buffers. Data is acked when retrieved by the caller, so there is some limited flow control to limit heap usage for larger transfers.

Request and response headers are handled in the typical fashion.

`Chunked responses` are recognized and handled `transparently`.

This library is based on, modified from:

1. [Bob Lemaire's asyncHTTPrequest Library](https://github.com/boblemaire/asyncHTTPrequest)

---

### Currently Supported Boards

1. **Teensy 4.1 using QNEthernet Library**

---
---

## Prerequisites

 1. [`Arduino IDE 1.8.19+` for Arduino](https://github.com/arduino/Arduino). [![GitHub release](https://img.shields.io/github/release/arduino/Arduino.svg)](https://github.com/arduino/Arduino/releases/latest)
 2. [`Teensy core v1.57+`](https://www.pjrc.com/teensy/td_download.html) for Teensy 4.1
 3. [`QNEthernet Library version v0.16.0+`](https://github.com/ssilverman/QNEthernet) for Teensy 4.1 built-in Ethernet.
 4. [`Teensy41_AsyncTCP library v1.1.0+`](https://github.com/khoih-prog/Teensy41_AsyncTCP) to use **Teensy 4.1 using QNEthernet Library**. To install, check [![arduino-library-badge](https://www.ardu-badge.com/badge/Teensy41_AsyncTCP.svg?)](https://www.ardu-badge.com/Teensy41_AsyncTCP)

---
---

## Installation

### Use Arduino Library Manager
The best and easiest way is to use `Arduino Library Manager`. Search for `AsyncHTTPRequest_Teensy41`, then select / install the latest version. You can also use this link [![arduino-library-badge](https://www.ardu-badge.com/badge/AsyncHTTPRequest_Teensy41.svg?)](https://www.ardu-badge.com/AsyncHTTPRequest_Teensy41) for more detailed instructions.

### Manual Install

1. Navigate to [AsyncHTTPRequest_Teensy41](https://github.com/khoih-prog/AsyncHTTPRequest_Teensy41) page.
2. Download the latest release `AsyncHTTPRequest_Teensy41-main.zip`.
3. Extract the zip file to `AsyncHTTPRequest_Teensy41-main` directory 
4. Copy the whole `AsyncHTTPRequest_Teensy41-main` folder to Arduino libraries' directory such as `~/Arduino/libraries/`.

### VS Code & PlatformIO

1. Install [VS Code](https://code.visualstudio.com/)
2. Install [PlatformIO](https://platformio.org/platformio-ide)
3. Install [**AsyncHTTPRequest_Teensy41** library](https://registry.platformio.org/libraries/khoih-prog/AsyncHTTPRequest_Teensy41) by using [Library Manager](https://registry.platformio.org/libraries/khoih-prog/AsyncHTTPRequest_Teensy41/installation). Search for AsyncHTTPRequest_Teensy41 in [Platform.io Author's Libraries](https://platformio.org/lib/search?query=author:%22Khoi%20Hoang%22)
4. Use included [platformio.ini](platformio/platformio.ini) file from examples to ensure that all dependent libraries will installed automatically. Please visit documentation for the other options and examples at [Project Configuration File](https://docs.platformio.org/page/projectconf.html)

---
---

### Packages' Patches

#### 1. For Teensy boards
 
 **To be able to compile and run on Teensy boards**, you have to copy the files in [**Packages_Patches for Teensy directory**](Packages_Patches/hardware/teensy/avr) into Teensy hardware directory (./arduino-1.8.19/hardware/teensy/avr/boards.txt). 

Supposing the Arduino version is 1.8.19. These files must be copied into the directory:

- `./arduino-1.8.19/hardware/teensy/avr/boards.txt`
- `./arduino-1.8.19/hardware/teensy/avr/cores/teensy/Stream.h`
- `./arduino-1.8.19/hardware/teensy/avr/cores/teensy3/Stream.h`
- `./arduino-1.8.19/hardware/teensy/avr/cores/teensy4/Stream.h`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
These files must be copied into the directory:

- `./arduino-x.yy.zz/hardware/teensy/avr/boards.txt`
- `./arduino-x.yy.zz/hardware/teensy/avr/cores/teensy/Stream.h`
- `./arduino-x.yy.zz/hardware/teensy/avr/cores/teensy3/Stream.h`
- `./arduino-x.yy.zz/hardware/teensy/avr/cores/teensy4/Stream.h`

---
---

### HOWTO Fix `Multiple Definitions` Linker Error

The current library implementation, using `xyz-Impl.h` instead of standard `xyz.cpp`, possibly creates certain `Multiple Definitions` Linker error in certain use cases.

You can include this `.hpp` file

```cpp
// Can be included as many times as necessary, without `Multiple Definitions` Linker Error
#include "AsyncHTTPRequest_Teensy41.hpp"     //https://github.com/khoih-prog/AsyncHTTPRequest_Teensy41
```

in many files. But be sure to use the following `.h` file **in just 1 `.h`, `.cpp` or `.ino` file**, which must **not be included in any other file**, to avoid `Multiple Definitions` Linker Error

```cpp
// To be included only in main(), .ino with setup() to avoid `Multiple Definitions` Linker Error
#include "AsyncHTTPRequest_Teensy41.h"           //https://github.com/khoih-prog/AsyncHTTPRequest_Teensy41
```

Check the new [**multiFileProject** example](examples/multiFileProject) for a `HOWTO` demo.

Have a look at the discussion in [Different behaviour using the src_cpp or src_h lib #80](https://github.com/khoih-prog/ESPAsync_WiFiManager/discussions/80)


---
---


### Examples

 1. [AsyncCustomHeader](examples/AsyncCustomHeader)
 2. [AsyncDweetGet](examples/AsyncDweetGet)
 3. [AsyncDweetPost](examples/AsyncDweetPost)
 4. [AsyncHTTPRequest](examples/AsyncHTTPRequest)
 5. [AsyncSimpleGET](examples/AsyncSimpleGET)
 6. [multiFileProject](examples/multiFileProject)


---

### Example [AsyncHTTPRequest](examples/AsyncHTTPRequest)

#### 1. File [AsyncHTTPRequest.ino](examples/AsyncHTTPRequest/AsyncHTTPRequest.ino)

https://github.com/khoih-prog/AsyncHTTPRequest_Teensy41/blob/558ddadd9345b15f35a53fa6048dbaeb101f3d11/examples/AsyncHTTPRequest/AsyncHTTPRequest.ino#L38-L184


---

#### 2. File [defines.h](examples/AsyncHTTPRequest/defines.h)

https://github.com/khoih-prog/AsyncHTTPRequest_Teensy41/blob/558ddadd9345b15f35a53fa6048dbaeb101f3d11/examples/AsyncHTTPRequest/defines.h#L16-L50


---
---



### Debug Terminal Ouput Samples


#### 1. [AsyncHTTPRequest](examples/AsyncHTTPRequest) on TEENSY 4.1


```
Start AsyncHTTPRequest on TEENSY 4.1
AsyncHTTPRequest_Teensy41 v1.9.2
Initialize Ethernet using DHCP => Connected! IP address:192.168.2.107

**************************************
abbreviation: EST
client_ip: aaa.bbb.ccc.ddd
datetime: 2022-11-10T13:30:13.641964-05:00
day_of_week: 4
day_of_year: 314
dst: false
dst_from: 
dst_offset: 0
dst_until: 
raw_offset: -18000
timezone: America/Toronto
unixtime: 1668105013
utc_datetime: 2022-11-10T18:30:13.641964+00:00
utc_offset: -05:00
week_number: 45
**************************************

**************************************
abbreviation: EST
client_ip: aaa.bbb.ccc.ddd
datetime: 2022-11-10T13:30:23.988273-05:00
day_of_week: 4
day_of_year: 314
dst: false
dst_from: 
dst_offset: 0
dst_until: 
raw_offset: -18000
timezone: America/Toronto
unixtime: 1668105023
utc_datetime: 2022-11-10T18:30:23.988273+00:00
utc_offset: -05:00
week_number: 45
**************************************
```

---

#### 2. [AsyncCustomHeader](examples/AsyncCustomHeader) on TEENSY 4.1


```
Start AsyncCustomHeader on TEENSY 4.1
AsyncHTTPRequest_Teensy41 v1.9.2
Initialize Ethernet using DHCP => Connected! IP address:192.168.2.107

Sending GET Request to http://worldtimeapi.org/api/timezone/America/Toronto.txt

**************************************
abbreviation: EST
client_ip: aaa.bbb.ccc.ddd
datetime: 2022-11-10T13:30:34.026965-05:00
day_of_week: 4
day_of_year: 314
dst: false
dst_from: 
dst_offset: 0
dst_until: 
raw_offset: -18000
timezone: America/Toronto
unixtime: 1668105034
utc_datetime: 2022-11-10T18:30:34.026965+00:00
utc_offset: -05:00
week_number: 45
**************************************

Sending GET Request to http://worldtimeapi.org/api/timezone/America/Toronto.txt

**************************************
abbreviation: EST
client_ip: aaa.bbb.ccc.ddd
datetime: 2022-11-10T13:30:43.989930-05:00
day_of_week: 4
day_of_year: 314
dst: false
dst_from: 
dst_offset: 0
dst_until: 
raw_offset: -18000
timezone: America/Toronto
unixtime: 1668105043
utc_datetime: 2022-11-10T18:30:43.989930+00:00
utc_offset: -05:00
week_number: 45
**************************************
```


---

#### 3. [AsyncDweetGET](examples/AsyncDweetGET) on TEENSY 4.1

```
Start AsyncDweetGET on TEENSY 4.1
AsyncHTTPRequest_Teensy41 v1.9.2
Initialize Ethernet using DHCP => Connected! IP address:192.168.2.107

**************************************
{"this":"succeeded","by":"dweeting","the":"dweet","with":{"thing":"currentSecond","created":"2022-03-18T19:51:49.407Z","content":{"second":66},"transaction":"4dcdcae9-ace0-4767-86d0-6b830fd3fc05"}}
**************************************
"second":66
Value string: 66
Actual value: 66
```

---

#### 4. [AsyncDweetPOST](examples/AsyncDweetPOST) on TEENSY 4.1

```
Start AsyncDweetPOST on TEENSY 4.1
AsyncHTTPRequest_Teensy41 v1.9.2
Initialize Ethernet using DHCP => Connected! IP address:192.168.2.107

Making new POST request

**************************************
{"this":"succeeded","by":"dweeting","the":"dweet","with":{"thing":"pinA0-Read","created":"2022-03-18T19:57:17.768Z","content":{"sensorValue":1007},"transaction":"76940001-4d31-4995-a712-189d9d874cb1"}}
**************************************
"sensorValue":1007
Value string: 1007
Actual value: 1007
```

---

#### 5. [AsyncSimpleGET](examples/AsyncSimpleGET) on TEENSY 4.1


```
Start AsyncSimpleGET on TEENSY 4.1
AsyncHTTPRequest_Teensy41 v1.9.2
Initialize Ethernet using DHCP => Connected! IP address:192.168.2.107

**************************************
abbreviation: EST
client_ip: aaa.bbb.ccc.ddd
datetime: 2022-11-10T13:31:03.990079-05:00
day_of_week: 4
day_of_year: 314
dst: false
dst_from: 
dst_offset: 0
dst_until: 
raw_offset: -18000
timezone: America/Toronto
unixtime: 1668105063
utc_datetime: 2022-11-10T18:31:03.990079+00:00
utc_offset: -05:00
week_number: 45
**************************************

**************************************
abbreviation: EST
client_ip: aaa.bbb.ccc.ddd
datetime: 2022-11-10T13:31:14.045606-05:00
day_of_week: 4
day_of_year: 314
dst: false
dst_from: 
dst_offset: 0
dst_until: 
raw_offset: -18000
timezone: America/Toronto
unixtime: 1668105074
utc_datetime: 2022-11-10T18:31:14.045606+00:00
utc_offset: -05:00
week_number: 45
**************************************
```


---
---

### Debug

Debug is enabled by default on Serial.

You can also change the debugging level from 0 to 4

```cpp
#define ASYNC_HTTP_DEBUG_PORT           Serial

// Use from 0 to 4. Higher number, more debugging messages and memory usage.
#define _ASYNC_HTTP_LOGLEVEL_           1
```

---

### Troubleshooting

If you get compilation errors, more often than not, you may need to install a newer version of the `ESP32 / ESP8266 / STM32` core for Arduino.

Sometimes, the library will only work if you update the `Teensy` core to the latest version because I am using newly added functions.

---

### Issues ###

Submit issues to: [AsyncHTTPRequest_Teensy41 issues](https://github.com/khoih-prog/AsyncHTTPRequest_Teensy41/issues)

---

## TO DO

 1. Fix bug. Add enhancement
 2. Add many more examples.


## DONE

 1. Initial porting and coding for **Teensy 4.1 using built-in QNEthernet**
 2. Add debugging features.
 3. Add PUT, PATCH, DELETE and HEAD besides GET and POST.
 4. Optimize library code by using `reference-passing` instead of `value-passing`
 5. Fix long timeout if using `IPAddress`
 6. Display only successful responseText in examples
 7. Improve debug messages by adding functions to display error messages instead of `cryptic error number`
 8. Not try to reconnect to the same `host:port` after connected
 9. Fix bug of wrong `reqStates`
10. Default to reconnect to the same `host:port` after connected for new HTTP sites.
11. Use `allman astyle` and add `utils`

---
---

### Contributions and Thanks

This library is based on, modified, bug-fixed and improved from:

1. [Bob Lemaire's **asyncHTTPrequest Library**](https://github.com/boblemaire/asyncHTTPrequest) to use the better **asynchronous** features of these following Async TCP Libraries : ( [`ESPAsyncTCP`](https://github.com/me-no-dev/ESPAsyncTCP), [`AsyncTCP`](https://github.com/me-no-dev/AsyncTCP), and [`Teensy41_AsyncTCP`](https://github.com/khoih-prog/Teensy41_AsyncTCP) )


<table>
  <tr>
    <td align="center"><a href="https://github.com/boblemaire"><img src="https://github.com/boblemaire.png" width="100px;" alt="boblemaire"/><br /><sub><b>⭐️ Bob Lemaire</b></sub></a><br /></td>
  </tr>
</table>

---

### Contributing

If you want to contribute to this project:

- Report bugs and errors
- Ask for enhancements
- Create issues and pull requests
- Tell other people about this library

---

### License and credits ###

- The library is licensed under [GPLv3](https://github.com/khoih-prog/AsyncHTTPRequest_Teensy41/blob/main/LICENSE)

---

## Copyright

Copyright (C) <2018>  <Bob Lemaire, IoTaWatt, Inc.>

Copyright (C) <2022-> Khoi Hoang



