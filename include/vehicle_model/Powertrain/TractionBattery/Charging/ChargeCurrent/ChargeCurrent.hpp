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

#ifndef VMDL_VEHICLE_POWERTRAIN_TRACTIONBATTERY_CHARGING_CHARGECURRENT_H
#define VMDL_VEHICLE_POWERTRAIN_TRACTIONBATTERY_CHARGING_CHARGECURRENT_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle::powertrain::tractionbattery::charging {
using ParentClass = Model;

/** ChargeCurrent model. */
class ChargeCurrent : public ParentClass {
public:

    ChargeCurrent(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		DC("DC", this),
		Phase1("Phase1", this),
		Phase2("Phase2", this),
		Phase3("Phase3", this)
    {}

    /**
    * DC: sensor
    * Current DC charging current at inlet. Negative if returning energy to grid.
    *
    * Unit: A
    **/
    DataPointFloat DC;

    /**
    * Phase1: sensor
    * Current AC charging current (rms) at inlet for Phase 1. Negative if returning energy to grid.
    *
    * Unit: A
    **/
    DataPointFloat Phase1;

    /**
    * Phase2: sensor
    * Current AC charging current (rms) at inlet for Phase 2. Negative if returning energy to grid.
    *
    * Unit: A
    **/
    DataPointFloat Phase2;

    /**
    * Phase3: sensor
    * Current AC charging current (rms) at inlet for Phase 3. Negative if returning energy to grid.
    *
    * Unit: A
    **/
    DataPointFloat Phase3;

};
} // namespace velocitas::vehicle::powertrain::tractionbattery::charging
#endif // VMDL_VEHICLE_POWERTRAIN_TRACTIONBATTERY_CHARGING_CHARGECURRENT_H
