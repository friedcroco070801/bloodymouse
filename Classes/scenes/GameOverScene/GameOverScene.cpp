#include "GameOverScene.h"
#include "SceneManager.h"
#include "Definitions.h"
#include "../GameScene/components/background/Background.h"

USING_NS_CC;

Scene* GameOverScene::createScene()
{
    return GameOverScene::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in GameOverScene.cpp\n");
}

// on "init" you need to initialize your instance
bool GameOverScene::init()
{
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    // Draw background
    auto ground = Sprite::create("sprites/ground.png");
    Background("sprites/back0.png").drawBackground(this, visibleSize.width + origin.x, visibleSize.height / 2 + origin.y, -3, BACKGROUND_0_CYCLE);
    Background("sprites/back1.png").drawBackground(this, visibleSize.width + origin.x, visibleSize.height / 2 + origin.y, -2, BACKGROUND_1_CYCLE);
    Background("sprites/back2.png").drawBackground(this, visibleSize.width + origin.x, visibleSize.height / 2 + origin.y, -1, BACKGROUND_2_CYCLE);
    Background("sprites/ground.png").drawBackground(this, visibleSize.width + origin.x, visibleSize.height / 8 + origin.y, 0, GROUND_CYCLE);

    // Draw pipe
    auto pipe = Sprite::create("sprites/pipe2.png");
    pipe->setPosition(visibleSize.width / 4 + origin.x, visibleSize.height / 2 + pipe->getContentSize().height / 2 + origin.y);
    this->addChild(pipe);

    // Draw instruction
    auto intstruct = Label::createWithTTF("Press ENTER to return to replay...", "fonts/FreePixel.ttf", MAIN_MENU_LABEL_SIZE);
    intstruct->setPosition(visibleSize.width / 2 + origin.x, ground->getContentSize().height / 2 + origin.y);
    this->addChild(intstruct); 

    // Listen to keyboard Esc
    auto keyEscListener = EventListenerKeyboard::create();
    keyEscListener->onKeyPressed = CC_CALLBACK_2(GameOverScene::onKeyPressed, this);
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(keyEscListener, this);

    return true;
}

void GameOverScene::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event) {
    if (keyCode == EventKeyboard::KeyCode::KEY_ENTER) {
        gotoMainMenuScene();
    }
}

void GameOverScene::gotoMainMenuScene() {
    CHANGE_SCENE_FADING(MainMenuScene);
}