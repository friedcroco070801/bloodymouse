#include "Background.h"
#include "Definitions.h"

USING_NS_CC;

Background::Background(std::string filename) {
    node = Sprite::create(filename);
}

void Background::drawBackground(Scene* scene, float x, float y, int zOrder, float cycle) {
    // Set background position
    node->setPosition(x, y);

    // Set background animation
    auto move = MoveBy::create(cycle, Vec2(0 - node->getContentSize().width / 2, 0));
    auto reset = MoveTo::create(0, Vec2(x, y));
    auto seq = Sequence::create(move, reset, NULL);
    node->runAction(RepeatForever::create(seq));

    // Draw background on scene
    scene->addChild(node, zOrder);
}
