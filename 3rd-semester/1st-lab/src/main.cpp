#include <SFML/Graphics.hpp>
#include <iostream>
#include "util.h"

#include "shapes/Circle.h"
#include "shapes/Rectangle.h"
#include "shapes/Line.h"

void switchWorkspace(bool& workingWithCircles, bool& workingWithRectangles, bool& workingWithLines)
{
    if (workingWithCircles)
    {
        workingWithCircles = false;
        workingWithRectangles = true;
    }
    else if (workingWithRectangles)
    {
        workingWithRectangles = false;
        workingWithLines = true;
    }
    else
    {
        workingWithLines = false;
        workingWithCircles = true;
    }
}

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
        Rectangle secondConstructorRectangle{ 300.0f, 200.0f, 70.0f, 130.0f, util::secondRectangleColorComponents };
        secondConstructorRectangle.show(rectanglesToRender);
    }
}

int main()
{
    sf::RenderWindow window{ sf::VideoMode{ util::windowWidth, util::windowHeight }, "study" };

    std::vector<std::unique_ptr<Circle>> circlesToRender{};
    std::vector<std::unique_ptr<Rectangle>> rectanglesToRender{};
    std::vector<std::unique_ptr<Line>> linesToRender{};

    // todo: namespace workspace
    bool workingWithCircles{ true };
    bool workingWithRectangles{ false };
    bool workingWithLines{ false };

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
                    switchWorkspace(workingWithCircles, workingWithRectangles, workingWithLines);
                }
                if (workingWithCircles)
                {
                    checkForCircleShapeCreation(circlesToRender);
                }
                if (workingWithRectangles)
                {
                    checkForRectangleShapeCreation(rectanglesToRender);
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
