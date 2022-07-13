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
