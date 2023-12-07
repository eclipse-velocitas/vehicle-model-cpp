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

#ifndef VMDL_VEHICLE_VERSIONVSS_H
#define VMDL_VEHICLE_VERSIONVSS_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle {
using ParentClass = Model;

/** VersionVSS model. */
class VersionVSS : public ParentClass {
public:

    VersionVSS(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		Major("Major", this),
		Minor("Minor", this),
		Patch("Patch", this),
		Label("Label", this)
    {}

    /**
    * Major: attribute (uint32)
    * Supported Version of VSS - Major version.
    *
    **/
    DataPointUint32 Major;

    /**
    * Minor: attribute (uint32)
    * Supported Version of VSS - Minor version.
    *
    **/
    DataPointUint32 Minor;

    /**
    * Patch: attribute (uint32)
    * Supported Version of VSS - Patch version.
    *
    **/
    DataPointUint32 Patch;

    /**
    * Label: attribute (string)
    * Label to further describe the version.
    *
    **/
    DataPointString Label;

};
} // namespace velocitas::vehicle
#endif // VMDL_VEHICLE_VERSIONVSS_H
