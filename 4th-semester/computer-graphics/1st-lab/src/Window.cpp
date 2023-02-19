#include "Window.h"

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
			if (glfwGetKey(m_window, GLFW_KEY_H) == GLFW_PRESS)
			{
				constants[0] += 0.1f;
				makeFirstGraph(vertices, constants);
			}
			break;
		}
		case GraphType::second:
		{
			break;
		}
		case GraphType::third:
		{
			break;
		}
		case GraphType::fourth:
		{
			break;
		}
		case GraphType::fifth:
		{
			break;
		}
		case GraphType::sixth:
		{
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
