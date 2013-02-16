#ifndef _IMAGE_SOURCE_H_
#define _IMAGE_SOURCE_H_

#include "surface_helper.h"

class ImageSource {
private:
  static SDL_Surface* playerImageSheet;
  static SDL_Surface* enemyImageSheet;
public:
  static SDL_Surface* getPlayerImageSheet(){
    if(playerImageSheet == NULL)
      playerImageSheet = SurfaceHelper::load("images//player_main_sheet.png");
    return playerImageSheet;
  }

  static SDL_Surface* getEnemyImageSheet(){
    if(enemyImageSheet == NULL)
      enemyImageSheet = SurfaceHelper::load("images//enemy_main_sheet.png");
    return enemyImageSheet;
  }
};

#endif
