#include <catch.hxx>
#include "screenObject.hxx"
#include "missile.hxx"
#include "vector"

TEST_CASE("OBJECT HITS TOP")
{
    Geometry geometry;
    ge211::Position position {20, 20};
    ScreenObject obj{geometry, position};
    CHECK_FALSE(obj.hits_top(geometry));

    obj.center = {0,0};

    CHECK(obj.hits_top(geometry));

    obj.center = {geometry.scene_dims.width/2 , geometry.scene_dims.height/2};
    CHECK_FALSE(obj.hits_top(geometry));

    obj.center = {geometry.scene_dims.width , geometry.scene_dims.height};
    CHECK_FALSE(obj.hits_top(geometry));

    obj.center = {geometry.scene_dims.width/2, 5};
    CHECK(obj.hits_top(geometry));
}

TEST_CASE("OBJECT HITS SIDES")
{
    Geometry geometry;
    ge211::Position position {20, 20};

    ScreenObject obj{geometry, position};
    CHECK_FALSE(obj.hits_side(geometry));

    obj.center = {0, 0};
    CHECK(obj.hits_side(geometry));

    obj.center = {geometry.scene_dims.width/2, geometry.scene_dims.height/2};
    CHECK_FALSE(obj.hits_side(geometry));

    obj.center = { geometry.scene_dims.width, geometry.scene_dims.height/2};
    CHECK(obj.hits_side(geometry));

    obj.center = { -2, geometry.scene_dims.height/2};
    CHECK(obj.hits_side(geometry));

}
TEST_CASE("OBJECTS HITS BOTTOM")
{
    Geometry geometry;
    ge211::Position position {20, 20};
    ScreenObject obj{geometry, position};
    CHECK_FALSE(obj.hits_bottom(geometry));

    obj.center = {0,0};

    CHECK_FALSE(obj.hits_bottom(geometry));

    obj.center = {geometry.scene_dims.width/2 , geometry.scene_dims.height/2};
    CHECK_FALSE(obj.hits_bottom(geometry));

    obj.center = {geometry.scene_dims.width , geometry.scene_dims.height};
    CHECK(obj.hits_bottom(geometry));

    obj.center = {geometry.scene_dims.width/2, geometry.scene_dims.height-5};
    CHECK(obj.hits_bottom(geometry));
}
TEST_CASE("OBJECTS HIT BY MISSILE") {
    Geometry geometry;
    ge211::Position position{20, 20};
    ge211::Position pos {20, 20};
    ScreenObject obj{geometry, position};
    std::vector<Missile> ammo;

    for( int i = 0; i< 5; i++){
        pos.x += 40;
        pos.y += 40;
       Missile missile(geometry, pos);

       ammo.push_back(missile);
    }
    obj.center = {position.x + 40, position.y + 40};

    CHECK(obj.hit_by_missile(ammo));
    CHECK_FALSE(obj.hit_by_missile(ammo));

    obj.center = {position.x + 40, position.y + 40};

    CHECK_FALSE(obj.hit_by_missile(ammo));
    CHECK_FALSE(obj.hit_by_missile(ammo));

    obj.center = {position.x + 80, position.y + 80};

    CHECK(obj.hit_by_missile(ammo));
    CHECK_FALSE(obj.hit_by_missile(ammo));

    obj.center = {200, 200};
    CHECK_FALSE(obj.hit_by_missile(ammo));

}
TEST_CASE("Reflect Velocity")
{
    Geometry geometry;
    ge211::Position position {50, 50};

    ScreenObject obj {geometry, position};
    obj.velocity = {geometry.falcon_velocity};
    ScreenObject test{geometry, position};
    test.velocity = {geometry.falcon_velocity};

    test.reflect_horizontally();

    CHECK_FALSE(test.velocity.width == obj.velocity.width);
    CHECK(test.velocity.height == obj.velocity.height);

    obj.reflect_horizontally();
    CHECK(test.velocity.width == obj.velocity.width);
    CHECK(test.velocity.height == obj.velocity.height);

    test.reflect_horizontally();
    CHECK(test.velocity.width == obj.velocity.width*-1);
    CHECK(test.velocity.height == obj.velocity.height);

    obj.reflect_horizontally();
    CHECK(test.velocity.width == obj.velocity.width);
    CHECK(test.velocity.height == obj.velocity.height);

    test.reflect_vertically();

    CHECK(test.velocity.width == obj.velocity.width);
    CHECK_FALSE(test.velocity.height == obj.velocity.height);

    obj.reflect_vertically();
    CHECK(test.velocity.width == obj.velocity.width);
    CHECK(test.velocity.height == obj.velocity.height);

    test.reflect_vertically();
    CHECK(test.velocity.width == obj.velocity.width);
    CHECK(test.velocity.height == obj.velocity.height*-1);

    obj.reflect_vertically();
    CHECK(test.velocity.width == obj.velocity.width);
    CHECK(test.velocity.height == obj.velocity.height);
}
TEST_CASE("Helper Function")
{
    Geometry geometry;
    ge211::Position position {50, 50};

    std::vector<Missile> ammo;

    ScreenObject obj {geometry, position};
    Missile missile(geometry, position);
    ammo.push_back(missile);


    CHECK(obj.got_hit(missile));
    CHECK(obj.hit_by_missile(ammo));

}