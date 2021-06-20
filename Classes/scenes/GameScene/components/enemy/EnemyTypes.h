#ifndef __ENEMY_TYPES_H__
#define __ENEMY_TYPES_H__

#include "cocos2d.h"
#include "Enemy.h"
#include "EnemyDefinitions.h"

// ENEMY.01: Mr.Maapj
class EnemyMaapj : public Enemy {
public:
    EnemyMaapj() : Enemy("sprites/enemy/maapj_1.png") {}
    void drawEnemy(cocos2d::Scene* scene);
};

#endif // !__ENEMY_TYPES_H__