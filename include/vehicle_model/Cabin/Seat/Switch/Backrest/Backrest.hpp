/**
 * Copyright (c) 2023-2024 Contributors to the Eclipse Foundation
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

#ifndef VMDL_VEHICLE_CABIN_SEAT_SWITCH_BACKREST_H
#define VMDL_VEHICLE_CABIN_SEAT_SWITCH_BACKREST_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

#include "vehicle_model/Cabin/Seat/Switch/Backrest/Lumbar/Lumbar.hpp"
#include "vehicle_model/Cabin/Seat/Switch/Backrest/SideBolster/SideBolster.hpp"

namespace velocitas::vehicle::cabin::seat::switch_ {
using ParentClass = Model;

/** Backrest model. */
class Backrest : public ParentClass {
public:

    Backrest(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		IsReclineForwardEngaged("IsReclineForwardEngaged", this),
		IsReclineBackwardEngaged("IsReclineBackwardEngaged", this),
		Lumbar("Lumbar", this),
		SideBolster("SideBolster", this)
    {}

    /**
    * IsReclineForwardEngaged: actuator
    * Backrest recline forward switch engaged (SingleSeat.Backrest.Recline).
    *
    **/
    DataPointBoolean IsReclineForwardEngaged;

    /**
    * IsReclineBackwardEngaged: actuator
    * Backrest recline backward switch engaged (SingleSeat.Backrest.Recline).
    *
    **/
    DataPointBoolean IsReclineBackwardEngaged;

    /**
    * Lumbar: branch
    * Switches for SingleSeat.Backrest.Lumbar.
    *
    **/
    vehicle::cabin::seat::switch_::backrest::Lumbar Lumbar;

    /**
    * SideBolster: branch
    * Switches for SingleSeat.Backrest.SideBolster.
    *
    **/
    vehicle::cabin::seat::switch_::backrest::SideBolster SideBolster;

};
} // namespace velocitas::vehicle::cabin::seat::switch_
#endif // VMDL_VEHICLE_CABIN_SEAT_SWITCH_BACKREST_H
