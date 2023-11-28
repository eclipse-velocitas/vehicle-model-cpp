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

#ifndef VMDL_VEHICLE_POWERTRAIN_COMBUSTIONENGINE_DIESELEXHAUSTFLUID_H
#define VMDL_VEHICLE_POWERTRAIN_COMBUSTIONENGINE_DIESELEXHAUSTFLUID_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle::powertrain::combustionengine {
using ParentClass = Model;

/** DieselExhaustFluid model. */
class DieselExhaustFluid : public ParentClass {
public:

    DieselExhaustFluid(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		Capacity("Capacity", this),
		Level("Level", this),
		Range("Range", this),
		IsLevelLow("IsLevelLow", this)
    {}

    /**
    * Capacity: attribute (float)
    * Capacity in liters of the Diesel Exhaust Fluid Tank.
    *
    * Unit: l
    **/
    DataPointFloat Capacity;

    /**
    * Level: sensor
    * Level of the Diesel Exhaust Fluid tank as percent of capacity. 0 = empty. 100 = full.
    *
    * Value range: [0, 100]
    * Unit: percent
    **/
    DataPointUint32 Level;

    /**
    * Range: sensor
    * Remaining range in meters of the Diesel Exhaust Fluid present in the vehicle.
    *
    * Unit: m
    **/
    DataPointUint32 Range;

    /**
    * IsLevelLow: sensor
    * Indicates if the Diesel Exhaust Fluid level is low. True if level is low. Definition of low is vehicle dependent.
    *
    **/
    DataPointBoolean IsLevelLow;

};
} // namespace velocitas::vehicle::powertrain::combustionengine
#endif // VMDL_VEHICLE_POWERTRAIN_COMBUSTIONENGINE_DIESELEXHAUSTFLUID_H
