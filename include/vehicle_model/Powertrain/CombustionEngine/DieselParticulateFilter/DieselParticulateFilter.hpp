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

#ifndef VMDL_VEHICLE_POWERTRAIN_COMBUSTIONENGINE_DIESELPARTICULATEFILTER_H
#define VMDL_VEHICLE_POWERTRAIN_COMBUSTIONENGINE_DIESELPARTICULATEFILTER_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle::powertrain::combustionengine {
using ParentClass = Model;

/** DieselParticulateFilter model. */
class DieselParticulateFilter : public ParentClass {
public:

    DieselParticulateFilter(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		InletTemperature("InletTemperature", this),
		OutletTemperature("OutletTemperature", this),
		DeltaPressure("DeltaPressure", this)
    {}

    /**
    * InletTemperature: sensor
    * Inlet temperature of Diesel Particulate Filter.
    *
    * Unit: celsius
    **/
    DataPointFloat InletTemperature;

    /**
    * OutletTemperature: sensor
    * Outlet temperature of Diesel Particulate Filter.
    *
    * Unit: celsius
    **/
    DataPointFloat OutletTemperature;

    /**
    * DeltaPressure: sensor
    * Delta Pressure of Diesel Particulate Filter.
    *
    * Unit: Pa
    **/
    DataPointFloat DeltaPressure;

};
} // namespace velocitas::vehicle::powertrain::combustionengine
#endif // VMDL_VEHICLE_POWERTRAIN_COMBUSTIONENGINE_DIESELPARTICULATEFILTER_H
