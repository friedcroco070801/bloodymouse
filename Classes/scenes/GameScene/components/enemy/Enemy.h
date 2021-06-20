#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "cocos2d.h"

class Enemy {
protected:
    cocos2d::Sprite* node;
public:
    Enemy(const char* filename);
    void drawEnemy(cocos2d::Scene* scene, cocos2d::ActionInterval* action, cocos2d::Animate* animate);
    // static void die(cocos2d::Sprite* node);
    // static void release(cocos2d::Node* node);
};

#endif // !__PIPE_H__