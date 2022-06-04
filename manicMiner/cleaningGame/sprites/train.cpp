//train
#include "train.h"

using namespace trains;

void train::loadTrain(){
    trainX = 0;
    trainY = -50.0;
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

    train::chairUpTexture.setSmooth(true);
    train::chairUpSprite.setTexture(chairUpTexture);
    train::chairUpSprite.setScale(1.f, 1.f);
    train::chairDownTexture.setSmooth(true);
    train::chairDownSprite.setTexture(chairDownTexture);
    train::chairDownSprite.setScale(1.f, 1.f);
    train::tableTexture.setSmooth(true);
    train::tableSprite.setTexture(tableTexture);
    train::tableSprite.setScale(1.f, 1.f);
    train::doorLeftTexture.setSmooth(true);
    train::doorLeftSprite.setTexture(doorLeftTexture);
    train::doorLeftSprite.setScale(1.f, 1.f);
    train::doorRightTexture.setSmooth(true);
    train::doorRightSprite.setTexture(doorRightTexture);
    train::doorRightSprite.setScale(1.f, 1.f);
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
