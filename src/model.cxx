#include "model.hxx"
#include <ge211.hxx>


Model::Model(const Geometry &geometry)
      :geometry_(geometry)
      ,falcon(Falcon(geometry, geometry.falcon_top_left0()))
      ,destroyerVelocity(geometry_.destroyer_velocity)
      ,screenState(false)
      ,count(geometry_.destroyer_cols)
      ,doubt(0)
      ,deathStar(geometry_, {50, 50})
{

    innitialize_asteroids();
    innitialize_destroyers(count);

}

void Model::launch() {
    srand(time(nullptr));

    screenState = true;
    for(Asteroid&  asteroid: stones){

        int x = 2;
        int y = 3;
        int kx = (rand() % 3) -1;
        int ky = (rand() % 3) -1 ;

        asteroid.velocity = {1+x*kx, 1+y*ky};

        //asteroid.velocity += {4, 4};

    }
}

void Model::Move_asteroid() {

    if(!screenState) return;

    for(Asteroid & asteroid : stones){
        if (asteroid.hit_by_missile(ammo)){
            std::swap(asteroid, stones.back());
            stones.pop_back();
        }
    }

    for(Asteroid&  asteroid: stones){
        check_asteroid_collision(asteroid);
        asteroid.center += asteroid.velocity;
    }

}

void Model::update(double dt) {

    if(!deathStar.appear) Move_destroyer();
    Move_asteroid();
    move_missile();
    doubt += dt;
    if (screenState && !deathStar.appear){

        if(falcon_hits_something()){
            falcon.life_ -= 1;
            screenState = false;
            if(falcon.life_ > 0){
                fleet.clear();
                stones.clear();
                ammo.clear();
                innitialize_destroyers(count);
                innitialize_asteroids();
                falcon.center = geometry_.falcon_top_left0();
                return;
            }else{
                fleet.clear();
                stones.clear();
                ammo.clear();
                innitialize_destroyers(geometry_.destroyer_cols);
                count = geometry_.destroyer_cols;
                innitialize_asteroids();
                falcon.center = geometry_.falcon_top_left0();
                falcon.life_ = 3;
                return;
            }
        }

    }

    if (fleet.empty() && falcon.life_ > 0 && deathStar.life >0 &&
    deathStar.appear){

        move_deathstar();
        if (deathStar.life < 1){
            deathStar.center = {50 + deathStar.radius, 50 +
                                deathStar.radius};
            deathStar.life = 3;
            falcon.life_ = 3;
            deathStar.appear = false;
            screenState = false;
            stones.clear();
            ammo.clear();
            count = geometry_.destroyer_cols;
            innitialize_destroyers(count);
            innitialize_asteroids();
            falcon.center = geometry_.falcon_top_left0();
            return;
        }
        if(falcon_hits_something()){
            falcon.life_ -= 1;
            screenState = false;
            if(falcon.life_ > 0){
                deathStar.center = {50 + deathStar.radius,
                                    50+deathStar.radius};
                screenState = false;
                stones.clear();
                ammo.clear();
                innitialize_asteroids();
                falcon.center = geometry_.falcon_top_left0();
                return;
            }else{
                deathStar.center = {50 + deathStar.radius,
                                    50 + deathStar.radius};
                deathStar.life = 3;
                deathStar.appear = false;
                screenState = false;
                stones.clear();
                ammo.clear();
                innitialize_destroyers(geometry_.destroyer_cols);
                count = geometry_.destroyer_cols;
                innitialize_asteroids();
                falcon.center = geometry_.falcon_top_left0();
                falcon.life_ = 3;
                return;
            }
        }
    }



}

void Model::check_asteroid_collision(Asteroid & asteroid) {

    if (deathStar.appear){
        if(asteroid.hits_screenObject(deathStar)) {
            asteroid.reflect_horizontally();
            asteroid.reflect_vertically();
        }
    }

    if (asteroid.hits_bottom(geometry_) || asteroid.hits_side(geometry_)
    || asteroid.hits_top(geometry_)){

        if(asteroid.hits_bottom(geometry_)) asteroid.reflect_vertically();
        if(asteroid.hits_side(geometry_)) asteroid.reflect_horizontally();
        if(asteroid.hits_top(geometry_)) asteroid.reflect_vertically();
        return;
    }

   /* for (Destroyer destroyer : fleet){
        if(asteroid.hits_destroyer(destroyer)) {
            asteroid.reflect_vertically();
            asteroid.reflect_horizontally();
            return;
            }
    }*/

    if(asteroid.hit_above_special()){
        asteroid.reflect_vertically();

    }

    for(Asteroid& ast : stones ){
        if (!(asteroid.center.x == ast.center.x && asteroid.center.y
        == ast.center.y)){
            if(asteroid.hits_screenObject(ast)) {
                asteroid.reflect_vertically();
                asteroid.reflect_horizontally();
                return;
            }
        }
    }

}

