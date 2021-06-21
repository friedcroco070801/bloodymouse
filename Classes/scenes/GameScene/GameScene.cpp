#include "GameScene.h"
#include "SceneManager.h"
#include "Definitions.h"
#include "components/background/Background.h"
#include "components/pipe/Pipe.h"
#include "components/enemy/EnemyTypes.h"
#include "components/enemy/Death.h"
#include "components/battery/Battery.h"
#include "components/score/Score.h"

USING_NS_CC;

Scene* GameScene::createScene()
{
    // Create physics world
    auto world = Scene::createWithPhysics();
    world->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_NONE);
    world->getPhysicsWorld()->setGravity(Vec2(0.0f, 0.0f));

    // Create scene
    auto scene = GameScene::create();
    world->addChild(scene);
    return world;
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in GameScene.cpp\n");
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    // Initialize private properties
    battery = 4;
    score = 0;

    // Draw moving background
    Background("sprites/back0.png").drawBackground(this, visibleSize.width + origin.x, visibleSize.height / 2 + origin.y, -3, BACKGROUND_0_CYCLE);
    Background("sprites/back1.png").drawBackground(this, visibleSize.width + origin.x, visibleSize.height / 2 + origin.y, -2, BACKGROUND_1_CYCLE);
    Background("sprites/back2.png").drawBackground(this, visibleSize.width + origin.x, visibleSize.height / 2 + origin.y, -1, BACKGROUND_2_CYCLE);
    Background("sprites/ground.png").drawBackground(this, visibleSize.width + origin.x, visibleSize.height / 8 + origin.y, 0, GROUND_CYCLE);

    // Draw pretext
    auto pretext = Sprite::create("sprites/pretext.png");
    pretext->setOpacity(205);
    pretext->setPosition(visibleSize.width / 2 + origin.x, visibleSize.height / 8 + origin.y);
    this->addChild(pretext);

    // Draw pipe
    auto pipeSprite = Sprite::create("sprites/pipe2.png");
    pipe.drawPipe(this, visibleSize.width / 4 + origin.x, visibleSize.height / 2 + pipeSprite->getContentSize().height / 2, 1);

    // Draw a object releaser on the left of the map
    auto destroyer = Node::create();
    auto destroyerBody = PhysicsBody::createBox(Size(1, visibleSize.height));
    destroyerBody->setDynamic(false);
    destroyerBody->setCollisionBitmask(DESTROY_BITMASK);
    destroyerBody->setContactTestBitmask(ENEMY_BITMASK | DEATH_BITMASK);
    destroyerBody->setCategoryBitmask(DESTROY_BITMASK);
    destroyer->setPhysicsBody(destroyerBody);
    destroyer->setPosition(0 - visibleSize.width / 16 + origin.x, visibleSize.height / 2  + origin.y);
    this->addChild(destroyer);

    // Draw a battery
    Battery::drawBattery(this, battery);

    // Draw a score
    Score::drawScore(this, score);

    // Draw a typer
    auto typerInstruction = Label::createWithTTF("TYPE to crush mice!", "fonts/FreePixel.ttf", GAME_LABEL_SIZE);
    typerInstruction->setPosition(visibleSize.width / 5 + origin.x, visibleSize.height / 8 + origin.y);
    this->addChild(typerInstruction);

    typer.drawTyper(this);

    // // Listen to touch
    // auto touchListener = EventListenerTouchOneByOne::create();
    // touchListener->setSwallowTouches(true);
    // touchListener->onTouchBegan = CC_CALLBACK_2(GameScene::onTouchBegan, this);
    // Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);

    // Listen to contact
    auto contactListener = EventListenerPhysicsContact::create();
    contactListener->onContactBegin = CC_CALLBACK_1(GameScene::onContactBegin, this);
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);

    // Listen to keyboard Esc
    auto keyEscListener = EventListenerKeyboard::create();
    keyEscListener->onKeyPressed = CC_CALLBACK_2(GameScene::onKeyPressed, this);
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(keyEscListener, this);

    // Schedule 
    enemyTypes = 1;
    this->schedule(CC_SCHEDULE_SELECTOR(GameScene::spawn1), 0.3f);

    return true;
}

