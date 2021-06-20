#include "Pipe.h"
#include "Definitions.h"

USING_NS_CC;

Pipe::Pipe(): isCrushing(false) {
    // Create sprite
    node = Sprite::create("sprites/pipe2.png");

    // Create physic body
    auto body = PhysicsBody::createBox(node->getContentSize());
    body->setDynamic(false);
    body->setCollisionBitmask(PIPE_BITMASK);
	body->setContactTestBitmask(ENEMY_BITMASK);
    body->setCategoryBitmask(PIPE_BITMASK);
    node->setPhysicsBody(body);   
}

void Pipe::drawPipe(cocos2d::Scene* scene, float x, float y, int zOrder) {
    // Set position
    node->setPosition(x, y);

    // Draw pipe on scene
    scene->addChild(node, zOrder);
}

void Pipe::crush() {
    // Create animation
    if (!isCrushing) {
        isCrushing = true;

        auto crushDown = MoveBy::create(PIPE_CRUSHING_CYCLE / 2, Vec2(0, 0 - Director::getInstance()->getVisibleSize().height / 4));
        auto crushUp = MoveBy::create(PIPE_CRUSHING_CYCLE / 2, Vec2(0, Director::getInstance()->getVisibleSize().height / 4));
        auto resetBool = CallFunc::create([this](){
            this->isCrushing = false;
        });
        seq = Sequence::create(crushDown, crushUp, resetBool, NULL);
        node->runAction(seq);
    }
}
