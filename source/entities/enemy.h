#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "game_entity.h"
#include "../states/enemy_walking.h"

class Enemy: public GameEntity {
public:
  Enemy();
  void loop();
  void render(SDL_Surface* display);
  void cleanUp();
};

#endif
