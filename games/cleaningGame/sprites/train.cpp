//train
#include "train.h"

using namespace trains;

void train::loadTrain(float _spriteSize){
    spriteSize = _spriteSize;
    spriteReductionFactor = 1.0f; //equals 1 to 1 scale
    trainX = 10.f;
    trainY = -600.f; //minus number so train beings off top of screen
    //load texture files
    train::trainTextureAndSpriteInfo[1].textureNameString = "sprites/doorLeft.png";
    train::trainTextureAndSpriteInfo[2].textureNameString = "sprites/doorRight.png";
    train::trainTextureAndSpriteInfo[3].textureNameString = "sprites/chairDown.png";
    train::trainTextureAndSpriteInfo[4].textureNameString = "sprites/chairUp.png";
    train::trainTextureAndSpriteInfo[5].textureNameString = "sprites/table.png";
    train::trainTextureAndSpriteInfo[6].textureNameString = "sprites/toiletLeft.png";
    train::trainTextureAndSpriteInfo[7].textureNameString = "sprites/toiletRight.png";
    train::trainTextureAndSpriteInfo[8].textureNameString = "sprites/carpet.png";
    train::trainTextureAndSpriteInfo[9].textureNameString = "sprites/rack.png";
    train::trainTextureAndSpriteInfo[10].textureNameString = "sprites/rightsidewithwindow.png";
    train::trainTextureAndSpriteInfo[11].textureNameString = "sprites/leftsidewithwindow.png";
    train::trainTextureAndSpriteInfo[12].textureNameString = "sprites/outsideDoorFaceRight.png";
    train::trainTextureAndSpriteInfo[13].textureNameString = "sprites/outsideDoorFaceLeft.png";
    train::trainTextureAndSpriteInfo[14].textureNameString = "sprites/leftsidenowindow.png";
    train::trainTextureAndSpriteInfo[15].textureNameString = "sprites/rightsidenowindow.png";
    //loop through the texture and sprite structure to load texture and assign texture to sprite
    for (uint8_t i = 1; i < sizeof(train::trainTextureAndSpriteInfo)/sizeof(train::trainTextureAndSpriteInfo[0]); i++){
        if (!train::trainTextureAndSpriteInfo[i].textureName.loadFromFile(train::trainTextureAndSpriteInfo[i].textureNameString)){
            std::cout << train::trainTextureAndSpriteInfo[i].textureNameString << " not loaded" << std::endl;
        }
        else {
            std::cout << train::trainTextureAndSpriteInfo[i].textureNameString << " is loaded" << std::endl;
            train::trainTextureAndSpriteInfo[i].textureName.setSmooth(true);
            train::trainTextureAndSpriteInfo[i].spriteName.setTexture(train::trainTextureAndSpriteInfo[i].textureName);
            train::trainTextureAndSpriteInfo[i].spriteName.setScale(spriteReductionFactor, spriteReductionFactor);
        }
    }
}//endLoadTrain
void train::drawTrain(sf::RenderWindow &windowRef){
       //go through the train info array and draw the right sprite according to the value
       //train object is passed by reference so function can be used for multiple functions
       //trainX = top left corner of first value of array
    for (uint8_t counter = 0; counter < sizeof(ietInfo)/sizeof(ietInfo[0]); counter++){
        for (uint8_t counter2 = 0; counter2 < sizeof(ietInfo[0])/sizeof(ietInfo[0][0]); counter2++){
            int spriteNum = ietInfo[counter][counter2];
            if (spriteNum > 0){
                trainTextureAndSpriteInfo[spriteNum].spriteName.setPosition(trainX + counter2 * spriteSize, trainY + counter * spriteSize );
                windowRef.draw(trainTextureAndSpriteInfo[spriteNum].spriteName);
            }
        }
    }
}//end drawTrain
bool train::onTrainCollisionCheck(float receiveX, float receiveY){
    float receiveX2 = receiveX + spriteSize;
    float receiveY2 = receiveY + spriteSize;
    if ((receiveX >= trainX && receiveX <= trainX + (sizeof(ietInfo[0])/sizeof(ietInfo[0][0] * 32)))){
        std::cout << "player in X boundary" << std::endl;
    }

    return false;
}//end onTrainCollisionCheck;
