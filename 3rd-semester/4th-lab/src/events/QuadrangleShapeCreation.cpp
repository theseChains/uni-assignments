#include "QuadrangleShapeCreation.h"

void Creation::checkForQuadrangleShapeCreation(std::array<std::unique_ptr<Quadrangle>, 3>& quadranglesToRender)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
    {
        handleDefaultQuadrangleShapeCreation(quadranglesToRender[util::defaultShapeIndex]);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
    {
        handleFirstConstructorQuadrangleCreation(quadranglesToRender[util::firstConstructorShapeIndex]);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::V))
    {
        handleSecondConstructorQuadrangleCreation(quadranglesToRender[util::secondConstructorShapeIndex]);
    }
    // deletion
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
    {
        hideAndDeleteShape(quadranglesToRender[util::defaultShapeIndex]);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
    {
        hideAndDeleteShape(quadranglesToRender[util::firstConstructorShapeIndex]);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::H))
    {
        hideAndDeleteShape(quadranglesToRender[util::secondConstructorShapeIndex]);
    }
}

void Creation::createAndShowDefaultQuadrangle(std::unique_ptr<Quadrangle>& newQuadranglePtr)
{
    Quadrangle defaultQuadrangle{};

    defaultQuadrangle.show();
    newQuadranglePtr = std::make_unique<Quadrangle>(defaultQuadrangle);
}

struct QuadrangleVertices
{
    float m_firstX{};
    float m_firstY{};
    float m_secondX{};
    float m_secondY{};
    float m_thirdX{};
    float m_thirdY{};
    float m_fourthX{};
    float m_fourthY{};
};

QuadrangleVertices createRandomQuadrangleVertices()
{
    float firstX{ rnd::getFloat(util::guiWidth + 200, util::windowWidth - 200) };
    float firstY{ rnd::getFloat(0, util::windowHeight - 200) };
    // a bit messy but i'll leave it like that whatever
    float secondX{ firstX + rnd::getFloat(10, 200) };
    float secondY{ firstY + rnd::getFloat(10, 50) };
    float thirdX{ secondX - rnd::getFloat(10, 50) };
    float thirdY{ secondY + rnd::getFloat(10, 200) };
    float fourthX{ thirdX - rnd::getFloat(10, 200) };
    float fourthY{ secondY + rnd::getFloat(10, 50) };

    return { firstX, firstY, secondX, secondY, thirdX, thirdY, fourthX, fourthY };
}

Quadrangle Creation::createFirstConstructorQuadrangle()
{
    QuadrangleVertices vertices{ createRandomQuadrangleVertices() };
    Color color{ createRandomColor() };

    Quadrangle firstConstructorQuadrangle{ vertices.m_firstX, vertices.m_firstY,
        vertices.m_secondX, vertices.m_secondY, vertices.m_thirdX, vertices.m_thirdY,
        vertices.m_fourthX, vertices.m_fourthY, sf::Color(color.m_redComponent,
        color.m_greenComponent, color.m_blueComponent) };

    return firstConstructorQuadrangle;
}

Quadrangle Creation::createSecondConstructorQuadrangle()
{
    QuadrangleVertices vertices{ createRandomQuadrangleVertices() };
    Color color{ createRandomColor() };

    int alphaComponent{ rnd::getNumber(50, 255) };

    Quadrangle secondConstructorQuadrangle{ vertices.m_firstX, vertices.m_firstY,
        vertices.m_secondX, vertices.m_secondY, vertices.m_thirdX, vertices.m_thirdY,
        vertices.m_fourthX, vertices.m_fourthY, std::array{ color.m_redComponent,
        color.m_greenComponent, color.m_blueComponent, alphaComponent } };

    return secondConstructorQuadrangle;
}

void Creation::handleDefaultQuadrangleShapeCreation(std::unique_ptr<Quadrangle>& quadranglePtr)
{
    if (quadranglePtr != nullptr)
    {
        hideAndDeleteShape(quadranglePtr);
        createAndShowDefaultQuadrangle(quadranglePtr);
    }
    else
    {
        createAndShowDefaultQuadrangle(quadranglePtr);
    }
}

void Creation::handleFirstConstructorQuadrangleCreation(std::unique_ptr<Quadrangle>& quadranglePtr)
{
    if (quadranglePtr != nullptr)
    {
        hideAndDeleteShape(quadranglePtr);
        Quadrangle firstConstructorQuadrangle{ createFirstConstructorQuadrangle() };

        firstConstructorQuadrangle.show();
        quadranglePtr = std::make_unique<Quadrangle>(firstConstructorQuadrangle);
    }
    else
    {
        Quadrangle firstConstructorQuadrangle{ createFirstConstructorQuadrangle() };

        firstConstructorQuadrangle.show();
        quadranglePtr = std::make_unique<Quadrangle>(firstConstructorQuadrangle);
    }
}

void Creation::handleSecondConstructorQuadrangleCreation(std::unique_ptr<Quadrangle>& quadranglePtr)
{
    if (quadranglePtr != nullptr)
    {
        hideAndDeleteShape(quadranglePtr);
        Quadrangle secondConstructorQuadrangle{ createSecondConstructorQuadrangle() };

        secondConstructorQuadrangle.show();
        quadranglePtr = std::make_unique<Quadrangle>(secondConstructorQuadrangle);
    }
    else
    {
        Quadrangle secondConstructorQuadrangle{ createSecondConstructorQuadrangle() };

        secondConstructorQuadrangle.show();
        quadranglePtr = std::make_unique<Quadrangle>(secondConstructorQuadrangle);
    }
}
