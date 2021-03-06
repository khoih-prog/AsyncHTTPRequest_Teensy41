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
  You should have received a copy of the GNU General Public License along with this program.  If not, see <https://www.gnu.org/licenses/>.  
 
  Version: 1.7.1
  
  Version Modified By   Date      Comments
  ------- -----------  ---------- -----------
  1.7.1    K Hoang     18/03/2022 Initial coding for Teensy 4.1 using built-in QNEthernet.
                                  Bump up version to v1.7.1 to sync with AsyncHTTPRequest_Generic v1.7.1
 *****************************************************************************************************************************/

#pragma once

#ifndef ASYNC_HTTP_REQUEST_TEENSY41_H
#define ASYNC_HTTP_REQUEST_TEENSY41_H

#include "Teensy41_AsyncTCP.h"

#include "AsyncHTTPRequest_Teensy41.hpp"
#include "AsyncHTTPRequest_Teensy41_Impl.h"

#endif    // ASYNC_HTTP_REQUEST_TEENSY41_H
