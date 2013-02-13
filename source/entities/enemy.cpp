#include "enemy.h"

Enemy::Enemy(){
  sprite = SurfaceHelper::load("images//image.png");
  pos_x = pos_y = 50;
  velocity_x = velocity_y = 10;
}

void Enemy::loop(){
  if(pos_x >= (SCREEN_WIDTH - 64) || pos_x <= 0)
    velocity_x = -velocity_x;
  pos_x += velocity_x;
}

void Enemy::render(SDL_Surface* display){
  SurfaceHelper::draw(display, sprite, pos_x, pos_y);
}

void Enemy::cleanUp(){
  SDL_FreeSurface(sprite);
}

