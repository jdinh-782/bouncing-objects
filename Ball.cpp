//
// Created by jdinh on 10/29/2020.
//

#ifndef BOUNCING_OBJECTS_BALL_CPP
#define BOUNCING_OBJECTS_BALL_CPP

#include "Ball.h"


template <class T>
Ball<T>::Ball()
{
    ball.setPosition(0,0);
}


template<class T>
Ball<T>::Ball(T& ball) : ball(ball)
{
    //empty
}


template<class T>
void Ball<T>::bounce(float windowX, float windowY)
{
    ball.move(vel.x, vel.y);

    sf::Vector2f pos = ball.getPosition();

    if (pos.x > (windowX - 100.00) || pos.x < 0.00)
    {
        vel.x = -vel.x;
    }

    if (pos.y > (windowY - 100.00) || pos.y < 0.00)
    {
        vel.y = -vel.y;
    }
}


template<class T>
void Ball<T>::draw(sf::RenderTarget &window, sf::RenderStates state) const
{
    window.draw(ball);
}


#endif //BOUNCING_OBJECTS_BALL_CPP