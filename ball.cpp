#include "ball.h"

ball::ball(float startX, float startY){
    position.x = startX;
    position.y = startY;

    shape.setRadius(10);
    shape.setFillColor(Color::Green);
    shape.setPosition(position);

    // Initial velocity
    xVelocity = 0.3f;
    yVelocity = 0.3f;
}

FloatRect ball::getPosition(){
    return shape.getGlobalBounds();
}

CircleShape ball::getShape(){
    return shape;
}

void ball::update(Time dt){
    // Use seconds instead of milliseconds (more stable)
    position.x += xVelocity * dt.asSeconds() * 1000;
    position.y += yVelocity * dt.asSeconds() * 1000;

    shape.setPosition(position);
}

void ball::reboundSides(){
    xVelocity = -xVelocity;
}

void ball::reboundTop(){
    yVelocity = -yVelocity;
}

void ball::reboundBat(){
    yVelocity = -yVelocity;

    // Add slight randomness for better gameplay
    position.y -= 5;
}

void ball::hitBottom(){
    // Reset position to center top
    position.x = 800;
    position.y = 0;

    // Send ball upward again
    yVelocity = -yVelocity;

    shape.setPosition(position);
}
