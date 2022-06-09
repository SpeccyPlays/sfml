//player class header
#ifndef LEVEL_H
#define LEVEL_H
#include <SFML/Graphics.hpp>
#include <iostream>

namespace levels {
    class player_1{
    public :
        float xPosition;
        float yPosition;
        float moveIncrement;
        sf::Texture playerTexture;
        sf::Sprite playerSprite;
        void initPlayer(float xStart, float yStart, float moveAmount, std::string textureFileName);
        void updateLocation(float xUpdateValue, float yUpdateValue);
    };
}
#endif // PLAYER

