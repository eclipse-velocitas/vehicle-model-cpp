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

#ifndef VMDL_VEHICLE_SERVICE_H
#define VMDL_VEHICLE_SERVICE_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle {
using ParentClass = Model;

/** Service model. */
class Service : public ParentClass {
public:

    Service(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		IsServiceDue("IsServiceDue", this),
		DistanceToService("DistanceToService", this),
		TimeToService("TimeToService", this)
    {}

    /**
    * IsServiceDue: sensor
    * Indicates if vehicle needs service (of any kind). True = Service needed now or in the near future. False = No known need for service.
    *
    **/
    DataPointBoolean IsServiceDue;

    /**
    * DistanceToService: sensor
    * Remaining distance to service (of any kind). Negative values indicate service overdue.
    *
    * Unit: km
    **/
    DataPointFloat DistanceToService;

    /**
    * TimeToService: sensor
    * Remaining time to service (of any kind). Negative values indicate service overdue.
    *
    * Unit: s
    **/
    DataPointInt32 TimeToService;

};
} // namespace velocitas::vehicle
#endif // VMDL_VEHICLE_SERVICE_H
