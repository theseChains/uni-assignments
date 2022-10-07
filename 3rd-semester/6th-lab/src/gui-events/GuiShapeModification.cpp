#include "GuiShapeModification.h"

void guiCheckForCircularShapeArrayModification(DynamicArray<std::unique_ptr<Figure>>& shapesToRender)
{
    if (ImGui::Button("Enlarge circular shapes (O)"))
    {
        Modification::enlargeCircularArrayShapes(shapesToRender);
    }
    if (ImGui::Button("Reduce circular shapes (I)"))
    {
        Modification::reduceCircularArrayShapes(shapesToRender);
    }
}

void guiCheckForCircularShapeListModification(DynamicList<std::unique_ptr<Figure>>& shapesToRender)
{
    if (ImGui::Button("Enlarge circular shapes (O)"))
    {
        Modification::enlargeCircularListShapes(shapesToRender);
    }
    if (ImGui::Button("Reduce circular shapes (I)"))
    {
        Modification::reduceCircularListShapes(shapesToRender);
    }
}
