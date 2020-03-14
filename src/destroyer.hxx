#pragma once
#include "geometry.hxx"
#include <ge211.hxx>
#include "missile.hxx"
#include "screenObject.hxx"

class Destroyer : public ScreenObject {

public:

    Destroyer(Geometry const&, ge211::Position position);


    ge211::Position top_center(Geometry const & geometry) const;


    //bool hits_screenObject(ScreenObject& ) const override;

    void fire_missile(std::vector<Missile> &, Geometry const &);



    ///
    /// Member Variables
    ///

    ge211::Dimensions velocity;
};