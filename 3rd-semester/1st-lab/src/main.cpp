#include <SFML/Graphics.hpp>

#include "util.h"

#include "shapes/Circle.h"
#include "shapes/Rectangle.h"
#include "shapes/Line.h"

int main()
{
    sf::RenderWindow window{ sf::VideoMode{ util::windowWidth, util::windowHeight }, "study" };
    Circle defaultCircle{};
    Circle firstConstructorCircle{ 120.0f, 40.0f, 90.0f, sf::Color::Yellow };
    std::array<int, 4> secondCircleColorComponents{ 34, 65, 89, 200 };
    Circle secondConstructorCircle{ 200.0f, 130.0f, 120.0f, secondCircleColorComponents };

    std::vector<sf::CircleShape> shapesToRender{};

    //shapesToRender.push_back(defaultCircle.getSprite());
    
    Rectangle defaultRectangle{};

    Line defaultLine{};

    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed)
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                {
                    window.close();
                }
                if (event.key.code == sf::Keyboard::U)
                {
                    defaultCircle.changeRadius(100.0f);
                }
                if (event.key.code == sf::Keyboard::I)
                {
                    defaultCircle.moveTo(8.0f, 15.0f);
                }
                if (event.key.code == sf::Keyboard::F && !(firstConstructorCircle.m_isShown))
                {
                    firstConstructorCircle.show(shapesToRender);
                }
                if (event.key.code == sf::Keyboard::S && !(secondConstructorCircle.m_isShown))
                {
                    secondConstructorCircle.show(shapesToRender);
                }
                if (event.key.code == sf::Keyboard::B)
                {
                    firstConstructorCircle.moveTo(-8.0f, 15.0f);
                }
                if (event.key.code == sf::Keyboard::R)
                {
                    defaultLine.rotate(2.0f);
                }
                if (event.key.code == sf::Keyboard::LControl && event.key.code == sf::Keyboard::R)
                {
                    defaultLine.rotate(-2.0f);
                }
                if (event.key.code == sf::Keyboard::P)
                {
                    defaultRectangle.changeWidth(3.0f);
                }
                if (event.key.code == sf::Keyboard::O)
                {
                    defaultRectangle.moveTo(2.0f, 2.0f);
                }
            }
        }

        window.clear();

        for (auto& shape : shapesToRender)
        {
            window.draw(shape);
        }

        window.draw(defaultCircle.getSprite());
        window.draw(defaultRectangle.getSprite());
        window.draw(defaultLine.getSprite());

        window.display();
    }

    return 0;
}
