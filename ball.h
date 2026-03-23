#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class ball {
private:
    Vector2f position;
    CircleShape shape;
    float m_speed=300.0f;
    float xVelocity = 0.3f;
    float yVelocity = 0.3f;

public:
    ball(float startX, float startY);

    FloatRect getPosition();
    CircleShape getShape();

    void update(Time dt);

    void reboundSides();
    void reboundBat();
    void reboundTop();

    void hitBottom();
};
