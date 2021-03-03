#ifndef PORT_H
#define PORT_H

#include "../utils/types.h"

// Write to the port
void port_write(uint16_t port, uint8_t data);

// Read the ports
uint8_t port_read(uint16_t port);

#endif