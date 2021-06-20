#ifndef __BATTERY_H__
#define __BATTERY_H__

#include "cocos2d.h"

class Battery {
public:
    static cocos2d::Sprite* node;
    static void drawBattery(cocos2d::Scene* scene, int battery);
};

#endif // !__BATTERY_H__