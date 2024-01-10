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

#ifndef VMDL_VEHICLE_CABIN_INFOTAINMENT_H
#define VMDL_VEHICLE_CABIN_INFOTAINMENT_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

#include "vehicle_model/Cabin/Infotainment/HMI/HMI.hpp"
#include "vehicle_model/Cabin/Infotainment/Media/Media.hpp"
#include "vehicle_model/Cabin/Infotainment/Navigation/Navigation.hpp"

namespace velocitas::vehicle::cabin {
using ParentClass = Model;

/** Infotainment model. */
class Infotainment : public ParentClass {
public:

    Infotainment(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		Media("Media", this),
		Navigation("Navigation", this),
		HMI("HMI", this)
    {}

    /**
    * Media: branch
    * All Media actions
    *
    **/
    vehicle::cabin::infotainment::Media Media;

    /**
    * Navigation: branch
    * All navigation actions
    *
    **/
    vehicle::cabin::infotainment::Navigation Navigation;

    /**
    * HMI: branch
    * HMI related signals
    *
    **/
    vehicle::cabin::infotainment::HMI HMI;

};
} // namespace velocitas::vehicle::cabin
#endif // VMDL_VEHICLE_CABIN_INFOTAINMENT_H
