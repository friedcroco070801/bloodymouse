#ifndef __PIPE_H__
#define __PIPE_H__

#include "cocos2d.h"

class Pipe {
private:
    cocos2d::Sprite* node;
    bool isCrushing;
    cocos2d::Sequence* seq;
public:
    Pipe();
    void drawPipe(cocos2d::Scene* scene, float x, float y, int zOrder);
    void crush();
};

#endif // !__PIPE_H__