#include "sdl_app.h"

int main(int argc, char *argv[]){
  SdlApp* app = new SdlApp();

  return app->onExecute();
}
