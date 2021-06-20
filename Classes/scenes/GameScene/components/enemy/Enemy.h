#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "cocos2d.h"

class Enemy {
protected:
    cocos2d::Sprite* node;
public:
    Enemy(std::string filename);
    void drawEnemy(cocos2d::Scene* scene, cocos2d::ActionInterval* action, cocos2d::Animate* animate);
    void die();
};

#endif // !__PIPE_H__