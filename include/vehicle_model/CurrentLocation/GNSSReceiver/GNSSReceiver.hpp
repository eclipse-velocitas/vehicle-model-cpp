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

#ifndef VMDL_VEHICLE_CURRENTLOCATION_GNSSRECEIVER_H
#define VMDL_VEHICLE_CURRENTLOCATION_GNSSRECEIVER_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

#include "vehicle_model/CurrentLocation/GNSSReceiver/MountingPosition/MountingPosition.hpp"

namespace velocitas::vehicle::currentlocation {
using ParentClass = Model;

/** GNSSReceiver model. */
class GNSSReceiver : public ParentClass {
public:

    GNSSReceiver(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		FixType("FixType", this),
		MountingPosition("MountingPosition", this)
    {}

    /**
    * FixType: sensor
    * Fix status of GNSS receiver.
    *
    * Allowed values: NONE, TWO_D, TWO_D_SATELLITE_BASED_AUGMENTATION, TWO_D_GROUND_BASED_AUGMENTATION, TWO_D_SATELLITE_AND_GROUND_BASED_AUGMENTATION, THREE_D, THREE_D_SATELLITE_BASED_AUGMENTATION, THREE_D_GROUND_BASED_AUGMENTATION, THREE_D_SATELLITE_AND_GROUND_BASED_AUGMENTATION
    **/
    DataPointString FixType;

    /**
    * MountingPosition: branch
    * Mounting position of GNSS receiver antenna relative to vehicle coordinate system. Axis definitions according to ISO 8855. Origin at center of (first) rear axle.
    *
    **/
    vehicle::currentlocation::gnssreceiver::MountingPosition MountingPosition;

};
} // namespace velocitas::vehicle::currentlocation
#endif // VMDL_VEHICLE_CURRENTLOCATION_GNSSRECEIVER_H
