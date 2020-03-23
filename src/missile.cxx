
#include "geometry.hxx"
#include "missile.hxx"


Missile::Missile(Geometry const& geometry, ge211::Position position)
        :missile_dims_{geometry.missile_dims}
        ,missile_velocity_{geometry.missile_velocity}
        ,center_missile_position{position}
        ,radius{2}
{ }


bool Missile::hit_top(Geometry const& geometry) const {

    return(center_missile_position.y - 0.5*geometry.missile_dims.height < 0);
}

bool Missile::hit_bottom(Geometry const& geometry) const {

    return (center_missile_position.y + 0.5*geometry.missile_dims.height
    > geometry.scene_dims.height);
}

Missile Missile::next_(bool status)  {

    Missile copy(*this);
    if(status) {
        copy.center_missile_position += copy.missile_velocity_;
    }else{
        copy.center_missile_position -= copy.missile_velocity_;
    }

    return copy;
}

ge211::Position Missile::top_left() const
{

    ge211::Position topleft = {center_missile_position.x - radius,
                               center_missile_position.y - radius};

    return topleft;
}

ge211::Position Missile::bottom_right() const
{

    ge211::Position  bottomright = {center_missile_position.x + radius,
                                    center_missile_position.y + radius};
    return bottomright;
}




