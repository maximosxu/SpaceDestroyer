#include "geometry.hxx"
#include "screenObject.hxx"
#include "falcon.hxx"
#include "missile.hxx"

Falcon::Falcon(Geometry const& geometry, ge211::Position position)
        : ScreenObject(geometry, position, 30)
        ,life_(geometry.f_life)

{ }

Falcon Falcon::next_() {
    Falcon copy (*this);
    copy.center += velocity;

    return copy;
}

//bool Falcon::hits_screenObject(ScreenObject & dest) const {
//    return ((abs(dest.center.x - center.x)) < dest.radius + radius) ||
//           ((abs(dest.center.y - center.y)) < dest.radius + radius);
//
//}

ge211::Position Falcon::top_center(Geometry const & geometry)const{

    return {center.x, center.y - geometry.falcon_dim_.width - 3};
}

void Falcon::fire_missile(std::vector<Missile>& ammo, Geometry const & geometry){

    ge211::Position position = top_center(geometry);
    Missile missile(geometry, position);
    missile.missile_velocity_ = geometry.falcon_missile_velocity;
    ammo.push_back(missile);
}

void Falcon::destroy() {

    life_ -= 1;
}

bool Falcon::isAlive() {

    return life_ > 0;
}





