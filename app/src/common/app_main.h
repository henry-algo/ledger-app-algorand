/*******************************************************************************
*   (c) 2018 - 2022 Zondax AG
*
*  Licensed under the Apache License, Version 2.0 (the "License");
*  you may not use this file except in compliance with the License.
*  You may obtain a copy of the License at
*
*      http://www.apache.org/licenses/LICENSE-2.0
*
*  Unless required by applicable law or agreed to in writing, software
*  distributed under the License is distributed on an "AS IS" BASIS,
*  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*  See the License for the specific language governing permissions and
*  limitations under the License.
********************************************************************************/
#pragma once

#include <stdbool.h>
#include "apdu_codes.h"

#define OFFSET_CLA                      0
#define OFFSET_INS                      1  //< Instruction offset
#define OFFSET_P1                       2  //< P1
#define OFFSET_P2                       3  //< P2
#define OFFSET_DATA_LEN                 4  //< Data Length
#define OFFSET_DATA                     5  //< Data offset

#define APDU_MIN_LENGTH                 5
#define ACCOUNT_ID_LENGTH               4

#define P1_INIT                         0  //< P1
#define P1_ADD                          1  //< P1
#define P1_LAST                         2  //< P1
#define P1_SINGLE_CHUNK                10  //< P1

#define OFFSET_PAYLOAD_TYPE             OFFSET_P1

#define P1_FIRST 0x00
#define P1_FIRST_ACCOUNT_ID 0x01
#define P1_MORE  0x80
#define P1_WITH_REQUEST_USER_APPROVAL  0x80

#define P2_LAST  0x00
#define P2_MORE  0x80

#define INS_GET_VERSION     0x00
#define INS_GET_PUBLIC_KEY  0x03
#define INS_GET_ADDRESS     0x04
#define INS_SIGN_MSGPACK    0x08

void app_init();

void app_main();

void handleApdu(volatile uint32_t *flags, volatile uint32_t *tx, uint32_t rx);

void extractHDPath();
