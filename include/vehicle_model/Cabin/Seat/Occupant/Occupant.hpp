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

#ifndef VMDL_VEHICLE_CABIN_SEAT_OCCUPANT_H
#define VMDL_VEHICLE_CABIN_SEAT_OCCUPANT_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

#include "vehicle_model/Cabin/Seat/Occupant/Identifier/Identifier.hpp"

namespace velocitas::vehicle::cabin::seat {
using ParentClass = Model;

/** Occupant model. */
class Occupant : public ParentClass {
public:

    Occupant(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		Identifier("Identifier", this)
    {}

    /**
    * Identifier: branch
    * Identifier attributes based on OAuth 2.0.
    *
    **/
    vehicle::cabin::seat::occupant::Identifier Identifier;

};
} // namespace velocitas::vehicle::cabin::seat
#endif // VMDL_VEHICLE_CABIN_SEAT_OCCUPANT_H
