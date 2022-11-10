# AsyncHTTPRequest_Teensy41

[![arduino-library-badge](https://www.ardu-badge.com/badge/AsyncHTTPRequest_Teensy41.svg?)](https://www.ardu-badge.com/AsyncHTTPRequest_Teensy41)
[![GitHub release](https://img.shields.io/github/release/khoih-prog/AsyncHTTPRequest_Teensy41.svg)](https://github.com/khoih-prog/AsyncHTTPRequest_Teensy41/releases)
[![GitHub](https://img.shields.io/github/license/mashape/apistatus.svg)](https://github.com/khoih-prog/AsyncHTTPRequest_Teensy41/blob/master/LICENSE)
[![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat)](#Contributing)
[![GitHub issues](https://img.shields.io/github/issues/khoih-prog/AsyncHTTPRequest_Teensy41.svg)](http://github.com/khoih-prog/AsyncHTTPRequest_Teensy41/issues)

---
---

## Table of contents

* [Table of contents](#table-of-contents)
* [Changelog](#changelog)
  * [Releases v1.9.2](#releases-v192)
  * [Releases v1.9.1](#releases-v191)
  * [Releases v1.9.0](#releases-v190)
  * [Releases v1.8.1](#releases-v181)
  * [Releases v1.8.0](#releases-v180)
  * [Releases v1.7.1](#releases-v171)

---
---

## Changelog

### Release v1.9.2

1. Default to reconnect to the same `host:port` after connected for new HTTP sites. Check [Host/Headers not always sent with 1.10.1 #44](https://github.com/khoih-prog/AsyncHTTPRequest_Generic/issues/44)
2. Use `allman astyle` and add `utils`

### Release v1.9.1

1. Fix bug of wrong `reqStates`. Check [Release 1.9 breakes previously running code #39](https://github.com/khoih-prog/AsyncHTTPRequest_Generic/issues/39) and [Callback behaviour is buggy (ESP8266) #43](https://github.com/khoih-prog/AsyncHTTPRequest_Generic/issues/43).
2. Optional larger `DEFAULT_RX_TIMEOUT` from default 3s, for slower networks

### Release v1.9.0

1. Fix bug. 
2. Clean up

### Releases v1.8.1

1. Not try to reconnect to the same host:port after connected. Check [setReuse feature #12](https://github.com/khoih-prog/AsyncHTTPSRequest_Generic/issues/12)

### Releases v1.8.0

1. Fix long timeout if using bad `IPAddress`
2. Optimize code
3. Display only successful responseText in examples
4. Improve debug messages by adding functions to display error messages instead of `cryptic error number`

### Releases v1.7.1

1. Initial porting and coding for **Teensy 4.1 using built-in QNEthernet**
2. Bump up version to v1.7.1 to sync with [AsyncHTTPRequest_Generic](https://github.com/khoih-prog/AsyncHTTPRequest_Generic) v1.7.1



