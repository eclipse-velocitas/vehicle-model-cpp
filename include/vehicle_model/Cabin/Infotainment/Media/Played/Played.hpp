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

#ifndef VMDL_VEHICLE_CABIN_INFOTAINMENT_MEDIA_PLAYED_H
#define VMDL_VEHICLE_CABIN_INFOTAINMENT_MEDIA_PLAYED_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle::cabin::infotainment::media {
using ParentClass = Model;

/** Played model. */
class Played : public ParentClass {
public:

    Played(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		Source("Source", this),
		Artist("Artist", this),
		Album("Album", this),
		Track("Track", this),
		URI("URI", this)
    {}

    /**
    * Source: actuator
    * Media selected for playback
    *
    * Allowed values: UNKNOWN, SIRIUS_XM, AM, FM, DAB, TV, CD, DVD, AUX, USB, DISK, BLUETOOTH, INTERNET, VOICE, BEEP
    **/
    DataPointString Source;

    /**
    * Artist: sensor
    * Name of artist being played
    *
    **/
    DataPointString Artist;

    /**
    * Album: sensor
    * Name of album being played
    *
    **/
    DataPointString Album;

    /**
    * Track: sensor
    * Name of track being played
    *
    **/
    DataPointString Track;

    /**
    * URI: sensor
    * User Resource associated with the media
    *
    **/
    DataPointString URI;

};
} // namespace velocitas::vehicle::cabin::infotainment::media
#endif // VMDL_VEHICLE_CABIN_INFOTAINMENT_MEDIA_PLAYED_H
