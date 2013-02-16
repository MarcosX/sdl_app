#include "enemy_walking.h"

EnemyWalking::EnemyWalking(GameEntity* entity){
  sprites = ImageSource::getEnemyImageSheet();
  this->max_frames = 4;
  this->height = 64;
  this->width = 64;
  this->enemy = (Enemy*)entity;
  current_frame = 0;
}

void EnemyWalking::loop(){
  current_frame++;
  if(current_frame >= max_frames)
    current_frame = 0;
  if(enemy->getPosX() >= (SCREEN_WIDTH - width)){
    enemy->move_left = true;
    enemy->move_right = false;
  }
  if (enemy->getPosX() <= 0){
    enemy->move_left = false;
    enemy->move_right = true;
  }
}

void EnemyWalking::render(SDL_Surface* display){
  if(enemy->move_down)
    SurfaceHelper::draw(display, sprites, enemy->getPosX(), enemy->getPosY(), current_frame*width, 0, width, height);
  else if(enemy->move_up)
    SurfaceHelper::draw(display, sprites, enemy->getPosX(), enemy->getPosY(), current_frame*width, 192, width, height);
  else if(enemy->move_left)
    SurfaceHelper::draw(display, sprites, enemy->getPosX(), enemy->getPosY(), current_frame*width, 64, width, height);
  else if(enemy->move_right)
    SurfaceHelper::draw(display, sprites, enemy->getPosX(), enemy->getPosY(), current_frame*width, 128, width, height);
  else
    SurfaceHelper::draw(display, sprites, enemy->getPosX(), enemy->getPosY(), 64, 0, width, height);
}

void EnemyWalking::cleanUp(){
  SDL_FreeSurface(sprites);
}

