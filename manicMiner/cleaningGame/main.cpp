#include <iostream>
#include <SFML/Graphics.hpp>
#include "player/player.h"
#include "sprites/train.h"
#define SCREENWIDTH 800
#define SCREENHEIGHT 600
//note 0 is top of level

using namespace player;
using namespace sf;
using namespace std;
using namespace trains;

RenderWindow window(VideoMode(SCREENWIDTH, SCREENHEIGHT), "Train cleaning", Style::Default);
View view1(FloatRect(0.f, 1000.f, 800.f, 600.f));
player_1 ben;
train iet;

void drawStuff();
void init();

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
        Keyboard keys;
        //check what key is pressed and move view and player accordingly
        if (keys.isKeyPressed(keys.Left)){
            view1.move(-5.0f, 0.f);
            ben.updateLocation(-ben.moveIncrement, 0);
        }
        if (keys.isKeyPressed(keys.Right)){
            view1.move(5.0f, 0.f);
            ben.updateLocation(ben.moveIncrement, 0);
        }
        if (keys.isKeyPressed(keys.Up)){
            view1.move(0.0f, -5.f);
            ben.updateLocation(0, -ben.moveIncrement);
        }
        if (keys.isKeyPressed(keys.Down)){
            view1.move(0.0f, 5.f);
            ben.updateLocation(0, ben.moveIncrement);
        }
        drawStuff();
    }

    return 0;
}
void init(){
    //setup the world
    window.setView(view1);
    ben.initPlayer(400.0, 1300.0, 5.f, "sprites/player.png");
    iet.loadTrain();
    window.setFramerateLimit(60);
}
void drawStuff(){
    window.clear();
    //go through the train info array and draw the right according to the value
    for (uint8_t counter = 0; counter < 38; counter++){
        for (uint8_t counter2 = 0; counter2 < 5; counter2 ++){
            int spriteNum = iet.ietInfo[counter][counter2];
            switch (spriteNum){
                case 0 :
                    break;
                case 1 :
                    iet.doorLeftSprite.setPosition(iet.trainX + counter2 * 32.f, iet.trainY + counter * 32.f );
                    window.draw(iet.doorLeftSprite);
                    break;
                case 2 :
                    iet.doorRightSprite.setPosition((iet.trainX + counter2 * 32.f), (iet.trainY + counter * 32.f) );
                    window.draw(iet.doorRightSprite);
                    break;
                case 3 :
                    iet.chairDownSprite.setPosition(iet.trainX + counter2 * 32.f, iet.trainY + counter * 32.f );
                    window.draw(iet.chairDownSprite);
                    break;
               case 4 :
                    iet.chairUpSprite.setPosition(iet.trainX + counter2 * 32.f, iet.trainY + counter * 32.f );
                    window.draw(iet.chairUpSprite);
                    break;
                case 5 :
                    iet.tableSprite.setPosition(iet.trainX + counter2 * 32.f, iet.trainY + counter * 32.f );
                    window.draw(iet.tableSprite);
                    break;
                case 6 :
                    iet.toiletLeftSprite.setPosition(iet.trainX + counter2 * 32.f, iet.trainY + counter * 32.f );
                    window.draw(iet.toiletLeftSprite);
                    break;
                case 7 :
                    iet.toiletRightSprite.setPosition((iet.trainX + counter2 * 32.f), (iet.trainY + counter * 32.f) );
                    window.draw(iet.toiletRightSprite);
                    break;
                case 8 :
                    iet.carpetSprite.setPosition(iet.trainX + counter2 * 32.f, iet.trainY + counter * 32.f );
                    window.draw(iet.carpetSprite);
                    break;
                case 9 :
                    iet.rackSprite.setPosition(iet.trainX + counter2 * 32.f, iet.trainY + counter * 32.f );
                    window.draw(iet.rackSprite);
                    break;
            }
        }
    }
    //move train down screen
    if (iet.trainY < 0){
       iet.trainY += 5.f;
    }
    window.draw(ben.playerSprite); //draw player last otherwise he disappears under other sprites
    window.setView(view1);
    window.display();
}

