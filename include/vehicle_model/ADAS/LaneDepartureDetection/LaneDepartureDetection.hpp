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

#ifndef VMDL_VEHICLE_ADAS_LANEDEPARTUREDETECTION_H
#define VMDL_VEHICLE_ADAS_LANEDEPARTUREDETECTION_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle::adas {
using ParentClass = Model;

/** LaneDepartureDetection model. */
class LaneDepartureDetection : public ParentClass {
public:

    LaneDepartureDetection(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		IsEnabled("IsEnabled", this),
		IsWarning("IsWarning", this),
		IsError("IsError", this)
    {}

    /**
    * IsEnabled: actuator
    * Indicates if lane departure detection system is enabled. True = Enabled. False = Disabled.
    *
    **/
    DataPointBoolean IsEnabled;

    /**
    * IsWarning: sensor
    * Indicates if lane departure detection registered a lane departure.
    *
    **/
    DataPointBoolean IsWarning;

    /**
    * IsError: sensor
    * Indicates if lane departure system incurred an error condition. True = Error. False = No Error.
    *
    **/
    DataPointBoolean IsError;

};
} // namespace velocitas::vehicle::adas
#endif // VMDL_VEHICLE_ADAS_LANEDEPARTUREDETECTION_H
