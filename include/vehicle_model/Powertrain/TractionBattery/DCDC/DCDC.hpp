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

#ifndef VMDL_VEHICLE_POWERTRAIN_TRACTIONBATTERY_DCDC_H
#define VMDL_VEHICLE_POWERTRAIN_TRACTIONBATTERY_DCDC_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle::powertrain::tractionbattery {
using ParentClass = Model;

/** DCDC model. */
class DCDC : public ParentClass {
public:

    DCDC(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		PowerLoss("PowerLoss", this),
		Temperature("Temperature", this)
    {}

    /**
    * PowerLoss: sensor
    * Electrical energy lost by power dissipation to heat inside DC/DC converter.
    *
    * Unit: W
    **/
    DataPointFloat PowerLoss;

    /**
    * Temperature: sensor
    * Current temperature of DC/DC converter converting battery high voltage to vehicle low voltage (typically 12 Volts).
    *
    * Unit: celsius
    **/
    DataPointFloat Temperature;

};
} // namespace velocitas::vehicle::powertrain::tractionbattery
#endif // VMDL_VEHICLE_POWERTRAIN_TRACTIONBATTERY_DCDC_H
