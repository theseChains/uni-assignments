#include "Programs.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "stb_image_write.h"

#include <vector>

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
	Camera camera{ glm::vec3{ 0.0f, 0.0f, 1.0f } };
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

void saveImage(GLFWwindow* window, const char* filepath)
{
	int width{};
	int height{};
	glfwGetFramebufferSize(window, &width, &height);
	int numberOfChannels{ 3 };
	int stride{ numberOfChannels * width };
	stride += (stride % 4) ? (4 - stride % 4) : 0;
	int bufferSize = stride * height;
	std::vector<char> buffer(bufferSize);
	glPixelStorei(GL_PACK_ALIGNMENT, 4);
	glReadBuffer(GL_FRONT);
	glReadPixels(0, 0, width, height, GL_RGB, GL_UNSIGNED_BYTE, buffer.data());
	stbi_flip_vertically_on_write(true);
	stbi_write_png(filepath, width, height, numberOfChannels, buffer.data(), stride);
}

void runFirstProgram()
{
	Window window{ 1200, 720 };
	Shader shader{ "../shaders/shader.vert", "../shaders/shader.frag" };

	Texture container{};
	unsigned int containerTexture{ container.loadTexture("../res/container.jpg") };

	float imageVertices[]{
		-1.0f, -1.0f, 0.0f, 0.0f,
		 1.0f, -1.0f, 1.0f, 0.0f,
		-1.0f,  1.0f, 0.0f, 1.0f,

		 1.0f,  1.0f, 1.0f, 1.0f,
		 1.0f, -1.0f, 1.0f, 0.0f,
		-1.0f,  1.0f, 0.0f, 1.0f
	};

	Mesh imageMesh{ imageVertices, sizeof(imageVertices), 2, 4 };
	shader.setInt("texture", 0);

	bool flip{ false };
	bool fPressed{ false };
	bool showOnlyRedAndGreen{ false };
	bool rPressed{ false };
	bool invert{ false };
	bool iPressed{ false };

	while (!window.windowShouldClose())
	{
		float currentFrame{ static_cast<float>(glfwGetTime()) };
		config::deltaTime = currentFrame - config::lastFrame;
		config::lastFrame = currentFrame;

		window.processInput(config::camera, config::deltaTime);

		bool fCurrentlyPressed{ glfwGetKey(window.getWindow(), GLFW_KEY_F) == GLFW_PRESS };
		if (!fPressed && fCurrentlyPressed)
		{
			flip = !flip;
			shader.setBool("flip", flip);
		}
		fPressed = fCurrentlyPressed;

		bool rCurrentlyPressed{ glfwGetKey(window.getWindow(), GLFW_KEY_R) == GLFW_PRESS };
		if (!rPressed && rCurrentlyPressed)
		{
			showOnlyRedAndGreen = !showOnlyRedAndGreen;
			shader.setBool("showOnlyRedAndGreen", showOnlyRedAndGreen);
		}
		rPressed = rCurrentlyPressed;

		bool iCurrentlyPressed{ glfwGetKey(window.getWindow(), GLFW_KEY_I) == GLFW_PRESS };
		if (!iPressed && iCurrentlyPressed)
		{
			invert = !invert;
			shader.setBool("invert", invert);
		}
		iPressed = iCurrentlyPressed;

		glClearColor(0.1f, 0.1f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		shader.use();

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, containerTexture);

		glBindVertexArray(imageMesh.getVAO());
		glDrawArrays(GL_TRIANGLES, 0, 6);

		window.swapBuffers();
		glfwPollEvents();
	}

	glfwTerminate();
}
