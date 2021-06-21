#ifndef __SCORE_H__
#define __SCORE_H__

#include "cocos2d.h"

class Score {
    static cocos2d::Vector<cocos2d::Sprite*> nodes;
public:
    static void drawScore(cocos2d::Scene*, int score);
};

#endif // !__SCORE_H__