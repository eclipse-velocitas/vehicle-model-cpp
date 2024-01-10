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

#ifndef VMDL_VEHICLE_BODY_WINDSHIELD_H
#define VMDL_VEHICLE_BODY_WINDSHIELD_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

#include "vehicle_model/Body/Windshield/WasherFluid/WasherFluid.hpp"
#include "vehicle_model/Body/Windshield/Wiping/Wiping.hpp"

namespace velocitas::vehicle::body {
using ParentClass = Model;

/** Windshield model. */
class Windshield : public ParentClass {
public:

    Windshield(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		Wiping("Wiping", this),
		IsHeatingOn("IsHeatingOn", this),
		WasherFluid("WasherFluid", this)
    {}

    /**
    * Wiping: branch
    * Windshield wiper signals.
    *
    **/
    vehicle::body::windshield::Wiping Wiping;

    /**
    * IsHeatingOn: actuator
    * Windshield heater status. False - off, True - on.
    *
    **/
    DataPointBoolean IsHeatingOn;

    /**
    * WasherFluid: branch
    * Windshield washer fluid signals
    *
    **/
    vehicle::body::windshield::WasherFluid WasherFluid;

};
} // namespace velocitas::vehicle::body
#endif // VMDL_VEHICLE_BODY_WINDSHIELD_H
