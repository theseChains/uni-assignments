#include "GraphInput.h"

void handleFirstOrFourthGraphInput(GLFWwindow* window, std::array<float, 4>& constants)
{
	if (glfwGetKey(window, GLFW_KEY_H) == GLFW_PRESS)
		constants[0] += 0.1f;
	else if (glfwGetKey(window, GLFW_KEY_Y) == GLFW_PRESS)
		constants[0] -= 0.1f;
}

void handleSecondOrThirdGraphInput(GLFWwindow* window, std::array<float, 4>& constants)
{
	if (glfwGetKey(window, GLFW_KEY_H) == GLFW_PRESS)
		constants[0] += 0.1f;
	else if (glfwGetKey(window, GLFW_KEY_Y) == GLFW_PRESS)
		constants[0] -= 0.1f;
	else if (glfwGetKey(window, GLFW_KEY_J) == GLFW_PRESS)
		constants[1] += 0.1f;
	else if (glfwGetKey(window, GLFW_KEY_U) == GLFW_PRESS)
		constants[1] -= 0.1f;
}

void handleFifthGraphInput(GLFWwindow* window, std::array<float, 4>& constants)
{
	if (glfwGetKey(window, GLFW_KEY_H) == GLFW_PRESS)
		constants[0] += 0.1f;
	else if (glfwGetKey(window, GLFW_KEY_Y) == GLFW_PRESS)
		constants[0] -= 0.1f;
	else if (glfwGetKey(window, GLFW_KEY_J) == GLFW_PRESS)
		constants[1] += 0.1f;
	else if (glfwGetKey(window, GLFW_KEY_U) == GLFW_PRESS)
		constants[1] -= 0.1f;
	else if (glfwGetKey(window, GLFW_KEY_I) == GLFW_PRESS)
		constants[2] += 0.1f;
	else if (glfwGetKey(window, GLFW_KEY_K) == GLFW_PRESS)
		constants[2] -= 0.1f;
}

void handleSixthGraphInput(GLFWwindow* window, std::array<float, 4>& constants)
{
	if (glfwGetKey(window, GLFW_KEY_H) == GLFW_PRESS)
		constants[0] += 0.1f;
	else if (glfwGetKey(window, GLFW_KEY_Y) == GLFW_PRESS)
		constants[0] -= 0.1f;
	else if (glfwGetKey(window, GLFW_KEY_J) == GLFW_PRESS)
		constants[1] += 0.1f;
	else if (glfwGetKey(window, GLFW_KEY_U) == GLFW_PRESS)
		constants[1] -= 0.1f;
	else if (glfwGetKey(window, GLFW_KEY_I) == GLFW_PRESS)
		constants[2] += 0.1f;
	else if (glfwGetKey(window, GLFW_KEY_K) == GLFW_PRESS)
		constants[2] -= 0.1f;
	else if (glfwGetKey(window, GLFW_KEY_O) == GLFW_PRESS)
		constants[3] += 0.1f;
	else if (glfwGetKey(window, GLFW_KEY_L) == GLFW_PRESS)
		constants[3] -= 0.1f;
}
