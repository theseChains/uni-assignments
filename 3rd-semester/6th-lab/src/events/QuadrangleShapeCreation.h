#ifndef QUADRANGLE_SHAPE_CREATION_H
#define QUADRANGLE_SHAPE_CREATION_H

#include <array>
#include <memory>

#include "../util.h"

#include "../shapes/Quadrangle.h"

#include "ShapeCreationAuxiliary.h"

namespace Creation
{
    void checkForQuadrangleShapeCreation(std::array<std::unique_ptr<Quadrangle>, 3>& quadranglesToRender);

    void createAndShowDefaultQuadrangle(std::unique_ptr<Quadrangle>& newQuadranglePtr);
    Quadrangle createFirstConstructorQuadrangle();
    Quadrangle createSecondConstructorQuadrangle();

    void handleDefaultQuadrangleShapeCreation(std::unique_ptr<Quadrangle>& quadranglePtr);
    void handleFirstConstructorQuadrangleCreation(std::unique_ptr<Quadrangle>& quadranglePtr);
    void handleSecondConstructorQuadrangleCreation(std::unique_ptr<Quadrangle>& quadranglePtr);
}

#endif
