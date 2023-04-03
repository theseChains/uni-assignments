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

	GraphType graphType{ GraphType::second };
	float constant{ 0.3f };

	float graphVertices[2000]{};
	makeGraph(graphVertices, graphType, constant);

	Mesh graph{ graphVertices, sizeof(graphVertices), 2 };

	while (!window.windowShouldClose())
	{
		window.processInput();

		glClearColor(0.1f, 0.1f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		shader.use();
		glBindVertexArray(graph.getVAO());
		glDrawArrays(GL_LINE_STRIP, 0, 1000);

		window.swapBuffers();
		glfwPollEvents();
	}

	glfwTerminate();
}
