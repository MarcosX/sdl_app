#include "enemy.h"

Enemy::Enemy(){
  current_state = new EnemyWalking(this);
  pos_x = pos_y = 50;
  width = height = 64;
  velocity_x = velocity_y = 5;
  move_up = move_left = move_down = false;
  move_right = true;
}

void Enemy::loop(){
  current_state->loop();
  if(move_right) pos_x += velocity_x;
  if(move_left) pos_x -= velocity_x;
}

void Enemy::render(SDL_Surface* display){
  current_state->render(display);
}

void Enemy::cleanUp(){
  delete(current_state);
}

