#include "Enemy.h"
#include "Death.h"
#include "Definitions.h"

USING_NS_CC;

Enemy::Enemy(std::string filename) {
    // Create sprite
    node = Sprite::create(filename);
    node->setScale(CCRANDOM_0_1() + 0.5);

    // Create physic body
    auto body = PhysicsBody::createBox(node->getContentSize());
    body->setDynamic(false);
    body->setCollisionBitmask(ENEMY_BITMASK);
    body->setContactTestBitmask(true);
    node->setPhysicsBody(body);   
}

void Enemy::drawEnemy(Scene* scene, ActionInterval* action, Animate* animate) {
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    // Set position
    node->setPosition(visibleSize.width + origin.x, visibleSize.height / 4 + node->getContentSize().height * node->getScale() / 2 + origin.y);

    // Set animation
    node->runAction(MoveBy::create(ENEMY_APPROACHING_CYCLE, Vec2(0 - 1.5 * visibleSize.width, 0)));

    if (animate != NULL)
        node->runAction(RepeatForever::create(animate));

    if (action != NULL)
        node->runAction(RepeatForever::create(action));

    // Draw node on scene
    scene->addChild(node);
}

void Enemy::die() {
    Death(node->getScale()).drawDeath((Scene *) node->getParent(), node->getPositionX());
    node->getParent()->removeChild(node);
}

