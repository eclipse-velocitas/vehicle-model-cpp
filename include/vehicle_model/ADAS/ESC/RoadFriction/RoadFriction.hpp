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

#ifndef VMDL_VEHICLE_ADAS_ESC_ROADFRICTION_H
#define VMDL_VEHICLE_ADAS_ESC_ROADFRICTION_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle::adas::esc {
using ParentClass = Model;

/** RoadFriction model. */
class RoadFriction : public ParentClass {
public:

    RoadFriction(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		MostProbable("MostProbable", this),
		LowerBound("LowerBound", this),
		UpperBound("UpperBound", this)
    {}

    /**
    * MostProbable: sensor
    * Most probable road friction, as calculated by the ESC system. Exact meaning of most probable is implementation specific. 0 = no friction, 100 = maximum friction.
    *
    * Value range: [0, 100]
    * Unit: percent
    **/
    DataPointFloat MostProbable;

    /**
    * LowerBound: sensor
    * Lower bound road friction, as calculated by the ESC system. 5% possibility that road friction is below this value. 0 = no friction, 100 = maximum friction.
    *
    * Value range: [0, 100]
    * Unit: percent
    **/
    DataPointFloat LowerBound;

    /**
    * UpperBound: sensor
    * Upper bound road friction, as calculated by the ESC system. 95% possibility that road friction is below this value. 0 = no friction, 100 = maximum friction.
    *
    * Value range: [0, 100]
    * Unit: percent
    **/
    DataPointFloat UpperBound;

};
} // namespace velocitas::vehicle::adas::esc
#endif // VMDL_VEHICLE_ADAS_ESC_ROADFRICTION_H
