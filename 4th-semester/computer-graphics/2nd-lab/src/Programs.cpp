#include "Programs.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <algorithm>
#include <array>

#include "Mesh.h"
#include "Shader.h"
#include "Window.h"

void runFirstProgram()
{
	Window window{};
	Shader shader{ "../shaders/2dShader.vert", "../shaders/2dShader.frag" };

	float vertex[]{ -0.8f, -0.8f, 0.0f };
	Mesh dot{ vertex, sizeof(vertex), 1 };

	double currentFrame{ glfwGetTime() };
    double lastFrame{ currentFrame };
    double deltaTime{};

	glPointSize(5.0f);
	//glm::vec3 movementSpeed{ glm::vec3{ 0.01f } };
	glm::vec3 startingPosition{ -0.8f, -0.8f, 0.0f };
	glm::vec3 endPosition{ glm::vec3{ 0.0f } };
	while (!window.windowShouldClose())
	{
		currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		window.processInput();

		glClearColor(0.1f, 0.1f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		float alpha{ 0.1f * static_cast<float>(deltaTime) };
		std::clamp(alpha, 0.0f, 1.0f);
		glm::vec3 currentPosition{ startingPosition * alpha + (1 - alpha) * endPosition };

		glm::mat4 transform{ glm::mat4{ 1.0f } };
		transform = glm::translate(transform, glm::vec3{ alpha * 10.0f });
		transform = glm::rotate(transform, static_cast<float>(glfwGetTime()),
				glm::vec3{ 0.0f, 0.0f, 1.0f });

		shader.use();
		shader.setMat4("transform", transform);

		glBindVertexArray(dot.getVAO());
		glDrawArrays(GL_POINTS, 0, 1);

		window.swapBuffers();
		glfwPollEvents();
	}

	glfwTerminate();
}

void runSecondProgram()
{
	Window window{};
	Shader shader{ "../shaders/2dShader.vert", "../shaders/2dShader.frag" };

	float rectangleVertices[]{
		// first triangle
		 0.5f,  0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		-0.5f,  0.5f, 0.0f,
		// second triangle
		 0.5f, -0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f,
		-0.5f,  0.5f, 0.0f
	}; 

	Mesh rectangle{ rectangleVertices, sizeof(rectangleVertices), 3 };

	while (!window.windowShouldClose())
	{
		window.processInput();

		glClearColor(0.1f, 0.1f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		shader.use();

		glBindVertexArray(rectangle.getVAO());
		glDrawArrays(GL_TRIANGLES, 0, 6);

		window.swapBuffers();
		glfwPollEvents();
	}

	glfwTerminate();
}
