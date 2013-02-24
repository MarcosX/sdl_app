#include "enemy.h"

Enemy::Enemy(){
  current_state = new EnemyWalking(this);
  pos_x = pos_y = 50;
}

void Enemy::loop(){
  current_state->loop();
}

void Enemy::render(SDL_Surface* display){
  current_state->render(display);
}

void Enemy::cleanUp(){
  delete(current_state);
}

