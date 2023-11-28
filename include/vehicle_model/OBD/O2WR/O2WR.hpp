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

#ifndef VMDL_VEHICLE_OBD_O2WR_H
#define VMDL_VEHICLE_OBD_O2WR_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle::obd {
using ParentClass = Model;

/** O2WR model. */
class O2WR : public ParentClass {
public:

    O2WR(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		Lambda("Lambda", this),
		Voltage("Voltage", this),
		Current("Current", this)
    {}

    /**
    * Lambda: sensor
    * PID 2x (byte AB) and PID 3x (byte AB) - Lambda for wide range/band oxygen sensor
    *
    **/
    DataPointFloat Lambda;

    /**
    * Voltage: sensor
    * PID 2x (byte CD) - Voltage for wide range/band oxygen sensor
    *
    * Unit: V
    **/
    DataPointFloat Voltage;

    /**
    * Current: sensor
    * PID 3x (byte CD) - Current for wide range/band oxygen sensor
    *
    * Unit: A
    **/
    DataPointFloat Current;

};
} // namespace velocitas::vehicle::obd
#endif // VMDL_VEHICLE_OBD_O2WR_H
