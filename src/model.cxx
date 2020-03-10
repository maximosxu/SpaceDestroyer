#include "model.hxx"
#include "ge211"
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

missile missile::next() {
    return missile(ge211::Position{0, 0});
}

bool missile::collision() {
    return false;
}
