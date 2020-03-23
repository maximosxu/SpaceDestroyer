
#include "screenObject.hxx"
#include "geometry.hxx"


ScreenObject::ScreenObject(Geometry const& geometry, ge211::Position position)
             :alive_{false}
             ,center{ position}
             ,velocity { 0, 0 }
             ,radius {10}
{ }

ScreenObject::ScreenObject(Geometry const& geometry,
        ge211::Position position, int radius)
             :alive_{false}
             ,center{position.x+radius, position.y+radius}
             ,velocity{0,0}
             ,radius{radius}
{ }


bool ScreenObject::hits_side(Geometry const & geometry) const {

    return (center.x - radius < 0) || (center.x + radius >= geometry.scene_dims.width);
}


bool ScreenObject::hits_bottom(Geometry const & geometry) const {
    return (center.y + radius >= geometry.scene_dims.height-radius);
}

bool ScreenObject::hits_top(Geometry const & geometry) const {
    return (center.y - radius < 0);
}

bool ScreenObject::hit_by_missile(std::vector<Missile>& ammo) {

    for (Missile& missile : ammo){

        if(got_hit(missile)){
            std::swap(missile, ammo.back());
            ammo.pop_back();
            return true;
        }
    }
    return false;
}

ge211::Position ScreenObject::top_left() const {

    ge211::Position topleft = {center.x - radius, center.y - radius};
    return topleft;
}
/*ge211::Position ScreenObject::bottom_right() const{

    ge211::Position  bottomright = {center.x + radius, center.y + radius};
    return bottomright;
}*/

void ScreenObject::reflect_vertically() {

    velocity.height *= -1;
}

void ScreenObject::reflect_horizontally() {

    velocity.width *= -1;
}

bool ScreenObject::got_hit(Missile& missile) const{

     return !((missile.bottom_right().y < top_left().y) ||
             (missile.bottom_right().x < top_left().x) ||
            (center.y + radius < missile.top_left().y) ||
             (center.x + radius < missile.top_left().x));


}

bool ScreenObject::hits_screenObject(ScreenObject& obj) const {

     int x = (center.x - obj.center.x) * (center.x - obj.center.x);
     int y = (center.y - obj.center.y) * (center.y - obj.center.y);
     int distance = (radius + obj.radius) * (radius + obj.radius);

    return (x + y < distance);

}

/*bool ScreenObject::hits_destroyer(ScreenObject& obj) const{
    int x = (center.x - obj.center.x) * (center.x - obj.center.x);
    int y = (center.y - obj.center.y) * (center.y - obj.center.y);
    int distance = (radius + obj.radius) * (radius + obj.radius);

    return (x + y  < distance);*/
//}



