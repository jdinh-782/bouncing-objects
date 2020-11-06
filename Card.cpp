//
// Created by jdinh on 10/29/2020.
//

#include "Card.h"

Card::Card()
{
    value = "Ace";
    suit = "Hearts";
    cardBackground.setPosition(sf::Vector2f(0,0));
}


Card::Card(string setValue, string setSuit)
{
    value = setValue;
    suit = setSuit;
    cardBackground.setPosition(sf::Vector2f(0,0));
}


string Card::changeFaceValue(string value)
{
    if (value == "Ace")
    {
        value = "A";
    }

    else if (value == "Jack")
    {
        value = "J";
    }

    else if (value == "Queen")
    {
        value = "Q";
    }

    else if (value == "King")
    {
        value = "K";
    }

    else
    {
        value = value;
    }
    return value;
}


void Card::setFaceValue()
{
    finalValue = changeFaceValue(value);

    if (!font.loadFromFile("OpenSans-Bold.ttf"))
    {
        exit(1);
    }

    if (suit == "Hearts" || suit == "Diamonds")
    {
        faceValue.setFillColor(sf::Color::Red);
    }

    else
    {
        faceValue.setFillColor(sf::Color::Black);
    }
    faceValue.setFont(font);
    faceValue.setString(finalValue);
    faceValue.setStyle(sf::Text::Bold);
    faceValue.setCharacterSize(50);
    faceValue.setPosition(cardBackground.getPosition().x + 45,cardBackground.getPosition().y + 50);
}


void Card::setSuit()
{
    if (!texture.loadFromFile("heart.png"))
    {
        exit(1);
    }

    if (suit == "Hearts")
    {
        texture.loadFromFile("heart.png");
    }

    else if (suit == "Spades")
    {
        texture.loadFromFile("spades.png");
    }

    else if (suit == "Clubs")
    {
        texture.loadFromFile("clubs.png");
    }

    else if (suit == "Diamonds")
    {
        texture.loadFromFile("diamonds.png");
    }

    suit1.setScale(0.50, 0.50);
    suit1.setTexture(texture);
    suit1.setPosition(cardBackground.getPosition().x +3, cardBackground.getPosition().y +3);


    suit2.setScale(0.50, 0.50);
    suit2.setTexture(texture);
    suit2.setPosition(cardBackground.getPosition().x +123, cardBackground.getPosition().y +173);
    suit2.setRotation(180);
}


void Card::setCard()
{
    cardBackground.setFillColor(sf::Color::White);
    cardBackground.setPosition(sf::Vector2f(10, 10));
    cardBackground.setSize(sf::Vector2f(125, 175));
}


void Card::move(float windowX, float windowY)
{
    cardBackground.move(windowX, windowY);
    faceValue.move(windowX, windowY);
    suit1.move(windowX, windowY);
    suit2.move(windowX, windowY);

    sf::Vector2f pos = cardBackground.getPosition();

    if (pos.x > (windowX - 100.00) || pos.x < 0.00)
    {
        vel.x = -vel.x;
    }

    if (pos.y > (windowY - 100.00) || pos.y < 0.00)
    {
        vel.y = -vel.y;
    }
}


sf::Vector2f Card::getPosition()
{
    return cardBackground.getPosition();
}


void Card::draw (sf::RenderTarget &window, sf::RenderStates state) const
{
    window.draw(cardBackground);
    window.draw(faceValue);
    window.draw(suit1);
    window.draw(suit2);
}

