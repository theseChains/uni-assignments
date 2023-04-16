#include "Programs.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <array>

#include "Graphs.h"
#include "Mesh.h"
#include "Shader.h"
#include "Window.h"

void runFirstProgram()
{
	Window window{};
	Shader shader{ "../shaders/2dShader.vert", "../shaders/2dShader.frag" };

	GraphType graphType{ GraphType::first };
	float constant{ 0.3f };

	float firstPart[1000]{};
	float secondPart[1000]{};
	makeGraph(firstPart, secondPart, graphType, constant);

	Mesh first{ firstPart, sizeof(firstPart), 2 };
	Mesh second{ secondPart, sizeof(secondPart), 2 };

	while (!window.windowShouldClose())
	{
		window.processInput();

		glClearColor(0.1f, 0.1f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		shader.use();
		glBindVertexArray(first.getVAO());
		glDrawArrays(GL_LINE_STRIP, 0, 500);
		glBindVertexArray(second.getVAO());
		glDrawArrays(GL_LINE_STRIP, 0, 500);

		window.swapBuffers();
		glfwPollEvents();
	}

	glfwTerminate();
}
