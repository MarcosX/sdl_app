#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "../states/enemy_walking.h"
#include "game_entity.h"

class Enemy: public GameEntity {
private:
  EntityState* walking;
public:
  Enemy();
  void loop();
  void render(SDL_Surface* display);
  void cleanUp();
};

#endif
