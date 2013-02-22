#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "game_entity.h"
#include "../states/player_walking.h"

class Player: public GameEntity {
private:
  EntityState* current_state;
public:
  Player();
  void loop();
  void render(SDL_Surface* display);
  void cleanUp();
  void event(SDL_Event* event);
};

#endif
