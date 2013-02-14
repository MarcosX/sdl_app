#ifndef _PLAYER_WALKING_ANIMATION_H_
#define _PLAYER_WALKING_ANIMATION_H_

#include <SDL/SDL.h>
#include <string>
#include "../surface_helper.h"
#include "../entities/game_entity.h"
#include "../entities/player.h"
#include "entity_state.h"

class Player;

class PlayerWalking: public EntityState {
private:
  Player* player;
public:
  PlayerWalking(GameEntity* entity, std::string file, int max_frames, int width, int height);
  void loop();
  void render(SDL_Surface* display);
  void cleanUp();
  void event(SDL_Event* event);
};

#endif
