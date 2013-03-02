#include "sdl_app.h"

SdlApp::SdlApp(){
  old_time = 0;
  display = NULL;
  frame_rate = 48;
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
  if((background = SurfaceHelper::load("images//floor.png")) == NULL)
    return false;
  player = new Player();
  enemy = new Enemy();
  block = new Block(200, 200);
  return true;
}

void SdlApp::onLoop(){
  int delay_time = FRAMES_PER_SECOND_DELAY - (SDL_GetTicks() - old_time);
  if(delay_time > 0)
    SDL_Delay((Uint32)delay_time);
  if((old_time + frame_rate > SDL_GetTicks()))
    return;
  old_time = SDL_GetTicks();
  int old_player_x = player->pos_x;
  int old_player_y = player->pos_y;
  player->loop();
  enemy->loop();
  if(player->hits(enemy)){
    delete(player);
    player = new Player();
  }
  if(player->hits(block)){
    player->pos_x = old_player_x;
    player->pos_y = old_player_y;
  }
}

void SdlApp::onRender(){
  for(int i = 0; i < SCREEN_WIDTH; i+=32)
    for(int j = 0; j < SCREEN_HEIGHT; j+=32)
      SurfaceHelper::draw(display, background, i, j);
  enemy->render(display);
  player->render(display);
  block->render(display);
  SDL_Flip(display);
}

