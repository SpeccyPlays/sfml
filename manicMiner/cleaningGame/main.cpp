#include <iostream>
#include <SFML/Graphics.hpp>
#include "player/player.h"
#include "sprites/train.h"

using namespace player;
using namespace sf;
using namespace std;
using namespace trains;

RenderWindow window(VideoMode(800, 600), "Train cleaning", Style::Default);
player_1 willy;
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
        if (keys.isKeyPressed(keys.Left)){
            willy.updateLocation(-willy.moveIncrement, 0);
        }
        if (keys.isKeyPressed(keys.Right)){
            willy.updateLocation(willy.moveIncrement, 0);
        }
        if (keys.isKeyPressed(keys.Up)){
            willy.updateLocation(0, -willy.moveIncrement);
        }
        if (keys.isKeyPressed(keys.Down)){
            willy.updateLocation(0, willy.moveIncrement);
        }
        drawStuff();
    }

    return 0;
}
void init(){
    willy.initPlayer(100.f, 100.f, 1.f, "sprites/player.png");
    iet.loadTrain();
    window.setFramerateLimit(60);
}
void drawStuff(){
    window.clear();
    window.draw(willy.playerSprite);
    for (uint8_t counter = 0; counter < 38; counter++){
        for (uint8_t counter2 = 0; counter2 < 5; counter2 ++){
            int spriteNum = iet.ietInfo[counter][counter2];
            switch (spriteNum){
                case 0 :
                    break;
                case 1 :
                    iet.doorLeftSprite.setPosition(iet.trainX + counter2 * 32.f, iet.trainY + counter * 32.f );
                    window.draw(iet.doorLeftSprite);
                    cout << iet.trainY + counter * 32.f << endl;
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

            }
        }
    }

    iet.trainY += 0.1f;
    window.display();
}
