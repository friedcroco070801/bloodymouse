#ifndef __DEATH_H__
#define __DEATH_H__

#include "cocos2d.h"
#include "Definitions.h"
USING_NS_CC;

class Death {
public:
    static void drawDeath(Scene* scene, float x, float scale) {
        // Create sprite and scale
        auto node = Sprite::create("sprites/enemy/death.png");
        node->setScale(scale);

        auto visibleSize = Director::getInstance()->getVisibleSize();
        Vec2 origin = Director::getInstance()->getVisibleOrigin();

        // Set position
        node->setPosition(Vec2(x, visibleSize.height / 4 + node->getContentSize().height * node->getScaleX() / 2 + origin.y));
        CCLOG("Pos: %f %f\n", node->getPosition().x, node->getPosition().x);

        // Draw node on scene
        scene->addChild(node, 2);

        // Set animation
        node->runAction(MoveBy::create(ENEMY_APPROACHING_CYCLE, Vec2(0 - 1.5 * visibleSize.width, 0)));
        CCLOG("After: %f %f\n", node->getPosition().x, node->getPosition().x);

        // Create physic body
        auto body = PhysicsBody::createBox(node->getContentSize());
        body->setDynamic(false);
        body->setCollisionBitmask(DEATH_BITMASK);
        body->setContactTestBitmask(DESTROY_BITMASK);
        body->setCategoryBitmask(DEATH_BITMASK);
        node->setPhysicsBody(body); 
    }

    // static void release(Node* node) {
    //     node->getParent()->removeChild(node);
    // }
};

#endif // !__DEATH_H__