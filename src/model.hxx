#pragma once
#include "geometry.hxx"
#include "screenObject.hxx"
#include "missile.hxx"
#include "falcon.hxx"
#include "asteroid.hxx"
#include "destroyer.hxx"
#include "deathStar.hxx"
#include  <vector>

//
// Model Classes
//

class  Model{

public:
    explicit Model(Geometry const& geometry = Geometry());

    void launch();

    void update(double);

    void Move_asteroid();

    void Move_destroyer();

    void check_asteroid_collision(Asteroid &);

    bool falcon_hits_something();

    void innitialize_asteroids();

    void innitialize_destroyers(int count);

    void falconupdate(int);

    void fire_missiles_now(int);

    void move_missile();

    void move_deathstar();

///
/// Member Variables
///

    Geometry const geometry_;

    std::vector<Missile> ammo;

    std::vector<Destroyer> fleet;

    std::vector<Asteroid> stones;

    Falcon falcon;

    DeathStar deathStar;

    ge211::Dimensions destroyerVelocity;

    bool screenState;

    int count; /// Number of destroyers on screen
    double doubt;


};

