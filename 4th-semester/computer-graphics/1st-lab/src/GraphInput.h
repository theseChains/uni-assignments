#ifndef GRAPH_INPUT_H
#define GRAPH_INPUT_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <array>

void handleFirstOrFourthGraphInput(GLFWwindow* window, std::array<float, 4>& constants);
void handleSecondOrThirdGraphInput(GLFWwindow* window, std::array<float, 4>& constants);
void handleFifthGraphInput(GLFWwindow* window, std::array<float, 4>& constants);
void handleSixthGraphInput(GLFWwindow* window, std::array<float, 4>& constants);

#endif
