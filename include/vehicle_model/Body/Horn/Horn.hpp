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

#ifndef VMDL_VEHICLE_BODY_HORN_H
#define VMDL_VEHICLE_BODY_HORN_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle::body {
using ParentClass = Model;

/** Horn model. */
class Horn : public ParentClass {
public:

    Horn(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		IsActive("IsActive", this)
    {}

    /**
    * IsActive: actuator
    * Horn active or inactive. True = Active. False = Inactive.
    *
    **/
    DataPointBoolean IsActive;

};
} // namespace velocitas::vehicle::body
#endif // VMDL_VEHICLE_BODY_HORN_H
