#pragma once
#include "geometry.hxx"
#include <ge211.hxx>
#include "missile.hxx"
#include "screenObject.hxx"

class Falcon : public ScreenObject {

    /// number of lives controller


public:

    Falcon(const Geometry &geometry, ge211::Position position);

//    Falcon next_() ;

    ge211::Position top_center(Geometry const & geometry) const;


    //bool hits_screenObject(ScreenObject& ) const override;

    void fire_missile(std::vector<Missile> &, Geometry const &);

//    void destroy();

//    bool isAlive();




    ///
    ///Member Variables
    ///

    int life_ ;

};