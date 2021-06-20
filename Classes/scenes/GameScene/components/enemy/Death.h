#ifndef __DEATH_H__
#define __DEATH_H__

#include "cocos2d.h"
#include "Definitions.h"
USING_NS_CC;

class Death {
protected:
    Sprite* node;
public:
    Death(float scale) {
        // Create sprite and scale
        node = Sprite::create("sprites/enemy/death.png");
        node->setScale(scale);

        // Create physic body
        auto body = PhysicsBody::createBox(node->getContentSize());
        body->setDynamic(false);
        body->setCollisionBitmask(DEATH_BITMASK);
        body->setContactTestBitmask(true);
        node->setPhysicsBody(body); 
    }
    void drawDeath(Scene* scene, float x) {
        auto visibleSize = Director::getInstance()->getVisibleSize();
        Vec2 origin = Director::getInstance()->getVisibleOrigin();

        // Set position
        node->setPosition(x, visibleSize.height / 4 + node->getContentSize().height * node->getScale() / 2 + origin.y);

        // Set animation
        node->runAction(MoveBy::create(ENEMY_APPROACHING_CYCLE, Vec2(0 - 1.5 * visibleSize.width, 0)));

        // Draw node on scene
        scene->addChild(node);
    }
};

#endif // !__DEATH_H__