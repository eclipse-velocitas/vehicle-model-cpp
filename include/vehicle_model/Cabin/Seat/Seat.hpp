/**
 * Copyright (c) 2023 Contributors to the Eclipse Foundation
 *
 * This program and the accompanying materials are made available under the
 * terms of the Apache License, Version 2.0 which is available at
 * https://www.apache.org/licenses/LICENSE-2.0.
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef VMDL_VEHICLE_CABIN_SEAT_H
#define VMDL_VEHICLE_CABIN_SEAT_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

#include "vehicle_model/Cabin/Seat/Airbag/Airbag.hpp"
#include "vehicle_model/Cabin/Seat/Backrest/Backrest.hpp"
#include "vehicle_model/Cabin/Seat/Headrest/Headrest.hpp"
#include "vehicle_model/Cabin/Seat/Occupant/Occupant.hpp"
#include "vehicle_model/Cabin/Seat/Seating/Seating.hpp"
#include "vehicle_model/Cabin/Seat/Switch/Switch.hpp"

namespace velocitas::vehicle::cabin {
using ParentClass = Model;

/** Seat model. */
class Seat : public ParentClass {
public:

    Seat(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		IsOccupied("IsOccupied", this),
		Occupant("Occupant", this),
		IsBelted("IsBelted", this),
		Heating("Heating", this),
		Massage("Massage", this),
		Position("Position", this),
		Height("Height", this),
		Tilt("Tilt", this),
		Backrest("Backrest", this),
		Seating("Seating", this),
		Headrest("Headrest", this),
		Airbag("Airbag", this),
		Switch("Switch", this)
    {}

    /**
    * IsOccupied: sensor
    * Does the seat have a passenger in it.
    *
    **/
    DataPointBoolean IsOccupied;

    /**
    * Occupant: branch
    * Occupant data.
    *
    **/
    vehicle::cabin::seat::Occupant Occupant;

    /**
    * IsBelted: sensor
    * Is the belt engaged.
    *
    **/
    DataPointBoolean IsBelted;

    /**
    * Heating: actuator
    * Seat cooling / heating. 0 = off. -100 = max cold. +100 = max heat.
    *
    * Value range: [-100, 100]
    * Unit: percent
    **/
    DataPointInt32 Heating;

    /**
    * Massage: actuator
    * Seat massage level. 0 = off. 100 = max massage.
    *
    * Value range: [0, 100]
    * Unit: percent
    **/
    DataPointUint32 Massage;

    /**
    * Position: actuator
    * Seat position on vehicle x-axis. Position is relative to the frontmost position supported by the seat. 0 = Frontmost position supported.
    *
    * Value range: [0, ]
    * Unit: mm
    **/
    DataPointUint32 Position;

    /**
    * Height: actuator
    * Seat position on vehicle z-axis. Position is relative within available movable range of the seating. 0 = Lowermost position supported.
    *
    * Value range: [0, ]
    * Unit: mm
    **/
    DataPointUint32 Height;

    /**
    * Tilt: actuator
    * Tilting of seat relative to vehicle z-axis. 0 = seating is flat, seat and vehicle z-axis are parallel. Positive degrees = seat tilted backwards, seat z-axis is tilted backward.
    *
    * Unit: degrees
    **/
    DataPointFloat Tilt;

    /**
    * Backrest: branch
    * Describes signals related to the backrest of the seat.
    *
    **/
    vehicle::cabin::seat::Backrest Backrest;

    /**
    * Seating: branch
    * Describes signals related to the seating/base of the seat.
    *
    * Seating is here considered as the part of the seat that supports the thighs. Additional cushions (if any) for support of lower legs is not covered by this branch.
    *
    **/
    vehicle::cabin::seat::Seating Seating;

    /**
    * Headrest: branch
    * Headrest settings.
    *
    **/
    vehicle::cabin::seat::Headrest Headrest;

    /**
    * Airbag: branch
    * Airbag signals.
    *
    **/
    vehicle::cabin::seat::Airbag Airbag;

    /**
    * Switch: branch
    * Seat switch signals
    *
    **/
    vehicle::cabin::seat::Switch Switch;

};
} // namespace velocitas::vehicle::cabin
#endif // VMDL_VEHICLE_CABIN_SEAT_H
