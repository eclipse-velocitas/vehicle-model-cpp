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

#ifndef VMDL_VEHICLE_CABIN_HVAC_STATION_H
#define VMDL_VEHICLE_CABIN_HVAC_STATION_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle::cabin::hvac {
using ParentClass = Model;

/** Station model. */
class Station : public ParentClass {
public:

    Station(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		FanSpeed("FanSpeed", this),
		Temperature("Temperature", this),
		AirDistribution("AirDistribution", this)
    {}

    /**
    * FanSpeed: actuator
    * Fan Speed, 0 = off. 100 = max
    *
    * Value range: [0, 100]
    * Unit: percent
    **/
    DataPointUint32 FanSpeed;

    /**
    * Temperature: actuator
    * Temperature
    *
    * Unit: celsius
    **/
    DataPointInt32 Temperature;

    /**
    * AirDistribution: actuator
    * Direction of airstream
    *
    * Allowed values: UP, MIDDLE, DOWN
    **/
    DataPointString AirDistribution;

};
} // namespace velocitas::vehicle::cabin::hvac
#endif // VMDL_VEHICLE_CABIN_HVAC_STATION_H
