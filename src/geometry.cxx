// YOU SHOULD NOT CHANGE THIS FILE.

#include "geometry.hxx"

// This is the default (and only) constructor for `Geometry`. It determines
// all the default values of all the member variables.
Geometry::Geometry() noexcept
        : destroyer_cols {   5}
        , destroyer_rows {   1}
        , asteroid_cols  {   4}
        , asteroid_rows  {   2}
        , falcon_dim_    { 60,  60}
        , destroyer_top_margin{  10}
        , asteroid_top_margin { scene_dims.height / 4}
        , destroyer_side_margin{  100 }
        , asteroid_side_margin{ 30}
        , destroyer_depth    {  scene_dims.height/16 }
        , asteroid_depth     { scene_dims.height*3 /4}
        , bottom_margin  {   10 }
        , falcon_velocity { 10, 10 }
        , deathStar_velocity { 3, 3 }
        ,deathStar_dims{100, 100}
        , destroyer_velocity { 2, 0 }
        , asteroid_velocity {3,3}
        , missile_velocity { 0, -3 }
        , asteroid_spacing  {   10,   5 }
        , destroyer_spacing {   10,   5 }
        , scene_dims     { 1024, 768 }
        ,missile_dims { 4, 4}
        ,f_life{   3 }
        ,d_life{   3 }
        ,asteroid_velocity1{2, -2}
        ,asteroid_velocity2{-2, 3}
        ,asteroid_velocity3{-3, 1}
        ,asteroid_velocity4{-2, 2}
        ,destroyer_dims {75, 75}
        ,falcon_missile_velocity{0,-3}
        ,destroyer_missile_velocity{0,3}

{}

ge211::Position Geometry::falcon_top_left0() const noexcept
{
    return { scene_dims.width / 2 - falcon_dim_.width/2,
             scene_dims.height - bottom_margin - falcon_dim_.height- 100 };
}

// Computes how large each destroyer and asteroid can be
// (in a given dimension), given the
// total number of pixels available in that dimension, the
// number of destroyers and asteroids
// in that dimensions, and the number of space pixels to
// leave in between.
//
// PRECONDITION: divisor > 0
static int div_w_spacing(int total, int divisor, int space)
{
    if (divisor > 0)
        return (total - (divisor - 1) * space) / divisor;

    throw ge211::Client_logic_error("need at least 1 row & 1 column");
}

// Computes the dimensions of each asteroid from the other parameters.
ge211::Dimensions Geometry::asteroid_dims() const noexcept
{
    ge211::Dimensions field{scene_dims.width - 2 * asteroid_side_margin,
                            asteroid_depth - asteroid_top_margin};
    int width  = div_w_spacing(field.width, asteroid_cols,
            asteroid_spacing.width);
    int height = div_w_spacing(field.height, asteroid_rows,
            asteroid_spacing.height);
    return {width, height};
}

//// Computes the dimensions of each destroyer from the other parameters.
//ge211::Dimensions Geometry::destroyer_dims() const noexcept {
//    ge211::Dimensions field{scene_dims.width - 2 * destroyer_side_margin,
//                            destroyer_depth - destroyer_top_margin};
//    int width = div_w_spacing(field.width, destroyer_cols,
//    destroyer_spacing.width);
//    int height = div_w_spacing(field.height, destroyer_rows,
//    destroyer_spacing.height);
//    return {width, height};
//}