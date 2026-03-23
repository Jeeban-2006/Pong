#include <SFML/Graphics.hpp>
#include "bat.h"

using namespace sf;

bat::bat(float startX, float startY) {

    m_Position.x = startX;
    m_Position.y = startY;

    m_Shape.setSize(Vector2f(100, 20));
    m_Shape.setFillColor(Color::White);   // IMPORTANT (so you can see it)
    m_Shape.setPosition(m_Position);

    m_Speed = 400.0f;      // set speed
    m_MovingLeft = false;  // initialize
    m_MovingRight = false; // initialize
}

FloatRect bat::getPosition() {
    return m_Shape.getGlobalBounds();
}

RectangleShape bat::getShape() {
    return m_Shape;
}

void bat::moveLeft() {
    m_MovingLeft = true;
}

void bat::moveRight() {
    m_MovingRight = true;
}

void bat::stopLeft() {
    m_MovingLeft = false;
}

void bat::stopRight() {
    m_MovingRight = false;
}

void bat::update(Time dt) {

    if (m_MovingLeft) {
        m_Position.x -= m_Speed * dt.asSeconds();
    }

    if (m_MovingRight) {
        m_Position.x += m_Speed * dt.asSeconds();
    }

    m_Shape.setPosition(m_Position);
}
