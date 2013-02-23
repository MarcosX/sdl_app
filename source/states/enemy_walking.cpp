#include "enemy_walking.h"

EnemyWalking::EnemyWalking(GameEntity* entity){
  sprites = ImageSource::getEnemyImageSheet();
  max_frames = 3;
  height = 32;
  width = 32;
  enemy = (Enemy*)entity;
  velocity_x = velocity_y = 5;
  current_frame = 0;
}

void EnemyWalking::loop(){
  current_frame++;
  if(current_frame >= max_frames)
    current_frame = 0;
  if(enemy->pos_x >= (SCREEN_WIDTH - width)){
    enemy->move_left = true;
    enemy->move_right = false;
  }
  if (enemy->pos_x <= 0){
    enemy->move_left = false;
    enemy->move_right = true;
  }
  if(enemy->move_right) enemy->pos_x += velocity_x;
  if(enemy->move_left) enemy->pos_x -= velocity_x;
}

void EnemyWalking::render(SDL_Surface* display){
  if(enemy->move_down)
    SurfaceHelper::draw(display, sprites, enemy->pos_x, enemy->pos_y, current_frame*width + 94, 0 + 128, width, height);
  else if(enemy->move_up)
    SurfaceHelper::draw(display, sprites, enemy->pos_x, enemy->pos_y, current_frame*width + 94, 96 + 128, width, height);
  else if(enemy->move_left)
    SurfaceHelper::draw(display, sprites, enemy->pos_x, enemy->pos_y, current_frame*width + 94, 32 + 128, width, height);
  else if(enemy->move_right)
    SurfaceHelper::draw(display, sprites, enemy->pos_x, enemy->pos_y, current_frame*width + 94, 64 + 128, width, height);
  else
    SurfaceHelper::draw(display, sprites, enemy->pos_x, enemy->pos_y, width, 0, width, height);
}

void EnemyWalking::cleanUp(){
  SDL_FreeSurface(sprites);
}

