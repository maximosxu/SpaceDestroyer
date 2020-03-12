#include "model.hxx"
#include "ge211.hxx"
#include "geometry.hxx"

void falcon::destruct() {

}

ge211::Position falcon::pointer() {
    return {0, 0};
}

bool falcon::hit_side(int width) {
    return false;
}

bool falcon::hit_vertical_boundary(int height) {
    return false;
}

bool falcon::missile_collision() {
    return false;
}

screenObject falcon::next_() {
    return screenObject::next_();
}


void asteroid::destruct() {
    screenObject::destruct();
}

ge211::Position asteroid::pointer() {
    return screenObject::pointer();
}

bool asteroid::hit_side(int width) {
    return screenObject::hit_side(width);
}

bool asteroid::hit_vertical_boundary(int height) {
    return screenObject::hit_vertical_boundary(height);
}

bool asteroid::missile_collision() {
    return screenObject::missile_collision();
}

screenObject asteroid::next_() {
    return screenObject::next_();
}

void destroyer::destruct() {
    screenObject::destruct();
}

ge211::Position destroyer::pointer() {
    return screenObject::pointer();
}

bool destroyer::hit_side(int width) {
    return screenObject::hit_side(width);
}

bool destroyer::hit_vertical_boundary(int height) {
    return screenObject::hit_vertical_boundary(height);
}

bool destroyer::missile_collision() {
    return screenObject::missile_collision();
}

screenObject destroyer::next_() {
    return screenObject::next_();
}

screenObject missile::next() {
    return screenObject::next_();
}

void model::update() { }
void model::launch() { }
void model::go_left(bool b) { }
void model::go_right(bool b) { }
void model::thrust(bool b) { }
model::model(const Geometry &geometry)
        : geometry_(geometry)
        , deathstar_(deathstar_.top_left(),300)
        , falcon_(falcon_.top_left(),100)
{}