#include "Typer.h"
#include "Definitions.h"

USING_NS_CC;
using namespace std;

std::string words[] = {
    "apple", "an", "and", "agree", "agressive", "amper", "ant", "attitude",
    "higher", "order", "function", "is", "used", "to", "implement", "currying", "and", "partial", "application", "currying", "is", "the", "concept", "where", "multiparameter", "functions", "are", "composed", "into", "functions", "which", "accept", "only", "one", "parameter", "partial", "application", "is", "the", "function", "returned", "when", "replacing", "one", "or", "more", "parameters", "of", "a", "multiparameter", "function", "with", "values", "currying", "and", "partial", "application", "are", "related", "but", "not", "necessarily", "the", "same",
    "romeo", "and", "juliet", "begins", "as", "the", "chorus", "introduces", "two", "feuding", "families", "of", "verona", "the", "capulets", "and", "the", "montagues", "on", "a", "hot", "summers", "day", "the", "young", "men", "of", "each", "faction", "fight", "until", "the", "prince", "of", "verona", "intercedes", "and", "threatens", "to", "banish", "them", "soon", "after", "the", "head", "of", "the", "capulet", "family", "plans", "a", "feast", "his", "goal", "is", "to", "introduce", "his", "daughter", "juliet", "to", "a", "count", "named", "paris", "who", "seeks", "to", "marry", "juliet", "montague", "son", "romeo", "and", "his", "friends", "benvolio", "and", "mercutio", "hear", "of", "the", "party", "and", "resolve", "to", "go", "in", "disguise", "romeo", "hopes", "to", "see", "his", "beloved", "rosaline", "at", "the", "party", "instead", "while", "there", "he", "meets", "juliet", "and", "falls", "instantly", "in", "love", "with", "her", "juliet", "cousin", "tybalt", "recognises", "the", "montague", "boys", "and", "forces", "them", "to", "leave", "just", "as", "romeo", "and", "juliet", "discover", "one", "another",
    "water", "is", "an", "inorganic", "transparent", "tasteless", "odorless", "and", "nearly", "colorless", "chemical", "substance", "which", "is", "the", "main", "constituent", "of", "earth", "hydrosphere", "and", "the", "fluids", "of", "all", "known", "living", "organisms", "is", "transported", "by", "boats", "through", "seas", "rivers", "lakes", "and", "canals", "large", "quantities", "of", "water", "ice", "and", "steam", "are", "used", "for", "cooling", "and", "heating", "in", "industry", "and", "homes", "water", "is", "an", "excellent", "solvent", "for", "a", "wide", "variety", "of", "substances", "both", "mineral", "and", "organic", "as", "such", "it", "is", "widely", "used", "in", "industrial", "processes", "and", "in", "cooking", "and", "washing", "water", "ice", "and", "snow", "are", "also", "central", "to", "many", "sports", "and", "other", "forms", "of", "entertainment", "such", "as", "swimming", "pleasure", "boating", "boat", "racing", "surfing", "sport", "fishing", "diving", "ice", "skating", "and", "skiing"
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