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
