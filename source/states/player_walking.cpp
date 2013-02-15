#include "player_walking.h"

PlayerWalking::PlayerWalking(GameEntity* entity)
: EntityState(entity){
  sprites = SurfaceHelper::load("images//Player_main_sheet.png");
  this->max_frames = 3;
  this->height = 32;
  this->width = 32;
  this->player = (Player*)entity;
  current_frame = 0;
}

void PlayerWalking::loop(){
  current_frame++;
  if(current_frame >= max_frames)
    current_frame = 0;
}

void PlayerWalking::render(SDL_Surface* display){
  SurfaceHelper::draw(display, sprites, player->getPosX(), player->getPosY(), current_frame*width, 0, width, height);
}

void PlayerWalking::cleanUp(){
  SDL_FreeSurface(sprites);
}

void PlayerWalking::event(SDL_Event* event){
  switch(event->type){
    case SDL_KEYDOWN:
      switch(event->key.keysym.sym){
        case SDLK_RIGHT:
          player->move_right = true;
          break;
        case SDLK_LEFT:
          player->move_left = true;
          break;
        case SDLK_UP:
          player->move_up = true;
          break;
        case SDLK_DOWN:
          player->move_down = true;
          break;
        default:
          break;
      }
      break;
    case SDL_KEYUP:
      switch(event->key.keysym.sym){
        case SDLK_RIGHT:
          player->move_right = false;
          break;
        case SDLK_LEFT:
          player->move_left = false;
          break;
        case SDLK_UP:
          player->move_up = false;
          break;
        case SDLK_DOWN:
          player->move_down = false;
          break;
      }
      break;
    default:
      break;
  }
}
