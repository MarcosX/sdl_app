#ifndef _ENTITY_ANIMATION_H_
#define _ENTITY_ANIMATION_H_

#include <SDL/SDL.h>
#include <string>
#include "../surface_helper.h"
#include "../entities/game_entity.h"

class EntityAnimation {
protected:
 SDL_Surface* sprites;
 GameEntity* entity;
 int current_frame, max_frames;
 int width, height;
public:
 virtual void loop(){};
 virtual void event(SDL_Event* event){};
 virtual void render(SDL_Surface* display){};
 virtual void cleanUp(){};
};

#endif
