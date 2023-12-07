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

#ifndef VMDL_VEHICLE_CHASSIS_STEERINGWHEEL_H
#define VMDL_VEHICLE_CHASSIS_STEERINGWHEEL_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle::chassis {
using ParentClass = Model;

/** SteeringWheel model. */
class SteeringWheel : public ParentClass {
public:

    SteeringWheel(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		Angle("Angle", this),
		Tilt("Tilt", this),
		Extension("Extension", this),
		Position("Position", this)
    {}

    /**
    * Angle: sensor
    * Steering wheel angle. Positive = degrees to the left. Negative = degrees to the right.
    *
    * Unit: degrees
    **/
    DataPointInt32 Angle;

    /**
    * Tilt: actuator
    * Steering wheel column tilt. 0 = Lowest position. 100 = Highest position.
    *
    * Value range: [0, 100]
    * Unit: percent
    **/
    DataPointUint32 Tilt;

    /**
    * Extension: actuator
    * Steering wheel column extension from dashboard. 0 = Closest to dashboard. 100 = Furthest from dashboard.
    *
    * Value range: [0, 100]
    * Unit: percent
    **/
    DataPointUint32 Extension;

    /**
    * Position: attribute (string)
    * Position of the steering wheel on the left or right side of the vehicle.
    *
    * Allowed values: FRONT_LEFT, FRONT_RIGHT
    **/
    DataPointString Position;

};
} // namespace velocitas::vehicle::chassis
#endif // VMDL_VEHICLE_CHASSIS_STEERINGWHEEL_H
