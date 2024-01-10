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

#ifndef VMDL_VEHICLE_BODY_H
#define VMDL_VEHICLE_BODY_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

#include "vehicle_model/Body/Hood/Hood.hpp"
#include "vehicle_model/Body/Horn/Horn.hpp"
#include "vehicle_model/Body/Lights/Lights.hpp"
#include "vehicle_model/Body/Mirrors/Mirrors.hpp"
#include "vehicle_model/Body/Raindetection/Raindetection.hpp"
#include "vehicle_model/Body/Trunk/Trunk.hpp"
#include "vehicle_model/Body/Windshield/Windshield.hpp"

namespace velocitas::vehicle {
using ParentClass = Model;

/** Body model. */
class Body : public ParentClass {
public:
    class TrunkCollection : public ParentClass {
    public:

        TrunkCollection(ParentClass* parent):
            ParentClass("Trunk", parent),
            Front("Front", this),
            Rear("Rear", this)
        {
        }

        vehicle::body::Trunk Front;
        vehicle::body::Trunk Rear;
    };


    class WindshieldCollection : public ParentClass {
    public:

        WindshieldCollection(ParentClass* parent):
            ParentClass("Windshield", parent),
            Front("Front", this),
            Rear("Rear", this)
        {
        }

        vehicle::body::Windshield Front;
        vehicle::body::Windshield Rear;
    };


    class MirrorsCollection : public ParentClass {
    public:

        MirrorsCollection(ParentClass* parent):
            ParentClass("Mirrors", parent),
            Left("Left", this),
            Right("Right", this)
        {
        }

        vehicle::body::Mirrors Left;
        vehicle::body::Mirrors Right;
    };

    Body(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		BodyType("BodyType", this),
		RefuelPosition("RefuelPosition", this),
		Hood("Hood", this),
		Trunk(this),
		Horn("Horn", this),
		Raindetection("Raindetection", this),
		Windshield(this),
		Lights("Lights", this),
		Mirrors(this),
		RearMainSpoilerPosition("RearMainSpoilerPosition", this)
    {}

    /**
    * BodyType: attribute (string)
    * Body type code as defined by ISO 3779.
    *
    **/
    DataPointString BodyType;

    /**
    * RefuelPosition: attribute (string)
    * Location of the fuel cap or charge port.
    *
    * Allowed values: FRONT_LEFT, FRONT_RIGHT, MIDDLE_LEFT, MIDDLE_RIGHT, REAR_LEFT, REAR_RIGHT
    **/
    DataPointString RefuelPosition;

    /**
    * Hood: branch
    * Hood status.
    *
    **/
    vehicle::body::Hood Hood;

    /**
    * Trunk: branch
    * Trunk status.
    *
    **/
    TrunkCollection Trunk;

    /**
    * Horn: branch
    * Horn signals.
    *
    **/
    vehicle::body::Horn Horn;

    /**
    * Raindetection: branch
    * Rainsensor signals.
    *
    **/
    vehicle::body::Raindetection Raindetection;

    /**
    * Windshield: branch
    * Windshield signals.
    *
    **/
    WindshieldCollection Windshield;

    /**
    * Lights: branch
    * All lights.
    *
    **/
    vehicle::body::Lights Lights;

    /**
    * Mirrors: branch
    * All mirrors.
    *
    **/
    MirrorsCollection Mirrors;

    /**
    * RearMainSpoilerPosition: actuator
    * Rear spoiler position, 0% = Spoiler fully stowed. 100% = Spoiler fully exposed.
    *
    * Value range: [0, 100]
    * Unit: percent
    **/
    DataPointFloat RearMainSpoilerPosition;

};
} // namespace velocitas::vehicle
#endif // VMDL_VEHICLE_BODY_H
