//
// Created by jdinh on 10/29/2020.
//

#ifndef BOUNCING_OBJECTS_CARD_H
#define BOUNCING_OBJECTS_CARD_H

#include <string>
#include <SFML/Graphics.hpp>

using namespace std;


class Card : public sf::Drawable, sf::Transformable
{
private:
    sf::RectangleShape cardBackground;
    sf::Text faceValue;
    sf::Sprite suit1;
    sf::Sprite suit2;
    sf::Font font;
    sf::Texture texture;
    sf::Vector2f vel{20,5};
    string value, suit, finalValue;

public:
    Card();
    Card(string setValue, string setSuit);

    void setFaceValue();
    void setSuit();
    void setCard();

    static string changeFaceValue(string value);

    void move(float windowX, float windowY);

    sf::Vector2f getPosition();

    virtual void draw (sf::RenderTarget &window, sf::RenderStates state) const;
};


#endif //BOUNCING_OBJECTS_CARD_H
