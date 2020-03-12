#include "ui.hxx"

ge211::Color const falcon_color {255, 127, 127};
ge211::Color const asteroid_color{255, 255, 127};
ge211::Color const destroyer_color{255, 215, 127};
ge211::Color const missile_color{255, 0, 0 };
ge211::Color const life_color{10, 200, 0 };
ge211::Color const deathStar_color{255, 255, 255};

Ui::Ui(Model & model)
   :model_(model)
   { }
ge211::Dimensions Ui::initial_window_dimensions() const {
    return model_.geometry_.scene_dims;
}

void Ui::draw(ge211::Sprite_set & sprites)

{
    sprites.add_sprite(falcon_sprite_, model_.falcon.top_left());

    for(Asteroid& asteroid : model_.stones){
        sprites.add_sprite(asteroid_sprite_, asteroid.top_left());
    }
    for (Destroyer& destroyer : model_.fleet){
        sprites.add_sprite(destroyer_sprite_, destroyer.top_left());
    }
    for(Missile missile : model_.ammo){
        sprites.add_sprite(missile_sprite_, missile.top_left());
    }
    for(int i = 0; i < model_.falcon.life_; i++){
        sprites.add_sprite(life_sprite_, {20 + (i*30), model_.geometry_.scene_dims.height - 80});
    }
    if(model_.deathStar.appear){
        sprites.add_sprite(death_sprite_, model_.deathStar.top_left());

        for(int i = 0; i < model_.deathStar.life; i++) {
            sprites.add_sprite(life_sprite_, {20 + (i * 30), 30});
        }
    }


}

void Ui::on_key(ge211::Key key) {

    if (key == ge211::Key::code('q')){
        quit();
    } else if (key == ge211::Key::code(' ')){
        if(!model_.screenState) model_.launch();
    }else if(key == ge211::Key::up()){
        model_.falconupdate(1);
    }else if(key == ge211::Key::down()){
        model_.falconupdate(2);
    } else if (key == ge211::Key::left()){
        model_.falconupdate(3);
    } else if (key == ge211::Key::right()){
        model_.falconupdate(4);
    }else if(key == ge211::Key::code('f')){
        model_.fire_missiles_now(1);
    }

}

void Ui::on_frame(double dt) {
//    ge211::Random* rnd = &get_random();
    model_.update();
}

