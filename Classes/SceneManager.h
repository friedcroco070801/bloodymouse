#ifndef __SCENEMANAGER_H__
#define __SCENEMANAGER_H__

#include "cocos2d.h"
#include "Definitions.h"
#include "scenes/SplashScene/SplashScene.h"
#include "scenes/MainMenuScene/MainMenuScene.h"
#include "scenes/GameScene/GameScene.h"

#define CHANGE_SCENE(scene) SceneManager::replaceScene(scene::createScene())
#define CHANGE_SCENE_FADING(scene) SceneManager::replaceSceneWithFading(scene::createScene())

class SceneManager {
public:
    static void replaceScene(cocos2d::Scene* scene) {
        cocos2d::Director::getInstance()->replaceScene(scene);
    }

    static void replaceSceneWithFading(cocos2d::Scene* scene) {
        cocos2d::Director::getInstance()->replaceScene(cocos2d::TransitionFade::create(TRANSITION_TIME, scene));
    }
};

#endif // __SCENEMANAGER_H__