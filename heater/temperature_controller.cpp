#include "temperature_controller.h"

///////////////////////////////////////////////////////////////////////////////
void
TemperatureController::setTargetTemp(float target)
{
	this->target = target;

	// TODO: handle communication here
}
///////////////////////////////////////////////////////////////////////////////
float
TemperatureController::getTargetTemp()
{
	return this->target;
}
///////////////////////////////////////////////////////////////////////////////
