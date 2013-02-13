#ifndef _SDL_APP_H_
#define _SDL_APP_H_

#include <SDL/SDL.h>
#include "surface_helper.h"
#include "entities/player.h"
#include "entities/enemy.h"
#include "constants.h"

class SdlApp{
private:
  bool running;
  int frame_rate;
  int old_time;
  SDL_Surface* display;
  SDL_Surface* background;
  Player* player;
  Enemy* enemy;

public:
  SdlApp();
  int onExecute();
  int onInit();
  void onEvent(SDL_Event* event);
  void onLoop();
  void onRender();
  void onCleanUp();
};

#endif
