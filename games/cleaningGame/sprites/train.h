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
        //declare the millions of textures and sprites
        //inside sprites
        float spriteReductionFactor;
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
        sf::Texture toiletLeftTexture;
        sf::Sprite toiletLeftSprite;
        sf::Texture toiletRightTexture;
        sf::Sprite toiletRightSprite;
        sf::Texture carpetTexture;
        sf::Sprite carpetSprite;
        sf::Texture rackTexture;
        sf::Sprite rackSprite;
        //outside of train sprites
        sf::Texture rightSideWithWindowTexture;
        sf::Sprite rightSideWithWindowSprite;
        sf::Texture leftSideWithWindowTexture;
        sf::Sprite leftSideWithWindowSprite;
        int ietInfo[38][7] {
        {0,6,0,8,7,0,0},
        {0,0,0,8,0,0,0},
        {0,8,8,8,8,8,0},
        {0,1,0,8,2,0,0},
        {0,9,8,8,8,9,0},
        {11,3,3,8,3,3,10},
        {0,8,8,8,8,8,0},
        {0,3,3,8,3,3,0},
        {0,8,8,8,8,8,0},
        {11,5,0,8,5,0,10},
        {0,8,8,8,8,8,0},
        {0,4,4,8,4,4,0},
        {0,3,3,8,3,3,0},
        {11,8,8,8,8,8,10},
        {0,3,3,8,3,3,0},
        {0,8,8,8,8,8,0},
        {0,5,0,8,5,0,0},
        {11,8,8,8,8,8,10},
        {0,4,4,8,4,4,0},
        {0,8,8,8,8,8,0},
        {0,4,4,8,4,4,0},
        {11,8,8,8,8,8,10},
        {0,4,4,8,4,4,0},
        {0,3,3,8,3,3,0},
        {0,8,8,8,8,8,0},
        {11,5,0,8,5,0,10},
        {0,8,8,8,8,8,0},
        {0,4,4,8,4,4,0},
        {0,8,8,8,8,8,0},
        {11,4,4,8,4,4,10},
        {0,8,8,8,8,8,0},
        {0,4,4,8,4,4,0},
        {0,8,8,8,8,8,0},
        {11,4,4,8,4,4,10},
        {0,8,8,8,8,8,0},
        {0,4,4,8,4,4,0},
        {0,9,8,8,8,9,0},
        {0,1,0,8,2,0,0}};
        void loadTrain();
        void drawTrain(); //not used. Done in main instead

    };
}
#endif // TRAIN

