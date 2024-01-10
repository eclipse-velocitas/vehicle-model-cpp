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

#ifndef VMDL_VEHICLE_DRIVER_IDENTIFIER_H
#define VMDL_VEHICLE_DRIVER_IDENTIFIER_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle::driver {
using ParentClass = Model;

/** Identifier model. */
class Identifier : public ParentClass {
public:

    Identifier(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		Subject("Subject", this),
		Issuer("Issuer", this)
    {}

    /**
    * Subject: sensor
    * Subject for the authentication of the occupant. E.g. UserID 7331677.
    *
    **/
    DataPointString Subject;

    /**
    * Issuer: sensor
    * Unique Issuer for the authentication of the occupant. E.g. https://accounts.funcorp.com.
    *
    **/
    DataPointString Issuer;

};
} // namespace velocitas::vehicle::driver
#endif // VMDL_VEHICLE_DRIVER_IDENTIFIER_H
