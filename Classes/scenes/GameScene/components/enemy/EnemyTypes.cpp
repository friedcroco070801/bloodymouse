#include "cocos2d.h"
#include "Enemy.h"
#include "EnemyDefinitions.h"
#include "EnemyTypes.h"

USING_NS_CC;

// ENEMY.01: Mr.Maapj
void EnemyMaapj::drawEnemy(Scene* scene) {
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

// ENEMY.02: Mr.Mawaru
void EnemyMawaru::drawEnemy(Scene* scene) {
    // Set action
    auto rotate = RotateBy::create(MAWARU_SPINNING_CYCLE * 2, 0 - 720);
    auto jump = JumpBy::create(MAWARU_JUMPING_CYCLE, Vec2(0, 0), node->getContentSize().height * (1 + CCRANDOM_0_1()), 1);
    auto action = Spawn::createWithTwoActions(rotate, jump);

    // Draw enemy
    Enemy::drawEnemy(scene, action, NULL);
}

// ENEMY.03: Miss Feng
void EnemyFeng::drawEnemy(Scene* scene) {
    // Set animation for Maapj
    Vector<SpriteFrame*> frames;
    frames.reserve(2);
    frames.pushBack(SpriteFrame::create("sprites/enemy/feng_alte_1.png", Rect(0, 0, 45, 45)));
    frames.pushBack(SpriteFrame::create("sprites/enemy/feng_alte_2.png", Rect(0, 0, 45, 45)));
    Animation* animation = Animation::createWithSpriteFrames(frames, (1 + CCRANDOM_0_1()) * FENG_ANIMATION_SPEED);
    Animate* animate = Animate::create(animation);

    // Set action
    auto action = MoveBy::create(FENG_MOVING_CYCLE * (0.5 + CCRANDOM_0_1()), Vec2(0 - Director::getInstance()->getVisibleSize().width * 1.5, 0));

    // Draw enemy
    Enemy::drawEnemy(scene, action, animate);
}

// ENEMY.04: Grand Rama
void EnemyRama::drawEnemy(Scene* scene) {
    // Set animation for Maapj
    Vector<SpriteFrame*> frames;
    frames.reserve(4);
    frames.pushBack(SpriteFrame::create("sprites/enemy/rama_1.png", Rect(0, 0, 45, 90)));
    frames.pushBack(SpriteFrame::create("sprites/enemy/rama_2.png", Rect(0, 0, 45, 90)));
    frames.pushBack(SpriteFrame::create("sprites/enemy/rama_3.png", Rect(0, 0, 45, 90)));
    frames.pushBack(SpriteFrame::create("sprites/enemy/rama_2.png", Rect(0, 0, 45, 90)));
    Animation* animation = Animation::createWithSpriteFrames(frames, (1 + CCRANDOM_0_1()) * RAMA_ANIMATION_SPEED);
    Animate* animate = Animate::create(animation);

    // Set action
    auto action = MoveBy::create(RAMA_MOVING_CYCLE * (0.5 + CCRANDOM_0_1()), Vec2(0 - Director::getInstance()->getVisibleSize().width * 1.5, 0));

    // Draw enemy
    Enemy::drawEnemy(scene, action, animate);
}

// ENEMY.05: Prince Zaba
void EnemyZaba::drawEnemy(Scene* scene) {
    // Set animation
    Animate* animate = NULL;

    // Set action
    auto delay = DelayTime::create((1 + CCRANDOM_0_1()) * ZABA_WAITING_CYCLE);
    auto jump = JumpBy::create(ZABA_JUMPING_CYCLE, Vec2(0 - node->getContentSize().width * 2, 0), (0.5 + CCRANDOM_0_1()) * node->getContentSize().width, 1);
    Vector<SpriteFrame*> frames1;
    frames1.reserve(1);
    frames1.pushBack(SpriteFrame::create("sprites/enemy/zaba_2.png", Rect(0, 0, 45, 50)));
    Animation* animation1 = Animation::createWithSpriteFrames(frames1, 1.0 / 60);
    auto change1 = Animate::create(animation1);
    Vector<SpriteFrame*> frames2;
    frames2.reserve(1);
    frames2.pushBack(SpriteFrame::create("sprites/enemy/zaba_1.png", Rect(0, 0, 45, 50)));
    Animation* animation2 = Animation::createWithSpriteFrames(frames2, 1.0 / 60);
    auto change2 = Animate::create(animation2);
    auto action = Sequence::create(delay, change1, jump, change2, NULL);

    // Draw enemy
    Enemy::drawEnemy(scene, action, animate);
}