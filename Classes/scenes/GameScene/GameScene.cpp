#include "GameScene.h"
#include "SceneManager.h"
#include "Definitions.h"
#include "components/background/Background.h"
#include "components/pipe/Pipe.h"

USING_NS_CC;

Scene* GameScene::createScene()
{
    // Create physics world
    auto world = Scene::createWithPhysics();
    world->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);

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

    // Draw moving background
    Background("sprites/back0.png").drawBackground(this, visibleSize.width + origin.x, visibleSize.height / 2 + origin.y, -3, BACKGROUND_0_CYCLE);
    Background("sprites/back1.png").drawBackground(this, visibleSize.width + origin.x, visibleSize.height / 2 + origin.y, -2, BACKGROUND_1_CYCLE);
    Background("sprites/back2.png").drawBackground(this, visibleSize.width + origin.x, visibleSize.height / 2 + origin.y, -1, BACKGROUND_2_CYCLE);
    Background("sprites/ground.png").drawBackground(this, visibleSize.width + origin.x, visibleSize.height / 8 + origin.y, 0, GROUND_CYCLE);

    // Draw pipe
    auto pipeSprite = Sprite::create("sprites/pipe2.png");
    pipe.drawPipe(this, visibleSize.width / 4 + origin.x, visibleSize.height / 2 + pipeSprite->getContentSize().height / 2, 1);

    // Listen to touch
    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->setSwallowTouches(true);
    touchListener->onTouchBegan = CC_CALLBACK_2(GameScene::onTouchBegan, this);
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);

    return true;
}

bool GameScene::onTouchBegan(Touch* touch, Event* event) {
    pipe.crush();
    return true;
}