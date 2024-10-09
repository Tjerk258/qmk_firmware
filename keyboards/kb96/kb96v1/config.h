// Copyright 2023 Tjerk (@Tjerk258)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

#define USB_POLLING_INTERVAL_MS 1

#define I2C_DRIVER I2CD2
#define I2C1_SCL_PIN B10
#define I2C1_SDA_PIN B11
#define I2C1_CLOCK_SPEED 400000
#define I2C1_DUTY_CYCLE FAST_DUTY_CYCLE_2

/* RGB Settings*/
// #define DRIVER_COUNT 3
#define IS31FL3733_I2C_ADDRESS_1  0b1010000
#define IS31FL3733_I2C_ADDRESS_2  0b1010001
#define IS31FL3733_I2C_ADDRESS_3  0b1010010
#define IS31FL3733_SYNC_1   IS31FL3733_SYNC_SLAVE
#define IS31FL3733_SYNC_2   IS31FL3733_SYNC_SLAVE
#define IS31FL3733_SYNC_3   IS31FL3733_SYNC_MASTER
#define IS31FL3733_GLOBAL_CURRENT  237
#define IS31FL3733_SW_PULLUP IS31FL3733_PUR_16K_OHM
#define IS31FL3733_CS_PULLDOWN IS31FL3733_PUR_16K_OHM

#define DRIVER_1_LED_TOTAL 61
#define DRIVER_2_LED_TOTAL 53
#define DRIVER_3_LED_TOTAL 34
#define RGB_MATRIX_LED_COUNT (DRIVER_1_LED_TOTAL + DRIVER_2_LED_TOTAL + DRIVER_3_LED_TOTAL)
