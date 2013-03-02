#ifndef _BLOCK_H_
#define _BLOCK_H_

#include "game_entity.h"

class Block : public GameEntity {
public:
  Block(int x, int y){ pos_x = x; pos_y = y;}
  int getWidth(){return 32; };
  int getHeight(){return 32; };
  void render(SDL_Surface* display){
    SurfaceHelper::draw(display, ImageSource::getBlockImage(), pos_x, pos_y);
  }
};

#endif
