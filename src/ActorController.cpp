#include "ActorController.hpp"

void ActorController::setup()
{

    
    box.set(width, height, depth );
    box.setPosition(x, y+(height/2), z);
    
}
 

void ActorController::update()
{
    box.set(width, height, depth );
    if(id >= 199)
    {
        box.setPosition(x, (y)-((height)/2) + 50, z);
    }else{
        box.setPosition(x, y+(height/2), z);
    }

    
}

void ActorController::draw()
{
    box.draw();
}


