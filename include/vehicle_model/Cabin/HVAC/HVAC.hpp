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

#ifndef VMDL_VEHICLE_CABIN_HVAC_H
#define VMDL_VEHICLE_CABIN_HVAC_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

#include "vehicle_model/Cabin/HVAC/Station/Station.hpp"

#include <stdexcept>

namespace velocitas::vehicle::cabin {
using ParentClass = Model;

/** HVAC model. */
class HVAC : public ParentClass {
public:
    class StationCollection : public ParentClass {
    public:
        class RowType : public ParentClass {
        public:
            RowType(std::string name, ParentClass* parent):
                ParentClass(name, parent),
                Left("Left", this),
                Right("Right", this)
            {
            }

            vehicle::cabin::hvac::Station Left;
            vehicle::cabin::hvac::Station Right;
        };

        StationCollection(ParentClass* parent):
            ParentClass("Station", parent),
            Row1("Row1", this),
            Row2("Row2", this),
            Row3("Row3", this),
            Row4("Row4", this)
        {
        }

        RowType& Row(int index) {
            if (index == 1) {
                return Row1;
            }
            if (index == 2) {
                return Row2;
            }
            if (index == 3) {
                return Row3;
            }
            if (index == 4) {
                return Row4;
            }
            throw std::runtime_error("Given value is outside of allowed range [1;4]!");
        }

        RowType Row1;
        RowType Row2;
        RowType Row3;
        RowType Row4;
    };

    HVAC(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		Station(this),
		IsRecirculationActive("IsRecirculationActive", this),
		IsFrontDefrosterActive("IsFrontDefrosterActive", this),
		IsRearDefrosterActive("IsRearDefrosterActive", this),
		IsAirConditioningActive("IsAirConditioningActive", this),
		AmbientAirTemperature("AmbientAirTemperature", this)
    {}

    /**
    * Station: branch
    * HVAC for single station in the vehicle
    *
    **/
    StationCollection Station;

    /**
    * IsRecirculationActive: actuator
    * Is recirculation active.
    *
    **/
    DataPointBoolean IsRecirculationActive;

    /**
    * IsFrontDefrosterActive: actuator
    * Is front defroster active.
    *
    **/
    DataPointBoolean IsFrontDefrosterActive;

    /**
    * IsRearDefrosterActive: actuator
    * Is rear defroster active.
    *
    **/
    DataPointBoolean IsRearDefrosterActive;

    /**
    * IsAirConditioningActive: actuator
    * Is Air conditioning active.
    *
    **/
    DataPointBoolean IsAirConditioningActive;

    /**
    * AmbientAirTemperature: sensor
    * Ambient air temperature inside the vehicle.
    *
    * Unit: celsius
    **/
    DataPointFloat AmbientAirTemperature;

};
} // namespace velocitas::vehicle::cabin
#endif // VMDL_VEHICLE_CABIN_HVAC_H
