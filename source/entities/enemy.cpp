#include "enemy.h"

Enemy::Enemy(){
  walking = new EnemyWalking(this);
  pos_x = pos_y = 50;
  width = height = 64;
  velocity_x = velocity_y = 5;
  move_up = move_left = move_down = false;
  move_right = true;
}

void Enemy::loop(){
  walking->loop();
  if(move_right) pos_x += velocity_x;
  if(move_left) pos_x -= velocity_x;
}

void Enemy::render(SDL_Surface* display){
  walking->render(display);
}

void Enemy::cleanUp(){
  delete(walking);
}

