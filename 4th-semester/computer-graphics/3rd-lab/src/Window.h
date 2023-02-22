#ifndef WINDOW_H
#define WINDOW_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Window
{
public:
	Window(int windowWidth, int windowHeight);

	void processInput();
	bool windowShouldClose();
	void swapBuffers();
	GLFWwindow* getWindow() const;

private:
	GLFWwindow* m_window{};

	int m_width{};
	int m_height{};
};

#endif
