#ifndef VMDL_VEHICLE_CABIN_H
#define VMDL_VEHICLE_CABIN_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

#include "vehicle_model/Cabin/Convertible/Convertible.hpp"
#include "vehicle_model/Cabin/Door/Door.hpp"
#include "vehicle_model/Cabin/HVAC/HVAC.hpp"
#include "vehicle_model/Cabin/Infotainment/Infotainment.hpp"
#include "vehicle_model/Cabin/Lights/Lights.hpp"
#include "vehicle_model/Cabin/RearShade/RearShade.hpp"
#include "vehicle_model/Cabin/RearviewMirror/RearviewMirror.hpp"
#include "vehicle_model/Cabin/Seat/Seat.hpp"
#include "vehicle_model/Cabin/SeatService/SeatService.hpp"
#include "vehicle_model/Cabin/Sunroof/Sunroof.hpp"

#include <stdexcept>

namespace velocitas::vehicle {
using ParentClass = Model;

/** Cabin model. */
class Cabin : public ParentClass {
public:
    class DoorCollection : public ParentClass {
    public:
        class RowType : public ParentClass {
        public:
            RowType(std::string name, ParentClass* parent):
                ParentClass(name, parent),
                Left("Left", this),
                Right("Right", this)
            {
            }

            vehicle::cabin::Door Left;
            vehicle::cabin::Door Right;
        };

        DoorCollection(ParentClass* parent):
            ParentClass("Door", parent),
            Row1("Row1", this),
            Row2("Row2", this)
        {
        }

        RowType& Row(int index) {
            if (index == 1) {
                return Row1;
            }
            if (index == 2) {
                return Row2;
            }
            throw std::runtime_error("Given value is outside of allowed range [1;2]!");
        }

        RowType Row1;
        RowType Row2;
    };


    class SeatCollection : public ParentClass {
    public:
        class RowType : public ParentClass {
        public:
            RowType(std::string name, ParentClass* parent):
                ParentClass(name, parent),
                Pos1("Pos1", this),
                Pos2("Pos2", this),
                Pos3("Pos3", this)
            {
            }

            vehicle::cabin::Seat& Pos(int index) {
                if (index == 1) {
                    return Pos1;
                }
                if (index == 2) {
                    return Pos2;
                }
                if (index == 3) {
                    return Pos3;
                }
                throw std::runtime_error("Given value is outside of allowed range [1;3]!");
            }

            vehicle::cabin::Seat Pos1;
            vehicle::cabin::Seat Pos2;
            vehicle::cabin::Seat Pos3;
        };

        SeatCollection(ParentClass* parent):
            ParentClass("Seat", parent),
            Row1("Row1", this),
            Row2("Row2", this)
        {
        }

        RowType& Row(int index) {
            if (index == 1) {
                return Row1;
            }
            if (index == 2) {
                return Row2;
            }
            throw std::runtime_error("Given value is outside of allowed range [1;2]!");
        }

        RowType Row1;
        RowType Row2;
    };

    Cabin(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		RearShade("RearShade", this),
		HVAC("HVAC", this),
		Infotainment("Infotainment", this),
		Sunroof("Sunroof", this),
		RearviewMirror("RearviewMirror", this),
		Lights("Lights", this),
		Door(this),
		DoorCount("DoorCount", this),
		Seat(this),
		SeatService(this),
		DriverPosition("DriverPosition", this),
		SeatRowCount("SeatRowCount", this),
		SeatPosCount("SeatPosCount", this),
		Convertible("Convertible", this)
    {}

    /**
    * RearShade: branch
    * Rear window shade.
    *
    **/
    vehicle::cabin::RearShade RearShade;

    /**
    * HVAC: branch
    * Climate control
    *
    **/
    vehicle::cabin::HVAC HVAC;

    /**
    * Infotainment: branch
    * Infotainment system.
    *
    **/
    vehicle::cabin::Infotainment Infotainment;

    /**
    * Sunroof: branch
    * Sun roof status.
    *
    **/
    vehicle::cabin::Sunroof Sunroof;

    /**
    * RearviewMirror: branch
    * Rearview mirror.
    *
    **/
    vehicle::cabin::RearviewMirror RearviewMirror;

    /**
    * Lights: branch
    * Interior lights signals and sensors.
    *
    **/
    vehicle::cabin::Lights Lights;

    /**
    * Door: branch
    * All doors, including windows and switches.
    *
    **/
    DoorCollection Door;

    /**
    * DoorCount: attribute (uint8)
    * Number of doors in vehicle.
    *
    **/
    DataPointUint32 DoorCount;

    /**
    * Seat: branch
    * All seats.
    *
    **/
    SeatCollection Seat;
    vehicle::cabin::SeatService SeatService;

    /**
    * DriverPosition: attribute (uint8)
    * The position of the driver seat in row 1.
    *
    * Default value is position 1, i.e. a typical LHD vehicle.
    *
    **/
    DataPointUint32 DriverPosition;

    /**
    * SeatRowCount: attribute (uint8)
    * Number of seat rows in vehicle.
    *
    * Default value corresponds to two rows of seats.
    *
    **/
    DataPointUint32 SeatRowCount;

    /**
    * SeatPosCount: attribute (uint8[])
    * Number of seats across each row from the front to the rear.
    *
    * Default value corresponds to two seats in front row and 3 seats in second row.
    *
    **/
    DataPointUint32Array SeatPosCount;

    /**
    * Convertible: branch
    * Convertible roof.
    *
    **/
    vehicle::cabin::Convertible Convertible;

};
} // namespace velocitas::vehicle
#endif // VMDL_VEHICLE_CABIN_H
