//player class header
#ifndef TRAIN_H
#define TRAIN_H
#include <SFML/Graphics.hpp>
#include <iostream>

namespace trains {
    class train{
    public :
        float trainX;
        float trainY;
        sf::Texture chairUpTexture;
        sf::Sprite chairUpSprite;
        sf::Texture chairDownTexture;
        sf::Sprite chairDownSprite;
        sf::Texture tableTexture;
        sf::Sprite tableSprite;
        sf::Texture doorLeftTexture;
        sf::Sprite doorLeftSprite;
        sf::Texture doorRightTexture;
        sf::Sprite doorRightSprite;
        int ietInfo[38][5] {
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {1,0,0,2,0},
        {0,0,0,0,0},
        {3,3,0,3,3},
        {0,0,0,0,0},
        {3,3,0,3,3},
        {0,0,0,0,0},
        {5,0,0,5,0},
        {0,0,0,0,0},
        {4,4,0,4,4},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0}};
        void loadTrain();
        void drawTrain();

    };
}
#endif // TRAIN

