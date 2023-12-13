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
    {0, A_11,    B_11,    C_11},
    {0, D_11,    E_11,    F_11},
    {0, G_11,    H_11,    I_11},
    {0, J_11,    K_11,    L_11},
    {0, A_12,    B_12,    C_12},
    {0, D_12,    E_12,    F_12},
    {0, G_12,    H_12,    I_12},
    {0, J_12,    K_12,    L_12},
    {0, A_13,    B_13,    C_13},
    {0, D_13,    E_13,    F_13},
    {0, G_13,    H_13,    I_13},
    {0, J_13,    K_13,    L_13},
    {0, A_14,    B_14,    C_14},
    {0, D_14,    E_14,    F_14},
    {0, G_14,    H_14,    I_14},
    {0, A_15,    B_15,    C_15},
    {0, D_15,    E_15,    F_15},
    {0, G_15,    H_15,    I_15},
    {0, J_15,    K_15,    L_15},
    {0, A_16,    B_16,    C_16},
    {0, G_16,    H_16,    I_16},
};

led_config_t g_led_config = { {
  // Key Matrix to LED Index
  {  0, 1, 2, 3},
  {  4, 5, 6, 7},
  {  8, 9, 10, 11},
  {  12, 13, 14, NO_LED},
  {  15, 16, 17, 18},
  {  19, NO_LED, 20, NO_LED},
 
}, {
  // LED Index to Physical Position
  {9, 0}, {21, 0}, {33, 0}, {45, 0},
  {0, 6}, {3, 6}, {15, 6}, {27, 6}, 
  {0, 18}, {3, 18}, {15, 18}, {27, 18}, 
  {0, 29}, {6, 29}, {21, 29},
  {0, 41}, {8, 41}, {24, 41}, {36, 41}, 
  {0, 52},          {30, 52}
    
}, {
  // LED Index to Flag
   4,4,4,4,
   4,4,4,4,
   4,4,4,4,
   4,4,4,
   4,4,4,4,
     4,  4
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