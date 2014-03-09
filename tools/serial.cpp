#include "serial.h"

///////////////////////////////////////////////////////////////////////////////
SerialPort::SerialPort(unsigned int num, unsigned int baud, Parity parity, unsigned int databits, unsigned int stopbits)
 : port_number(num),
   baud(baud),
   parity(parity),
   databits(databits),
   stopbits(stopbits)
{
	unsigned init = 0;

	switch (baud) {
		case 110:
			init |= _COM_110; break;
		case 150:
			init |= _COM_150; break;
		case 300:
			init |= _COM_300; break;
		case 600:
			init |= _COM_600; break;
		case 1200:
			init |= _COM_1200; break;
		case 2400:
			init |= _COM_2400; break;
		case 4800:
			init |= _COM_4800; break;
		case 9600:
			init |= _COM_9600; break;
		default:
			throw Error("init", "Baud rate not supported.");
	}

	switch (parity) {
		case EVEN:
			init |= _COM_EVENPARITY; break;
		case ODD:
			init |= _COM_ODDPARITY; break;
		case NONE:
			init |= _COM_NOPARITY; break;
		default:
			throw Error("init", "Illegal parity.");
	}

	switch (databits) {
		case 7:
			init |= _COM_CHR7; break;
		case 8:
			init |= _COM_CHR8; break;
		default:
			throw Error("init", "Illegal number of data bits.");
	}

	switch (stopbits) {
		case 1:
			init |= _COM_STOP1; break;
		case 2:
			init |= _COM_STOP2; break;
		default:
			throw Error("init", "Illegal number of stop bits.");
	}

	debug_printf("init COM%d with 0x%X...\n", port_number+1, init);
	unsigned short status = _bios_serialcom(_COM_INIT, port_number, init);
	debug_printf("init COM%d, status:\n", port_number+1);
	printStatus(status);
}
///////////////////////////////////////////////////////////////////////////////
int
SerialPort::countPorts()
{
	unsigned short equip = _bios_equiplist();
	return (equip & 0x0c00) >> 9;
}
///////////////////////////////////////////////////////////////////////////////
void
SerialPort::write(char d)
{
	debug_printf("sending %X...\n", d);
	unsigned short status = _bios_serialcom(_COM_SEND, port_number, d);

	if (status & 0x8000) {
		debug_printf("error sending (0x%4.4X)\n", status);
		printStatus(getStatus());
	}
}
///////////////////////////////////////////////////////////////////////////////
char
SerialPort::waitForData()
{
	debug_printf("waiting for data...\n");
	unsigned short status = _bios_serialcom(_COM_RECEIVE, port_number, 0);

	if (status != 0)
		debug_printf("read: serial status: %4.4X\n", status);

	if (status & 0xFF00 > 0)
		debug_printf("error\n");

	// TODO: check for error

	return (char) (status & 0x00FF);
}
///////////////////////////////////////////////////////////////////////////////
unsigned short
SerialPort::getStatus()
{
	return _bios_serialcom(_COM_STATUS, port_number, 0);
}
///////////////////////////////////////////////////////////////////////////////
void
SerialPort::printStatus(unsigned short status)
{
	if (status)
		debug_printf("COM%d status (0x%4.4X):\n", port_number+1, status);

	if (status & 0x8000) debug_printf("timeout\n");
	if (status & 0x4000) debug_printf("transmit reg empty\n");
	if (status & 0x2000) debug_printf("transmit holding reg empty\n");
	if (status & 0x1000) debug_printf("break detected\n");
	if (status & 0x0800) debug_printf("framing error\n");
	if (status & 0x0400) debug_printf("parity error\n");
	if (status & 0x0200) debug_printf("overrun error\n");
	if (status & 0x0100) debug_printf("data ready\n");
	if (status & 0x0080) debug_printf("receive line signal detected\n");
	if (status & 0x0040) debug_printf("ring indicator\n");
	if (status & 0x0020) debug_printf("data-set ready\n");
	if (status & 0x0010) debug_printf("clear to send\n");
	if (status & 0x0008) debug_printf("receive line signal detector changed\n");
	if (status & 0x0004) debug_printf("trailing edge ring detector\n");
	if (status & 0x0002) debug_printf("data set ready changed\n");
	if (status & 0x0001) debug_printf("clear to send changed\n");
}
///////////////////////////////////////////////////////////////////////////////
