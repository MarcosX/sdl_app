#include "sdl_app.h"

SdlApp::SdlApp(){
  old_time = 0;
  display = NULL;
  frame_rate = 24;
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
  if((display = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL)
    return false;
  if((background = SurfaceHelper::load("images//bg.jpg")) == NULL)
    return false;
  player = new Player();
  enemy = new Enemy();
  return true;
}

void SdlApp::onLoop(){
  int delay_time = FRAMES_PER_SECOND_DELAY - (SDL_GetTicks() - old_time);
  if(delay_time > 0)
    SDL_Delay((Uint32)delay_time);
  if((old_time + frame_rate > SDL_GetTicks()))
    return;
  old_time = SDL_GetTicks();
  player->loop();
  enemy->loop();
  if(collide(player, enemy)){
    delete(player);
    player = new Player();
  }
}

void SdlApp::onRender(){
  SurfaceHelper::draw(display, background, 0, 0);
  enemy->render(display);
  player->render(display);
  SDL_Flip(display);
}

bool SdlApp::collide(GameEntity* entity1, GameEntity* entity2){
  if(entity1->getPosX() + entity1->getWidth() < entity2->getPosX()) return false;
  if(entity1->getPosX() > entity2->getPosX() + entity2->getWidth()) return false;
  if(entity1->getPosY() + entity1->getHeight() < entity2->getPosY()) return false;
  if(entity1->getPosY() > entity2->getPosY() + entity2->getHeight()) return false;
  return true;
}

