#include "geometry.hxx"

Geometry::Geometry() noexcept
        : bottom_margin     {   50 }
        , side_asteroid_margin     {   200 }
        , side_destroyer_margin     {   150 }
        , top_destroyer_margin     {  100 }
        , top_asteroid_margin  {  300 }
        , object_spacing    {  20 }
        , destroyer_num  {   10 }
        , asteroid_num    {    5 }
        , missile_dims_     { 10, 10 }
        , asteroid_radius_ {    50 }
        , destroyer_dims_  {   100,   100 }
        , deathstar_radius_  {   200 }
        , scene_dims     { 1500, 1500 }
        , falcon_dims_   {  100,  20 }
{ }

ge211::Position Geometry::Falcon_Position() const noexcept
{
    return { scene_dims.width / 2,
             scene_dims.height - bottom_margin - falcon_dims_.height };
}