#include "Ball.h"
#include "Card.h"


int main()
{
    Card card("Ace", "Hearts");
    card.setCard();
    card.setFaceValue();
    card.setSuit();
    Ball<Card> cardObj(card);

    sf::CircleShape obj;
    Ball<sf::CircleShape> ball(obj);

    sf::RenderWindow window(sf::VideoMode(1600, 900, 32), "Bouncing Ball");
    float xPos = window.getSize().x;
    float yPos = window.getSize().y;

    obj.setFillColor(sf::Color::Blue);
    obj.setRadius(50.f);

    window.setFramerateLimit(60);

    while(window.isOpen())
    {
        sf::Event event{};

        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        ball.bounce(xPos, yPos); //YOUR BOUNCE FUNCTION WILL BE CALLED HERE
        cardObj.bounce(xPos, yPos);

        window.clear(sf::Color::Black);
        window.draw(cardObj);
        window.draw(ball); //SOMETHING GETS DRAWN HERE
        window.display();
    }
    return 0;
}
