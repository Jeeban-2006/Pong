#include <iostream>
#include <SFML/Graphics.hpp>
#include "bat.h"
#include "ball.h"
#include <sstream>

using namespace sf;

int main(){
    VideoMode vm(1600, 900);
    RenderWindow window(vm, "Pong", Style::Fullscreen);

    int score = 0;
    int lives = 3;

    // Bat (paddle)
    bat b(1600/2 - 50, 900 - 40);

    // Ball
    ball Ball(800, 0);

    // HUD
    Text hud;
    Font font;
    font.loadFromFile("font/KOMIKAP_.ttf");
    hud.setFont(font);
    hud.setFillColor(Color::White);
    hud.setCharacterSize(75);
    hud.setPosition(20, 20);

    Clock clock;

    while (window.isOpen()){

        // Handle events
        Event event;
        while(window.pollEvent(event)){
            if(event.type == Event::Closed){
                window.close();
            }
        }

        // Keyboard input
        if(Keyboard::isKeyPressed(Keyboard::Escape)){
            window.close();
        }

        if(Keyboard::isKeyPressed(Keyboard::Left)){
            b.moveLeft();
        } else {
            b.stopLeft();
        }

        if(Keyboard::isKeyPressed(Keyboard::Right)){
            b.moveRight();
        } else {
            b.stopRight();
        }

        // Update
        Time dt = clock.restart();
        b.update(dt);
        Ball.update(dt);

        // Ball collisions

        // Left & right walls
        if (Ball.getPosition().left < 0 ||
            Ball.getPosition().left + Ball.getPosition().width > 1600) {
            Ball.reboundSides();
        }

        // Top wall
        if (Ball.getPosition().top < 0) {
            Ball.reboundTop();
        }

        // Bat collision
        if (Ball.getPosition().intersects(b.getPosition())) {
            Ball.reboundBat();
            score++;
        }

        // Bottom (lose life)
        if (Ball.getPosition().top > 900) {
            Ball.hitBottom();
            lives--;
        }
        
        if (lives <= 0){
             window.close();          
           }

        // Update HUD
        std::stringstream ss;
        ss << "Score: " << score << "   Lives: " << lives;
        hud.setString(ss.str());

        // Draw
        window.clear();
        window.draw(hud);
        window.draw(b.getShape());
        window.draw(Ball.getShape());
        window.display();
    }

    return 0;
}
