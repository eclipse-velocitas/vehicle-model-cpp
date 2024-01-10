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

#ifndef VMDL_VEHICLE_CABIN_SEAT_SWITCH_SEATING_H
#define VMDL_VEHICLE_CABIN_SEAT_SWITCH_SEATING_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle::cabin::seat::switch_ {
using ParentClass = Model;

/** Seating model. */
class Seating : public ParentClass {
public:

    Seating(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		IsForwardEngaged("IsForwardEngaged", this),
		IsBackwardEngaged("IsBackwardEngaged", this)
    {}

    /**
    * IsForwardEngaged: actuator
    * Is switch to increase seating length engaged (SingleSeat.Seating.Length).
    *
    **/
    DataPointBoolean IsForwardEngaged;

    /**
    * IsBackwardEngaged: actuator
    * Is switch to decrease seating length engaged (SingleSeat.Seating.Length).
    *
    **/
    DataPointBoolean IsBackwardEngaged;

};
} // namespace velocitas::vehicle::cabin::seat::switch_
#endif // VMDL_VEHICLE_CABIN_SEAT_SWITCH_SEATING_H
