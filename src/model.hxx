#pragma once

#include <ge211.hxx>

//
// Model Classes
//

// Base class for every object on screen
class screenObject{


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


public:
    //The following are derived from above.
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
    void destruct() override;
    screenObject next_() override;
    ge211::Position  pointer() override;
    bool hit_side(int width) override;
    bool hit_vertical_boundary (int height) override;
    bool missile_collision() override;


};



class asteroid: public screenObject{

    // predefined private members


public:
    //The following are derived from above.
    void destruct() override;
    screenObject next_() override;
    ge211::Position  pointer() override;
    bool hit_side(int width) override;
    bool hit_vertical_boundary (int height) override;
    bool missile_collision() override;


};



class deathstar: public destroyer{

    // predefined private members


public:
    //The following are derived from above.


};



class missile{

public:
    ge211::Position  position;
    ge211::Dimensions velocity{0, 0};
    bool alive = true;

    explicit missile(ge211::Position  position) :position(position){};
    // member functions

    //Returns true when missile hits top or bottom
    bool hit_bound();

    //Destroys missile
    void destroy();

    missile next();


};

class model{

    const static int gridwidth = 1500;
    const static int gridheight = 1000;
    const static int numberofDestroyers = 10;
    const static int numberofAsteroids = 15;

public:

    model()= default; ;
    // Helper function to Checks if any collision between a missile
    // and any space object and destroys the space object and missile
    static void missileSpaceObjectCollision();

    // Helper function to Checks if missile is out of bounds and destroy it
    void missileOutOfBounds();

    //update the state of the game using the predefined instructions
    void update();

    //starts the game
    void launch();

    ///
    /// MEMBER VARIABLES
    ///

    std::vector<destroyer> destroyers_;
    std::vector<missile> missiles_;
    std::vector<asteroid> asteroids_;
    falcon milleniumfalcon_;

};