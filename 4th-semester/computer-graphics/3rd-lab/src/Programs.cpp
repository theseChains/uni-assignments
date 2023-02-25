#include "Programs.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <numbers>

#include "Camera.h"
#include "Coordinates.h"
#include "Mesh.h"
#include "Shader.h"
#include "Window.h"

namespace config
{
	float deltaTime{ 0.0f }; // time between current frame and last frame
	float lastFrame{ 0.0f };
	float lastX{ 1200 / 2.0f };
	float lastY{ 720 / 2.0f };
	bool firstMouse{ true };
	Camera camera{ glm::vec3(0.0f, 0.0f, 5.0f) };
}

void mouseCallback([[maybe_unused]] GLFWwindow* window, double xposIn, double yposIn)
{
	float xpos{ static_cast<float>(xposIn) };
	float ypos{ static_cast<float>(yposIn) };
	// initial set up
	if (config::firstMouse)
	{
		config::lastX = xpos;
		config::lastY = ypos;
		config::firstMouse = false;
	}
	// calculate coordinate offset between last frame and current frame
	float xOffset{ xpos - config::lastX };
	float yOffset{ config::lastY - ypos }; // reversed since y coords range from bottom to top

	config::lastX = xpos;
	config::lastY = ypos;

	config::camera.processMouseMovement(xOffset, yOffset);
}

void runFirstProgram()
{
	Window window{ 1200, 720 };
	glfwSetCursorPosCallback(window.getWindow(), mouseCallback);
	Shader shader{ "../shaders/shader.vert", "../shaders/shader.frag" };
	Shader lightShader{ "../shaders/lightCube.vert", "../shaders/lightCube.frag" };

    glEnable(GL_DEPTH_TEST);

	Mesh dodecahedronMesh{ coords::dodecahedron, sizeof(coords::dodecahedron), 3, 6 };
	Mesh light{ coords::light, sizeof(coords::light), coords::lightIndices,
			sizeof(coords::lightIndices), 3 };
	Mesh icosahedronMesh{ coords::icosahedron, sizeof(coords::icosahedron), 3, 6 };

	bool rotate{ false };
	bool renderIcosahedron{ true };

	while (!window.windowShouldClose())
	{
		float currentFrame{ static_cast<float>(glfwGetTime()) };
		config::deltaTime = currentFrame - config::lastFrame;
		config::lastFrame = currentFrame;

		window.processInput(config::camera, config::deltaTime, rotate, renderIcosahedron);

		glClearColor(0.1f, 0.1f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		shader.use();
		shader.setVec3("objectColor", glm::vec3{ 0.5f, 0.9f, 0.8f });
		shader.setVec3("lightPos", glm::vec3{ 1.2f, 1.0f, 3.0f });
		shader.setVec3("lightColor", 1.0f, 1.0f, 1.0f);
		shader.setVec3("viewPos", config::camera.getPosition());

		glm::mat4 projection{ glm::mat4{ 1.0f } };
		projection = glm::perspective(glm::radians(config::camera.getZoom()),
			static_cast<float>(1200) / static_cast<float>(720), 0.1f, 100.0f);
		shader.setMat4("projection", projection);

		glm::mat4 view{ config::camera.getLookAtMatrix() };
		shader.setMat4("view", view);

		glm::mat4 model{ glm::mat4{ 1.0f } };
		if (rotate)
		{
			model = glm::rotate(model, static_cast<float>(glfwGetTime()) * glm::radians(20.0f),
					glm::vec3{ 1.0f, 0.0f, 0.0f });
		}

		shader.setMat4("model", model);

		if (renderIcosahedron)
		{
			glBindVertexArray(icosahedronMesh.getVAO());
			glDrawArrays(GL_TRIANGLES, 0, 60);
		}
		else
		{
			glBindVertexArray(dodecahedronMesh.getVAO());
			glDrawArrays(GL_TRIANGLES, 0, 108);
		}

		lightShader.use();
		lightShader.setMat4("projection", projection);
		lightShader.setMat4("view", view);
		model = glm::mat4{ 1.0f };
		model = glm::translate(model, glm::vec3{ 1.2f, 1.0f, 3.0f });
		model = glm::scale(model, glm::vec3{ 0.2f });
		lightShader.setMat4("model", model);

		glBindVertexArray(light.getVAO());
		glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

		window.swapBuffers();
		glfwPollEvents();
	}

	glfwTerminate();
}
