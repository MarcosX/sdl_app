#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "game_entity.h"
#include "../states/entity_state.h"
#include "../states/player_walking.h"

class Player: public GameEntity {
private:
  EntityState* walking;
  bool move_left, move_right, move_up, move_down;
public:
  Player();
  void loop();
  void render(SDL_Surface* display);
  void cleanUp();
  void event(SDL_Event* event);
};

#endif
