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

#ifndef VMDL_VEHICLE_CABIN_DOOR_H
#define VMDL_VEHICLE_CABIN_DOOR_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

#include "vehicle_model/Cabin/Door/Shade/Shade.hpp"
#include "vehicle_model/Cabin/Door/Window/Window.hpp"

namespace velocitas::vehicle::cabin {
using ParentClass = Model;

/** Door model. */
class Door : public ParentClass {
public:

    Door(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		IsOpen("IsOpen", this),
		IsLocked("IsLocked", this),
		Window("Window", this),
		IsChildLockActive("IsChildLockActive", this),
		Shade("Shade", this)
    {}

    /**
    * IsOpen: actuator
    * Is door open or closed
    *
    **/
    DataPointBoolean IsOpen;

    /**
    * IsLocked: actuator
    * Is door locked or unlocked. True = Locked. False = Unlocked.
    *
    **/
    DataPointBoolean IsLocked;

    /**
    * Window: branch
    * Door window status
    *
    **/
    vehicle::cabin::door::Window Window;

    /**
    * IsChildLockActive: sensor
    * Is door child lock engaged. True = Engaged. False = Disengaged.
    *
    **/
    DataPointBoolean IsChildLockActive;

    /**
    * Shade: branch
    * Side window shade
    *
    **/
    vehicle::cabin::door::Shade Shade;

};
} // namespace velocitas::vehicle::cabin
#endif // VMDL_VEHICLE_CABIN_DOOR_H
