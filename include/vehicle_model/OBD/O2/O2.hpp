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

#ifndef VMDL_VEHICLE_OBD_O2_H
#define VMDL_VEHICLE_OBD_O2_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle::obd {
using ParentClass = Model;

/** O2 model. */
class O2 : public ParentClass {
public:

    O2(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		Voltage("Voltage", this),
		ShortTermFuelTrim("ShortTermFuelTrim", this)
    {}

    /**
    * Voltage: sensor
    * PID 1x (byte A) - Sensor voltage
    *
    * Unit: V
    **/
    DataPointFloat Voltage;

    /**
    * ShortTermFuelTrim: sensor
    * PID 1x (byte B) - Short term fuel trim
    *
    * Unit: percent
    **/
    DataPointFloat ShortTermFuelTrim;

};
} // namespace velocitas::vehicle::obd
#endif // VMDL_VEHICLE_OBD_O2_H
