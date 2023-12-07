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

#ifndef VMDL_VEHICLE_EXTERIOR_H
#define VMDL_VEHICLE_EXTERIOR_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle {
using ParentClass = Model;

/** Exterior model. */
class Exterior : public ParentClass {
public:

    Exterior(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		AirTemperature("AirTemperature", this),
		Humidity("Humidity", this),
		LightIntensity("LightIntensity", this)
    {}

    /**
    * AirTemperature: sensor
    * Air temperature outside the vehicle.
    *
    * Unit: celsius
    **/
    DataPointFloat AirTemperature;

    /**
    * Humidity: sensor
    * Relative humidity outside the vehicle. 0 = Dry, 100 = Air fully saturated.
    *
    * Value range: [0, 100]
    * Unit: percent
    **/
    DataPointFloat Humidity;

    /**
    * LightIntensity: sensor
    * Light intensity outside the vehicle. 0 = No light detected, 100 = Fully lit.
    *
    * Mapping to physical units and calculation method is sensor specific.
    *
    * Value range: [0, 100]
    * Unit: percent
    **/
    DataPointFloat LightIntensity;

};
} // namespace velocitas::vehicle
#endif // VMDL_VEHICLE_EXTERIOR_H
