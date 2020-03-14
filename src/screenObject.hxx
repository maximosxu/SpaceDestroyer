// Defines the class that models the general screenObject

#pragma once
#include "geometry.hxx"
#include <ge211.hxx>
#include "missile.hxx"
#include "vector"



class ScreenObject{

public:

    ScreenObject(const Geometry &, ge211::Position);


    ScreenObject(const Geometry &, ge211::Position, int);

//Returns the next position
    //virtual ScreenObject next_() {return *this;}

    virtual bool hits_screenObject(ScreenObject &) const ;

    //virtual ~ScreenObject() {};

    //The following perform collision detection
    bool hits_side(Geometry const&) const;

    bool hits_bottom(Geometry const&) const;

    bool hits_top(Geometry const&) const;

    // Receives a vector of missiles called the ammo and
    //checks is any missile in ammo hit the spaceObject.
    //If true it destroys the missile then returns true

    bool hits_destroyer(ScreenObject &) const;

    bool hit_by_missile(std::vector<Missile>& ammo );

    void reflect_vertically();

    void reflect_horizontally();

    ge211::Position top_left() const;

    ge211::Position bottom_right() const;

    bool got_hit(Missile &) const;

    ///
    /// Member Variables
    ///

    bool alive_;
    ge211::Position center;
    ge211::Dimensions velocity;
    int radius;


};
