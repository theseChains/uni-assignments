#ifndef TEXTURE_H
#define TEXTURE_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

class Texture
{
public:
	Texture() = default;

	unsigned int m_id{};

	void bind();

	unsigned int loadTexture(const char* path);
};

#endif
