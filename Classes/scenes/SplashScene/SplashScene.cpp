#include "SplashScene.h"
#include "SceneManager.h"
#include "Definitions.h"

USING_NS_CC;

Scene* SplashScene::createScene()
{
    return SplashScene::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in SplashScene.cpp\n");
}

// on "init" you need to initialize your instance
bool SplashScene::init()
{
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    // Add introduction of game
    auto intro = Label::createWithTTF("A game by friedcroco for MashUp Game Jam 2", "fonts/FreePixel.ttf", INTRO_LABEL_SIZE);
    intro->setPosition(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y);
    this->addChild(intro);

    // Change scene to main menu
    this->scheduleOnce(CC_SCHEDULE_SELECTOR(SplashScene::gotoMainMenuScene), INTRO_LABEL_DURATION);

    return true;
}

void SplashScene::gotoMainMenuScene(float) {
    CHANGE_SCENE_FADING(MainMenuScene);
}