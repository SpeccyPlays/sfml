#include <iostream>
#include <SFML/Graphics.hpp>
#include "player/player.h"
#include "sprites/train.h"
#define SCREENWIDTH 800.f
#define SCREENHEIGHT 600.f
#define LEVELWIDTH 2400.f
#define LEVELHEIGHT 3200.f
//note 0 is top of level

using namespace players;
using namespace sf;
using namespace std;
using namespace trains;

RenderWindow window(VideoMode(SCREENWIDTH, SCREENHEIGHT), "Train cleaning", Style::Default);
Texture backgroundImage;
Sprite background;
View view1(FloatRect(0.f, 1000.f, SCREENWIDTH, SCREENHEIGHT));
View miniMap(FloatRect(0.f, 0.f, LEVELWIDTH, LEVELHEIGHT));
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
    ben.initPlayer(400.0, 1300.0, 2.f, "sprites/playerSpriteSheet.png");
    view1.setCenter(ben.xPosition, ben.yPosition);
    iet.loadTrain(spriteSize);
    hst.loadTrain(spriteSize);
    window.setFramerateLimit(60);
    hst.trainX = 438;
    miniMap.setViewport(sf::FloatRect(0.75f, 0.f, 0.25f, 0.25f));
}
void drawStuff(){
    window.clear();
    //draw everything to main view
    window.setView(view1); //do this here otherwise lag when moving screen compared to player and it looks weird
    window.draw(background);
    iet.drawTrain(window);
    hst.drawTrain(window);
    window.draw(ben.playerSprite); //draw player last otherwise he disappears under other sprites
//    redraw everything to the minimap view
    window.setView(miniMap);
    window.draw(background);
    iet.drawTrain(window);
    hst.drawTrain(window);
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
            //only move the view if the player is away from the edges. Otherwise, only move player
            //change rotation of sprite so it's facing direction of movement
            //below is in progress
            if ((playerObject.xPosition > SCREENWIDTH / 2) && (playerObject.xPosition < LEVELWIDTH - (SCREENWIDTH /2))) {
                view1.move(-playerObject.moveIncrement, 0.f);
            }
            if (playerObject.xPosition > (0 + spriteSize)){
                playerObject.updateLocation(-playerObject.moveIncrement, 0.f);
            }
            if (playerObject.playerSprite.getRotation() != 270.f){
                playerObject.playerSprite.setRotation(270.f);
            }
        }
        if (keys.isKeyPressed(keys.Right)){
            if ((playerObject.xPosition > SCREENWIDTH / 2) && (playerObject.xPosition < (LEVELWIDTH - SCREENWIDTH /2))){
                view1.move(playerObject.moveIncrement, 0.f);
            }
            if (playerObject.xPosition < (LEVELWIDTH - spriteSize)){
                playerObject.updateLocation(playerObject.moveIncrement, 0.f);
            }
            if (playerObject.playerSprite.getRotation() != 90.f){
                playerObject.playerSprite.setRotation(90.f);
            }
        }
        if (keys.isKeyPressed(keys.Up)){
            if ((playerObject.yPosition > SCREENHEIGHT / 2) && (playerObject.yPosition < (LEVELHEIGHT - SCREENHEIGHT / 2))){
                view1.move(0.f, -playerObject.moveIncrement);
            }
            if (playerObject.yPosition > (0 + spriteSize)){
                playerObject.updateLocation(0.f, -playerObject.moveIncrement);
            }
            if (playerObject.playerSprite.getRotation() != 0.f){
                playerObject.playerSprite.setRotation(0.f);
            }
        }
        if (keys.isKeyPressed(keys.Down)){
            if ((playerObject.yPosition > SCREENHEIGHT / 2) && (playerObject.yPosition < (LEVELHEIGHT - SCREENHEIGHT / 2))){
                view1.move(0.f, playerObject.moveIncrement);
            }
            if (playerObject.yPosition < (LEVELHEIGHT - spriteSize)){
                playerObject.updateLocation(0.f, playerObject.moveIncrement);
            }
            if (playerObject.playerSprite.getRotation() != 180.f){
                playerObject.playerSprite.setRotation(180.f);
            }
        }
}
