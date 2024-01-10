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

#ifndef VMDL_VEHICLE_CABIN_SEAT_HEADREST_H
#define VMDL_VEHICLE_CABIN_SEAT_HEADREST_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle::cabin::seat {
using ParentClass = Model;

/** Headrest model. */
class Headrest : public ParentClass {
public:

    Headrest(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		Height("Height", this),
		Angle("Angle", this)
    {}

    /**
    * Height: actuator
    * Position of headrest relative to movable range of the head rest. 0 = Bottommost position supported.
    *
    * Value range: [0, ]
    * Unit: mm
    **/
    DataPointUint32 Height;

    /**
    * Angle: actuator
    * Headrest angle, relative to backrest, 0 degrees if parallel to backrest, Positive degrees = tilted forward.
    *
    * Unit: degrees
    **/
    DataPointFloat Angle;

};
} // namespace velocitas::vehicle::cabin::seat
#endif // VMDL_VEHICLE_CABIN_SEAT_HEADREST_H
