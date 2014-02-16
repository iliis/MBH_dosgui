#ifndef __PRINTER_H_INCLUDED__
#define __PRINTER_H_INCLUDED__

#include "temperature_sensor.h"
#include "temperature_controller.h"

class Printer {
	TemperatureController left_extruder,
						  right_extruder,
						  platform,
						  interior;

public:

	void stop(){};
	void pause(){};
};

#endif
