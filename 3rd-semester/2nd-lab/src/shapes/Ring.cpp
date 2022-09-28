#include "Ring.h"

Ring::Ring(const Circle& outerCircle)
    : m_outerCircle{ outerCircle },
    m_innerCircle{ outerCircle }
{
    std::cout << "Ring object created\n";
}

Ring::Ring(const Circle& outerCircle, const Circle& innerCircle)
    : m_outerCircle{ outerCircle },
    m_innerCircle{ innerCircle }
{
    std::cout << "Ring object created\n";
}

Ring::OptCircles Ring::show(bool modifyVisibility)
{

}

void Ring::moveTo(float offsetX, float offsetY)
{

}

bool Ring::isShown() const
{
    return m_isShown;
}
