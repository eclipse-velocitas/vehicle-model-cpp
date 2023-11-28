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

#ifndef VMDL_VEHICLE_OBD_STATUS_H
#define VMDL_VEHICLE_OBD_STATUS_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle::obd {
using ParentClass = Model;

/** Status model. */
class Status : public ParentClass {
public:

    Status(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		IsMILOn("IsMILOn", this),
		DTCCount("DTCCount", this),
		IgnitionType("IgnitionType", this)
    {}

    /**
    * IsMILOn: sensor
    * Malfunction Indicator Light (MIL) False = Off, True = On
    *
    **/
    DataPointBoolean IsMILOn;

    /**
    * DTCCount: sensor
    * Number of sensor Trouble Codes (DTC)
    *
    **/
    DataPointUint32 DTCCount;

    /**
    * IgnitionType: sensor
    * Type of the ignition for ICE - spark = spark plug ignition, compression = self-igniting (Diesel engines)
    *
    * Allowed values: SPARK, COMPRESSION
    **/
    DataPointString IgnitionType;

};
} // namespace velocitas::vehicle::obd
#endif // VMDL_VEHICLE_OBD_STATUS_H
