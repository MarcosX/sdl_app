#ifndef _GAME_ENTITY_H_
#define _GAME_ENTITY_H_

#include <SDL/SDL.h>
#include "../helpers/surface_helper.h"
#include "../helpers/constants.h"

class GameEntity {
protected:
  int pos_x, pos_y;
  int width, height;
  int velocity_x, velocity_y;
public:
  int getPosX() {return pos_x;};
  int getPosY() {return pos_y;};
  int getWidth() {return width;};
  int getHeight() {return height;};
  virtual void loop(){};
  virtual void render(SDL_Surface* display){};
  virtual void cleanUp(){};
};

#endif
