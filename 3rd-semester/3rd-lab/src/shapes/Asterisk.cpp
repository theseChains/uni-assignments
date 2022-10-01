#include "Asterisk.h"

Asterisk::Asterisk() : m_zeroDegreeLine{ Line{} }, m_sixtyDegreeLine{ Line{} },
    m_oneTwentyDegreeLine{ Line{} }, m_oneEightyDegreeLine{ Line{} },
    m_twoFortyDegreeLine{ Line{} }, m_threeHundredDegreeLine{ Line{} }
{
    std::cout << "Asterisk object created\n";
}

Asterisk::Asterisk(float mainPointX, float mainPointY, float length, const sf::Color& color)
    : m_zeroDegreeLine{ Line{ mainPointX, mainPointY, length, color } },
    m_sixtyDegreeLine{ Line{ mainPointX, mainPointY, length, color } },
    m_oneTwentyDegreeLine{ Line{ mainPointX, mainPointY, length, color } },
    m_oneEightyDegreeLine{ Line{ mainPointX, mainPointY, length, color } },
    m_twoFortyDegreeLine{ Line{ mainPointX, mainPointY, length, color } },
    m_threeHundredDegreeLine{ Line{ mainPointX, mainPointY, length, color } }
{
    std::cout << "Asterisk object created\n";
}

// placeholder black color to shorten the code a little bit
Asterisk::Asterisk(float mainPointX, float mainPointY, float length,
        const std::array<int, 4>& colorComponents)
    : m_zeroDegreeLine{ Line{ mainPointX, mainPointY, length, sf::Color::Black } },
    m_sixtyDegreeLine{ Line{ mainPointX, mainPointY, length, sf::Color::Black } },
    m_oneTwentyDegreeLine{ Line{ mainPointX, mainPointY, length, sf::Color::Black } },
    m_oneEightyDegreeLine{ Line{ mainPointX, mainPointY, length, sf::Color::Black } },
    m_twoFortyDegreeLine{ Line{ mainPointX, mainPointY, length, sf::Color::Black } },
    m_threeHundredDegreeLine{ Line{ mainPointX, mainPointY, length, sf::Color::Black } }
{
    // initialize the colors here instead
    initializeColorComponents(m_zeroDegreeLine, colorComponents);
    initializeColorComponents(m_sixtyDegreeLine, colorComponents);
    initializeColorComponents(m_oneTwentyDegreeLine, colorComponents);
    initializeColorComponents(m_oneEightyDegreeLine, colorComponents);
    initializeColorComponents(m_twoFortyDegreeLine, colorComponents);
    initializeColorComponents(m_threeHundredDegreeLine, colorComponents);

    std::cout << "Asterisk object created\n";
}

Asterisk::OptAsterisk Asterisk::show(bool modifyVisibility)
{
    if (modifyVisibility)
    {
        if (m_isShown)
        {
            m_isShown = false;

            return { std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt };
        }
        else
        {
            m_isShown = true;

            return OptAsterisk{ createRotatedLineSprite(0.0f), createRotatedLineSprite(60.0f),
                createRotatedLineSprite(120.0f), createRotatedLineSprite(180.0f),
                createRotatedLineSprite(240.0f), createRotatedLineSprite(300.0f) };
        }
    }
    // for rendering
    else
    {
        if (m_isShown)
        {
            return OptAsterisk{ createRotatedLineSprite(0.0f), createRotatedLineSprite(60.0f),
                createRotatedLineSprite(120.0f), createRotatedLineSprite(180.0f),
                createRotatedLineSprite(240.0f), createRotatedLineSprite(300.0f) };
        }
        else
        {
            return { std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt };
        }
    }
}

void Asterisk::moveTo(float offsetX, float offsetY)
{
    if (m_isShown)
    {
        show();

        // all lines have the same position but different rotation
        float lineX{ m_zeroDegreeLine.getPosition().getX() };
        float lineY{ m_zeroDegreeLine.getPosition().getY() };

        m_zeroDegreeLine.setPosition(lineX + offsetX, lineY + offsetY);
        m_sixtyDegreeLine.setPosition(lineX + offsetX, lineY + offsetY);
        m_oneTwentyDegreeLine.setPosition(lineX + offsetX, lineY + offsetY);
        m_oneEightyDegreeLine.setPosition(lineX + offsetX, lineY + offsetY);
        m_twoFortyDegreeLine.setPosition(lineX + offsetX, lineY + offsetY);
        m_threeHundredDegreeLine.setPosition(lineX + offsetX, lineY + offsetY);

        show();
    }
}

void Asterisk::rotate(float angleOffset)
{
    if (m_isShown)
    {
        show();

        m_currentRotationAngle += angleOffset;

        show();
    }
}

bool Asterisk::isShown() const
{
    return m_isShown;
}

sf::RectangleShape Asterisk::createRotatedLineSprite(float rotationAngle) const
{
    sf::RectangleShape rotatedLineSprite{};

    rotatedLineSprite.setPosition(m_zeroDegreeLine.getPosition().getX(),
            m_zeroDegreeLine.getPosition().getY());
    rotatedLineSprite.setFillColor(m_zeroDegreeLine.getColor());
    rotatedLineSprite.setSize(sf::Vector2f{ m_zeroDegreeLine.getLength(), util::lineWidth });
    rotatedLineSprite.setRotation(rotationAngle + m_currentRotationAngle);

    return rotatedLineSprite;
}

void Asterisk::initializeColorComponents(Line& line, const std::array<int, 4>& colorComponents)
{
    line.setColor(sf::Color(colorComponents[component::red], colorComponents[component::green],
            colorComponents[component::blue], colorComponents[component::alpha]));
}
