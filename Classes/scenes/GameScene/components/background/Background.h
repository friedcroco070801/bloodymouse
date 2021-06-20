#ifndef __BACKGROUND_H__
#define __BACKGROUND_H__

#include "cocos2d.h"

class Background {
private:
    cocos2d::Sprite* node;
public:
    Background(std::string filename);
    void drawBackground(cocos2d::Scene* scene, float x, float y, int zOrder, float cycle);
};

#endif // !__BACKGROUND_H__