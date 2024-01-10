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

#ifndef VMDL_VEHICLE_CABIN_REARVIEWMIRROR_H
#define VMDL_VEHICLE_CABIN_REARVIEWMIRROR_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle::cabin {
using ParentClass = Model;

/** RearviewMirror model. */
class RearviewMirror : public ParentClass {
public:

    RearviewMirror(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		DimmingLevel("DimmingLevel", this)
    {}

    /**
    * DimmingLevel: actuator
    * Dimming level of rearview mirror. 0 = undimmed. 100 = fully dimmed.
    *
    * Value range: [, 100]
    * Unit: percent
    **/
    DataPointUint32 DimmingLevel;

};
} // namespace velocitas::vehicle::cabin
#endif // VMDL_VEHICLE_CABIN_REARVIEWMIRROR_H
