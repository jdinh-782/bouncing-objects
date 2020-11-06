//
// Created by jdinh on 10/29/2020.
//

#ifndef BOUNCING_OBJECTS_BALL_H
#define BOUNCING_OBJECTS_BALL_H

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;


template <class T>
class Ball : public sf::Drawable, sf::Transformable
{
private:
    T& ball;
    sf::Vector2f vel{20,5};

public:
    Ball();
    Ball(T& ball);

    void bounce(float windowX, float windowY);

    virtual void draw (sf::RenderTarget &window, sf::RenderStates state) const;
};


#include "Ball.cpp"

#endif //BOUNCING_OBJECTS_BALL_H
