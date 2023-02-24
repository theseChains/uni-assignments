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
	Shader lightShader{ "../shaders/lightCube.vert", "../shaders/lightCube.frag" };

	const float ratio{ std::numbers::phi_v<float> };

	float dodecahedron[]{
		// blue
		-(1.0f / ratio), 0.0f, ratio,	// 0
		-(1.0f / ratio), 0.0f, -ratio,	// 1
		(1.0f / ratio), 0.0f, -ratio,   // 2
		(1.0f / ratio), 0.0f, ratio,    // 3
		// green
		0.0f, -ratio, (1.0f / ratio),	// 4
		0.0f, ratio, (1.0f / ratio),	// 5
		0.0f, -ratio, -(1.0f / ratio),	// 6
		0.0f, ratio, -(1.0f / ratio),	// 7
		// red
		-ratio, (1.0f / ratio), 0.0f,	// 8
		-ratio, -(1.0f / ratio), 0.0f,	// 9
		ratio, (1.0f / ratio), 0.0f,	// 10
		ratio, -(1.0f / ratio), 0.0f,	// 11
		// orange
		-1.0f, -1.0f, -1.0f,			// 12
		1.0f, -1.0f, -1.0f,				// 13
		-1.0f, 1.0f, -1.0f,				// 14
		-1.0f, -1.0f, 1.0f,				// 15
		1.0f, 1.0f, -1.0f,				// 16
		-1.0f, 1.0f, 1.0f,				// 17
		1.0f, -1.0f, 1.0f,				// 18
		1.0f, 1.0f, 1.0f,				// 19
	};

	int dodecahedronIndices[]{
		3, 18, 11,
		3, 19, 10,
		3, 10, 11,

		3, 18, 4,
		0, 15, 4,
		0, 3, 4,
		
		3, 19, 5,
		0, 17, 5,
		5, 3, 0,

		0, 15, 9,
		0, 17, 8,
		0, 9, 8,

		18, 4, 6,
		18, 11, 13,
		6, 18, 13,

		15, 4, 6,
		15, 9, 12,
		12, 15, 6,

		17, 8, 14,
		17, 5, 7,
		14, 17, 7,

		19, 10, 16,
		19, 5, 7,
		7, 16, 19,

		11, 13, 2,
		11, 10, 16,
		2, 11, 16,

		8, 9, 12,
		8, 14, 1,
		8, 12, 1,

		6, 12, 1,
		6, 13, 2,
		1, 6, 2,

		7, 14, 1,
		7, 16, 2,
		7, 1, 2
	};

	float lightVertices[]{
		-1.0f, -1.0f, -1.0f,	// 0
		1.0f, -1.0f, -1.0f,		// 1
		-1.0f, 1.0f, -1.0f,		// 2
		-1.0f, -1.0f, 1.0f,		// 3
		1.0f, 1.0f, -1.0f,		// 4
		-1.0f, 1.0f, 1.0f,		// 5
		1.0f, -1.0f, 1.0f,		// 6
		1.0f, 1.0f, 1.0f		// 7
	};

	int lightIndices[]{
		0, 1, 2,
		1, 2, 4,
		0, 3, 1,
		3, 1, 6,
		0, 2, 5,
		0, 3, 5,
		3, 5, 6,
		5, 6, 7,
		2, 5, 7,
		7, 2, 4,
		1, 6, 7,
		1, 4, 7
	};

    glEnable(GL_DEPTH_TEST);

	Mesh mesh{ dodecahedron, sizeof(dodecahedron), dodecahedronIndices, sizeof(dodecahedronIndices), 3 };
	Mesh light{ lightVertices, sizeof(lightVertices), lightIndices, sizeof(lightIndices), 3 };
	Mesh icosahedronMesh{ coords::icosahedron, sizeof(coords::icosahedron), 3, 6 };

    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	while (!window.windowShouldClose())
	{
		float currentFrame{ static_cast<float>(glfwGetTime()) };
		config::deltaTime = currentFrame - config::lastFrame;
		config::lastFrame = currentFrame;

		window.processInput(config::camera, config::deltaTime);

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
		model = glm::rotate(model, static_cast<float>(glfwGetTime()) * glm::radians(20.0f),
				glm::vec3{ 0.5f, 1.0f, 0.0f });
		shader.setMat4("model", model);

		glBindVertexArray(icosahedronMesh.getVAO());
		glDrawArrays(GL_TRIANGLES, 0, 60);

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
