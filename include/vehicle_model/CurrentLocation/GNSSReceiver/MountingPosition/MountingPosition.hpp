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

#ifndef VMDL_VEHICLE_CURRENTLOCATION_GNSSRECEIVER_MOUNTINGPOSITION_H
#define VMDL_VEHICLE_CURRENTLOCATION_GNSSRECEIVER_MOUNTINGPOSITION_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle::currentlocation::gnssreceiver {
using ParentClass = Model;

/** MountingPosition model. */
class MountingPosition : public ParentClass {
public:

    MountingPosition(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		X("X", this),
		Y("Y", this),
		Z("Z", this)
    {}

    /**
    * X: attribute (int16)
    * Mounting position of GNSS receiver antenna relative to vehicle coordinate system. Axis definitions according to ISO 8855. Origin at center of (first) rear axle. Positive values = forward of rear axle. Negative values = backward of rear axle.
    *
    * Unit: mm
    **/
    DataPointInt32 X;

    /**
    * Y: attribute (int16)
    * Mounting position of GNSS receiver antenna relative to vehicle coordinate system. Axis definitions according to ISO 8855. Origin at center of (first) rear axle. Positive values = left of origin. Negative values = right of origin. Left/Right is as seen from driver perspective, i.e. by a person looking forward.
    *
    * Unit: mm
    **/
    DataPointInt32 Y;

    /**
    * Z: attribute (int16)
    * Mounting position of GNSS receiver on Z-axis. Axis definitions according to ISO 8855. Origin at center of (first) rear axle. Positive values = above center of rear axle. Negative values = below center of rear axle.
    *
    * Unit: mm
    **/
    DataPointInt32 Z;

};
} // namespace velocitas::vehicle::currentlocation::gnssreceiver
#endif // VMDL_VEHICLE_CURRENTLOCATION_GNSSRECEIVER_MOUNTINGPOSITION_H
