#ifndef _SDL_APP_H_
#define _SDL_APP_H_

#include <SDL/SDL.h>
#include "entities/game_entity.h"
#include "entities/player.h"
#include "entities/enemy.h"
#include "helpers/constants.h"
#include "helpers/surface_helper.h"

class SdlApp{
private:
  bool running;
  int frame_rate;
  int old_time;
  SDL_Surface* display;
  SDL_Surface* background;
  Player* player;
  Enemy* enemy;

  int onInit();
  void onEvent(SDL_Event* event);
  void onLoop();
  void onRender();
  void onCleanUp();
  bool collide(GameEntity* entity1, GameEntity* entity2);
public:
  SdlApp();
  int onExecute();
};

#endif
