/****************************************************************************************************************************
  AsyncHTTPRequest_Teensy41.h - Dead simple AsyncHTTPRequest for Teensy41 QNEthernet

  For Teensy41 with QNEthernet

  AsyncHTTPRequest_Teensy41 is a library for Teensy41 with QNEthernet

  Based on and modified from

  1. asyncHTTPrequest Library         (https://github.com/boblemaire/asyncHTTPrequest)
  2. AsyncHTTPRequest_Generic Library (https://github.com/khoih-prog/AsyncHTTPRequest_Generic)

  Built by Khoi Hoang https://github.com/khoih-prog/AsyncHTTPRequest_Teensy41

  Copyright (C) <2018>  <Bob Lemaire, IoTaWatt, Inc.>
  This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License
  as published bythe Free Software Foundation, either version 3 of the License, or (at your option) any later version.
  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
  You should have received a copy of the GNU General Public License along with this program.
  If not, see <https://www.gnu.org/licenses/>.

  Version: 1.10.0
  
  Version Modified By   Date      Comments
  ------- -----------  ---------- -----------
  1.7.1    K Hoang     18/03/2022 Initial coding for Teensy 4.1 using built-in QNEthernet.
                                  Bump up version to v1.7.1 to sync with AsyncHTTPRequest_Generic v1.7.1
  1.8.0    K Hoang     01/09/2022 Fix bug. Improve debug messages. Optimize code
  1.8.1    K Hoang     18/10/2022 Not try to reconnect to the same host:port after connected
  1.9.0    K Hoang     21/10/2022 Fix bug. Clean up
  1.9.1    K Hoang     21/10/2022 Fix bug of wrong reqStates
  1.9.2    K Hoang     10/11/2022 Default to reconnect to the same host:port after connected for new HTTP sites
  1.10.0   K Hoang     01/02/2023 Fix _parseURL() bug
 *****************************************************************************************************************************/

#pragma once

#ifndef ASYNC_HTTP_REQUEST_TEENSY41_H
#define ASYNC_HTTP_REQUEST_TEENSY41_H

#include "Teensy41_AsyncTCP.h"

#include "AsyncHTTPRequest_Teensy41.hpp"
#include "AsyncHTTPRequest_Teensy41_Impl.h"

#endif    // ASYNC_HTTP_REQUEST_TEENSY41_H
