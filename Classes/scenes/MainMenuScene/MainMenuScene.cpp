#include "MainMenuScene.h"
#include "SceneManager.h"
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

    // Draw title background
    auto title = Sprite::create("sprites/Title.png");
    title->setPosition(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y);
    this->addChild(title);

    // Draw instruction
    auto intstruct = Label::createWithTTF("Press ENTER to dive in...", "fonts/FreePixel.ttf", MAIN_MENU_LABEL_SIZE);
    intstruct->setPosition(visibleSize.width / 2 + origin.x, visibleSize.height / 4 + origin.y);
    this->addChild(intstruct);    

    return true;
}