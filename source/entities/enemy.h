#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "game_entity.h"

class Enemy: public GameEntity {
private:
  SDL_Surface* sprite;
public:
  Enemy();
  void loop();
  void render(SDL_Surface* display);
  void cleanUp();
};

#endif
