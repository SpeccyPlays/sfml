//player class header
#ifndef STATION_H
#define STATION_H
#include <SFML/Graphics.hpp>
#include <iostream>

namespace stations {
    class station{
    public :
        //declare the millions of textures and sprites
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
        int stationInfo[38][5] {
        {6,0,8,7,0},
        {0,0,8,0,0},
        {8,8,8,8,8},
        {1,0,8,2,0},
        {9,8,8,8,9},
        {3,3,8,3,3},
        {8,8,8,8,8},
        {3,3,8,3,3},
        {8,8,8,8,8},
        {5,0,8,5,0},
        {8,8,8,8,8},
        {4,4,8,4,4},
        {3,3,8,3,3},
        {8,8,8,8,8},
        {3,3,8,3,3},
        {8,8,8,8,8},
        {5,0,8,5,0},
        {8,8,8,8,8},
        {4,4,8,4,4},
        {8,8,8,8,8},
        {4,4,8,4,4},
        {8,8,8,8,8},
        {4,4,8,4,4},
        {3,3,8,3,3},
        {8,8,8,8,8},
        {5,0,8,5,0},
        {8,8,8,8,8},
        {4,4,8,4,4},
        {8,8,8,8,8},
        {4,4,8,4,4},
        {8,8,8,8,8},
        {4,4,8,4,4},
        {8,8,8,8,8},
        {4,4,8,4,4},
        {8,8,8,8,8},
        {4,4,8,4,4},
        {9,8,8,8,9},
        {1,0,8,2,0}};
        void loadStation();
    };
}
#endif // TRAIN