// bool GameScene::onTouchBegan(Touch* touch, Event* event) {
//     pipe.crush();
//     return true;
// }

// Physical contact listener
bool GameScene::onContactBegin(PhysicsContact& contact) {
    PhysicsBody* colliderA = contact.getShapeA()->getBody();
    auto bitmaskA = colliderA->getCollisionBitmask();
    PhysicsBody* colliderB = contact.getShapeB()->getBody();
    auto bitmaskB = colliderB->getCollisionBitmask();

    // Case pipe and enemy collision
    if ((bitmaskA == PIPE_BITMASK && bitmaskB == ENEMY_BITMASK) || (bitmaskB == PIPE_BITMASK && bitmaskA == ENEMY_BITMASK)) {
        auto enemy = ((bitmaskA == ENEMY_BITMASK) ? colliderA->getNode() : colliderB->getNode());
        auto x = enemy->getPosition().x;
        auto scale = enemy->getScaleY();
        enemy->removeFromParent();
        [=](){Death::drawDeath(this, x, scale);}();
        score++;
        Score::drawScore(this, score);
        nextSpawn();
    }

    // Case destroyer and enemy collision
    if ((bitmaskA == DESTROY_BITMASK && bitmaskB == ENEMY_BITMASK) || (bitmaskB == DESTROY_BITMASK && bitmaskA == ENEMY_BITMASK)) {
        auto poka = (bitmaskA == ENEMY_BITMASK) ? colliderA->getNode() : colliderB->getNode();
        poka->removeFromParent();
        battery--;
        Battery::drawBattery(this, battery);
        if (battery <= 0) {
            auto def = UserDefault::getInstance();
            def->setIntegerForKey("SCORE", score);
            CHANGE_SCENE_FADING(GameOverScene);
        }
		CCLOG("Destroy ENEMY");
    }

    // Case destroyer and death collision
    if ((bitmaskA == DESTROY_BITMASK && bitmaskB == DEATH_BITMASK) || (bitmaskB == DESTROY_BITMASK && bitmaskA == DEATH_BITMASK)) {
        auto death = (bitmaskA == DEATH_BITMASK) ? colliderA->getNode() : colliderB->getNode();
        death->removeFromParent();
		CCLOG("Destroy DEATH");
    }

    return true;
}

void GameScene::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event) {
    if ((int) keyCode == (int) EventKeyboard::KeyCode::KEY_A + typer.getFirstChar() - 'a') {
        typer.updateTyper();
        typer.drawTyper(this);
        pipe.crush();
    }
}

void GameScene::spawn1(float) {
    if (CCRANDOM_0_1() < 0.2f) EnemyMaapj().drawEnemy(this);
}

void GameScene::spawn2(float) {
    if (CCRANDOM_0_1() < 0.2f) EnemyMawaru().drawEnemy(this);
}

void GameScene::spawn3(float) {
    if (CCRANDOM_0_1() < 0.2f) EnemyFeng().drawEnemy(this);
}

void GameScene::spawn4(float) {
    if (CCRANDOM_0_1() < 0.2f) EnemyRama().drawEnemy(this);
}

void GameScene::spawn5(float) {
    if (CCRANDOM_0_1() < 0.2f) EnemyZaba().drawEnemy(this);
}

void GameScene::nextSpawn() {
    if (score >= 15 && enemyTypes == 1) {
        enemyTypes++;
        this->schedule(CC_SCHEDULE_SELECTOR(GameScene::spawn2), 0.353f);
        return;
    }
    if (score >= 35 && enemyTypes == 2) {
        enemyTypes++;
        this->schedule(CC_SCHEDULE_SELECTOR(GameScene::spawn3), 0.403f);
        return;
    }
    if (score >= 60 && enemyTypes == 3) {
        enemyTypes++;
        this->schedule(CC_SCHEDULE_SELECTOR(GameScene::spawn4), 0.453f);
        return;
    }
    if (score >= 100 && enemyTypes == 4) {
        enemyTypes++;
        this->schedule(CC_SCHEDULE_SELECTOR(GameScene::spawn5), 0.503f);
        return;
    }
}