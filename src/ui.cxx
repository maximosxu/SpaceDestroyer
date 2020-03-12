#include "ui.hxx"

///
/// VIEW CONSTANTS
///
ge211::Color const falcon_color    {255, 127, 127};
ge211::Color const deathstar_color  {255, 255, 127};
ge211::Color const asteroid_color   {100, 100, 100};
ge211::Color const destroyer_color {200,200,200};
ge211::Color const missile_color {255,0,0};

///
/// VIEW FUNCTIONS
///

Ui::Ui(model& model)
        : model_(model)
{ }

ge211::Dimensions Ui::initial_window_dimensions() const
{
    return model_.geometry_.scene_dims;
}

void Ui::draw(ge211::Sprite_set& sprites)
{
    sprites.add_sprite(falcon_sprite_,model_.falcon_.top_left());
    sprites.add_sprite(deathstar_sprite_,model_.deathstar_.top_left());
    for (std::vector<destroyer>::iterator i = model_.destroyers_.begin(); i != model_.destroyers_.end(); i++)
        sprites.add_sprite(destroyer_sprite_, i->top_left());
    for (std::vector<asteroid>::iterator i = model_.asteroids_.begin(); i != model_.asteroids_.end(); i++)
        sprites.add_sprite(asteroid_sprite_, i->top_left());
    for (std::vector<missile>::iterator i = model_.missiles_.begin(); i != model_.missiles_.end(); i++)
        sprites.add_sprite(missile_sprite_, i->top_left());
}


///
/// CONTROLLER FUNCTIONS
///

void Ui::on_key(ge211::Key key)
{
    if (key == ge211::Key::code('q'))
        quit();

    if (key == ge211::Key::code(' '))
        model_.launch();

    if (key==ge211::Key::left())
        model_.go_left(true);

    if (key==ge211::Key::right())
        model_.go_right(true);

    if (key==ge211::Key::up())
        model_.thrust(true);
}

void Ui::on_frame(double)
{
    model_.update();
}