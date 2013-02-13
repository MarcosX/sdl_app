#ifndef _SDL_APP_H_
#define _SDL_APP_H_

#include <SDL/SDL.h>
#include "surface_helper.h"
#include "entities/player.h"
#include "entities/enemy.h"

#define FRAMES_PER_SECOND_DELAY 1000.0f/12.0f
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define SCREEN_BPP 32

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
