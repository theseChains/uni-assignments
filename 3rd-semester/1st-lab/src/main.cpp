#include <SFML/Graphics.hpp>

#include <functional>
#include <memory>
#include <random>

#include "util.h"

#include "shapes/Circle.h"
#include "shapes/Rectangle.h"
#include "shapes/Line.h"

namespace rnd
{
    std::mt19937 mt{ std::random_device{}() };
    
    int getNumber(int min, int max)
    {
        std::uniform_int_distribution range(min, max);
        return range(mt);
    }
}

void createCircleShape(std::vector<std::reference_wrapper<Circle>>& circlesToRender,
        const sf::Event& event)
{
    // define 3 if's here, create default circle in the first one, first constructor circle
    // in the second one, second constructor circle in the third one
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
    {
        
    }
}

int main()
{
    sf::RenderWindow window{ sf::VideoMode{ util::windowWidth, util::windowHeight }, "study" };
    Circle defaultCircle{};
    Circle firstConstructorCircle{ 120.0f, 40.0f, 90.0f, sf::Color::Yellow };
    std::array<int, 4> secondCircleColorComponents{ 34, 65, 89, 200 };
    Circle secondConstructorCircle{ 200.0f, 130.0f, 120.0f, secondCircleColorComponents };

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
                if (event.key.code == sf::Keyboard::F)
                {
                    firstConstructorCircle.show(circlesToRender);
                }
                if (event.key.code == sf::Keyboard::C)
                {
                    secondConstructorCircle.show(circlesToRender);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::V))
                {
                    defaultCircle.show(circlesToRender);
                }
                if (event.key.code == sf::Keyboard::D)
                {
                    firstConstructorCircle.moveTo(5.0f, 5.0f); 
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
