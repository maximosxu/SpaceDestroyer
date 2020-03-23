#pragma once

#include <ge211.hxx>

struct Geometry
{
    // Constructs an instance with the default parameters.
    Geometry() noexcept;

    // The dimensions of the whole window:
    ge211::Dimensions scene_dims;

    // The dimensions of the falcon (the block at the bottom):
    ge211::Dimensions falcon_dim_;

    // Number of columns of asteroids:
    int asteroid_cols;

    // Number of rows of asteroids:
    int asteroid_rows;


    // Number of columns of destroyers:
    int destroyer_cols;

    // Number of rows of destroyers:
    int destroyer_rows;

    // The number of pixels of space between each column and row of
    // asteroid:
    ge211::Dimensions asteroid_spacing;

    // The number of pixels of space between each column and
    // row of
    // destroyer:
    ge211::Dimensions destroyer_spacing;

    // The falcon velocity {width, height}:
    ge211::Dimensions falcon_velocity;

    // The destroyer velocity {width, height}:
    ge211::Dimensions destroyer_velocity;

    // The falcon velocity {width, height}:
    ge211::Dimensions deathStar_velocity;

    ge211::Dimensions asteroid_velocity;

    // The missile velocity {width, height}:
    ge211::Dimensions missile_velocity;

    // The missile size
    ge211::Dimensions missile_dims;




    // Number of pixels from top of screen to top of destroyer
    // formation:
    int destroyer_top_margin;

    // Number of pixels from sides of screen to sides of destroyer
    // formation:
    int destroyer_side_margin;

    // Number of pixels from top of screen to top of destroyer
    // formation:
    int asteroid_top_margin;

    // Number of pixels from sides of screen to sides of
    // destroyer formation:
    int asteroid_side_margin;

    //Number of pixels from *top* pf screen to the *bottom* of
    // destroyer formation.
    int destroyer_depth;

    //Number of pixels from *top* pf screen to the *bottom* of
    // asteroid formation.
    int asteroid_depth;

    // Number of pixels from bottom of screen to bottom of falcon
    // in frozen state.
    int bottom_margin;

    //Number of life on a falcon
    int f_life;

    //Number of life on a deathstar
    int d_life;

    ge211::Dimensions deathStar_dims;

    ge211::Dimensions falcon_missile_velocity;
    ge211::Dimensions destroyer_missile_velocity;

    ge211::Dimensions asteroid_velocity1;
    ge211::Dimensions asteroid_velocity2;
    ge211::Dimensions asteroid_velocity3;
    ge211::Dimensions asteroid_velocity4;


    // The initial position of the falcon. This is a member function
    // because
    // it's computed from the other properties.
    ge211::Position falcon_top_left0() const noexcept;

    // The dimensions of each destroyer. Also computed from the other
    // properties.
    //
    // PRECONDITIONS (asserted):
    //  - destroyer_cols > 0
    //  - destroyer_rows > 0
    ge211::Dimensions destroyer_dims;

    // The dimensions of each asteroid. Also computed from the other
    // properties.
    //
    // PRECONDITIONS (asserted):
    //  - destroyer_cols > 0
    //  - destroyer_rows > 0
    ge211::Dimensions asteroid_dims() const noexcept;


};

