#include "rgb_matrix.h"
#include "i2c_master.h"
#include "drivers/led/issi/is31fl3729.h"
#include "quantum.h"

const is31fl3729_led_t PROGMEM g_is31fl3729_leds[IS31FL3729_LED_COUNT] = {
/* Refer to IS31 manual for these locations
 *   driver
 *   |  R location
 *   |  |       G location
 *   |  |       |       B location
 *   |  |       |       | */
    {0, SW8_CS1,    SW8_CS2,    SW8_CS3},
    {0, SW7_CS1,    SW7_CS2,    SW7_CS3},
    {0, SW6_CS1,    SW6_CS2,    SW6_CS3},
    {0, SW5_CS1,    SW5_CS2,    SW5_CS3},
    {0, SW4_CS1,    SW4_CS2,    SW4_CS3},
    {0, SW3_CS1,    SW3_CS2,    SW3_CS3},
    {0, SW2_CS1,    SW2_CS2,    SW2_CS3},
    {0, SW1_CS1,    SW1_CS2,    SW1_CS3},

    {1, SW9_CS1,    SW9_CS2,    SW9_CS3},
    {1, SW8_CS1,    SW8_CS2,    SW8_CS3},
    {1, SW7_CS1,    SW7_CS2,    SW7_CS3},
    {1, SW6_CS1,    SW6_CS2,    SW6_CS3},
    {1, SW5_CS1,    SW5_CS2,    SW5_CS3},
    {1, SW4_CS1,    SW4_CS2,    SW4_CS3},
    {1, SW3_CS1,    SW3_CS2,    SW3_CS3},
    {1, SW2_CS1,    SW2_CS2,    SW2_CS3},
    {1, SW1_CS1,    SW1_CS2,    SW1_CS3},

    {4, SW2_CS10,   SW2_CS11,   SW2_CS12},

    //next

    {0, SW9_CS7,   SW9_CS8,   SW9_CS9},
    {0, SW8_CS7,   SW8_CS8,   SW8_CS9},
    {0, SW7_CS7,   SW7_CS8,   SW7_CS9},
    {0, SW6_CS7,   SW6_CS8,   SW6_CS9},
    {0, SW5_CS7,   SW5_CS8,   SW5_CS9},
    {0, SW4_CS7,   SW4_CS8,   SW4_CS9},
    {0, SW3_CS7,   SW3_CS8,   SW3_CS9},
    {0, SW2_CS7,   SW2_CS8,   SW2_CS9},
    {0, SW1_CS7,   SW1_CS8,   SW1_CS9},

    {1, SW9_CS4,   SW9_CS5,   SW9_CS6},
    {1, SW8_CS4,   SW8_CS5,   SW8_CS6},
    {1, SW7_CS4,   SW7_CS5,   SW7_CS6},
    {1, SW6_CS4,   SW6_CS5,   SW6_CS6},
    {1, SW5_CS4,   SW5_CS5,   SW5_CS6},
    {1, SW4_CS4,   SW4_CS5,   SW4_CS6},
    {1, SW3_CS4,   SW3_CS5,   SW3_CS6},
    {1, SW2_CS4,   SW2_CS5,   SW2_CS6},
    {1, SW1_CS4,   SW1_CS5,   SW1_CS6},

    {4, SW3_CS10,   SW3_CS11,   SW3_CS12},
    {4, SW1_CS10,   SW1_CS11,   SW1_CS12},

    //next

    {0, SW9_CS4,   SW9_CS5,   SW9_CS6},
    {0, SW8_CS4,   SW8_CS5,   SW8_CS6},
    {0, SW7_CS4,   SW7_CS5,   SW7_CS6},
    {0, SW6_CS4,   SW6_CS5,   SW6_CS6},
    {0, SW5_CS4,   SW5_CS5,   SW5_CS6},
    {0, SW4_CS4,   SW4_CS5,   SW4_CS6},
    {0, SW3_CS4,   SW3_CS5,   SW3_CS6},
    {0, SW2_CS4,   SW2_CS5,   SW2_CS6},
    {0, SW1_CS4,   SW1_CS5,   SW1_CS6},

    {1, SW9_CS7,   SW9_CS8,   SW9_CS9},
    {1, SW8_CS7,   SW8_CS8,   SW8_CS9},
    {1, SW7_CS7,   SW7_CS8,   SW7_CS9},
    {1, SW6_CS7,   SW6_CS8,   SW6_CS9},
    {1, SW5_CS7,   SW5_CS8,   SW5_CS9},
    {1, SW3_CS7,   SW3_CS8,   SW3_CS9},
    {1, SW2_CS7,   SW2_CS8,   SW2_CS9},
    {1, SW1_CS7,   SW1_CS8,   SW1_CS9},

    {4, SW3_CS7,   SW3_CS8,   SW3_CS9},
    {4, SW2_CS7,   SW2_CS8,   SW2_CS9},
    {4, SW1_CS7,   SW1_CS8,   SW1_CS9},

    //next

    {0, SW9_CS10,   SW9_CS11,   SW9_CS12},
    {0, SW8_CS10,   SW8_CS11,   SW8_CS12},
    {0, SW7_CS10,   SW7_CS11,   SW7_CS12},
    {0, SW5_CS10,   SW5_CS11,   SW5_CS12},
    {0, SW4_CS10,   SW4_CS11,   SW4_CS12},
    {0, SW3_CS10,   SW3_CS11,   SW3_CS12},
    {0, SW2_CS10,   SW2_CS11,   SW2_CS12},
    {0, SW1_CS10,   SW1_CS11,   SW1_CS12},

    {1, SW9_CS13,   SW9_CS14,   SW9_CS15},
    {1, SW8_CS13,   SW8_CS14,   SW8_CS15},
    {1, SW7_CS13,   SW7_CS14,   SW7_CS15},
    {1, SW6_CS13,   SW6_CS14,   SW6_CS15},
    {1, SW5_CS13,   SW5_CS14,   SW5_CS15},
    {1, SW4_CS13,   SW4_CS14,   SW4_CS15},
    {1, SW3_CS13,   SW3_CS14,   SW3_CS15},
    {1, SW2_CS13,   SW2_CS14,   SW2_CS15},
    {1, SW1_CS13,   SW1_CS14,   SW1_CS15},

    {4, SW3_CS4,   SW3_CS5,   SW3_CS6},
    {4, SW2_CS4,   SW2_CS5,   SW2_CS6},

    //next

    {0, SW9_CS13,   SW9_CS14,   SW9_CS15},
    {0, SW8_CS13,   SW8_CS14,   SW8_CS15},
    {0, SW6_CS13,   SW6_CS14,   SW6_CS15},
    {0, SW5_CS13,   SW5_CS14,   SW5_CS15},
    {0, SW4_CS13,   SW4_CS14,   SW4_CS15},
    {0, SW3_CS13,   SW3_CS14,   SW3_CS15},
    {0, SW2_CS13,   SW2_CS14,   SW2_CS15},
    {0, SW1_CS13,   SW1_CS14,   SW1_CS15},

    {1, SW9_CS10,   SW9_CS11,   SW9_CS12},
    {1, SW8_CS10,   SW8_CS11,   SW8_CS12},
    {1, SW7_CS10,   SW7_CS11,   SW7_CS12},
    {1, SW6_CS10,   SW6_CS11,   SW6_CS12},
    {1, SW5_CS10,   SW5_CS11,   SW5_CS12},
    {1, SW4_CS10,   SW4_CS11,   SW4_CS12},
    {1, SW2_CS10,   SW2_CS11,   SW2_CS12},
    {1, SW1_CS10,   SW1_CS11,   SW1_CS12},

    {4, SW3_CS1,   SW3_CS2,   SW3_CS3},
    {4, SW1_CS1,   SW1_CS2,   SW1_CS3},

    //next

    {3, SW1_CS13,   SW1_CS14,   SW1_CS15},
    {3, SW3_CS13,   SW3_CS14,   SW3_CS15},
    {3, SW4_CS13,   SW4_CS14,   SW4_CS15},
    {3, SW5_CS13,   SW5_CS14,   SW5_CS15},
    {3, SW6_CS13,   SW6_CS14,   SW6_CS15},
    {3, SW7_CS13,   SW7_CS14,   SW7_CS15},
    {3, SW8_CS13,   SW8_CS14,   SW8_CS15},
    {3, SW9_CS13,   SW9_CS14,   SW9_CS15},

    {3, SW3_CS10,   SW3_CS11,   SW3_CS12},
    {3, SW4_CS10,   SW4_CS11,   SW4_CS12},
    {3, SW5_CS10,   SW5_CS11,   SW5_CS12},
    {3, SW6_CS10,   SW6_CS11,   SW6_CS12},
    {3, SW9_CS10,   SW9_CS11,   SW9_CS12},

    {4, SW8_CS13,   SW8_CS14,   SW8_CS15},
    {4, SW7_CS13,   SW7_CS14,   SW7_CS15},
    {4, SW6_CS13,   SW6_CS14,   SW6_CS15},
    {4, SW3_CS13,   SW3_CS14,   SW3_CS15},
    {4, SW2_CS13,   SW2_CS14,   SW2_CS15},

    //next

    {3, SW1_CS4,   SW1_CS5,   SW1_CS6},
    {3, SW2_CS4,   SW2_CS5,   SW2_CS6},
    {3, SW3_CS4,   SW3_CS5,   SW3_CS6},
    {3, SW4_CS4,   SW4_CS5,   SW4_CS6},
    {3, SW8_CS4,   SW8_CS5,   SW8_CS6},

    {3, SW5_CS4,   SW5_CS5,   SW5_CS6},
    {3, SW6_CS4,   SW6_CS5,   SW6_CS6},
    {3, SW7_CS4,   SW7_CS5,   SW7_CS6},
    {3, SW9_CS4,   SW9_CS5,   SW9_CS6},

    {4, SW8_CS1,   SW8_CS2,   SW8_CS3},
    {4, SW7_CS1,   SW7_CS2,   SW7_CS3},
    {4, SW6_CS1,   SW6_CS2,   SW6_CS3},

    {4, SW5_CS1,   SW5_CS2,   SW5_CS3},
    {4, SW2_CS1,   SW2_CS2,   SW2_CS3},

    //next

    {3, SW2_CS1,   SW2_CS2,   SW2_CS3},
    {3, SW3_CS1,   SW3_CS2,   SW3_CS3},
    {3, SW4_CS1,   SW4_CS2,   SW4_CS3},
    {3, SW5_CS1,   SW5_CS2,   SW5_CS3},
    {3, SW6_CS1,   SW6_CS2,   SW6_CS3},
    {3, SW7_CS1,   SW7_CS2,   SW7_CS3},
    {3, SW8_CS1,   SW8_CS2,   SW8_CS3},
    {3, SW9_CS1,   SW9_CS2,   SW9_CS3},

    {3, SW3_CS7,   SW3_CS8,   SW3_CS9},
    {3, SW4_CS7,   SW4_CS8,   SW4_CS9},
    {3, SW5_CS7,   SW5_CS8,   SW5_CS9},
    {3, SW6_CS7,   SW6_CS8,   SW6_CS9},
    {3, SW7_CS7,   SW7_CS8,   SW7_CS9},
    {3, SW9_CS7,   SW9_CS8,   SW9_CS9},

    {4, SW8_CS7,   SW8_CS8,   SW8_CS9},
    {4, SW7_CS7,   SW7_CS8,   SW7_CS9},
    {4, SW6_CS7,   SW6_CS8,   SW6_CS9},
    {4, SW5_CS7,   SW5_CS8,   SW5_CS9},
};

led_config_t g_led_config = { {
  // Key Matrix to LED Index
  {  19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35,36, NO_LED  },
  {  39, 40, 41, 42, 43, 44,45 , 46, 47,48,49,50, 51, NO_LED,52, 53, 54 , 55 , 56},
  { 59, 60,  NO_LED, 61,62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76 },
  {   79, NO_LED,80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91,  NO_LED, 92,93, 94, NO_LED},
  {   NO_LED,97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107,  NO_LED, 108,109, 110, 111, 112, 113},
  { 116, 117,  NO_LED, 118, NO_LED, NO_LED,  119, NO_LED, NO_LED, NO_LED,120,121, 122, 123, 124, 125, 126, 127, NO_LED }
}, {
  // LED Index to Physical Position
  {9, 0}, {21, 0}, {33, 0}, {45, 0}, {57, 0}, {68, 0}, {81, 0}, {92, 0}, {105, 0}, {117, 0}, {129, 0}, {141, 0}, {153, 0}, {165, 0}, {177, 0}, {189, 0}, {201, 0}, {213, 0},
  {0, 6}, {3, 6}, {15, 6}, {27, 6}, {39, 6}, {51, 6}, {63, 6}, {75, 6}, {87, 6}, {99, 6}, {111, 6}, {123, 6}, {135, 6}, {147, 6}, {159, 6}, {171, 6},  {183, 6}, {195, 6}, {207, 6}, {222, 3},
  {0, 18}, {3, 18}, {15, 18}, {27, 18}, {39, 18}, {51, 18}, {63, 18}, {75, 18}, {87, 18}, {99, 18}, {111, 18}, {123, 18}, {135, 18}, {147, 18}, {165, 18},  {183, 18}, {195, 18}, {207, 18}, {219, 18}, {224, 17},
  {0, 29}, {6, 29}, {21, 29}, {33, 29}, {45, 29}, {57, 29}, {69, 29}, {81, 29}, {93, 29}, {105, 29}, {117, 29}, {129, 29}, {141, 29}, {153, 29}, {168, 29}, {183, 29}, {195, 29}, {207, 29}, {222, 32}, {224, 27},
  {0, 41}, {8, 41}, {24, 41}, {36, 41}, {48, 41}, {60, 41}, {72, 41}, {84, 41}, {96, 41}, {108, 41}, {120, 41}, {132, 41}, {144, 41}, {164, 41}, {183, 41}, {195, 41}, {207, 41}, {223, 36},
  {0, 52}, {11, 52}, {30, 52}, {42, 52}, {54, 52}, {66, 52}, {78, 52}, {90, 52}, {102, 52}, {114, 52}, {126, 52}, {138, 52}, {155, 52}, {171, 52}, {183, 52}, {195, 52}, {207, 52}, {222, 55}, {224, 45},
  {0, 64}, {5, 64}, {20, 64}, {35, 64}, {80, 64}, {123, 64}, {135, 64}, {147, 64}, {159, 64}, {171, 64}, {183, 64}, {195, 64}, {207, 64},
  {8, 64}, {16, 64}, {27, 64}, {42, 64}, {53, 64}, {69, 64}, {82, 64}, {94, 64}, {107, 64}, {115, 64}, {126, 64}, {138, 64}, {150, 64}, {162, 64}, {174, 64}, {186, 64}, {202, 64}, {210, 64}, {219, 64}, {224, 58}

}, {
  // LED Index to Flag
    2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
  2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,  2,
  2,4,4,4,4,4,4,4,4,4,4,4,4,4,  1,4,4,4,4,2,
  2,1,4,  4,4,4,4,4,4,4,4,4,4,4,1,4,4,2,4,2,
  2,1,  4,4,4,4,4,4,4,4,4,4,4,1,  4,4,4,  2,
  2,  1,4,4,4,4,4,4,4,4,4,4,  4,1,4,4,4,4,2,
  2,1,1,  1,    1,      1,1,1,2,2,4,4,4,
    2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2









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
