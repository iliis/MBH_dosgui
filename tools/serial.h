#ifndef __SERIAL_H_INCLUDED__
#define __SERIAL_H_INCLUDED__

#include <bios.h>
#include "tools/errorclass.h"
#include "tools/debug_printf.h"

enum Parity
{
	EVEN, ODD, NONE
};

class SerialPort
{
	unsigned int port_number;
	unsigned int baud;
	Parity parity;
	unsigned int databits;
	unsigned int stopbits;
public:
	SerialPort(unsigned int num, unsigned int baud, Parity parity, unsigned int databits, unsigned int stopbits);



	void write(char d);
	char waitForData();

	void printStatus(unsigned short status);
	unsigned short getStatus();

	static int countPorts();
};

#endif
