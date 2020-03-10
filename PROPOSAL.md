# Proposal: SPACE DESTROYER!

###About
Space destroyer is a hybrid version of the 
classic arcade games Asteroids and Space Invaders.

## Synopsis

###Elements
The game will have four elements that will be factored from different
sections as listed below:
     
  * **SpaceObject** 
   
    This is a Abstract class that defines the general 
    attributes and behavior of any of my objects floating
    in space. It comprises of the following listed 
    elements;
    
    - *Falcon*
    
      A horizontally and vertically movable triangle that produces
      rectangles at the upper tip that we refer to as missiles.
      It inherits the abstract class spaceobject, and is controlled by
      the user.
      
    -  *Destroyer*
    
       Horizontally movable rectangles located at the top of the
       screen with their main tip facing down. Their movement is predefined
        and the speed varies depending on the level. They also
        randomly shoot straight missiles downwards. They are inherited 
        from the abstract class Space Object.
        
        -  *DeathStar*
            
            This is a bigger horizontally movable object that shoots 
            missiles at a faster rate than other Destroyers. It also 
            moves faster than other destroyers and disappears
            on one part of the screen and reappears on the other
            side of the screen. 
            It also has a longer life span than other destroyers. 
            It inherits the Destroyer class. 
        
    -  *Asteroids*
       
       These are circular objects randomly floating on the screen. They are 
       inherited from the Abstract Space Object class.
  
  *  **Missile**   
  
     These are vertically mobile rectangles that originate from some members of 
     Space Object. The velocity and size are determined by which type of object
     produced them. 
    
##Goal
The players goal is to control the falcon to shoot and manoeuvre the Asteroids
to eventually destroy the Destroyers and the DeathStar in the Boss level.


##Game play
The game starts in a frozen state with the falcon stationary 
at the center bottom with three bars at the left corner of the screen 
showing the player lives left. Asteroids are positioned
in the middle of the screen and the destroyers 
are stationary at the top of the screen. 
When spacebar is pressed the game starts and the asteroids 
start randomly floating and 
the Destroyers begin moving horizontally at the top 
sporadically firing missiles 
downwards. To complete the level the player has to 
navigate by using the directional keys
and fire missiles at the 
Destroyers and asteroids with the space bar 
while dodging any approaching missiles or asteroids. 
If the player 
(falcon) hits any edge of the screen or any screen object
then their life is reduced by one. If the player loses 
all their lives
then the game ends and the game is reset.  

If the player manages to destroy all the destroyers then 
the boss stage begins 
with every other screen object being cleared and 
the boss replacing the destroyers
at the top. The player will strictly have their 
number of lives from the previous 
level. 

## Functional requirements
1.  The destroyers are placed stationary in a row at the top
when the game starts. The player is placed at the 
center of the x plane above the bottom
of the screen when the game start. The Asteroids are placed 
starting from the top 1/4 down to the bottom 3/4 
end and stationary in a frozen state.
2.  The player can launch the game by pressing the space bar and this makes
the Asteroids begin random motion while the destroyers move uniformly
horizontally towards the right.
3.  When the player presses the up or down key, the Falcon 
moves up or down with a predefined velocity. On release of 
the up or down key the Falcon resets to a 
velocity of zero and stops.
4.  When a side key is pressed, the Falcon surges towards that side
with a predefined velocity. On release of a side key, the falcon stops.
5. If the falcon hits any of the sides it loses one life. If the Falcon 
hits any of the screen elements or is hit by an element
or missile, it loses one life and is reset to a frozen state, and all
the asteroids are also recreated and reset to a frozen state. The remaining 
destroyers are also redrawn and reset to a frozen state awaiting user to press 
the space bar.
6. If the Falcon loses all lives the game is over and 
thus the game resets completely;
back to frozen mode 
with the player having 3 lives.
7. If any of the other space objects or the screen is hit by a asteroid 
except the Falcon, the asteroid is reflected both vertically 
and horizontally and it then continues with its random motion.
8. If an Asteroid is hit by a missile it is immediately destroyed. 
If a destroyer is hit by any missle then they are removed. 
9. If a destroyer hits any of the sides, all the destroyers velocity are
reflected horizontally.
10. Destroyers fire a missile straight down periodically
11. If the player destroy all destroyers the boss stage begins with the boss 
behaving directly as other destroyers except with a higher velocity, faster
shooting pace, and three lives. 
12.  If a missile hits any of the windows sides its destroyed. If it 
hits a spaceObject, both 
the object and the space missile are destroyed. 
If it hits a Falcon, the falcon loses a life and is reset.
13.   If the Falcon kills the boss or vice versa, the end of 
game procedure is updated.


## Open questions




