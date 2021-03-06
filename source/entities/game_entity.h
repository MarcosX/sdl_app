#ifndef _GAME_ENTITY_H_
#define _GAME_ENTITY_H_

#include <SDL/SDL.h>
#include "../helpers/surface_helper.h"
#include "../helpers/constants.h"
#include "../helpers/image_source.h"
#include "../states/entity_state.h"

class GameEntity {
protected:
  EntityState* current_state;
public:
  int pos_x, pos_y;
  virtual int getWidth() {return current_state->getWidth();};
  virtual int getHeight() {return current_state->getHeight();};
  virtual void loop(){};
  virtual void render(SDL_Surface* display){};
  virtual void cleanUp(){};
  virtual bool hits(GameEntity* target){};
};

#endif
