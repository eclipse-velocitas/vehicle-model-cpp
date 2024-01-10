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

#ifndef VMDL_VEHICLE_OBD_CATALYST_BANK2_H
#define VMDL_VEHICLE_OBD_CATALYST_BANK2_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle::obd::catalyst {
using ParentClass = Model;

/** Bank2 model. */
class Bank2 : public ParentClass {
public:

    Bank2(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		Temperature1("Temperature1", this),
		Temperature2("Temperature2", this)
    {}

    /**
    * Temperature1: sensor
    * PID 3D - Catalyst temperature from bank 2, sensor 1
    *
    * Unit: celsius
    **/
    DataPointFloat Temperature1;

    /**
    * Temperature2: sensor
    * PID 3F - Catalyst temperature from bank 2, sensor 2
    *
    * Unit: celsius
    **/
    DataPointFloat Temperature2;

};
} // namespace velocitas::vehicle::obd::catalyst
#endif // VMDL_VEHICLE_OBD_CATALYST_BANK2_H
