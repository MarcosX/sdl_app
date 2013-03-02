#include "sdl_app.h"
#include "helpers/image_source.h"

SDL_Surface* ImageSource::playerImageSheet = NULL;
SDL_Surface* ImageSource::enemyImageSheet = NULL;
SDL_Surface* ImageSource::blockImage = NULL;

int main(int argc, char *argv[]){
  SdlApp* app = new SdlApp();

  return app->onExecute();
}
