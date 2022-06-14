//train
#include "train.h"

using namespace trains;

void train::loadTrain(float _spriteSize){
    spriteSize = _spriteSize;
    spriteReductionFactor = 1.0f; //equals 1 to 1 scale
    trainX = 10.f;
    trainY = -600.f; //minus number so train beings off top of screen
    //load sprite images and map to texture
    if (!train::chairDownTexture.loadFromFile("sprites/chairDown.png")){
        std::cout << "Texture not loaded" << std::endl;
    }
    else {
        std::cout << "chairDown.png" << std::endl ;
    }
    if (!train::chairUpTexture.loadFromFile("sprites/chairUp.png")){
        std::cout << "Texture not loaded" << std::endl;
    }
    else {
        std::cout << "chairUp.png" << std::endl ;
    }
        if (!train::tableTexture.loadFromFile("sprites/table.png")){
        std::cout << "Texture not loaded" << std::endl;
    }
    else {
        std::cout << "table.png" << std::endl;
    }
    if (!train::doorLeftTexture.loadFromFile("sprites/doorLeft.png")){
        std::cout << "Texture not loaded" << std::endl;
    }
    else {
        std::cout << "doorLeft.png" << std::endl;
    }
    if (!train::doorRightTexture.loadFromFile("sprites/doorRight.png")){
        std::cout << "Texture not loaded" << std::endl;
    }
    else {
        std::cout << "doorRight.png" << std::endl;
    }
    if (!train::toiletLeftTexture.loadFromFile("sprites/toiletLeft.png")){
        std::cout << "Texture not loaded" << std::endl;
    }
    else {
        std::cout << "toiletLeft.png" << std::endl;
    }
    if (!train::toiletRightTexture.loadFromFile("sprites/toiletRight.png")){
        std::cout << "Texture not loaded" << std::endl;
    }
    else {
        std::cout << "toiletRight.png" << std::endl;
    }
    if (!train::carpetTexture.loadFromFile("sprites/carpet.png")){
        std::cout << "Texture not loaded" << std::endl;
    }
    else {
        std::cout << "carpet.png" << std::endl;
    }
    if (!train::rackTexture.loadFromFile("sprites/rack.png")){
        std::cout << "Texture not loaded" << std::endl;
    }
    else {
        std::cout << "rack.png" << std::endl;
    }
    if (!train::rightSideWithWindowTexture.loadFromFile("sprites/rightsidewithwindow.png")){
        std::cout << "Texture not loaded" << std::endl;
    }
    else {
        std::cout << "rightsidewithwindow.png" << std::endl;
    }
    if (!train::leftSideWithWindowTexture.loadFromFile("sprites/leftsidewithwindow.png")){
        std::cout << "Texture not loaded" << std::endl;
    }
    else {
        std::cout << "leftsidewithwindow.png" << std::endl;
    }
    if (!train::outsideDoorFaceRightTexture.loadFromFile("sprites/outsideDoorFaceRight.png")){
        std::cout << "Texture not loaded" << std::endl;
    }
    else {
        std::cout << "outsideDoorFaceRight.png" << std::endl;
    }
    if (!train::outsideDoorFaceLeftTexture.loadFromFile("sprites/outsideDoorFaceLeft.png")){
        std::cout << "Texture not loaded" << std::endl;
    }
    else {
        std::cout << "outsideDoorFaceLeft.png" << std::endl;
    }
    //texture and sprite stuff
    train::chairUpTexture.setSmooth(true);
    train::chairUpSprite.setTexture(chairUpTexture);//map texture to sprite
    train::chairUpSprite.setScale(spriteReductionFactor, spriteReductionFactor);

    train::chairDownTexture.setSmooth(true);
    train::chairDownSprite.setTexture(chairDownTexture);
    train::chairDownSprite.setScale(spriteReductionFactor, spriteReductionFactor);

    train::tableTexture.setSmooth(true);
    train::tableSprite.setTexture(tableTexture);
    train::tableSprite.setScale(spriteReductionFactor, spriteReductionFactor);

    train::doorLeftTexture.setSmooth(true);
    train::doorLeftSprite.setTexture(doorLeftTexture);
    train::doorLeftSprite.setScale(spriteReductionFactor, spriteReductionFactor);
    train::doorRightTexture.setSmooth(true);
    train::doorRightSprite.setTexture(doorRightTexture);
    train::doorRightSprite.setScale(spriteReductionFactor, spriteReductionFactor);

    train::toiletLeftTexture.setSmooth(true);
    train::toiletLeftSprite.setTexture(toiletLeftTexture);
    train::toiletLeftSprite.setScale(spriteReductionFactor, spriteReductionFactor);
    train::toiletRightTexture.setSmooth(true);
    train::toiletRightSprite.setTexture(toiletRightTexture);
    train::toiletRightSprite.setScale(spriteReductionFactor, spriteReductionFactor);

    train::carpetTexture.setSmooth(true);
    train::carpetSprite.setTexture(carpetTexture);
    train::carpetSprite.setScale(spriteReductionFactor, spriteReductionFactor);

    train::rackTexture.setSmooth(true);
    train::rackSprite.setTexture(rackTexture);
    train::rackSprite.setScale(spriteReductionFactor, spriteReductionFactor);

    train::rightSideWithWindowTexture.setSmooth(true);
    train::rightSideWithWindowSprite.setTexture(rightSideWithWindowTexture);
    train::rightSideWithWindowSprite.setScale(spriteReductionFactor, spriteReductionFactor);

    train::leftSideWithWindowTexture.setSmooth(true);
    train::leftSideWithWindowSprite.setTexture(leftSideWithWindowTexture);
    train::leftSideWithWindowSprite.setScale(spriteReductionFactor, spriteReductionFactor);

    train::outsideDoorFaceRightTexture.setSmooth(true);
    train::outsideDoorFaceRightSprite.setTexture(outsideDoorFaceRightTexture);
    train::outsideDoorFaceRightSprite.setScale(spriteReductionFactor, spriteReductionFactor);

    train::outsideDoorFaceLeftTexture.setSmooth(true);
    train::outsideDoorFaceLeftSprite.setTexture(outsideDoorFaceLeftTexture);
    train::outsideDoorFaceLeftSprite.setScale(spriteReductionFactor, spriteReductionFactor);
}
void train::drawTrain(sf::RenderWindow &windowRef){
       //go through the train info array and draw the right sprite according to the value
       //train object is passed by reference so function can be used for multiple functions
       //trainX = top left corner of first value of array
    for (uint8_t counter = 0; counter < 38; counter++){
        for (uint8_t counter2 = 0; counter2 < 7; counter2++){
            int spriteNum = ietInfo[counter][counter2];
            switch (spriteNum){
                case 0 :
                    break;
                case 1 :
                    doorLeftSprite.setPosition(trainX + counter2 * spriteSize, trainY + counter * spriteSize );
                    windowRef.draw(doorLeftSprite);
                    break;
                case 2 :
                    doorRightSprite.setPosition((trainX + counter2 * spriteSize), (trainY + counter * spriteSize) );
                    windowRef.draw(doorRightSprite);
                    break;
                case 3 :
                    chairDownSprite.setPosition(trainX + counter2 * spriteSize, trainY + counter * spriteSize );
                    windowRef.draw(chairDownSprite);
                    break;
               case 4 :
                    chairUpSprite.setPosition(trainX + counter2 * spriteSize, trainY + counter * spriteSize );
                    windowRef.draw(chairUpSprite);
                    break;
                case 5 :
                    tableSprite.setPosition(trainX + counter2 * spriteSize, trainY + counter * spriteSize );
                    windowRef.draw(tableSprite);
                    break;
                case 6 :
                    toiletLeftSprite.setPosition(trainX + counter2 * spriteSize, trainY + counter * spriteSize );
                    windowRef.draw(toiletLeftSprite);
                    break;
                case 7 :
                    toiletRightSprite.setPosition((trainX + counter2 * spriteSize), (trainY + counter * spriteSize) );
                    windowRef.draw(toiletRightSprite);
                    break;
                case 8 :
                    carpetSprite.setPosition(trainX + counter2 * spriteSize, trainY + counter * spriteSize );
                    windowRef.draw(carpetSprite);
                    break;
                case 9 :
                    rackSprite.setPosition(trainX + counter2 * spriteSize, trainY + counter * spriteSize );
                    windowRef.draw(rackSprite);
                    break;
                case 10 :
                    rightSideWithWindowSprite.setPosition(trainX + counter2 * spriteSize, trainY + counter * spriteSize );
                    windowRef.draw(rightSideWithWindowSprite);
                    break;
                case 11 :
                    leftSideWithWindowSprite.setPosition(trainX + counter2 * spriteSize, trainY + counter * spriteSize );
                    windowRef.draw(leftSideWithWindowSprite);
                    break;
                case 12 :
                    outsideDoorFaceRightSprite.setPosition(trainX + counter2 * spriteSize, trainY + counter * spriteSize );
                    windowRef.draw(outsideDoorFaceRightSprite);
                    break;
                case 13 :
                    outsideDoorFaceLeftSprite.setPosition(trainX + counter2 * spriteSize, trainY + counter * spriteSize );
                    windowRef.draw(outsideDoorFaceLeftSprite);
                    break;
            }
        }
    }
};
