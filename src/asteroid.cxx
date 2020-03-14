
#include "geometry.hxx"
#include "screenObject.hxx"
#include "asteroid.hxx"
#include <ge211.hxx>

Asteroid::Asteroid(Geometry const & geometry, ge211::Position position)
         : ScreenObject(geometry, position, 40)
{ }

ScreenObject Asteroid::next_(ge211::Dimensions velocity) {
    Asteroid copy(*this);
    copy.center += velocity;
    return copy;
}

bool Asteroid::hit_above_special() {

    return (top_left().y <= 180);
}

