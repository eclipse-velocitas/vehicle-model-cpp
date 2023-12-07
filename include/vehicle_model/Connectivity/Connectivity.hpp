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

#ifndef VMDL_VEHICLE_CONNECTIVITY_H
#define VMDL_VEHICLE_CONNECTIVITY_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle {
using ParentClass = Model;

/** Connectivity model. */
class Connectivity : public ParentClass {
public:

    Connectivity(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		IsConnectivityAvailable("IsConnectivityAvailable", this)
    {}

    /**
    * IsConnectivityAvailable: sensor
    * Indicates if connectivity between vehicle and cloud is available. True = Connectivity is available. False = Connectivity is not available.
    *
    * This signal can be used by onboard vehicle services to decide what features that shall be offered to the driver, for example disable the 'check for update' button if vehicle does not have connectivity.
    *
    **/
    DataPointBoolean IsConnectivityAvailable;

};
} // namespace velocitas::vehicle
#endif // VMDL_VEHICLE_CONNECTIVITY_H
