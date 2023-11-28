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

#ifndef VMDL_VEHICLE_ADAS_ESC_H
#define VMDL_VEHICLE_ADAS_ESC_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

#include "vehicle_model/ADAS/ESC/RoadFriction/RoadFriction.hpp"

namespace velocitas::vehicle::adas {
using ParentClass = Model;

/** ESC model. */
class ESC : public ParentClass {
public:

    ESC(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		IsEnabled("IsEnabled", this),
		IsError("IsError", this),
		IsEngaged("IsEngaged", this),
		IsStrongCrossWindDetected("IsStrongCrossWindDetected", this),
		RoadFriction("RoadFriction", this)
    {}

    /**
    * IsEnabled: actuator
    * Indicates if ESC is enabled. True = Enabled. False = Disabled.
    *
    **/
    DataPointBoolean IsEnabled;

    /**
    * IsError: sensor
    * Indicates if ESC incurred an error condition. True = Error. False = No Error.
    *
    **/
    DataPointBoolean IsError;

    /**
    * IsEngaged: sensor
    * Indicates if ESC is currently regulating vehicle stability. True = Engaged. False = Not Engaged.
    *
    **/
    DataPointBoolean IsEngaged;

    /**
    * IsStrongCrossWindDetected: sensor
    * Indicates if the ESC system is detecting strong cross winds. True = Strong cross winds detected. False = No strong cross winds detected.
    *
    **/
    DataPointBoolean IsStrongCrossWindDetected;

    /**
    * RoadFriction: branch
    * Road friction values reported by the ESC system.
    *
    **/
    vehicle::adas::esc::RoadFriction RoadFriction;

};
} // namespace velocitas::vehicle::adas
#endif // VMDL_VEHICLE_ADAS_ESC_H
