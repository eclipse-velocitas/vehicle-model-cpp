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

#ifndef VMDL_VEHICLE_CABIN_SEAT_SWITCH_BACKREST_SIDEBOLSTER_H
#define VMDL_VEHICLE_CABIN_SEAT_SWITCH_BACKREST_SIDEBOLSTER_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle::cabin::seat::switch_::backrest {
using ParentClass = Model;

/** SideBolster model. */
class SideBolster : public ParentClass {
public:

    SideBolster(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		IsMoreSupportEngaged("IsMoreSupportEngaged", this),
		IsLessSupportEngaged("IsLessSupportEngaged", this)
    {}

    /**
    * IsMoreSupportEngaged: actuator
    * Is switch for more side bolster support engaged (SingleSeat.Backrest.SideBolster.Support).
    *
    **/
    DataPointBoolean IsMoreSupportEngaged;

    /**
    * IsLessSupportEngaged: actuator
    * Is switch for less side bolster support engaged (SingleSeat.Backrest.SideBolster.Support).
    *
    **/
    DataPointBoolean IsLessSupportEngaged;

};
} // namespace velocitas::vehicle::cabin::seat::switch_::backrest
#endif // VMDL_VEHICLE_CABIN_SEAT_SWITCH_BACKREST_SIDEBOLSTER_H
