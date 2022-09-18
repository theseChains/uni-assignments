#include <SFML/Graphics.hpp>

#include <algorithm>
#include <functional>
#include <memory>
#include <ranges>

#include "util.h"

#include "shapes/Circle.h"
#include "shapes/Rectangle.h"
#include "shapes/Line.h"

void createCircleShape(std::vector<std::unique_ptr<Circle>>& circlesToRender,
        const sf::Event& event)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
    {
        Circle defaultCircle{};
        defaultCircle.show(circlesToRender);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
    {
        Circle firstConstructorCircle{ 120.0f, 40.0f, 90.0f, sf::Color::Yellow };
        firstConstructorCircle.show(circlesToRender);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::V))
    {
        Circle secondConstructorCircle{ 200.0f, 130.0f, 120.0f, util::secondCircleColorComponents };
        secondConstructorCircle.show(circlesToRender);
    }
}

int main()
{
    sf::RenderWindow window{ sf::VideoMode{ util::windowWidth, util::windowHeight }, "study" };

    std::vector<std::unique_ptr<Circle>> circlesToRender{};

    Rectangle defaultRectangle{};

    Line defaultLine{};

    // todo: make 3 boolean variables for circle, rectangle and line movement
    // alternate between these 3 modes by pressing 3 different keys
    // update show function so that with the second call it removes the sprite

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
                createCircleShape(circlesToRender, event);
                if (event.key.code == sf::Keyboard::D)
                {
                    for (auto& shape : circlesToRender)
                    {
                        shape->moveTo(5.0f, 5.0f);
                    }
                }
            }
        }

        window.clear();

        for (const auto& shape : circlesToRender)
        {
           window.draw(shape.get()->getSprite());
        }

        window.display();
    }

    return 0;
}
