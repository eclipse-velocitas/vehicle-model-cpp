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

#ifndef VMDL_VEHICLE_CURRENTLOCATION_H
#define VMDL_VEHICLE_CURRENTLOCATION_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

#include "vehicle_model/CurrentLocation/GNSSReceiver/GNSSReceiver.hpp"

namespace velocitas::vehicle {
using ParentClass = Model;

/** CurrentLocation model. */
class CurrentLocation : public ParentClass {
public:

    CurrentLocation(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		Timestamp("Timestamp", this),
		Latitude("Latitude", this),
		Longitude("Longitude", this),
		Heading("Heading", this),
		HorizontalAccuracy("HorizontalAccuracy", this),
		Altitude("Altitude", this),
		VerticalAccuracy("VerticalAccuracy", this),
		GNSSReceiver("GNSSReceiver", this)
    {}

    /**
    * Timestamp: sensor
    * Timestamp from GNSS system for current location, formatted according to ISO 8601 with UTC time zone.
    *
    **/
    DataPointString Timestamp;

    /**
    * Latitude: sensor
    * Current latitude of vehicle in WGS 84 geodetic coordinates, as measured at the position of GNSS receiver antenna.
    *
    * Value range: [-90, 90]
    * Unit: degrees
    **/
    DataPointDouble Latitude;

    /**
    * Longitude: sensor
    * Current longitude of vehicle in WGS 84 geodetic coordinates, as measured at the position of GNSS receiver antenna.
    *
    * Value range: [-180, 180]
    * Unit: degrees
    **/
    DataPointDouble Longitude;

    /**
    * Heading: sensor
    * Current heading relative to geographic north. 0 = North, 90 = East, 180 = South, 270 = West.
    *
    * Value range: [0, 360]
    * Unit: degrees
    **/
    DataPointDouble Heading;

    /**
    * HorizontalAccuracy: sensor
    * Accuracy of the latitude and longitude coordinates.
    *
    * Unit: m
    **/
    DataPointDouble HorizontalAccuracy;

    /**
    * Altitude: sensor
    * Current altitude relative to WGS 84 reference ellipsoid, as measured at the position of GNSS receiver antenna.
    *
    * Unit: m
    **/
    DataPointDouble Altitude;

    /**
    * VerticalAccuracy: sensor
    * Accuracy of altitude.
    *
    * Unit: m
    **/
    DataPointDouble VerticalAccuracy;

    /**
    * GNSSReceiver: branch
    * Information on the GNSS receiver used for determining current location.
    *
    **/
    vehicle::currentlocation::GNSSReceiver GNSSReceiver;

};
} // namespace velocitas::vehicle
#endif // VMDL_VEHICLE_CURRENTLOCATION_H
