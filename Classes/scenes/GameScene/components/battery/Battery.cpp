#include "Battery.h"
#include "Definitions.h"

USING_NS_CC;

Sprite* Battery::node = NULL;

void Battery::drawBattery(Scene* scene, int battery) {
    if (node != NULL) {
        node->removeFromParent();
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    // Create sprite
    node = Sprite::create("sprites/battery.png", Rect(72 * (battery < 0 ? 0 : battery), 0, 72, 240));

    // Set position
    node->setPosition((visibleSize.width / 4 - Sprite::create("sprites/pipe2.png")->getContentSize().width / 2) / 2 + origin.x, 
        visibleSize.height * 3 / 4);

    // Draw on scene
    scene->addChild(node);
}