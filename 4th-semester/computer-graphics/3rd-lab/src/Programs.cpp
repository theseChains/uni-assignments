#include "Programs.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Mesh.h"
#include "Shader.h"
#include "Window.h"

void runFirstProgram()
{
	Window window{ 1200, 720 };
	Shader shader{ "../shaders/2dShader.vert", "../shaders/2dShader.frag" };

	while (!window.windowShouldClose())
	{
		window.processInput();

		glClearColor(0.1f, 0.1f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		window.swapBuffers();
		glfwPollEvents();
	}

	glfwTerminate();
}
