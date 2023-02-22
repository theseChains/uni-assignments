#include "Window.h"

#include <iostream>

Window::Window(int windowWidth, int windowHeight)
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	m_window = glfwCreateWindow(windowWidth, windowHeight, "openglStudy", nullptr, nullptr);
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

	glViewport(0, 0, windowWidth, windowHeight);

	m_width = windowWidth;
	m_height = windowHeight;

	//glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}

void Window::processInput()
{
	if (glfwGetKey(m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(m_window, true);
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
