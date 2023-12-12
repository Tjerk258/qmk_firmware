#include "rgb_matrix.h"
#include "i2c_master.h"
#include "drivers/led/issi/is31fl3733.h"
#include "quantum.h"

const is31_led PROGMEM g_is31_leds[RGB_MATRIX_LED_COUNT] = {
/* Refer to IS31 manual for these locations
 *   driver
 *   |  R location
 *   |  |       G location
 *   |  |       |       B location
 *   |  |       |       | */
    {0, K_1,    J_1,    L_1},
    {0, K_2,    J_2,    L_2},
    {0, K_3,    J_3,    L_3},
    {0, K_4,    J_4,    L_4},
    {0, K_5,    J_5,    L_5},
    {0, K_6,    J_6,    L_6},
    {0, K_7,    J_7,    L_7},
    {0, K_8,    J_8,    L_8},
    {0, K_9,    J_9,    L_9},
    {0, K_10,   J_10,   L_10},
    {0, K_11,   J_11,   L_11},
    {0, K_12,   J_12,   L_12},

    {0, H_1,    G_1,    I_1},
    {0, H_2,    G_2,    I_2},
    {0, H_3,    G_3,    I_3},
    {0, H_4,    G_4,    I_4},
    {0, H_5,    G_5,    I_5},
    {0, H_6,    G_6,    I_6},
    {0, H_7,    G_7,    I_7},
    {0, H_8,    G_8,    I_8},
    {0, H_9,    G_9,    I_9},
    {0, H_10,   G_10,   I_10},
    {0, H_11,   G_11,   I_11},
    {0, H_12,   G_12,   I_12},

    {0, E_1,    D_1,    F_1},
    {0, E_2,    D_2,    F_2},
    {0, E_3,    D_3,    F_3},
    {0, E_4,    D_4,    F_4},
    {0, E_5,    D_5,    F_5},
    {0, E_6,    D_6,    F_6},
    {0, E_7,    D_7,    F_7},
    {0, E_8,    D_8,    F_8},
    {0, E_9,    D_9,    F_9},
    {0, E_10,   D_10,   F_10},
    {0, E_11,   D_11,   F_11},
    {0, E_12,   D_12,   F_12},

    {0, B_1,    A_1,    C_1},
    {0, B_2,    A_2,    C_2},
    {0, B_3,    A_3,    C_3},
    {0, B_4,    A_4,    C_4},
    {0, B_5,    A_5,    C_5},
    {0, B_7,    A_7,    C_7},
    {0, B_8,    A_8,    C_8},
    {0, B_9,    A_9,    C_9},
    {0, B_10,   A_10,   C_10},
    {0, B_11,   A_11,   C_11},
    {0, B_12,   A_12,   C_12}
};

led_config_t g_led_config = { {
  // Key Matrix to LED Index
  { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11},
  { 12,13,14,15,16,17,18,19,20,21,22,23},
  { 24,25,16,17,18,19,30,31,32,33,34,35},
  { 36,37,38,39,40,NO_LED,41,42,43,44,45,46}
}, {
  // LED Index to Physical Position
  {9,8},  {28,8}, {47,8}, {66,8}, {85,8}, {104,8}, {123,8}, {142,8}, {160,8}, {179,8},{198,8}, {217,8},
  {9,25}, {28,25},{47,25},{66,25},{85,25},{104,25},{123,25},{142,25},{160,25},{179,25},{198,25},{217,25},
  {9,41}, {28,41},{47,41},{66,41},{85,41},{104,41},{123,41},{142,41},{160,41},{179,41},{198,41},{217,41},
  {9,58}, {28,58},{47,58},{66,58},{85,58},     {113,58},    {142,58},{160,58},{179,58},{198,58},{217,58}
}, {
  // LED Index to Flag
  1,4,4,4,4,4,4,4,4,4,4,1,
  1,4,4,4,4,4,4,4,4,4,1,1,
  1,4,4,4,4,4,4,4,1,1,1,1,
  1,1,1,1,1,  1,1,1,1,1,1 
} };


// led_config_t g_led_config = { {
//   // Key Matrix to LED Index
//   {  17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, NO_LED, NO_LED, NO_LED, NO_LED  },
//   {  33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44,45 , NO_LED, 46, NO_LED, NO_LED, NO_LED, NO_LED },
//   { 48, 49, NO_LED, 50, 51, 52, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED },
//   {   NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED },
//   {   NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED },
//   { NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED,  NO_LED, NO_LED, NO_LED, NO_LED,NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED }
// }, {
//   // LED Index to Physical Position
//   {9, 0}, {21, 0}, {33, 0}, {45, 0}, {57, 0}, {68, 0}, {81, 0}, {92, 0}, {105, 0}, {117, 0}, {129, 0}, {141, 0}, {153, 0}, {165, 0}, {177, 0}, {0, 6}, {3, 6}, {15, 6}, {27, 6}, {39, 6}, {51, 6}, {63, 6}, {75, 6}, {87, 6}, {99, 6}, {111, 6}, {123, 6}, {135, 6}, {147, 6}, {159, 6}, {171, 6}, {0, 18}, {3, 18}, {15, 18}, {27, 18}, {39, 18}, {51, 18}, {63, 18}, {75, 18}, {87, 18}, {99, 18}, {111, 18}, {123, 18}, {135, 18}, {147, 18}, {165, 18}, {0, 29}, {6, 29}, {21, 29}, {33, 29}, {45, 29}, {57, 29}, {69, 29}
// }, {
//   // LED Index to Flag
//   2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,2,4,4,4,4,4,4,4,4,4,4,4,4,4,1,2,1,4,4,4,4,4,4,4
// } };