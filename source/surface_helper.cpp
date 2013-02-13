#include "surface_helper.h"

SurfaceHelper::SurfaceHelper(){
}

SDL_Surface* SurfaceHelper::load(std::string file){
  SDL_Surface* tmp = NULL;
  SDL_Surface* loaded = NULL;

  if((tmp = IMG_Load(file.c_str())) == NULL)
    return NULL;

  loaded = SDL_DisplayFormatAlpha(tmp);
  SDL_FreeSurface(tmp);
  return loaded;
}

bool SurfaceHelper::draw(SDL_Surface* destiny, SDL_Surface* source, int pos_x, int pos_y){
  if(destiny == NULL || source == NULL)
    return false;

  SDL_Rect position_rect;
  position_rect.x = pos_x;
  position_rect.y = pos_y;

  SDL_BlitSurface(source, NULL, destiny, &position_rect);
  return true;
}

bool SurfaceHelper::draw(SDL_Surface* destiny, SDL_Surface* source, int pos_x, int pos_y, int upper_x, int upper_y, int width, int height){
  if(destiny == NULL || source == NULL)
    return false;

  SDL_Rect position_rect;
  position_rect.x = pos_x;
  position_rect.y = pos_y;

  SDL_Rect source_rect;
  source_rect.x = upper_x;
  source_rect.y = upper_y;
  source_rect.w = width;
  source_rect.h = height;

  SDL_BlitSurface(source, &source_rect, destiny, &position_rect);
  return true;
}
