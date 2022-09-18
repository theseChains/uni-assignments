#include <SFML/Graphics.hpp>

#include "util.h"

#include "shapes/Circle.h"
#include "shapes/Rectangle.h"
#include "shapes/Line.h"

void checkForCircleShapeCreation(std::vector<std::unique_ptr<Circle>>& circlesToRender)
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

void checkForRectangleShapeCreation(std::vector<std::unique_ptr<Rectangle>>& rectanglesToRender)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
    {
        Rectangle defaultRectangle{};
        defaultRectangle.show(rectanglesToRender);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
    {
        Rectangle firstConstructorRectangle{ 55.0f, 95.0f, 100.0f, 80.0f, sf::Color::Green };
        firstConstructorRectangle.show(rectanglesToRender);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::V))
    {
        Rectangle secondConstructorRectangle{ 490.0f, 200.0f, 70.0f, 130.0f, util::secondRectangleColorComponents };
        secondConstructorRectangle.show(rectanglesToRender);
    }
}

void checkForLineShapeCreation(std::vector<std::unique_ptr<Line>>& linesToRender)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
    {
        Line defaultLine{};
        defaultLine.show(linesToRender);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
    {
        Line firstConstructorLine{ 380.0f, 300.0f, 85.0f, sf::Color::White };
        firstConstructorLine.show(linesToRender);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::V))
    {
        Line secondConstructorLine{ 45.0f, 210.0f, 40.0f, util::secondLineColorComponents };
        secondConstructorLine.show(linesToRender);
    }
}

int main()
{
    sf::RenderWindow window{ sf::VideoMode{ util::windowWidth, util::windowHeight }, "study" };

    std::vector<std::unique_ptr<Circle>> circlesToRender{};
    std::vector<std::unique_ptr<Rectangle>> rectanglesToRender{};
    std::vector<std::unique_ptr<Line>> linesToRender{};

    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                window.close();
            }
            
            if (event.type == event.KeyPressed)
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
                {
                    workspace::shift();
                }
                if (workspace::circles)
                {
                    checkForCircleShapeCreation(circlesToRender);
                }
                else if (workspace::rectangles)
                {
                    checkForRectangleShapeCreation(rectanglesToRender);
                }
                else
                {
                    checkForLineShapeCreation(linesToRender);
                }
            }
        }

        window.clear();

        for (const auto& circle : circlesToRender)
        {
           window.draw(circle.get()->getSprite());
        }

        for (const auto& rectangle : rectanglesToRender)
        {
            window.draw(rectangle.get()->getSprite());
        }

        for (const auto& line : linesToRender)
        {
            window.draw(line.get()->getSprite());
        }

        window.display();
    }

    return 0;
}
