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
        float spriteSize;
        struct textureAndSpriteInfo {
            std::string textureNameString;
            sf::Texture textureName;
            sf::Sprite spriteName;
        };
        textureAndSpriteInfo trainTextureAndSpriteInfo[14];
        int ietInfo[38][7] {
        {0,6,0,8,7,0,0},
        {0,0,0,8,0,0,0},
        {13,8,8,8,8,8,12},
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
        void loadTrain(float spriteSize);
        void drawTrain(sf::RenderWindow &windowRef); //not used. Done in main instead
    };
}
#endif // TRAIN

