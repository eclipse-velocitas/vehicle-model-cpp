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

#ifndef VMDL_VEHICLE_CABIN_SEAT_SWITCH_HEADREST_H
#define VMDL_VEHICLE_CABIN_SEAT_SWITCH_HEADREST_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle::cabin::seat::switch_ {
using ParentClass = Model;

/** Headrest model. */
class Headrest : public ParentClass {
public:

    Headrest(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		IsUpEngaged("IsUpEngaged", this),
		IsDownEngaged("IsDownEngaged", this),
		IsForwardEngaged("IsForwardEngaged", this),
		IsBackwardEngaged("IsBackwardEngaged", this)
    {}

    /**
    * IsUpEngaged: actuator
    * Head rest up switch engaged (SingleSeat.Headrest.Height).
    *
    **/
    DataPointBoolean IsUpEngaged;

    /**
    * IsDownEngaged: actuator
    * Head rest down switch engaged (SingleSeat.Headrest.Height).
    *
    **/
    DataPointBoolean IsDownEngaged;

    /**
    * IsForwardEngaged: actuator
    * Head rest forward switch engaged (SingleSeat.Headrest.Angle).
    *
    **/
    DataPointBoolean IsForwardEngaged;

    /**
    * IsBackwardEngaged: actuator
    * Head rest backward switch engaged (SingleSeat.Headrest.Angle).
    *
    **/
    DataPointBoolean IsBackwardEngaged;

};
} // namespace velocitas::vehicle::cabin::seat::switch_
#endif // VMDL_VEHICLE_CABIN_SEAT_SWITCH_HEADREST_H
