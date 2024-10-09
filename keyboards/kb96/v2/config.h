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

#define I2C_DRIVER I2CD1
#define I2C1_SCL_PIN B8
#define I2C1_SDA_PIN B9
#define I2C1_CLOCK_SPEED 400000
#define I2C1_DUTY_CYCLE FAST_DUTY_CYCLE_2

/* RGB Settings*/
// #define DRIVER_COUNT 3

#define IS31FL3729_SDB_PIN B7
#define IS31FL3729_I2C_ADDRESS_1 IS31FL3729_I2C_ADDRESS_VCC
#define IS31FL3729_I2C_ADDRESS_2 IS31FL3729_I2C_ADDRESS_SDA
#define IS31FL3729_I2C_ADDRESS_3 IS31FL3729_I2C_ADDRESS_SCL
#define IS31FL3729_I2C_ADDRESS_4 IS31FL3729_I2C_ADDRESS_GND
#define IS31FL3729_GLOBAL_CURRENT 0x35

// #define DRIVER_1_LED_TOTAL 61
// #define DRIVER_2_LED_TOTAL 53
// #define DRIVER_3_LED_TOTAL 34
// #define RGB_MATRIX_LED_COUNT (DRIVER_1_LED_TOTAL + DRIVER_2_LED_TOTAL + DRIVER_3_LED_TOTAL)
