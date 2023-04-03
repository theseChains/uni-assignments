#ifndef MESH_H
#define MESH_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

class Mesh
{
public:
	Mesh(float* vertices, int verticesSize, int numberOfVertices);

	unsigned int getVAO() const;
	unsigned int getVBO() const;

private:
	unsigned int m_vao{};
	unsigned int m_vbo{};
};

#endif
