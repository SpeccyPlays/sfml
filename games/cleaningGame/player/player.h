//player class header
#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include <iostream>

namespace players {
    class player{
    public :
        float xPosition;
        float yPosition;
        float moveIncrement;
        float spriteReductionFactor;
        sf::Texture playerTexture;
        sf::Sprite playerSprite;
        void initPlayer(float xStart, float yStart, float moveAmount, std::string textureFileName);
        void updateLocation(float xUpdateValue, float yUpdateValue);
    };
}
#endif // PLAYER
