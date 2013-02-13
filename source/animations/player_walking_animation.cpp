#include "player_walking_animation.h"

PlayerWalkingAnimation::PlayerWalkingAnimation(GameEntity* entity, std::string file, int max_frames, int width, int height){
  sprites = SurfaceHelper::load(file);
  this->max_frames = max_frames;
  this->height = height;
  this->width = width;
  this->entity = entity;
  current_frame = 0;
}

void PlayerWalkingAnimation::loop(){
  current_frame++;
  if(current_frame >= max_frames)
    current_frame = 0;
}

void PlayerWalkingAnimation::render(SDL_Surface* display){
  SurfaceHelper::draw(display, sprites, entity->getPosX(), entity->getPosY(), 0, current_frame*height, width, height);
}

void PlayerWalkingAnimation::cleanUp(){
  SDL_FreeSurface(sprites);
}
