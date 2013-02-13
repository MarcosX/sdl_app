#ifndef _SURFACE_HELPER_H_
#define _SURFACE_HELPER_H_

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <string>

class SurfaceHelper {
public:
  SurfaceHelper();
  static SDL_Surface* load(std::string file);
  static bool draw(SDL_Surface* destiny, SDL_Surface* source, int pos_x, int pos_y);
  static bool draw(SDL_Surface* destiny, SDL_Surface* source, int pos_x, int pos_y, int upper_x, int upper_y, int lower_x, int lower_y);
};

#endif
