#pragma once

#include <ge211.hxx>
#include "geometry.hxx"
#include <vector>

//
// Model Classes
//
using Block = ge211::Rectangle;

// Base class for every object on screen
class screenObject : public Block {


public:
    explicit screenObject(int radius) : radius(radius) {}

//defines how an object will be destructed
    virtual void destruct() {};
    //Returns the next position of next
    virtual screenObject next_() {return screenObject{radius};};
    // Returns the front middle end of the objectS on screen that
    // is used to control their movement and shoot missiles
    virtual ge211::Position  pointer() {return ge211::Position{0, 0};};
    // Defines behaviour when an object hits any side
    virtual bool hit_side(int width) {return false;}
    // Defines the behavior of objects when they hit  their vertical boundary
    virtual bool hit_vertical_boundary (int height) {return false;};
    //Defines what objects do when hit by a missile. Returns
    virtual bool missile_collision() {return false;};
    //used to set

protected:
    int radius{};
    bool alive = false;
    ge211::Position position{0, 0};
    ge211::Position center{0, 0};
    ge211::Dimensions velocity{1, 0};
};



class falcon: public screenObject{

    // predefined private members
    int live_ = 3;
    ge211::Position  position;

public:
    //The following are derived from above.
    explicit falcon(ge211::Position position, int radius ) : screenObject(radius), position(position) {};
    void destruct() override;
    screenObject next_() override;
    ge211::Position  pointer() override;
    bool hit_side(int width) override;
    bool hit_vertical_boundary (int height) override;
    bool missile_collision() override;


};



class destroyer: public screenObject{

    // predefined private members


public:
    //The following are derived from above.
    explicit destroyer(ge211::Position position, int radius) : screenObject(radius), position(position) {};
    void destruct() override;
    screenObject next_() override;
    ge211::Position  pointer() override;
    bool hit_side(int width) override;
    bool hit_vertical_boundary (int height) override;
    bool missile_collision() override;

private:
    ge211::Position  position;
};



class asteroid: public screenObject{

    // predefined private members


public:
    //The following are derived from above.
    explicit asteroid(ge211::Position position, int radius) : screenObject(radius), position(position) {};
    void destruct() override;
    screenObject next_() override;
    ge211::Position  pointer() override;
    bool hit_side(int width) override;
    bool hit_vertical_boundary (int height) override;
    bool missile_collision() override;

private:
    ge211::Position  position;
};



class deathstar: public destroyer{

    // predefined private members


public:
    //The following are derived from above.
    explicit deathstar(ge211::Position position, int radius) : destroyer(position, radius) {};

};



class missile : public screenObject{

public:
    explicit missile(ge211::Position position, int radius) : screenObject(radius), position(position) {};
    // member functions

    //Returns true when missile hits top or bottom
    bool hit_bound();

    //Destroys missile
    void destroy();

    screenObject next();


private:
    ge211::Position  position;
    ge211::Dimensions velocity{0, 0};
    bool alive = true;
};

class model{



public:
    explicit model(Geometry const& geometry = Geometry());
    //model()= default; ;
    // Helper function to Checks if any collision between a missile
    // and any space object and destroys the space object and missile
    static void missileSpaceObjectCollision();

    // Helper function to check if missile is out of bounds, destroying it
    void missileOutOfBounds();

    //update the state of the game using the predefined instructions
    void update();

    //starts the game
    void launch();

    // Falcon Movement
    void go_left(bool b);
    void go_right(bool b);
    void thrust(bool b);

    ///
    /// MEMBER VARIABLES
    ///

    std::vector<destroyer> destroyers_;
    std::vector<missile> missiles_;
    std::vector<asteroid> asteroids_;
    falcon falcon_;
    deathstar deathstar_;
    Geometry const     geometry_;
};