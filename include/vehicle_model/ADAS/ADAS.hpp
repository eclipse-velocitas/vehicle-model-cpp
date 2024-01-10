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

#ifndef VMDL_VEHICLE_ADAS_H
#define VMDL_VEHICLE_ADAS_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

#include "vehicle_model/ADAS/ABS/ABS.hpp"
#include "vehicle_model/ADAS/CruiseControl/CruiseControl.hpp"
#include "vehicle_model/ADAS/EBA/EBA.hpp"
#include "vehicle_model/ADAS/EBD/EBD.hpp"
#include "vehicle_model/ADAS/ESC/ESC.hpp"
#include "vehicle_model/ADAS/LaneDepartureDetection/LaneDepartureDetection.hpp"
#include "vehicle_model/ADAS/ObstacleDetection/ObstacleDetection.hpp"
#include "vehicle_model/ADAS/TCS/TCS.hpp"

namespace velocitas::vehicle {
using ParentClass = Model;

/** ADAS model. */
class ADAS : public ParentClass {
public:

    ADAS(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		ActiveAutonomyLevel("ActiveAutonomyLevel", this),
		SupportedAutonomyLevel("SupportedAutonomyLevel", this),
		CruiseControl("CruiseControl", this),
		LaneDepartureDetection("LaneDepartureDetection", this),
		ObstacleDetection("ObstacleDetection", this),
		ABS("ABS", this),
		TCS("TCS", this),
		ESC("ESC", this),
		EBD("EBD", this),
		EBA("EBA", this)
    {}

    /**
    * ActiveAutonomyLevel: sensor
    * Indicates the currently active level of autonomy according to SAE J3016 taxonomy.
    *
    * Follows https://www.sae.org/news/2019/01/sae-updates-j3016-automated-driving-graphic taxonomy. For SAE levels 3 and 4 the system is required to alert the driver before it will disengage. Level 4 systems are required to reach a safe state even if a driver does not take over. Only level 5 systems are required to not rely on a driver at all. While level 2 systems require the driver to be monitoring the system at all times, many level 2 systems, often termed "level 2.5" systems, do warn the driver shortly before reaching their operational limits, therefore we also support the DISENGAGING state for SAE_2.
    *
    * Allowed values: SAE_0, SAE_1, SAE_2_DISENGAGING, SAE_2, SAE_3_DISENGAGING, SAE_3, SAE_4_DISENGAGING, SAE_4, SAE_5
    **/
    DataPointString ActiveAutonomyLevel;

    /**
    * SupportedAutonomyLevel: attribute (string)
    * Indicates the highest level of autonomy according to SAE J3016 taxonomy the vehicle is capable of.
    *
    * Allowed values: SAE_0, SAE_1, SAE_2, SAE_3, SAE_4, SAE_5
    **/
    DataPointString SupportedAutonomyLevel;

    /**
    * CruiseControl: branch
    * Signals from Cruise Control system.
    *
    **/
    vehicle::adas::CruiseControl CruiseControl;

    /**
    * LaneDepartureDetection: branch
    * Signals from Lane Departure Detection System.
    *
    **/
    vehicle::adas::LaneDepartureDetection LaneDepartureDetection;

    /**
    * ObstacleDetection: branch
    * Signals form Obstacle Sensor System.
    *
    **/
    vehicle::adas::ObstacleDetection ObstacleDetection;

    /**
    * ABS: branch
    * Antilock Braking System signals.
    *
    **/
    vehicle::adas::ABS ABS;

    /**
    * TCS: branch
    * Traction Control System signals.
    *
    **/
    vehicle::adas::TCS TCS;

    /**
    * ESC: branch
    * Electronic Stability Control System signals.
    *
    **/
    vehicle::adas::ESC ESC;

    /**
    * EBD: branch
    * Electronic Brakeforce Distribution (EBD) System signals.
    *
    **/
    vehicle::adas::EBD EBD;

    /**
    * EBA: branch
    * Emergency Brake Assist (EBA) System signals.
    *
    **/
    vehicle::adas::EBA EBA;

};
} // namespace velocitas::vehicle
#endif // VMDL_VEHICLE_ADAS_H
