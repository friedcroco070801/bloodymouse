#ifndef __ENEMY_TYPES_H__
#define __ENEMY_TYPES_H__

#include "cocos2d.h"
#include "Enemy.h"
#include "EnemyDefinitions.h"

USING_NS_CC;

// ENEMY.01: Mr.Maapj
class EnemyMaapj : public Enemy {
public:
    EnemyMaapj() : Enemy("sprites/enemy/maapj_1.png") {}
    void drawEnemy(Scene* scene) {
        // Set animation for Maapj
        Vector<SpriteFrame*> frames;
        frames.reserve(2);
        frames.pushBack(SpriteFrame::create("sprites/enemy/maapj_1.png", Rect(0, 0, 45, 45)));
        frames.pushBack(SpriteFrame::create("sprites/enemy/maapj_2.png", Rect(0, 0, 45, 45)));
        Animation* animation = Animation::createWithSpriteFrames(frames, (1 + CCRANDOM_0_1()) * MAAPJ_ANIMATION_SPEED);
        Animate* animate = Animate::create(animation);

        // Set action
        auto delay = DelayTime::create((1 + CCRANDOM_0_1()) * MAAPJ_WAITING_CYCLE);
        auto moveLeft = MoveBy::create(MAAPJ_MOVING_CYCLE, Vec2(0 - node->getContentSize().width, 0));
        auto turn = ScaleBy::create(0, -1, 1);
        auto moveRight = MoveBy::create(MAAPJ_MOVING_CYCLE, Vec2(node->getContentSize().width, 0));
        auto action = Sequence::create(delay, turn, moveRight, delay, turn, moveLeft, NULL);

        // Draw enemy
        Enemy::drawEnemy(scene, action, animate);
    }
};

#endif // !__ENEMY_TYPES_H__