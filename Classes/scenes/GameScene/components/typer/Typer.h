#ifndef __TYPERS_H__
#define __TYPERS_H__

#include "cocos2d.h"

class Typer {
private:
    std::vector<std::string> strings;
    cocos2d::Vector<cocos2d::Sprite*> labels;
    int size;
public:
    Typer();
    void drawTyper(cocos2d::Scene* scene);
    char getFirstChar();
    void updateTyper();
};

#endif // !__TYPERS_H__