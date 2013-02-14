#include "player_walking.h"

PlayerWalking::PlayerWalking(GameEntity* entity, std::string file, int max_frames, int width, int height)
: EntityState(entity, file, max_frames, width, height){
  sprites = SurfaceHelper::load(file);
  this->max_frames = max_frames;
  this->height = height;
  this->width = width;
  this->player = (Player*)entity;
  current_frame = 0;
}

void PlayerWalking::loop(){
  current_frame++;
  if(current_frame >= max_frames)
    current_frame = 0;
}

void PlayerWalking::render(SDL_Surface* display){
  SurfaceHelper::draw(display, sprites, player->getPosX(), player->getPosY(), 0, current_frame*height, width, height);
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
