#include "player.h"

Player::Player(){
  walking = new PlayerWalkingAnimation(this, "source//images//yoshi.png", 8, 64, 64);
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
}

void Player::render(SDL_Surface* display){
  walking->render(display);
}

void Player::cleanUp(){
  delete(walking);
}

void Player::event(SDL_Event* event){
  switch(event->type){
    case SDL_KEYDOWN:
      switch(event->key.keysym.sym){
        case SDLK_RIGHT:
          move_right = true;
          break;
        case SDLK_LEFT:
          move_left = true;
          break;
        case SDLK_UP:
          move_up = true;
          break;
        case SDLK_DOWN:
          move_down = true;
          break;
        default:
          break;
      }
      break;
    case SDL_KEYUP:
      switch(event->key.keysym.sym){
        case SDLK_RIGHT:
          move_right = false;
          break;
        case SDLK_LEFT:
          move_left = false;
          break;
        case SDLK_UP:
          move_up = false;
          break;
        case SDLK_DOWN:
          move_down = false;
          break;
      }
      break;
    default:
      break;
  }
}
