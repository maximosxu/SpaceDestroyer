#include "model.hxx"
#include <catch.hxx>

//
// TODO: Write preliminary model tests.
//
// These tests should demonstrate at least six of the functional
// requirements.
//



TEST_CASE("Asteroid hits side")
{
    ge211::Position grid{1000, 1500};
    asteroid Asteroid();
    Asteroid.position{90, 90};
    CHECK_FALSE(Asteroid.hit_side(grid));
    Asteroid.position{-2, 50};
    CHECK(Asteroid.hit_side(grid));

}



TEST_CASE("Missile Out of bounds")
{
    ge211::Position grid{1000, 1500};

    missile Missile(30, 30);
    CHECK_FALSE(Missile.hit_bound(grid));
    CHECK(Missile.alive);
    Missile.position{400, 1600};
    CHECK(Missile.hit_bound(grid));
    Missile.destroy()
    CHECK_FALSE(Missile.alive);

}



TEST_CASE("Player gets hit by missile")
{
    model m();
    missile Missile;
    falcon player;
    CHECK_FALSE(player.missile_collision());
    player.position = {500,500};
    Missile.position = {500,400};
    Missile.velocity = {0,100};
    Missile.next();
    CHECK(player.missile_collision());
    player.destruct();
    Missile.destroy();
    CHECK_FALSE(Missile.alive);
    CHECK(player.live_ == 2);
}



TEST_CASE("Destroyer gets hit by missile")
{
    model m();
    missile Missile;
    destroyer Destroyer;
    CHECK_FALSE(Destroyer.missile_collision());
    Destroyer.position = {500,500};
    Missile.position = {500,400};
    Missile.velocity = {0,100};
    Missile.next();
    CHECK(Destroyer.missile_collision());
    Destroyer.destruct();
    Missile.destroy();
    CHECK_FALSE(Missile.alive);
}



TEST_CASE("Asteroid gets hit by missile")
{
    model m();
    missile Missile;
    asteroid Asteroid;
    Asteroid.position = {500,500};
    Missile.position = {500,400};
    Missile.velocity = {0,100};
    Missile.next();
    CHECK(Asteroid.missile_collision());
    Asteroid.destruct();
    Missile.destroy();
    CHECK_FALSE(Missile.alive);
}

TEST_CASE("Falcon Out of bounds") {
    ge211::Position grid{1000, 1500};
    falcon player;
    player.position = {500,1200};
    CHECK_FALSE(player.hit_bound(grid));
    CHECK(player.live_ == 3);
    player.position = {1300,1600};
    CHECK(player.hit_bound(grid));
    CHECK(player.live_ == 2);
}