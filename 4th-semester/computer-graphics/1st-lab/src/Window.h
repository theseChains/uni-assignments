#ifndef WINDOW_H
#define WINDOW_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <array>

#include "Graphs.h"

namespace window
{
	inline constexpr int width{ 1366 };
	inline constexpr int height{ 768 };
}

class Window
{
public:
	Window();

	void processInput(GraphType graphType, std::array<float, 4>& constants, float* vertices,
			float* xVertices);
	bool windowShouldClose();
	void swapBuffers();
	GLFWwindow* getWindow() const;

private:
	GLFWwindow* m_window{};
};

#endif
