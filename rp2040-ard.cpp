
#include <stdio.h>
#include "Usb.h"
#include "rp2040-ard.h"

ArduinoSerial::ArduinoSerial() {
}

void ArduinoSerial::print(char ch) {
    printf("%c", ch);
}
void ArduinoSerial::print(const char *str) {
    printf(str);
}
void ArduinoSerial::print(int v, const char *fmt) {
    printf(fmt, v);
}
void ArduinoSerial::println(const char *str) {
    printf("%s\n", str);
}
void ArduinoSerial::println(int v, const char *fmt) {
    printf(fmt, v);
    printf("\n");
}

ArduinoSerial Serial;


#include <hardware/gpio.h>

void ArduinoSPI::begin() {
    spi_init(spi, 20 * 1000 * 1000); // 20MHz
    gpio_set_function(PIN_SPI_SCK,  GPIO_FUNC_SPI);
    gpio_set_function(PIN_SPI_MOSI, GPIO_FUNC_SPI);
    gpio_set_function(PIN_SPI_MISO, GPIO_FUNC_SPI);

    gpio_init(PIN_SPI_SS);
    gpio_set_dir(PIN_SPI_SS, GPIO_OUT);
}
uint8_t ArduinoSPI::transfer(uint8_t in) {
    uint8_t out;
    spi_write_read_blocking(spi, &in, &out, 1);
    return out;
}
void ArduinoSPI::send(uint8_t *data, uint8_t size) {
    spi_write_blocking(spi, data, size);
}
void ArduinoSPI::receive(uint8_t *data, uint8_t size) {
    spi_read_blocking(spi, 0, data, size);
}

ArduinoSPI PicoSPI0(spi0);
ArduinoSPI PicoSPI1(spi1);
