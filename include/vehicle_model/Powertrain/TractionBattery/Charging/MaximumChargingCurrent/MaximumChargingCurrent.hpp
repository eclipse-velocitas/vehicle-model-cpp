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

#ifndef VMDL_VEHICLE_POWERTRAIN_TRACTIONBATTERY_CHARGING_MAXIMUMCHARGINGCURRENT_H
#define VMDL_VEHICLE_POWERTRAIN_TRACTIONBATTERY_CHARGING_MAXIMUMCHARGINGCURRENT_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle::powertrain::tractionbattery::charging {
using ParentClass = Model;

/** MaximumChargingCurrent model. */
class MaximumChargingCurrent : public ParentClass {
public:

    MaximumChargingCurrent(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		DC("DC", this),
		Phase1("Phase1", this),
		Phase2("Phase2", this),
		Phase3("Phase3", this)
    {}

    /**
    * DC: sensor
    * Maximum DC charging current at inlet that can be accepted by the system.
    *
    * Unit: A
    **/
    DataPointFloat DC;

    /**
    * Phase1: sensor
    * Maximum AC charging current (rms) at inlet for Phase 1 that can be accepted by the system.
    *
    * Unit: A
    **/
    DataPointFloat Phase1;

    /**
    * Phase2: sensor
    * Maximum AC charging current (rms) at inlet for Phase 2 that can be accepted by the system.
    *
    * Unit: A
    **/
    DataPointFloat Phase2;

    /**
    * Phase3: sensor
    * Maximum AC charging current (rms) at inlet for Phase 3 that can be accepted by the system.
    *
    * Unit: A
    **/
    DataPointFloat Phase3;

};
} // namespace velocitas::vehicle::powertrain::tractionbattery::charging
#endif // VMDL_VEHICLE_POWERTRAIN_TRACTIONBATTERY_CHARGING_MAXIMUMCHARGINGCURRENT_H
