#include "sdl_app.h"

SdlApp::SdlApp(){
  old_time = 0;
  display = NULL;
  frame_rate = 100;
  running = true;
  background = NULL;
}

int SdlApp::onExecute(){
  if(onInit() == false)
    return -1;

  SDL_Event event;
  while(running){
    while(SDL_PollEvent(&event)){
      onEvent(&event);
    }
    onLoop();
    onRender();
  }
  onCleanUp();
  return 0;
}

void SdlApp::onCleanUp(){
  player->cleanUp();
  enemy->cleanUp();
  SDL_FreeSurface(display);
  SDL_FreeSurface(background);
  SDL_Quit();
}

void SdlApp::onEvent(SDL_Event* event){
  if(event->type == SDL_QUIT)
    running = false;
  player->event(event);
}

int SdlApp::onInit(){
  if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    return false;
  if((display = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL)
    return false;
  if((background = SurfaceHelper::load("source//images//bg.jpg")) == NULL)
    return false;
  player = new Player();
  enemy = new Enemy();
  return true;
}

void SdlApp::onLoop(){
  if((old_time + frame_rate > SDL_GetTicks()))
    return;
  old_time = SDL_GetTicks();
  player->loop();
  enemy->loop();
}

void SdlApp::onRender(){
  SurfaceHelper::draw(display, background, 0, 0);
  enemy->render(display);
  player->render(display);
  SDL_Flip(display);
}

