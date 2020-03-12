
#pragma once

#include <ge211.hxx>

struct Geometry
{
    // Constructs an instance with the default parameters.
    Geometry() noexcept;

    // The dimensions of the whole window:
    ge211::Dimensions scene_dims;

    // The dimensions of the Falcon:
    ge211::Dimensions falcon_dims_;

    // The dimensions of the Destroyers:
    ge211::Dimensions destroyer_dims_;

    // The dimensions of the Deathstar:
    int deathstar_radius_;

    // The dimensions of the Asteroids:
    int asteroid_radius_;

    // The dimensions of a Missile:
    ge211::Dimensions missile_dims_;

    // Number of asteroids;
    int asteroid_num;

    // Number of destoryers;
    int destroyer_num;

    // The number of pixels of space between each space object
    ge211::Dimensions object_spacing;

    // Number of pixels from top of screen to top of destroyers:
    int top_destroyer_margin;

    // Number of pixels from top of screen to top of asteroids:
    int top_asteroid_margin;

    // Number of pixels from sides of screen to sides of destroyer formation:
    int side_destroyer_margin;

    // Number of pixels from sides of screen to sides of asteroid formation:
    int side_asteroid_margin;

    // Number of pixels from bottom of screen to bottom of Falcon.
    int bottom_margin;

    // The initial position of the Falcon. This is a member function because
    // it's computed from the other properties.
    ge211::Position Falcon_Position() const noexcept;
};
