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

#ifndef VMDL_VEHICLE_BODY_RAINDETECTION_H
#define VMDL_VEHICLE_BODY_RAINDETECTION_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle::body {
using ParentClass = Model;

/** Raindetection model. */
class Raindetection : public ParentClass {
public:

    Raindetection(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		Intensity("Intensity", this)
    {}

    /**
    * Intensity: sensor
    * Rain intensity. 0 = Dry, No Rain. 100 = Covered.
    *
    * Value range: [, 100]
    * Unit: percent
    **/
    DataPointUint32 Intensity;

};
} // namespace velocitas::vehicle::body
#endif // VMDL_VEHICLE_BODY_RAINDETECTION_H
