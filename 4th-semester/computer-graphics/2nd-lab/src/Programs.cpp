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

	float vertex[]{ 0.0f, 0.0f, 0.0f };
	Mesh dot{ vertex, sizeof(vertex), 1 };

	glPointSize(5.0f);
	glm::vec3 currentTranslate{ -0.8f, 0.0f, 0.0f };
	float currentAngle{ 0.0f };
	while (!window.windowShouldClose())
	{
		window.processInput();

		glClearColor(0.1f, 0.1f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glm::mat4 transform{ glm::mat4{ 1.0f } };
		transform = glm::rotate(transform, currentAngle, glm::vec3{ 0.0f, 0.0f, 1.0f });
		transform = glm::translate(transform, currentTranslate);

		currentTranslate.x += 0.0025f;
		currentAngle += 0.05f;

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
	Window window{ 800, 800 };
	Shader shader{ "../shaders/2dShader.vert", "../shaders/2dShader.frag" };
	Shader triangleShader{ "../shaders/2dShader.vert", "../shaders/2dShader.frag" };

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

	float triangleVertices[]{
		 0.25f, 0.5f, 0.0f,
		-0.25f, 0.5f, 0.0f,
		 0.00f, 0.9f, 0.0f
	};

	Mesh rectangle{ rectangleVertices, sizeof(rectangleVertices), 3 };
	Mesh triangle{ triangleVertices, sizeof(triangleVertices), 3 };

	double currentFrame{ glfwGetTime() };
    double lastFrame{ currentFrame };
    double elapsedTime{ 0.0f };

	float currentRotationAngle{ 0.0f };

	while (!window.windowShouldClose())
	{
		currentFrame = glfwGetTime();
		elapsedTime += currentFrame - lastFrame;
		lastFrame = currentFrame;

		window.processInput();

		glClearColor(0.1f, 0.1f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glm::mat4 transform{ glm::mat4{ 1.0f } };

		shader.use();
		shader.setMat4("transform", transform);

		glBindVertexArray(rectangle.getVAO());
		glDrawArrays(GL_TRIANGLES, 0, 6);

		triangleShader.use();
		transform = glm::rotate(transform, glm::radians(currentRotationAngle),
				glm::vec3{ 0.0f, 0.0f, 1.0f });
		triangleShader.setMat4("transform", transform);

		if (elapsedTime >= 1.0f)
		{
			currentRotationAngle += 90.0f;
			elapsedTime = 0.0f;
		}
		if (currentRotationAngle >= 360.0f)
			currentRotationAngle = 0.0f;

		glBindVertexArray(triangle.getVAO());
		glDrawArrays(GL_TRIANGLES, 0, 3);

		window.swapBuffers();
		glfwPollEvents();
	}

	glfwTerminate();
}
