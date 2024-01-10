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

#ifndef VMDL_VEHICLE_POWERTRAIN_TRACTIONBATTERY_STATEOFCHARGE_H
#define VMDL_VEHICLE_POWERTRAIN_TRACTIONBATTERY_STATEOFCHARGE_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle::powertrain::tractionbattery {
using ParentClass = Model;

/** StateOfCharge model. */
class StateOfCharge : public ParentClass {
public:

    StateOfCharge(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		Current("Current", this),
		Displayed("Displayed", this)
    {}

    /**
    * Current: sensor
    * Physical state of charge of the high voltage battery, relative to net capacity. This is not necessarily the state of charge being displayed to the customer.
    *
    * Value range: [0, 100.0]
    * Unit: percent
    **/
    DataPointFloat Current;

    /**
    * Displayed: sensor
    * State of charge displayed to the customer.
    *
    * Value range: [0, 100.0]
    * Unit: percent
    **/
    DataPointFloat Displayed;

};
} // namespace velocitas::vehicle::powertrain::tractionbattery
#endif // VMDL_VEHICLE_POWERTRAIN_TRACTIONBATTERY_STATEOFCHARGE_H
