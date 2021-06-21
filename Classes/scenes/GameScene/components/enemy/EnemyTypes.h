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

// ENEMY.02: Mr.Mawaru
class EnemyMawaru : public Enemy {
public:
    EnemyMawaru() : Enemy("sprites/enemy/mawaru.png") {}
    void drawEnemy(cocos2d::Scene* scene);
};

// ENEMY.03: Miss Feng
class EnemyFeng : public Enemy {
public:
    EnemyFeng() : Enemy("sprites/enemy/feng_1.png") {}
    void drawEnemy(cocos2d::Scene* scene);
};

// ENEMY.04: Grand Rama
class EnemyRama : public Enemy {
public:
    EnemyRama() : Enemy("sprites/enemy/rama_1.png") {}
    void drawEnemy(cocos2d::Scene* scene);
};

// ENEMY.05: Prince Zaba
class EnemyZaba : public Enemy {
public:
    EnemyZaba() : Enemy("sprites/enemy/zaba_1.png") {}
    void drawEnemy(cocos2d::Scene* scene);
};

#endif // !__ENEMY_TYPES_H__