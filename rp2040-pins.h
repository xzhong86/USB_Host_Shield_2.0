
#ifndef __rp2040_pins__
#define __rp2040_pins__

#ifndef RP2040_PINS_USER

#define PIN_SPI_SCK   10
#define PIN_SPI_MOSI  11
#define PIN_SPI_MISO  12
#define PIN_SPI_SS    13
#define PIN_UHS_INTR  14

#define MAX3421E_SS   P13
#define MAX3421E_INTR P14

#else // defined RP2040_PINS_USER
#include "rp2040-pins-user.h"

#endif

#endif
