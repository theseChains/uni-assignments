#include "GuiShapeModification.h"

void guiCheckForCircularShapeModification(std::array<std::unique_ptr<Figure>, 30>& shapesToRender)
{
    if (ImGui::Button("Enlarge circular shapes (O)"))
    {
        Modification::enlargeCircularShapes(shapesToRender);
    }
    if (ImGui::Button("Reduce circular shapes (I)"))
    {
        Modification::reduceCircularShapes(shapesToRender);
    }
}
