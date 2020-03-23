#include "geometry.hxx"
#include <ge211.hxx>
#include "missile.hxx"
#include "destroyer.hxx"
#include "deathStar.hxx"


DeathStar::DeathStar(Geometry const & geometry, ge211::Position position)
          : ScreenObject(geometry, position, 50)
          ,life(geometry.d_life)
          ,appear(false)
          ,velocity(geometry.destroyer_velocity*2)
          {}

ge211::Position DeathStar::top_center(Geometry const &geometry) const {

    return {center.x, center.y + radius + 10};
}

void DeathStar::fire_missile(std::vector<Missile> & ammo, Geometry
const & geometry) {

    ge211::Position position = top_center(geometry);
    Missile missile(geometry, position);
    missile.missile_velocity_ = geometry.destroyer_missile_velocity;
    ammo.push_back(missile);
}


