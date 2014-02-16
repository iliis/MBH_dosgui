#ifndef __TEMPERATURE_CONTROLLER_H_INCLUDED__
#define __TEMPERATURE_CONTROLLER_H_INCLUDED__

#include "temperature_sensor.h"

class TemperatureController : public TemperatureSensor {
	float target;
public:
	TemperatureController() : target(0) {};

	void  setTargetTemp(float target);
	float getTargetTemp();
	
	// TODO: add history for plots
};

#endif
