#include "GuiShapeModification.h"

void guiCheckForCircularShapeModification(DynamicArray<std::unique_ptr<Figure>>& shapesToRender)
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
