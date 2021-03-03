#include "port.h"

// Read data from the port
uint8_t port_read(uint16_t port)
{
    uint8_t ret;
    asm volatile("inb %1, %0"
                 : "=a"(ret)
                 : "d"(port));
    return ret;
}

// Write data to the port
void port_write(uint16_t port, uint8_t data)
{
    asm volatile("outb %0, %1"
                 : "=a"(data)
                 : "d"(port));
}
