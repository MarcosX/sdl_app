#include "player_walking.h"

PlayerWalking::PlayerWalking(GameEntity* entity){
  sprites = ImageSource::getPlayerImageSheet();
  this->max_frames = 4;
  this->height = 32;
  this->width = 32;
  this->player = (Player*)entity;
  velocity_x = velocity_y = 5;
  current_frame = 0;
  move_left = move_right = move_up = move_down = false;
}

void PlayerWalking::loop(){
  current_frame++;
  if(current_frame >= max_frames)
    current_frame = 0;
  if(move_up)
    player->pos_y -= 5;
  if(move_down)
    player->pos_y += 5;
  if(move_left)
    player->pos_x -= 5;
  if(move_right)
    player->pos_x += 5;
  if(player->pos_x <= 0) player->pos_x = 0;
  if(player->pos_x + width >= SCREEN_WIDTH) player->pos_x = SCREEN_WIDTH - width;
  if(player->pos_y <= 0) player->pos_y = 0;
  if(player->pos_y + height >= SCREEN_HEIGHT) player->pos_y = SCREEN_HEIGHT - height;
}

void PlayerWalking::render(SDL_Surface* display){
  if(move_down)
    SurfaceHelper::draw(display, sprites, player->pos_x, player->pos_y, current_frame*width, 0, width, height);
  else if(move_up)
    SurfaceHelper::draw(display, sprites, player->pos_x, player->pos_y, current_frame*width, 96, width, height);
  else if(move_left)
    SurfaceHelper::draw(display, sprites, player->pos_x, player->pos_y, current_frame*width, 32, width, height);
  else if(move_right)
    SurfaceHelper::draw(display, sprites, player->pos_x, player->pos_y, current_frame*width, 64, width, height);
  else
    SurfaceHelper::draw(display, sprites, player->pos_x, player->pos_y, 32, 0, width, height);
}

void PlayerWalking::cleanUp(){
  SDL_FreeSurface(sprites);
}

void PlayerWalking::event(SDL_Event* event){
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

bool PlayerWalking::hits(GameEntity* target){
  if(player->pos_x + player->getWidth() < target->pos_x) return false;
  if(player->pos_x > target->pos_x + target->getWidth()) return false;
  if(player->pos_y + player->getHeight() < target->pos_y) return false;
  if(player->pos_y > target->pos_y + target->getHeight()) return false;
  return true;
}

