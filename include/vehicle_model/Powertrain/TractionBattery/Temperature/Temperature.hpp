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

#ifndef VMDL_VEHICLE_POWERTRAIN_TRACTIONBATTERY_TEMPERATURE_H
#define VMDL_VEHICLE_POWERTRAIN_TRACTIONBATTERY_TEMPERATURE_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle::powertrain::tractionbattery {
using ParentClass = Model;

/** Temperature model. */
class Temperature : public ParentClass {
public:

    Temperature(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		Average("Average", this),
		Min("Min", this),
		Max("Max", this)
    {}

    /**
    * Average: sensor
    * Current average temperature of the battery cells.
    *
    * Unit: celsius
    **/
    DataPointFloat Average;

    /**
    * Min: sensor
    * Current minimum temperature of the battery cells, i.e. temperature of the coldest cell.
    *
    * Unit: celsius
    **/
    DataPointFloat Min;

    /**
    * Max: sensor
    * Current maximum temperature of the battery cells, i.e. temperature of the hottest cell.
    *
    * Unit: celsius
    **/
    DataPointFloat Max;

};
} // namespace velocitas::vehicle::powertrain::tractionbattery
#endif // VMDL_VEHICLE_POWERTRAIN_TRACTIONBATTERY_TEMPERATURE_H
