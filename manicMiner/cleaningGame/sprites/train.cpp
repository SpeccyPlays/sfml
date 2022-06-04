//train
#include "train.h"

using namespace trains;

void train::loadTrain(){
    spriteReductionFactor = 1.0f; //equals 1 to 1 scale
    trainX = 0.f;
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
};

/*void drawTrain(){
    for (uint8_t counter = 0; counter < 38; counter++){
        for (uint8_t counter2 = 0; counter2 < 5; counter2 ++){
            int spriteNum = train::ietInfo[counter][counter2];
            switch (spriteNum){
                case 0 :
                    break;
                case 1 :
                    train::doorLeftSprite.setPosition(counter2 * 32.f, counter * 32.f );
//                    sf::RenderWindow::draw(train::doorLeftSprite);
                    break;
                case 2 :
                    train::doorRightSprite.setPosition(counter2 * 32.f, counter * 32.f );
//                    sf::RenderWindow(train::doorRightSprite);
                    break;
                case 3 :
                    train::chairDownSprite.setPosition(counter2 * 32.f, counter * 32.f );
//                    sf::RenderWindow(train::chairDownSprite);
                    break;
               case 4 :
                    train::chairUpSprite.setPosition(counter2 * 32.f, counter * 32.f );
//                    sf::RenderWindow(train::chairUpSprite);
                    break;
                case 5 :
                    train::tableSprite.setPosition(counter2 * 32.f, counter * 32.f );
//                    sf::RenderWindow(train::tableSprite);
                    break;

            }
        }
    }
};*/
