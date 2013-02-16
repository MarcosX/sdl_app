#ifndef _ENEMY_WALKING_ANIMATION_H_
#define _ENEMY_WALKING_ANIMATION_H_

#include "../entities/enemy.h"
#include "entity_state.h"

class Enemy;

class EnemyWalking: public EntityState {
private:
  Enemy* enemy;
public:
  EnemyWalking(GameEntity* entity);
  void loop();
  void render(SDL_Surface* display);
  void cleanUp();
  void event(SDL_Event* event){};
};

#endif
