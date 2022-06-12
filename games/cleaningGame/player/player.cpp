//player
#include "player.h"

using namespace players;

void player::initPlayer(float xStart, float yStart, float moveAmount, std::string textureFileName){
    xPosition = xStart;
    yPosition = yStart;
    spriteFrame = 32;
    spriteFrameIncrement = 32;
    moveIncrement = moveAmount;
    spriteReductionFactor = 1.0f;
    if (!player::playerTexture.loadFromFile(textureFileName)){
        std::cout << "Texture not loaded" << std::endl;
    }
    else {
        std::cout << textureFileName << std::endl;
    }
    player::playerTexture.setSmooth(true);
    player::playerSprite.setTexture(playerTexture);
    player::playerSprite.setTextureRect(sf::IntRect(0,0,32,32));
    player::playerSprite.setScale(spriteReductionFactor, spriteReductionFactor);
    player::playerSprite.setOrigin(16.f, 16.f);
    player::playerSprite.setPosition(xPosition, yPosition);
};
void player::updateLocation(float xUpdateValue, float yUpdateValue){
    xPosition += xUpdateValue;
    yPosition += yUpdateValue;
    spriteFrame += spriteFrameIncrement;
    player::playerSprite.setPosition(xPosition, yPosition);
    player::playerSprite.setTextureRect(sf::IntRect(spriteFrame,0,32,32));
    if (spriteFrame >= 256 or spriteFrame == 0){
        spriteFrameIncrement = -spriteFrameIncrement;
    }
};
