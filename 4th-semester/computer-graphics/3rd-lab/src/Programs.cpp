#include "Programs.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <numbers>

#include "Camera.h"
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
	Camera camera{ glm::vec3(0.0f, 0.0f, 3.0f) };
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

	const float ratio{ std::numbers::phi_v<float> };

	float icosahedron[]{
		// upper part
		0.0f, ratio, 1.0f,
		0.0f, ratio, -1.0f,
		ratio, 1.0f, 0.0f,

		0.0f, ratio, 1.0f,
		0.0f, ratio, -1.0f,
		-ratio, 1.0f, 0.0f,

		0.0f, ratio, 1.0f,
		ratio, 1.0f, 0.0f,
		1.0f, 0.0f, ratio,

		0.0f, ratio, 1.0f,
		-ratio, 1.0f, 0.0f,
		-1.0f, 0.0f, ratio,

		0.0f, ratio, -1.0f,
		ratio, 1.0f, 0.0f,
		1.0f, 0.0f, -ratio,

		0.0f, ratio, -1.0f,
		-ratio, 1.0f, 0.0f,
		-1.0f, 0.0f, -ratio,

		0.0f, ratio, 1.0f,
		1.0f, 0.0f, ratio,
		-1.0f, 0.0f, ratio,

		0.0f, ratio, -1.0f,
		1.0f, 0.0f, -ratio,
		-1.0f, 0.0f, -ratio,

		// middle 4 triangles
		ratio, 1.0f, 0.0f,
		1.0f, 0.0f, ratio,
		ratio, -1.0f, 0.0f,

		ratio, 1.0f, 0.0f,
		1.0f, 0.0f, -ratio,
		ratio, -1.0f, 0.0f,

		-ratio, 1.0f, 0.0f,
		-1.0f, 0.0f, ratio,
		-ratio, -1.0f, 0.0f,

		-ratio, 1.0f, 0.0f,
		-1.0f, 0.0f, -ratio,
		-ratio, -1.0f, 0.0f,

		// lower part
		0.0f, -ratio, 1.0f,
		0.0f, -ratio, -1.0f,
		ratio, -1.0f, 0.0f,

		0.0f, -ratio, 1.0f,
		0.0f, -ratio, -1.0f,
		-ratio, -1.0f, 0.0f,

		0.0f, -ratio, 1.0f,
		ratio, -1.0f, 0.0f,
		1.0f, 0.0f, ratio,

		0.0f, -ratio, 1.0f,
		-ratio, -1.0f, 0.0f,
		-1.0f, 0.0f, ratio,

		0.0f, -ratio, -1.0f,
		ratio, -1.0f, 0.0f,
		1.0f, 0.0f, -ratio,

		0.0f, -ratio, -1.0f,
		-ratio, -1.0f, 0.0f,
		-1.0f, 0.0f, -ratio,

		0.0f, -ratio, 1.0f,
		1.0f, 0.0f, ratio,
		-1.0f, 0.0f, ratio,

		0.0f, -ratio, -1.0f,
		1.0f, 0.0f, -ratio,
		-1.0f, 0.0f, -ratio,
	};

	Mesh cube{ icosahedron, sizeof(icosahedron), 3 };

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	while (!window.windowShouldClose())
	{
		float currentFrame{ static_cast<float>(glfwGetTime()) };
		config::deltaTime = currentFrame - config::lastFrame;
		config::lastFrame = currentFrame;

		window.processInput(config::camera, config::deltaTime);

		glClearColor(0.1f, 0.1f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		shader.use();
		glm::mat4 projection{ glm::mat4{ 1.0f } };
		projection = glm::perspective(glm::radians(config::camera.getZoom()),
			static_cast<float>(1200) / static_cast<float>(720), 0.1f, 100.0f);
		shader.setMat4("projection", projection);

		glm::mat4 view{ config::camera.getLookAtMatrix() };
		shader.setMat4("view", view);

		glm::mat4 model{ glm::mat4{ 1.0f } };
		shader.setMat4("model", model);

		glBindVertexArray(cube.getVAO());
		glDrawArrays(GL_TRIANGLES, 0, 60);

		window.swapBuffers();
		glfwPollEvents();
	}

	glfwTerminate();
}