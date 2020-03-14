#include "model.hxx"
#include <catch.hxx>

TEST_CASE("FALCON LOSES ALL LIVES"){

    Geometry geometry;
    Model model_(geometry);
    model_.launch();

    CHECK(model_.screenState);

    model_.falcon.life_ -= 2;

    CHECK(model_.falcon.life_ == 1);

    Missile missile(geometry, model_.falcon.center);  // missile hits falcon

    model_.ammo.push_back(missile);

    model_.update();

    CHECK(model_.falcon.life_ == 3);
}
TEST_CASE("Asteroid hitting another screenObject")
{
    Geometry geometry;
    Model model_(geometry);
    model_.launch();

    CHECK(model_.screenState);

    if(model_.stones.size() > 1){

        model_.stones[0].velocity = {1 ,1};
        model_.stones[1].velocity = {-1 ,-1};
        model_.stones[1].center = model_.stones[0].center;

        model_.update();
        CHECK(model_.stones[0].velocity.width == 1);
        CHECK(model_.stones[0].velocity.height == 1);
        CHECK(model_.stones[1].velocity == ge211::Dimensions {1, 1});
    }
}

TEST_CASE("nn"){
    Geometry geometry;
    Model model_(geometry);
    model_.launch();

    CHECK(model_.screenState);

    Missile missile(geometry, model_.stones[0].center);
    int number = model_.stones.size();
    model_.ammo.push_back(missile);

    model_.update();

    CHECK(model_.stones.size() == number-1);
}

TEST_CASE("Destroyer hits Wall") {
    Geometry geometry;
    Model model_(geometry);
    model_.launch();

    CHECK(model_.screenState);
    int index = model_.fleet.size() -1;
    ge211::Dimensions innitialVelocity = model_.fleet[index].velocity;

    CHECK(model_.fleet[index].velocity == innitialVelocity);
    CHECK(model_.fleet[index-1].velocity == innitialVelocity);
    CHECK(model_.fleet[index-2].velocity == innitialVelocity);
    CHECK(model_.fleet[index-3].velocity == innitialVelocity);

    model_.fleet[index].center.x = model_.geometry_.scene_dims.width;
    innitialVelocity = model_.destroyerVelocity;
    model_.update();
    CHECK(model_.destroyerVelocity == innitialVelocity*-1);

}

TEST_CASE("Missile hits windows sides"){
    Geometry geometry;
    Model model_(geometry);
    model_.launch();

    Missile missile(geometry,{-10,-10});
    model_.ammo.push_back(missile);
    model_.update();
    CHECK(model_.ammo.empty());
}

TEST_CASE("Asteroid Field"){
    Geometry geometry;
    Model model_(geometry);
    model_.launch();

    ge211::Dimensions initialvelocity = model_.stones[0].velocity;
    model_.stones[0].center = {300,180};
    model_.update();
    CHECK(model_.stones[0].velocity.height == -1 * initialvelocity.height);
}