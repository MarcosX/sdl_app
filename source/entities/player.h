#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "game_entity.h"
#include "../animations/entity_animation.h"
#include "../animations/player_walking_animation.h"

class Player: public GameEntity {
private:
  EntityAnimation* walking;
  bool move_left, move_right, move_up, move_down;
public:
  Player();
  void loop();
  void render(SDL_Surface* display);
  void cleanUp();
  void event(SDL_Event* event);
};

#endif
