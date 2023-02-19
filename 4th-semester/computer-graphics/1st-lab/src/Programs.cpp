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

	GraphType graphType{ GraphType::sixth };
	std::array<float, 4> constants{};
	setUpConstants(graphType, constants);

	float graphVertices[2000]{};
	float xVertices[2000]{};
	makeGraph(graphVertices, graphType, constants, xVertices);

	Mesh firstGraph{ graphVertices, sizeof(graphVertices), 2 };
	Mesh secondGraph{ xVertices, sizeof(xVertices), 2 };

	while (!window.windowShouldClose())
	{
		window.processInput(graphType, constants, graphVertices, xVertices);
		firstGraph = Mesh{ graphVertices, sizeof(graphVertices), 2 };
		secondGraph = Mesh{ xVertices, sizeof(xVertices), 2 };

		glClearColor(0.1f, 0.1f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		shader.use();
		glBindVertexArray(firstGraph.getVAO());
		glDrawArrays(GL_LINE_STRIP, 0, 1000);
		glBindVertexArray(secondGraph.getVAO());
		glDrawArrays(GL_LINE_STRIP, 0, 1000);

		window.swapBuffers();
		glfwPollEvents();
	}

	glfwTerminate();
}

void runSecondProgram()
{
	Window window{};
	Shader shader{ "../shaders/2dShader.vert", "../shaders/2dShader.frag" };

	float vertices[]{
		-0.5f, -0.5f,
		 0.5f, -0.5f,
		 0.0f,  0.5f
	};

	Mesh triangle{ vertices, sizeof(vertices), 2 };

	int width{ 60 };
	int height{ 60 };

	while (!window.windowShouldClose())
	{
		glClearColor(0.1f, 0.1f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		shader.use();
		for (int x{ 0 }; x <= window::width; x += width)
		{
			for (int y{ 0 }; y <= window::height; y += height)
			{
				glViewport(x, y, width, height);
				glBindVertexArray(triangle.getVAO());
				glDrawArrays(GL_TRIANGLES, 0, 3);
			}
		}

		window.swapBuffers();
		glfwPollEvents();
	}

	glfwTerminate();
}
