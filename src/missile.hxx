#pragma once
#include "geometry.hxx"
#include <ge211.hxx>
//#include "destroyer.hxx"

struct Missile {

    explicit Missile(Geometry const&, ge211::Position );

    bool hit_top(Geometry const&) const;

    bool hit_bottom(Geometry const& )const;

    //Receives the boolean that it uses to determine whether
    //velocity is up or down.
    Missile next_(bool);

    ge211::Position top_left() const;

    ge211::Position bottom_right() const;

    ///
    /// Member Variables
    ///

    ge211::Dimensions missile_dims_;
    ge211::Dimensions missile_velocity_;
    ge211::Position center_missile_position;
    int radius;
};