void Model::Move_destroyer() {
    if(screenState) {

        if (fleet.empty() && falcon.life_ > 0) {
            screenState = false;
            deathStar.appear = true;
            stones.clear();
            ammo.clear();
            innitialize_asteroids();
            falcon.center = geometry_.falcon_top_left0();

            return;
        }
        for(Destroyer& destroyer: fleet){
            if (destroyer.hit_by_missile(ammo)){
                std::swap(destroyer, fleet.back());
                fleet.pop_back();
                count -= 1;
            }
        }

        int csount = fleet.size();
        if (fleet[0].hits_side(geometry_)) {
            destroyerVelocity *= -1;
            for (Destroyer & destroyer : fleet){
                destroyer.fire_missile(ammo, geometry_);
            }

        }else if (fleet[csount - 1].hits_side(geometry_)) {
            destroyerVelocity *= -1;
            for (Destroyer & destroyer : fleet){
                destroyer.fire_missile(ammo, geometry_);
            }
        }

        for (Destroyer &destroyer : fleet) {
            destroyer.center += destroyerVelocity;
        }
    }
}

bool Model::falcon_hits_something() {

    for(Destroyer& destroyer : fleet){
        if(falcon.hits_screenObject(destroyer)) return true;
   }
    for(Asteroid& asteroid : stones){
        if(falcon.hits_screenObject(asteroid)) return true;
    }
    if(falcon.hit_by_missile(ammo)) return true;

    return falcon.hits_side(geometry_) || (falcon.hits_bottom(geometry_)
                                           || (falcon.hits_top(geometry_)));

}

void Model::innitialize_asteroids() {

    for (int i = 0; i < geometry_.asteroid_rows; i++){
        for (int j = 0; j < geometry_.asteroid_cols; j++){
            ge211::Position  pos{geometry_.asteroid_side_margin +
                                 j * (geometry_.asteroid_dims().width +
                                 geometry_.asteroid_spacing.width),
                                 geometry_.asteroid_side_margin +
                                 i * (geometry_.asteroid_dims().height +
                                 geometry_.asteroid_spacing.height)};

            ge211::Position position {pos.x, geometry_.asteroid_top_margin +
            pos.y};
            Asteroid asteroid{geometry_, position};
            stones.push_back(asteroid);
        }
    }
}

void Model::innitialize_destroyers(int count) {
    for (int i = 0; i < 1; i++){
        for (int j = 0; j < count; j++){
            ge211::Position  pos{geometry_.destroyer_side_margin +
                                 j * (geometry_.destroyer_dims.width +
                                 geometry_.destroyer_spacing.width),
                                 geometry_.destroyer_side_margin +
                                 i * (geometry_.destroyer_dims.height +
                                 geometry_.destroyer_spacing.height)};

            ge211::Position position {pos.x, geometry_.destroyer_top_margin +
            pos.y};
            Destroyer destroyer{geometry_, position};
            fleet.push_back(destroyer);
        }
    }

}

void Model::falconupdate(int code) {

    if(!screenState) return;
    if (code == 1){
        falcon.center.y -= geometry_.falcon_velocity.height;
    }
    else if (code == 2){
        falcon.center.y += geometry_.falcon_velocity.height;
    }
    else if (code == 3){
        falcon.center.x -= geometry_.falcon_velocity.width;
    }
    else if (code == 4){
        falcon.center.x += geometry_.falcon_velocity.width;
    }
}

void Model::fire_missiles_now(int code) {
    if (!screenState) return;

    if (code == 1){

        falcon.fire_missile(ammo, geometry_);
    }

}

void Model::move_missile() {

    if(! screenState) return;

    for(Missile& missile : ammo){
        missile.center_missile_position += missile.missile_velocity_;
        if (missile.hit_bottom(geometry_) || missile.hit_top(geometry_)){
            std::swap(missile, ammo.back());
            ammo.pop_back();
        }
    }
}
void Model::move_deathstar() {
    if(! deathStar.appear || !screenState) return;

    if(deathStar.hit_by_missile(ammo)){
        deathStar.life -= 1;
        return;
    }
    if(deathStar.hits_side(geometry_)){
         deathStar.velocity *= -1;
         deathStar.fire_missile(ammo, geometry_);
         //deathStar.fire_missile(ammo, geometry_);
         //deathStar.fire_missile(ammo, geometry_);

    }
    deathStar.center += {deathStar.velocity};

    if(deathStar.center.x == geometry_.scene_dims.width/2 ||
        deathStar.center.x == geometry_.scene_dims.width/4 ||
        deathStar.center.x *3 == geometry_.scene_dims.width/4){
        //deathStar.center.x == geometry_.scene_dims.width/8 ||
        //deathStar.center.x *7 == geometry_.scene_dims.width/8 ||
        //deathStar.center.x *5== geometry_.scene_dims.width/8 ) {

        deathStar.fire_missile(ammo, geometry_);
        //deathStar.fire_missile(ammo, geometry_);
        //deathStar.fire_missile(ammo, geometry_);
    }
}

