#ifndef _PLAYER_WALKING_ANIMATION_H
#define _PLAYER_WALKING_ANIMATION_H

#include <SDL/SDL.h>
#include <string>
#include "../surface_helper.h"
#include "../entities/game_entity.h"
#include "entity_animation.h"

class PlayerWalkingAnimation: public EntityAnimation {
public:
 PlayerWalkingAnimation(GameEntity* entity, std::string file, int max_frames, int width, int height);
 void loop();
 void render(SDL_Surface* display);
 void cleanUp();
};

#endif
