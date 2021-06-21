#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "components/pipe/Pipe.h"
#include "components/enemy/Enemy.h"
#include "components/typer/Typer.h"

class GameScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(GameScene);
private:
    Pipe pipe;

    // bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
    bool onContactBegin(cocos2d::PhysicsContact& contact);
    void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
    void spawn(float dt);

    int battery;
    int score;

    Typer typer;
};

#endif // __GAME_SCENE_H__
