#include "Programs.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Camera.h"
#include "Coordinates.h"
#include "Mesh.h"
#include "Shader.h"
#include "Texture.h"
#include "Window.h"

namespace config
{
	float deltaTime{ 0.0f }; // time between current frame and last frame
	float lastFrame{ 0.0f };
	float lastX{ 1200 / 2.0f };
	float lastY{ 720 / 2.0f };
	bool firstMouse{ true };
	Camera camera{ glm::vec3{ 0.0f, 2.0f, 4.0f } };
	glm::vec3 lightPos{ 1.0f, 2.0f, 2.0f };
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
	glEnable(GL_CULL_FACE);

	Texture metal{};
	unsigned int metalTexture{ metal.loadTexture("../res/metal.png") };

	Texture container{};
	unsigned int containerTexture{ container.loadTexture("../res/container.jpg") };

	Texture marble{};
	unsigned int marbleTexture{ marble.loadTexture("../res/marble.jpg") };

	Mesh firstPart{ coords::firstPart, sizeof(coords::firstPart), 3, 8 };
	Mesh secondPart{ coords::secondPart, sizeof(coords::secondPart), 3, 8 };
	Mesh thirdPart{ coords::thirdPart, sizeof(coords::thirdPart), 3, 8 };

	Mesh lightMesh{ coords::light, sizeof(coords::light), 3, 3 };

	bool rotateLight{ false };
	bool oPressed{ false };
	bool rotateTetrahedron{ false };
	bool lPressed{ false };
	bool fPressed{ false };
	bool bPressed{ false };

	shader.setInt("material.diffuse", 0);
	shader.setInt("material.specular", 0);

	glm::vec3 lightAmbient{ glm::vec3{ 1.0f } };
	glm::vec3 lightDiffuse{ glm::vec3{ 1.0f } };
	glm::vec3 lightSpecular{ glm::vec3{ 1.0f } };

	while (!window.windowShouldClose())
	{
		float currentFrame{ static_cast<float>(glfwGetTime()) };
		config::deltaTime = currentFrame - config::lastFrame;
		config::lastFrame = currentFrame;

		window.processInput(config::camera, config::deltaTime);

		bool oCurrentlyPressed{ glfwGetKey(window.getWindow(), GLFW_KEY_O) == GLFW_PRESS };
		if (!oPressed && oCurrentlyPressed)
			rotateTetrahedron = !rotateTetrahedron;
		oPressed = oCurrentlyPressed;

		bool lCurrentlyPressed{ glfwGetKey(window.getWindow(), GLFW_KEY_L) == GLFW_PRESS };
		if (!lPressed && lCurrentlyPressed)
			rotateLight = !rotateLight;
		lPressed = lCurrentlyPressed;

		bool fCurrentlyPressed{ glfwGetKey(window.getWindow(), GLFW_KEY_F) == GLFW_PRESS };
		if (!fPressed && fCurrentlyPressed)
		{
			lightAmbient = glm::vec3{ 0.1f };
			lightDiffuse = glm::vec3{ 0.8f };
			lightSpecular = glm::vec3{ 1.0f };
		}
		fPressed = fCurrentlyPressed;

		bool bCurrentlyPressed{ glfwGetKey(window.getWindow(), GLFW_KEY_B) == GLFW_PRESS };
		if (!bPressed && bCurrentlyPressed)
		{
			lightAmbient = glm::vec3{ 1.0f };
			lightDiffuse = glm::vec3{ 1.0f };
			lightSpecular = glm::vec3{ 1.0f };
		}
		bPressed = bCurrentlyPressed;

		glClearColor(0.1f, 0.1f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		shader.use();
		shader.setVec3("light.position", config::lightPos);
		shader.setVec3("lightColor", glm::vec3{ 1.0f });
		shader.setVec3("viewPos", config::camera.getPosition());

        shader.setVec3("light.ambient", lightAmbient);
        shader.setVec3("light.diffuse", lightDiffuse);
        shader.setVec3("light.specular", lightSpecular);

        // material properties
        shader.setVec3("material.ambient", 0.25f, 0.25f, 0.25f);
        shader.setVec3("material.diffuse", 0.4f, 0.4f, 0.4f);
        shader.setVec3("material.specular", 0.774597f, 0.774597f, 0.774597f);
        shader.setFloat("material.shininess", 76.8f);

		glm::mat4 projection{ glm::mat4{ 1.0f } };
		projection = glm::perspective(glm::radians(config::camera.getZoom()),
				static_cast<float>(1200) / static_cast<float>(720), 0.1f, 100.0f);
		shader.setMat4("projection", projection);

		glm::mat4 view{ config::camera.getLookAtMatrix() };
		shader.setMat4("view", view);

		glm::mat4 model{ glm::mat4{ 1.0f } };
		if (rotateTetrahedron)
		{
			model = glm::rotate(model, currentFrame * glm::radians(40.0f),
					glm::vec3{ 0.0f, 1.0f, 0.0f });
		}
		shader.setMat4("model", model);

		glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, metalTexture);

		glBindVertexArray(firstPart.getVAO());
		glDrawArrays(GL_TRIANGLES, 0, 12);

		glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, marbleTexture);

		glBindVertexArray(secondPart.getVAO());
		glDrawArrays(GL_TRIANGLES, 0, 6);

		glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, containerTexture);

		glBindVertexArray(thirdPart.getVAO());
		glDrawArrays(GL_TRIANGLES, 0, 6);

		lightShader.use();
		lightShader.setMat4("projection", projection);
		lightShader.setMat4("view", view);

		if (rotateLight)
		{
			float lightX{ static_cast<float>(sin(currentFrame)) };
			float lightY{ 2.0f };
			float lightZ{ 2.0f * static_cast<float>(cos(currentFrame)) };
			config::lightPos = { lightX, lightY, lightZ };
		}

		model = glm::mat4{ 1.0f };
		model = glm::translate(model, config::lightPos);
		model = glm::scale(model, glm::vec3{ 0.2f });
		lightShader.setMat4("model", model);

		glBindVertexArray(lightMesh.getVAO());
		glDrawArrays(GL_TRIANGLES, 0, 36);

		window.swapBuffers();
		glfwPollEvents();
	}

	glfwTerminate();
}
