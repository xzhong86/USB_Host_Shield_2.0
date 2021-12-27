// -*- C++ -*-

#ifndef __rp2040_ard__
#define __rp2040_ard__

class ArduinoSerial {
public:
    ArduinoSerial();
    void print(char c);
};

extern ArduinoSerial Serial;

#include "hardware/spi.h"
//#include <hardware/spi.h>
class ArduinoSPI {
    spi_inst_t *spi;
public:
    ArduinoSPI(spi_inst_t *spi) : spi(spi) {}
    void setClockDivider(int) {}
    void begin();
    uint8_t transfer(uint8_t in);
    void send(uint8_t *data, uint8_t size);
    void receive(uint8_t *data, uint8_t size);
};

//extern ArduinoSPI PicoSPI0;
extern ArduinoSPI PicoSPI1;

#define delay(ms) busy_wait_us_32(ms * 1000)

#endif
