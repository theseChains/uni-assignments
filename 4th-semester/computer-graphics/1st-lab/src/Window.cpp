#include "Window.h"
#include "GraphInput.h"

#include <iostream>

Window::Window()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	m_window = glfwCreateWindow(window::width, window::height, "openglStudy", nullptr, nullptr);
	if (m_window == nullptr)
	{
		std::cerr << "failed to create GLFW window\n";
		glfwTerminate();
	}
	glfwMakeContextCurrent(m_window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cerr << "failed to initialize GLAD\n";
		glfwTerminate();
	}

	glViewport(0, 0, window::width, window::height);

	//glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}

void Window::processInput(GraphType graphType, std::array<float, 4>& constants, float* vertices,
		[[maybe_unused]] float* xVertices = nullptr)
{
	if (glfwGetKey(m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(m_window, true);

	switch (graphType)
	{
		case GraphType::first:
		{
			handleFirstOrFourthGraphInput(m_window, constants);
			makeFirstGraph(vertices, constants);
			break;
		}
		case GraphType::second:
		{
			handleSecondOrThirdGraphInput(m_window, constants);
			makeSecondGraph(vertices, constants);
			break;
		}
		case GraphType::third:
		{
			handleSecondOrThirdGraphInput(m_window, constants);
			makeThirdGraph(vertices, constants);
			break;
		}
		case GraphType::fourth:
		{
			handleFirstOrFourthGraphInput(m_window, constants);
			makeFourthGraph(xVertices, vertices, constants);
			break;
		}
		case GraphType::fifth:
		{
			handleFifthGraphInput(m_window, constants);
			makeFifthGraph(xVertices, vertices, constants);
			break;
		}
		case GraphType::sixth:
		{
			handleSixthGraphInput(m_window, constants);
			makeSixthGraph(vertices, constants);
			break;
		}
	}
}

bool Window::windowShouldClose()
{
	return glfwWindowShouldClose(m_window);
}

void Window::swapBuffers()
{
	glfwSwapBuffers(m_window);
}

GLFWwindow* Window::getWindow() const
{
	return m_window;
}
