//player
#include "player.h"

using namespace players;

void player::initPlayer(float xStart, float yStart, float moveAmount, std::string textureFileName){
    xPosition = xStart;
    yPosition = yStart;
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
    player::playerSprite.setScale(spriteReductionFactor, spriteReductionFactor);
    player::playerSprite.setOrigin(4.f, 4.f);
    player::playerSprite.setPosition(xPosition, yPosition);
};
void player::updateLocation(float xUpdateValue, float yUpdateValue){
    xPosition += xUpdateValue;
    yPosition += yUpdateValue;
    player::playerSprite.setPosition(xPosition, yPosition);
};
