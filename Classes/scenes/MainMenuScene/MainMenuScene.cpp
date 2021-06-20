#include "MainMenuScene.h"
#include "SceneManager.h"
#include "../GameScene/components/background/Background.h"
#include "Definitions.h"

USING_NS_CC;

Scene* MainMenuScene::createScene()
{
    return MainMenuScene::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in MainMenuScene.cpp\n");
}

// on "init" you need to initialize your instance
bool MainMenuScene::init()
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

    // Draw title
    auto title = Sprite::create("sprites/title.png");
    title->setPosition(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y);
    this->addChild(title);

    // Draw instruction
    auto intstruct = Label::createWithTTF("Start crushing mice with ENTER!", "fonts/FreePixel.ttf", MAIN_MENU_LABEL_SIZE);
    intstruct->setPosition(visibleSize.width / 2 + origin.x, ground->getContentSize().height / 2 + origin.y);
    this->addChild(intstruct); 

    // Change scene to game scene
    this->scheduleOnce(CC_SCHEDULE_SELECTOR(MainMenuScene::gotoGameScene), INTRO_LABEL_DURATION);   

    return true;
}

void MainMenuScene::gotoGameScene(float) {
    CHANGE_SCENE_FADING(GameScene);
}