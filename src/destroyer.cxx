#include "destroyer.hxx"

Destroyer::Destroyer(Geometry const & geometry, ge211::Position position)
          : ScreenObject(geometry, position, 40)
          {  }

ge211::Position Destroyer::top_center(Geometry const & geometry)const{

    return {center.x, center.y + 40 + 5};
}

void Destroyer::fire_missile(std::vector<Missile>& ammo, Geometry const & geometry)
{

    ge211::Position position = top_center(geometry);
    Missile missile(geometry, position);
    missile.missile_velocity_ = geometry.destroyer_missile_velocity;
    ammo.push_back(missile);
}

//ScreenObject Destroyer::next_() {
//    return ScreenObject::next_();
//}
