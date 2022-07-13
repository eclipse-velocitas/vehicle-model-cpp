#ifndef VMDL_VEHICLE_POWERTRAIN_ELECTRICMOTOR_H
#define VMDL_VEHICLE_POWERTRAIN_ELECTRICMOTOR_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle::powertrain {
using ParentClass = Model;

/** ElectricMotor model. */
class ElectricMotor : public ParentClass {
public:

    ElectricMotor(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		EngineCode("EngineCode", this),
		MaxPower("MaxPower", this),
		MaxTorque("MaxTorque", this),
		MaxRegenPower("MaxRegenPower", this),
		MaxRegenTorque("MaxRegenTorque", this),
		Speed("Speed", this),
		Temperature("Temperature", this),
		CoolantTemperature("CoolantTemperature", this),
		Power("Power", this),
		Torque("Torque", this)
    {}

    /**
    * EngineCode: attribute (string)
    * Engine code designation, as specified by vehicle manufacturer.
    *
    **/
    DataPointString EngineCode;

    /**
    * MaxPower: attribute (uint16)
    * Peak power, in kilowatts, that motor(s) can generate.
    *
    * Unit: kW
    **/
    DataPointUint32 MaxPower;

    /**
    * MaxTorque: attribute (uint16)
    * Peak power, in newton meter, that the motor(s) can generate.
    *
    * Unit: Nm
    **/
    DataPointUint32 MaxTorque;

    /**
    * MaxRegenPower: attribute (uint16)
    * Peak regen/brake power, in kilowatts, that motor(s) can generate.
    *
    * Unit: kW
    **/
    DataPointUint32 MaxRegenPower;

    /**
    * MaxRegenTorque: attribute (uint16)
    * Peak regen/brake torque, in newton meter, that the motor(s) can generate.
    *
    * Unit: Nm
    **/
    DataPointUint32 MaxRegenTorque;

    /**
    * Speed: sensor
    * Motor rotational speed measured as rotations per minute. Negative values indicate reverse driving mode.
    *
    * Unit: rpm
    **/
    DataPointInt32 Speed;

    /**
    * Temperature: sensor
    * Motor temperature.
    *
    * Unit: celsius
    **/
    DataPointInt32 Temperature;

    /**
    * CoolantTemperature: sensor
    * Motor coolant temperature (if applicable).
    *
    * Unit: celsius
    **/
    DataPointInt32 CoolantTemperature;

    /**
    * Power: sensor
    * Current motor power output. Negative values indicate regen mode.
    *
    * Unit: kW
    **/
    DataPointInt32 Power;

    /**
    * Torque: sensor
    * Current motor torque. Negative values indicate regen mode.
    *
    * Unit: Nm
    **/
    DataPointInt32 Torque;

};
} // namespace velocitas::vehicle::powertrain
#endif // VMDL_VEHICLE_POWERTRAIN_ELECTRICMOTOR_H
