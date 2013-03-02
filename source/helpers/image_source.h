#ifndef _IMAGE_SOURCE_H_
#define _IMAGE_SOURCE_H_

#include "surface_helper.h"

class ImageSource {
private:
  static SDL_Surface* playerImageSheet;
  static SDL_Surface* enemyImageSheet;
  static SDL_Surface* blockImage;
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

  static SDL_Surface* getBlockImage(){
    if(blockImage == NULL)
      blockImage = SurfaceHelper::load("images//block.png");
    return blockImage;
  }
};

#endif
