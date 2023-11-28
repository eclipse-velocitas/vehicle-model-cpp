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

#ifndef VMDL_VEHICLE_CABIN_SEAT_BACKREST_LUMBAR_H
#define VMDL_VEHICLE_CABIN_SEAT_BACKREST_LUMBAR_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle::cabin::seat::backrest {
using ParentClass = Model;

/** Lumbar model. */
class Lumbar : public ParentClass {
public:

    Lumbar(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		Support("Support", this),
		Height("Height", this)
    {}

    /**
    * Support: actuator
    * Lumbar support (in/out position). 0 = Innermost position. 100 = Outermost position.
    *
    * Value range: [0, 100]
    * Unit: percent
    **/
    DataPointFloat Support;

    /**
    * Height: actuator
    * Height of lumbar support. Position is relative within available movable range of the lumbar support. 0 = Lowermost position supported.
    *
    * Value range: [0, ]
    * Unit: mm
    **/
    DataPointUint32 Height;

};
} // namespace velocitas::vehicle::cabin::seat::backrest
#endif // VMDL_VEHICLE_CABIN_SEAT_BACKREST_LUMBAR_H
