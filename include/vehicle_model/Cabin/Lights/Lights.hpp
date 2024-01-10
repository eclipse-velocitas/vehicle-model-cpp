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

#ifndef VMDL_VEHICLE_CABIN_LIGHTS_H
#define VMDL_VEHICLE_CABIN_LIGHTS_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

#include "vehicle_model/Cabin/Lights/Spotlight/Spotlight.hpp"

#include <stdexcept>

namespace velocitas::vehicle::cabin {
using ParentClass = Model;

/** Lights model. */
class Lights : public ParentClass {
public:
    class SpotlightCollection : public ParentClass {
    public:

        SpotlightCollection(ParentClass* parent):
            ParentClass("Spotlight", parent),
            Row1("Row1", this),
            Row2("Row2", this),
            Row3("Row3", this),
            Row4("Row4", this)
        {
        }

        vehicle::cabin::lights::Spotlight& Row(int index) {
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

        vehicle::cabin::lights::Spotlight Row1;
        vehicle::cabin::lights::Spotlight Row2;
        vehicle::cabin::lights::Spotlight Row3;
        vehicle::cabin::lights::Spotlight Row4;
    };

    Lights(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		IsGloveBoxOn("IsGloveBoxOn", this),
		IsTrunkOn("IsTrunkOn", this),
		IsDomeOn("IsDomeOn", this),
		AmbientLight("AmbientLight", this),
		LightIntensity("LightIntensity", this),
		Spotlight(this)
    {}

    /**
    * IsGloveBoxOn: actuator
    * Is glove box light on
    *
    **/
    DataPointBoolean IsGloveBoxOn;

    /**
    * IsTrunkOn: actuator
    * Is trunk light light on
    *
    **/
    DataPointBoolean IsTrunkOn;

    /**
    * IsDomeOn: actuator
    * Is central dome light light on
    *
    **/
    DataPointBoolean IsDomeOn;

    /**
    * AmbientLight: sensor
    * How much ambient light is detected in cabin. 0 = No ambient light. 100 = Full brightness
    *
    * Value range: [0, 100]
    * Unit: percent
    **/
    DataPointUint32 AmbientLight;

    /**
    * LightIntensity: sensor
    * Intensity of the interior lights. 0 = Off. 100 = Full brightness.
    *
    * Value range: [0, 100]
    * Unit: percent
    **/
    DataPointUint32 LightIntensity;

    /**
    * Spotlight: branch
    * Spotlight for a specific area in the vehicle.
    *
    **/
    SpotlightCollection Spotlight;

};
} // namespace velocitas::vehicle::cabin
#endif // VMDL_VEHICLE_CABIN_LIGHTS_H
