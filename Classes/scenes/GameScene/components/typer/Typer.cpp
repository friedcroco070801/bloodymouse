#include "Typer.h"
#include "Definitions.h"

USING_NS_CC;
using namespace std;

std::string words[] = {
    "apple", "an", "and", "agree", "agressive", "amper", "ant", "attitude"
};

int wordsCount = sizeof(words)/sizeof(std::string);

Typer::Typer() {
    // Set up private properties
    size = 5;

    for (int i = 0; i < size; i++) {
        int index = (int) (CCRANDOM_0_1() * wordsCount);
        if (index >= wordsCount) index = wordsCount - 1;
        strings.push_back(words[index]);
    }
}

void Typer::drawTyper(Scene* scene) {
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    // Delete all existing labels
    for (auto it = labels.begin(); it != labels.end(); it++) {
        (*it)->removeFromParent();
    }
    labels.clear();

    // Draw on Scene
    float anchorX = visibleSize.width / 10 * 4 + origin.x;
    float anchorY = visibleSize.height / 8 + origin.y;

    for (unsigned int i = 0; i < strings.size(); i++) {
        string s = strings[i];

        for (unsigned int j = 0; j < s.length(); j++) {
            auto sprite = Sprite::create("sprites/font.png", Rect(((int) (s[j] - 'a')) * 48, 0, 48, 88));

            // First word
            if (i == 0 && j == 0) {
                sprite->setScale(1.0f);
            } else {
                sprite->setScale(0.5f);
            }

            anchorX = anchorX + sprite->getContentSize().width * sprite->getScaleX() / 2;

            sprite->setPosition(anchorX, anchorY);
            scene->addChild(sprite);

            anchorX = anchorX + sprite->getContentSize().width * sprite->getScaleX() / 2;
            
            labels.pushBack(sprite);
        }

        anchorX = anchorX + TYPER_SPACING;
    }
}

char Typer::getFirstChar() {
    return strings[0][0];
}

void Typer::updateTyper() {
    if (strings[0].length() <= 1) {
        strings.erase(strings.begin());
        int index = (int) (CCRANDOM_0_1() * wordsCount);
        if (index >= wordsCount) index = wordsCount - 1;
        strings.push_back(words[index]);
    }
    else {
        strings[0].erase(0, 1);
    }
}