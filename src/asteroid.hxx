#pragma once
#include "geometry.hxx"
#include <ge211.hxx>
#include "screenObject.hxx"
#include "vector"

class Asteroid : public ScreenObject {

public:
    Asteroid(Geometry const &, ge211::Position);

    ScreenObject next_(ge211::Dimensions);

    bool hit_above_special();


    ///
    /// Member Variables
    ///
    ///
};