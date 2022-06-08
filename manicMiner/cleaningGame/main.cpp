#include <iostream>
#include <SFML/Graphics.hpp>
#include "player/player.h"
#include "sprites/train.h"
#define SCREENWIDTH 800
#define SCREENHEIGHT 600
//note 0 is top of level

using namespace players;
using namespace sf;
using namespace std;
using namespace trains;

RenderWindow window(VideoMode(SCREENWIDTH, SCREENHEIGHT), "Train cleaning", Style::Default);
Texture backgroundImage;
Sprite background;
View view1(FloatRect(0.f, 1000.f, 800.f, 600.f));
View miniMap(FloatRect(0.f, 0.f, 2400.f, 3200.f));
player ben;
train iet;
train hst;
float spriteSize = 32.f;

void drawStuff();
void init();
void keyboardCheck(player &playerObject);
void drawTrain(train &trainObject);

int main(){
    init();
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        keyboardCheck(ben);
        drawStuff();
    }

    return 0;
}
void init(){
    //setup the world
//    view1.setRotation(340);
    if (!backgroundImage.loadFromFile("level/background2.png")){
        cout << "Background not loaded" << endl;
    }
    else {
        cout << "Background loaded" << endl;
    }
    background.setTexture(backgroundImage);
    window.setView(view1);
    ben.initPlayer(400.0, 1300.0, 2.f, "sprites/player.png");
    iet.loadTrain();
    hst.loadTrain();
    window.setFramerateLimit(60);
    hst.trainX = 438;
    miniMap.setViewport(sf::FloatRect(0.75f, 0.f, 0.25f, 0.25f));
}
void drawStuff(){
    window.clear();
    //draw everything to main view
    window.setView(view1); //do this here otherwise lag when moving screen compared to player and it looks weird
    window.draw(background);
    drawTrain(iet);
    drawTrain(hst);
    window.draw(ben.playerSprite); //draw player last otherwise he disappears under other sprites
//    redraw everything to the minimap view
    window.setView(miniMap);
    window.draw(background);
    drawTrain(iet);
    drawTrain(hst);
    window.draw(ben.playerSprite);
    window.display();
    //move train down screen
    if (iet.trainY <= 0){
        hst.trainY += 5.f;
        iet.trainY += 5.f;
    }
}
void keyboardCheck(player &playerObject){
        Keyboard keys;
        //check what key is pressed and move view and player accordingly
        if (keys.isKeyPressed(keys.Left)){
            view1.move(-playerObject.moveIncrement, 0.f);
            playerObject.updateLocation(-playerObject.moveIncrement, 0.f);
            if (playerObject.playerSprite.getRotation() != 270.f){
                playerObject.playerSprite.setRotation(270.f);
            }
        }
        if (keys.isKeyPressed(keys.Right)){
            view1.move(playerObject.moveIncrement, 0.f);
            playerObject.updateLocation(playerObject.moveIncrement, 0.f);
            if (playerObject.playerSprite.getRotation() != 90.f){
                playerObject.playerSprite.setRotation(90.f);
            }
        }
        if (keys.isKeyPressed(keys.Up)){
            view1.move(0.f, -playerObject.moveIncrement);
            playerObject.updateLocation(0.f, -playerObject.moveIncrement);
            if (playerObject.playerSprite.getRotation() != 0.f){
                playerObject.playerSprite.setRotation(0.f);
            }
        }
        if (keys.isKeyPressed(keys.Down)){
            view1.move(0.f, playerObject.moveIncrement);
            playerObject.updateLocation(0.f, playerObject.moveIncrement);
            if (playerObject.playerSprite.getRotation() != 180.f){
                playerObject.playerSprite.setRotation(180.f);
            }
        }
}
void drawTrain(train &trainObject){
       //go through the train info array and draw the right sprite according to the value
       //train object is passed by reference so function can be used for multiple functions
       //trainX = top left corner of first value of array
    for (uint8_t counter = 0; counter < 38; counter++){
        for (uint8_t counter2 = 0; counter2 < 5; counter2++){
            int spriteNum = trainObject.ietInfo[counter][counter2];
            switch (spriteNum){
                case 0 :
                    break;
                case 1 :
                    trainObject.doorLeftSprite.setPosition(trainObject.trainX + counter2 * spriteSize, trainObject.trainY + counter * spriteSize );
                    window.draw(trainObject.doorLeftSprite);
                    break;
                case 2 :
                    trainObject.doorRightSprite.setPosition((trainObject.trainX + counter2 * spriteSize), (trainObject.trainY + counter * spriteSize) );
                    window.draw(trainObject.doorRightSprite);
                    break;
                case 3 :
                    trainObject.chairDownSprite.setPosition(trainObject.trainX + counter2 * spriteSize, trainObject.trainY + counter * spriteSize );
                    window.draw(trainObject.chairDownSprite);
                    break;
               case 4 :
                    trainObject.chairUpSprite.setPosition(trainObject.trainX + counter2 * spriteSize, trainObject.trainY + counter * spriteSize );
                    window.draw(trainObject.chairUpSprite);
                    break;
                case 5 :
                    trainObject.tableSprite.setPosition(trainObject.trainX + counter2 * spriteSize, trainObject.trainY + counter * spriteSize );
                    window.draw(trainObject.tableSprite);
                    break;
                case 6 :
                    trainObject.toiletLeftSprite.setPosition(trainObject.trainX + counter2 * spriteSize, trainObject.trainY + counter * spriteSize );
                    window.draw(trainObject.toiletLeftSprite);
                    break;
                case 7 :
                    trainObject.toiletRightSprite.setPosition((trainObject.trainX + counter2 * spriteSize), (trainObject.trainY + counter * spriteSize) );
                    window.draw(trainObject.toiletRightSprite);
                    break;
                case 8 :
                    trainObject.carpetSprite.setPosition(trainObject.trainX + counter2 * spriteSize, trainObject.trainY + counter * spriteSize );
                    window.draw(trainObject.carpetSprite);
                    break;
                case 9 :
                    trainObject.rackSprite.setPosition(trainObject.trainX + counter2 * spriteSize, trainObject.trainY + counter * spriteSize );
                    window.draw(trainObject.rackSprite);
                    break;
            }
        }
    }
}
