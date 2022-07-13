#ifndef VMDL_VEHICLE_CABIN_INFOTAINMENT_MEDIA_H
#define VMDL_VEHICLE_CABIN_INFOTAINMENT_MEDIA_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

#include "vehicle_model/Cabin/Infotainment/Media/Played/Played.hpp"

namespace velocitas::vehicle::cabin::infotainment {
using ParentClass = Model;

/** Media model. */
class Media : public ParentClass {
public:

    Media(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		Action("Action", this),
		Played("Played", this),
		DeclinedURI("DeclinedURI", this),
		SelectedURI("SelectedURI", this),
		Volume("Volume", this)
    {}

    /**
    * Action: actuator
    * Tells if the media was
    *
    * Allowed values: UNKNOWN, STOP, PLAY, FAST_FORWARD, FAST_BACKWARD, SKIP_FORWARD, SKIP_BACKWARD
    **/
    DataPointString Action;

    /**
    * Played: branch
    * Collection of signals updated in concert when a new media is played
    *
    **/
    vehicle::cabin::infotainment::media::Played Played;

    /**
    * DeclinedURI: sensor
    * URI of suggested media that was declined
    *
    **/
    DataPointString DeclinedURI;

    /**
    * SelectedURI: actuator
    * URI of suggested media that was selected
    *
    **/
    DataPointString SelectedURI;

    /**
    * Volume: actuator
    * Current Media Volume
    *
    * Value range: [0, 100]
    **/
    DataPointUint32 Volume;

};
} // namespace velocitas::vehicle::cabin::infotainment
#endif // VMDL_VEHICLE_CABIN_INFOTAINMENT_MEDIA_H
