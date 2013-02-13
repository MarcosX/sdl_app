#ifndef _GAME_ENTITY_H_
#define _GAME_ENTITY_H_

#include <SDL/SDL.h>
#include "../surface_helper.h"
#include "../constants.h"

class GameEntity {
protected:
  int pos_x, pos_y;
  int velocity_x, velocity_y;
public:
  int getPosX() {return pos_x;};
  int getPosY() {return pos_y;};
  virtual void loop(){};
  virtual void render(SDL_Surface* display){};
  virtual void cleanUp(){};
};

#endif
