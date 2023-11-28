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

#ifndef VMDL_VEHICLE_CABIN_CONVERTIBLE_H
#define VMDL_VEHICLE_CABIN_CONVERTIBLE_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle::cabin {
using ParentClass = Model;

/** Convertible model. */
class Convertible : public ParentClass {
public:

    Convertible(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		Status("Status", this)
    {}

    /**
    * Status: sensor
    * Roof status on convertible vehicles.
    *
    * Allowed values: UNDEFINED, CLOSED, OPEN, CLOSING, OPENING, STALLED
    **/
    DataPointString Status;

};
} // namespace velocitas::vehicle::cabin
#endif // VMDL_VEHICLE_CABIN_CONVERTIBLE_H
