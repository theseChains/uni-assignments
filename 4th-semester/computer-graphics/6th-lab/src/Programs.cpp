#include "Programs.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#include <vector>

#include "Mesh.h"
#include "Shader.h"
#include "Texture.h"
#include "Window.h"

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

	// Setup Dear ImGui context
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;

	ImGui::StyleColorsDark();

	// Setup Platform/Renderer backends
	ImGui_ImplGlfw_InitForOpenGL(window.getWindow(), true);
	ImGui_ImplOpenGL3_Init("#version 330");

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
	bool showOnlyRedAndGreen{ false };
	bool invert{ false };
	bool renderImGui{ true };
	bool saveNow{ false };
	bool loaded{ false };

	while (!window.windowShouldClose())
	{
		if (saveNow)
		{
			saveImage(window.getWindow(), "../res/newImage.png");
			saveNow = false;
		}

		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		ImGui::Begin("menu");
		if (ImGui::Button("load image from file 'res/container.jpg'"))
			loaded = true;
		if (ImGui::Checkbox("flip image", &flip))
			shader.setBool("flip", flip);
        if (ImGui::Checkbox("show only red and green components", &showOnlyRedAndGreen))
			shader.setBool("showOnlyRedAndGreen", showOnlyRedAndGreen);
        if (ImGui::Checkbox("invert red and green components", &invert))
			shader.setBool("invert", invert);
		if (ImGui::Button("write to file 'res/newImage.png'"))
		{
			renderImGui = false;
			saveNow = true;
		}
		ImGui::End();

		window.processInput();

		glClearColor(0.1f, 0.1f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		if (loaded)
		{
			shader.use();

			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, containerTexture);

			glBindVertexArray(imageMesh.getVAO());
			glDrawArrays(GL_TRIANGLES, 0, 6);
		}

		if (renderImGui)
		{
			ImGui::Render();
			ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
		}
		else
		{
			ImGui::Render();
			renderImGui = true;
		}

		window.swapBuffers();
		glfwPollEvents();
	}

	glfwTerminate();
}
