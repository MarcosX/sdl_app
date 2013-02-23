#include "player.h"

Player::Player(){
  current_state = new PlayerWalking(this);
  pos_x = pos_y = 0;
  move_up = move_left = move_right = move_down = false;
}

void Player::loop(){
  current_state->loop();
}

void Player::render(SDL_Surface* display){
  current_state->render(display);
}

void Player::cleanUp(){
  delete(current_state);
}

void Player::event(SDL_Event* event){
  current_state->event(event);
}

bool Player::hits(GameEntity* target){
  return current_state->hits(target);
}

