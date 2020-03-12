#pragma once
#include "model.hxx"
#include <ge211.hxx>

extern ge211::Color const asteroid_color, falcon_color, destroyer_color, missile_color, life_color, deathStar_color;

struct Ui : ge211::Abstract_game
{
    explicit Ui(Model&);

    ge211::Dimensions initial_window_dimensions() const override;

    void draw(ge211::Sprite_set&) override;

    void on_key(ge211::Key) override;

    void on_frame(double dt) override;

     ///
     /// Memember Variables
     ///

     Model& model_;
     ge211::Circle_sprite const
            asteroid_sprite_ { 40, asteroid_color};
     ge211::Rectangle_sprite const
            falcon_sprite_  {model_.geometry_.falcon_dim_, falcon_color};
     ge211::Rectangle_sprite const
            destroyer_sprite_ {model_.geometry_.destroyer_dims, destroyer_color};
     ge211::Rectangle_sprite const
            missile_sprite_ {model_.geometry_.missile_dims, missile_color};
     ge211::Rectangle_sprite const
            death_sprite_{model_.geometry_.deathStar_dims, deathStar_color};
     ge211::Rectangle_sprite const
            life_sprite_{{10,10}, deathStar_color};



};