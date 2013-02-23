#ifndef _ENTITY_ANIMATION_H_
#define _ENTITY_ANIMATION_H_

#include <SDL/SDL.h>
#include <string>
#include "../helpers/surface_helper.h"
class GameEntity;

class EntityState {
protected:
 SDL_Surface* sprites;
 int current_frame, max_frames;
 int width, height;
 int velocity_x, velocity_y;
public:
 int getWidth(){return width;};
 int getHeight(){return height;};
 virtual void loop(){};
 virtual void event(SDL_Event* event){};
 virtual void render(SDL_Surface* display){};
 virtual void cleanUp(){};
 virtual bool hits(GameEntity* target){};
};

#endif
