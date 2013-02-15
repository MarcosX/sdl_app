#include "player.h"

Player::Player(){
  walking = new PlayerWalking(this);
  pos_x = pos_y = 0;
  velocity_x = velocity_y = 5;
  move_up = move_left = move_right = move_down = false;
}

void Player::loop(){
  walking->loop();
  if(move_up)
    pos_y -= 5;
  if(move_down)
    pos_y += 5;
  if(move_left)
    pos_x -= 5;
  if(move_right)
    pos_x += 5;
  if(pos_x <= 0) pos_x = 0;
  if(pos_x + 32 >= SCREEN_WIDTH) pos_x = SCREEN_WIDTH - 32;
  if(pos_y <= 0) pos_y = 0;
  if(pos_y + 32 >= SCREEN_HEIGHT) pos_y = SCREEN_HEIGHT -32;
}

void Player::render(SDL_Surface* display){
  walking->render(display);
}

void Player::cleanUp(){
  delete(walking);
}

void Player::event(SDL_Event* event){
  walking->event(event);
}

