#include <catch.hxx>
#include "missile.hxx"



TEST_CASE("MISSILE HITS TOP")
{
    Geometry geometry;
    ge211::Position position {20, 20};
    Missile missile (geometry, position);
    CHECK_FALSE(missile.hit_top(geometry));

    missile.center_missile_position = {0, 0};
    CHECK(missile.hit_top(geometry));

    missile.center_missile_position.y += 5;
    CHECK_FALSE(missile.hit_top(geometry));

    missile.center_missile_position = {geometry.scene_dims.width,
                                       geometry.scene_dims.height};
    CHECK_FALSE(missile.hit_top(geometry));
}
TEST_CASE("MISSILE HITS BOTTOM")
{
    Geometry geometry;
    ge211::Position position {20, 20};
    Missile missile (geometry, position);
    CHECK_FALSE(missile.hit_bottom(geometry));

    missile.center_missile_position = {0, 0};
    CHECK_FALSE(missile.hit_bottom(geometry));

    missile.center_missile_position.y -= 1;
    CHECK_FALSE(missile.hit_bottom(geometry));

    missile.center_missile_position = {geometry.scene_dims.width,
                                       geometry.scene_dims.height};
    CHECK(missile.hit_bottom(geometry));
}
TEST_CASE("ACCURATE NEXT MISSILE")
{
    Geometry geometry;
    ge211::Position position {20, 20};
    Missile missile (geometry, position);
    CHECK(missile.missile_velocity_ == geometry.missile_velocity);

    bool status_up = true;
    bool status_down = false;

    Missile test_missile = missile.next_(status_up);
    CHECK(test_missile.missile_velocity_ == geometry.missile_velocity);
    CHECK(test_missile.center_missile_position.y ==
    missile.center_missile_position.y + geometry.missile_velocity.height);
    CHECK(test_missile.center_missile_position.x ==
    missile.center_missile_position.x + geometry.missile_velocity.width);

    Missile test_missile_2 = missile.next_(status_up);
    CHECK_FALSE(test_missile.center_missile_position.y ==
    test_missile_2.center_missile_position.y + geometry.missile_velocity.height);
    CHECK_FALSE(test_missile.center_missile_position.x !=
    test_missile_2.center_missile_position.x + geometry.missile_velocity.width);
    CHECK(test_missile.center_missile_position.y ==
    test_missile_2.center_missile_position.y);
    CHECK(test_missile.center_missile_position.x ==
    test_missile_2.center_missile_position.x);

    Missile test_missile_3 = test_missile.next_(status_down);
    CHECK(test_missile_3.missile_velocity_ == geometry.missile_velocity);
    CHECK(test_missile_3.center_missile_position.y ==
    test_missile_2.center_missile_position.y - geometry.missile_velocity.height);
    CHECK(test_missile_3.center_missile_position.x ==
    test_missile_2.center_missile_position.x - geometry.missile_velocity.width);

    Missile test_missile_4 = test_missile_2.next_(status_down);
    CHECK_FALSE(test_missile_3.center_missile_position.y ==
    test_missile_4.center_missile_position.y - geometry.missile_velocity.height);
    CHECK_FALSE(test_missile_3.center_missile_position.x !=
    test_missile_4.center_missile_position.x - geometry.missile_velocity.width);
    CHECK(test_missile_3.center_missile_position.y ==
    test_missile_4.center_missile_position.y);
    CHECK(test_missile_3.center_missile_position.x ==
    test_missile_4.center_missile_position.x);


}