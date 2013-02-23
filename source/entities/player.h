#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "game_entity.h"
#include "../states/player_walking.h"

class Player: public GameEntity {
public:
  Player();
  void loop();
  void render(SDL_Surface* display);
  void cleanUp();
  void event(SDL_Event* event);
  bool hits(GameEntity* target);
};

#endif
