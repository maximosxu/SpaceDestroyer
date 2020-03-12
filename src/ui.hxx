
#pragma once

#include "model.hxx"
#include <ge211.hxx>

///
/// VIEW CONSTANTS
///

extern ge211::Color const falcon_color, asteroid_color, destroyer_color, deathstar_color, missile_color;

struct Ui : ge211::Abstract_game
{
    ///
    /// CONSTRUCTOR
    ///

    // Constructs a `Ui` given a reference to the model that stores
    // the actual state of the game.

    explicit Ui(model&);

    ///
    /// MEMBER FUNCTIONS (for the view)
    ///

    // Returns the size of the window as given by `geometry_.scene_dims`.
    // (GE211 calls this to find out how big to make the window.)
    ge211::Dimensions initial_window_dimensions() const override;

    // Renders all the game entities to the screen.
    void draw(ge211::Sprite_set&) override;

    ///
    /// MEMBER FUNCTIONS (for the controller)
    ///


    //  - On ' ', tells the model to launch the ball.
    void on_key(ge211::Key) override;

    // Updates the model to reflect the passage of time, by calling
    // `Model::update`.
    //
    // While this function is passed `dt`, the elapsed time in seconds since the
    // previous frame, we aren't using that for now.

    void on_frame(double dt) override;

    ///
    /// MEMBER VARIABLE (model reference)
    ///

    // This is a reference to the model. It means that the UI doesn't
    // own the model but has access to it. Thus, the client of the UI
    // (brick_out.cpp) must create a `Model` first and then pass that by
    // reference to the `Ui` constructor.
    model& model_;

    ///
    /// MEMBER VARIABLES (for the view)
    ///

    // These three definitions create the sprites that we need to
    // display the circle, the paddle, and the bricks to the screen.
    // Each depends on the geometry, which it can access via the `model_`
    // member variable. Member variables are initialized in order, which
    // means that `model_` will be properly initialized before we use it
    // here.

    ge211::Circle_sprite    const
            deathstar_sprite_    {model_.geometry_.deathstar_radius_,  deathstar_color};

    ge211::Rectangle_sprite const
            destroyer_sprite_  {model_.geometry_.destroyer_dims_, destroyer_color};

    ge211::Rectangle_sprite const
            falcon_sprite_   {model_.geometry_.falcon_dims_, falcon_color};

    ge211::Rectangle_sprite const
            missile_sprite_   {model_.geometry_.missile_dims_, missile_color};

    ge211::Circle_sprite    const
            asteroid_sprite_    {model_.geometry_.asteroid_radius_,  asteroid_color};
};
