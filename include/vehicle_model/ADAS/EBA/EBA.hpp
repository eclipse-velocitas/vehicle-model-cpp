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

#ifndef VMDL_VEHICLE_ADAS_EBA_H
#define VMDL_VEHICLE_ADAS_EBA_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle::adas {
using ParentClass = Model;

/** EBA model. */
class EBA : public ParentClass {
public:

    EBA(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		IsEnabled("IsEnabled", this),
		IsError("IsError", this),
		IsEngaged("IsEngaged", this)
    {}

    /**
    * IsEnabled: actuator
    * Indicates if EBA is enabled. True = Enabled. False = Disabled.
    *
    **/
    DataPointBoolean IsEnabled;

    /**
    * IsError: sensor
    * Indicates if EBA incurred an error condition. True = Error. False = No Error.
    *
    **/
    DataPointBoolean IsError;

    /**
    * IsEngaged: sensor
    * Indicates if EBA is currently regulating brake pressure. True = Engaged. False = Not Engaged.
    *
    **/
    DataPointBoolean IsEngaged;

};
} // namespace velocitas::vehicle::adas
#endif // VMDL_VEHICLE_ADAS_EBA_H
