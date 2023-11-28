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

#ifndef VMDL_VEHICLE_CHASSIS_ACCELERATOR_H
#define VMDL_VEHICLE_CHASSIS_ACCELERATOR_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle::chassis {
using ParentClass = Model;

/** Accelerator model. */
class Accelerator : public ParentClass {
public:

    Accelerator(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		PedalPosition("PedalPosition", this)
    {}

    /**
    * PedalPosition: sensor
    * Accelerator pedal position as percent. 0 = Not depressed. 100 = Fully depressed.
    *
    * Value range: [0, 100]
    * Unit: percent
    **/
    DataPointUint32 PedalPosition;

};
} // namespace velocitas::vehicle::chassis
#endif // VMDL_VEHICLE_CHASSIS_ACCELERATOR_H
