#include "Score.h"
#include "Definitions.h"

USING_NS_CC;

Vector<Sprite*> Score::nodes;
void Score::drawScore(Scene* scene, int score) {
    // Delete child
    for (auto it = nodes.begin(); it != nodes.end(); it++) {
        (*it)->removeFromParent();
    }
    nodes.clear();

    // Draw score
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    float anchorX = visibleSize.width + origin.x - 20.0f;
    float anchorY = visibleSize.height + origin.y - 20.0f - Sprite::create("sprites/digit.png")->getContentSize().height / 2;

    do {
        int digit = score % 10;
        score /= 10;

        // Draw sprite
        auto sprite = Sprite::create("sprites/digit.png", Rect(64 * digit, 0, 64, 96));
        anchorX -= sprite->getContentSize().width / 2;
        sprite->setPosition(anchorX, anchorY);
        anchorX -= sprite->getContentSize().width / 2;
        nodes.pushBack(sprite);
        scene->addChild(sprite);

    } while (score > 0);
}