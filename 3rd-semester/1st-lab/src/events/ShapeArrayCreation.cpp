#include "ShapeArrayCreation.h"
#include "../aliases.h"

template <typename ShapeType>
void ArrayCreation::checkForShapeArrayCreation(vector_of_shape_arrays<ShapeType>& arraysToRender)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
    {
        // i could probably split the create and show funciton in Creation namespace 
        // to 2 functions so that i can easily create random shapes here
        ShapeType firstShape{};
        ShapeType secondShape{};
        ShapeType thirdShape{};

        firstShape.show();
        secondShape.show();
        thirdShape.show();

        // i think i have to construct this in-place, otherwise std::construct_at fails
        arraysToRender.push_back(std::array<std::unique_ptr<ShapeType>, 3>{ 
            std::make_unique<ShapeType>(firstShape),
            std::make_unique<ShapeType>(secondShape), 
            std::make_unique<ShapeType>(thirdShape) 
        });
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::N))
    {
        if (!arraysToRender.empty())
        {
            arraysToRender.pop_back();
        }
    }
}

template void ArrayCreation::checkForShapeArrayCreation(vector_of_circle_arrays&);
template void ArrayCreation::checkForShapeArrayCreation(vector_of_line_arrays&);
