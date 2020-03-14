#pragma once
#include "geometry.hxx"
#include <ge211.hxx>
#include "missile.hxx"
#include "screenObject.hxx"

class DeathStar : public ScreenObject{

public:

    DeathStar(Geometry const &, ge211::Position position);

    ge211::Position top_center(Geometry const & geometry) const;


    //bool hits_screenObject(ScreenObject& ) const override;

    void fire_missile(std::vector<Missile> &, Geometry const &);


    ///
    /// Member Variables
    ///

    int life;
    bool appear;
    ge211::Dimensions velocity;
};