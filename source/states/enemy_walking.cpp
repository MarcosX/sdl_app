#include "enemy_walking.h"

EnemyWalking::EnemyWalking(GameEntity* entity){
  sprites = ImageSource::getEnemyImageSheet();
  max_frames = 3;
  height = 32;
  width = 32;
  enemy = (Enemy*)entity;
  velocity_x = velocity_y = 5;
  current_frame = 0;
  move_left = move_up = move_down = false;
  move_right = true;
}

void EnemyWalking::loop(){
  current_frame++;
  if(current_frame >= max_frames)
    current_frame = 0;
  if(enemy->pos_x >= (SCREEN_WIDTH - width)){
    move_left = true;
    move_right = false;
  }
  if (enemy->pos_x <= 0){
    move_left = false;
    move_right = true;
  }
  if(move_right) enemy->pos_x += velocity_x;
  if(move_left) enemy->pos_x -= velocity_x;
}

void EnemyWalking::render(SDL_Surface* display){
  if(move_down)
    SurfaceHelper::draw(display, sprites, enemy->pos_x, enemy->pos_y, current_frame*width + 94, 0 + 128, width, height);
  else if(move_up)
    SurfaceHelper::draw(display, sprites, enemy->pos_x, enemy->pos_y, current_frame*width + 94, 96 + 128, width, height);
  else if(move_left)
    SurfaceHelper::draw(display, sprites, enemy->pos_x, enemy->pos_y, current_frame*width + 94, 32 + 128, width, height);
  else if(move_right)
    SurfaceHelper::draw(display, sprites, enemy->pos_x, enemy->pos_y, current_frame*width + 94, 64 + 128, width, height);
  else
    SurfaceHelper::draw(display, sprites, enemy->pos_x, enemy->pos_y, width + 94, 128, width, height);
}

void EnemyWalking::cleanUp(){
  SDL_FreeSurface(sprites);
}

