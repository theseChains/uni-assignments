#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <array>

#include "Graphs.h"
#include "Mesh.h"
#include "Shader.h"
#include "Window.h"

int main()
{
	Window window{};
	Shader shader{ "../shaders/triangle.vert", "../shaders/triangle.frag" };

	GraphType graphType{ GraphType::sixth };
	std::array<float, 4> constants{};
	setUpConstants(graphType, constants);

	float graphVertices[2000]{};
	[[maybe_unused]] float xVertices[2000]{};
	makeGraph(graphVertices, graphType, constants, xVertices);

	Mesh firstGraph{ graphVertices, sizeof(graphVertices), 2 };
	[[maybe_unused]] Mesh secondGraph{ xVertices, sizeof(xVertices), 2 };

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
	return 0;
}
