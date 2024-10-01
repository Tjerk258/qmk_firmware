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

#define RGB_MATRIX_SOLID_COLOR     // Static single hue no speed support
#define RGB_MATRIX_ALPHAS_MODS         // Static dual hue speed is hue for secondary hue
#define RGB_MATRIX_GRADIENT_UP_DOWN    // Static gradient top to bottom speed controls how much gradient changes
#define RGB_MATRIX_GRADIENT_LEFT_RIGHT    // Static gradient left to right speed controls how much gradient changes
#define RGB_MATRIX_BREATHING           // Single hue brightness cycling animation
#define RGB_MATRIX_BAND_SAT        // Single hue band fading saturation scrolling left to right
#define RGB_MATRIX_BAND_VAL        // Single hue band fading brightness scrolling left to right
#define RGB_MATRIX_BAND_PINWHEEL_SAT   // Single hue 3 blade spinning pinwheel fades saturation
#define RGB_MATRIX_BAND_PINWHEEL_VAL   // Single hue 3 blade spinning pinwheel fades brightness
#define RGB_MATRIX_BAND_SPIRAL_SAT     // Single hue spinning spiral fades saturation
#define RGB_MATRIX_BAND_SPIRAL_VAL     // Single hue spinning spiral fades brightness
#define RGB_MATRIX_CYCLE_ALL           // Full keyboard solid hue cycling through full gradient
#define RGB_MATRIX_CYCLE_LEFT_RIGHT    // Full gradient scrolling left to right
#define RGB_MATRIX_CYCLE_UP_DOWN       // Full gradient scrolling top to bottom
#define RGB_MATRIX_CYCLE_OUT_IN        // Full gradient scrolling out to in
#define RGB_MATRIX_CYCLE_OUT_IN_DUAL   // Full dual gradients scrolling out to in
#define RGB_MATRIX_RAINBOW_MOVING_CHEVRON  // Full gradient Chevron shapped scrolling left to right
#define RGB_MATRIX_CYCLE_PINWHEEL      // Full gradient spinning pinwheel around center of keyboard
#define RGB_MATRIX_CYCLE_SPIRAL        // Full gradient spinning spiral around center of keyboard
#define RGB_MATRIX_DUAL_BEACON         // Full gradient spinning around center of keyboard
#define RGB_MATRIX_RAINBOW_BEACON      // Full tighter gradient spinning around center of keyboard
#define RGB_MATRIX_RAINBOW_PINWHEELS   // Full dual gradients spinning two halfs of keyboard
#define RGB_MATRIX_FLOWER_BLOOMING     // Full tighter gradient of first half scrolling left to right and second half scrolling right to left
#define RGB_MATRIX_RAINDROPS           // Randomly changes a single key's hue
#define RGB_MATRIX_JELLYBEAN_RAINDROPS // Randomly changes a single key's hue and saturation
#define RGB_MATRIX_HUE_BREATHING       // Hue shifts up a slight ammount at the same time then shifts back
#define RGB_MATRIX_HUE_PENDULUM        // Hue shifts up a slight ammount in a wave to the right then back to the left
#define RGB_MATRIX_HUE_WAVE            // Hue shifts up a slight ammount and then back down in a wave to the right
#define RGB_MATRIX_PIXEL_FRACTAL       // Single hue fractal filled keys pulsing horizontally out to edges
#define RGB_MATRIX_PIXEL_FLOW          // Pulsing RGB flow along LED wiring with random hues
#define RGB_MATRIX_PIXEL_RAIN          // Randomly light keys with random hues
#define RGB_MATRIX_TYPING_HEATMAP      // How hot is your WPM!
#define RGB_MATRIX_DIGITAL_RAIN        // That famous computer simulation
#define RGB_MATRIX_SOLID_REACTIVE_SIMPLE   // Pulses keys hit to hue & value then fades value out
#define RGB_MATRIX_SOLID_REACTIVE      // Static single hue pulses keys hit to shifted hue then fades to current hue
#define RGB_MATRIX_SOLID_REACTIVE_WIDE       // Hue & value pulse near a single key hit then fades value out
#define RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE  // Hue & value pulse near multiple key hits then fades value out
#define RGB_MATRIX_SOLID_REACTIVE_CROSS      // Hue & value pulse the same column and row of a single key hit then fades value out
#define RGB_MATRIX_SOLID_REACTIVE_MULTICROSS // Hue & value pulse the same column and row of multiple key hits then fades value out
#define RGB_MATRIX_SOLID_REACTIVE_NEXUS      // Hue & value pulse away on the same column and row of a single key hit then fades value out
#define RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS // Hue & value pulse away on the same column and row of multiple key hits then fades value out
#define RGB_MATRIX_SPLASH              // Full gradient & value pulse away from a single key hit then fades value out
#define RGB_MATRIX_MULTISPLASH         // Full gradient & value pulse away from multiple key hits then fades value out
#define RGB_MATRIX_SOLID_SPLASH        // Hue & value pulse away from a single key hit then fades value out
#define RGB_MATRIX_SOLID_MULTISPLASH   // Hue & value pulse away from multiple key hits then fades value out
#define RGB_MATRIX_STARLIGHT           // LEDs turn on and off at random at varying brightness maintaining user set color
#define RGB_MATRIX_STARLIGHT_DUAL_HUE  // LEDs turn on and off at random at varying brightness modifies user set hue by +- 30
#define RGB_MATRIX_STARLIGHT_DUAL_SAT  // LEDs turn on and off at random at varying brightness modifies user set saturation by +- 30
#define RGB_MATRIX_RIVERFLOW           // Modification to breathing animation offset's animation depending on key location to simulate a river flowing
#define RGB_MATRIX_EFFECT_MAX
// #define ENABLE_RGB_MATRIX_ALPHAS_MODS
// #define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
// #define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
// #define ENABLE_RGB_MATRIX_BREATHING
// #define ENABLE_RGB_MATRIX_BAND_SAT
// #define ENABLE_RGB_MATRIX_BAND_VAL
// #define ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
// #define ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
// #define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
// #define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
// #define ENABLE_RGB_MATRIX_CYCLE_ALL
// #define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
// #define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
// #define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
// #define ENABLE_RGB_MATRIX_CYCLE_OUT_IN
// #define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
// #define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
// #define ENABLE_RGB_MATRIX_CYCLE_SPIRAL
// #define ENABLE_RGB_MATRIX_DUAL_BEACON
// #define ENABLE_RGB_MATRIX_RAINBOW_BEACON
// #define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
// #define ENABLE_RGB_MATRIX_RAINDROPS
// #define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
// #define ENABLE_RGB_MATRIX_HUE_BREATHING
// #define ENABLE_RGB_MATRIX_HUE_PENDULUM
// #define ENABLE_RGB_MATRIX_HUE_WAVE
// #define ENABLE_RGB_MATRIX_PIXEL_FRACTAL
// #define ENABLE_RGB_MATRIX_PIXEL_RAIN





// #define ENABLE_RGB_MATRIX_TYPING_HEATMAP
// #define ENABLE_RGB_MATRIX_DIGITAL_RAIN

#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#define ENABLE_RGB_MATRIX_SPLASH
#define ENABLE_RGB_MATRIX_MULTISPLASH
#define ENABLE_RGB_MATRIX_SOLID_SPLASH
#define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH
