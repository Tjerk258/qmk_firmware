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

    {3, SW2_CS10,   SW2_CS11,   SW2_CS12},

    //next row

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

    {3, SW3_CS10,   SW3_CS11,   SW3_CS12},
    {3, SW1_CS10,   SW1_CS11,   SW1_CS12},

    //next row

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

    {3, SW3_CS7,   SW3_CS8,   SW3_CS9},
    {3, SW2_CS7,   SW2_CS8,   SW2_CS9},
    {3, SW1_CS7,   SW1_CS8,   SW1_CS9},

    //next row

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

    {3, SW3_CS4,   SW3_CS5,   SW3_CS6},
    {3, SW2_CS4,   SW2_CS5,   SW2_CS6},

    //next row

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

    {3, SW3_CS1,   SW3_CS2,   SW3_CS3},
    {3, SW1_CS1,   SW1_CS2,   SW1_CS3},

    //next row

    {2, SW1_CS13,   SW1_CS14,   SW1_CS15},
    {2, SW3_CS13,   SW3_CS14,   SW3_CS15},
    {2, SW4_CS13,   SW4_CS14,   SW4_CS15},
    {2, SW5_CS13,   SW5_CS14,   SW5_CS15},
    {2, SW6_CS13,   SW6_CS14,   SW6_CS15},
    {2, SW7_CS13,   SW7_CS14,   SW7_CS15},
    {2, SW8_CS13,   SW8_CS14,   SW8_CS15},
    {2, SW9_CS13,   SW9_CS14,   SW9_CS15},

    {2, SW3_CS10,   SW3_CS11,   SW3_CS12},
    {2, SW4_CS10,   SW4_CS11,   SW4_CS12},
    {2, SW5_CS10,   SW5_CS11,   SW5_CS12},
    {2, SW6_CS10,   SW6_CS11,   SW6_CS12},
    {2, SW9_CS10,   SW9_CS11,   SW9_CS12},

    {3, SW8_CS13,   SW8_CS14,   SW8_CS15},
    {3, SW7_CS13,   SW7_CS14,   SW7_CS15},
    {3, SW6_CS13,   SW6_CS14,   SW6_CS15},
    {3, SW3_CS13,   SW3_CS14,   SW3_CS15},
    {3, SW2_CS13,   SW2_CS14,   SW2_CS15},

    //next row

    {2, SW1_CS4,   SW1_CS5,   SW1_CS6},
    {2, SW2_CS4,   SW2_CS5,   SW2_CS6},
    {2, SW3_CS4,   SW3_CS5,   SW3_CS6},
    {2, SW4_CS4,   SW4_CS5,   SW4_CS6},
    {2, SW8_CS4,   SW8_CS5,   SW8_CS6},

    {2, SW5_CS4,   SW5_CS5,   SW5_CS6},
    {2, SW6_CS4,   SW6_CS5,   SW6_CS6},
    {2, SW7_CS4,   SW7_CS5,   SW7_CS6},
    {2, SW9_CS4,   SW9_CS5,   SW9_CS6},

    {3, SW8_CS1,   SW8_CS2,   SW8_CS3},
    {3, SW7_CS1,   SW7_CS2,   SW7_CS3},
    {3, SW6_CS1,   SW6_CS2,   SW6_CS3},

    {3, SW5_CS1,   SW5_CS2,   SW5_CS3},
    {3, SW2_CS1,   SW2_CS2,   SW2_CS3},

    //next row

    {2, SW2_CS1,   SW2_CS2,   SW2_CS3},
    {2, SW3_CS1,   SW3_CS2,   SW3_CS3},
    {2, SW4_CS1,   SW4_CS2,   SW4_CS3},
    {2, SW5_CS1,   SW5_CS2,   SW5_CS3},
    {2, SW6_CS1,   SW6_CS2,   SW6_CS3},
    {2, SW7_CS1,   SW7_CS2,   SW7_CS3},
    {2, SW8_CS1,   SW8_CS2,   SW8_CS3},
    {2, SW9_CS1,   SW9_CS2,   SW9_CS3},

    {2, SW3_CS7,   SW3_CS8,   SW3_CS9},
    {2, SW4_CS7,   SW4_CS8,   SW4_CS9},
    {2, SW5_CS7,   SW5_CS8,   SW5_CS9},
    {2, SW6_CS7,   SW6_CS8,   SW6_CS9},
    {2, SW7_CS7,   SW7_CS8,   SW7_CS9},
    {2, SW9_CS7,   SW9_CS8,   SW9_CS9},

    {3, SW8_CS7,   SW8_CS8,   SW8_CS9},
    {3, SW7_CS7,   SW7_CS8,   SW7_CS9},
    {3, SW6_CS7,   SW6_CS8,   SW6_CS9},
    {3, SW5_CS7,   SW5_CS8,   SW5_CS9},
};
