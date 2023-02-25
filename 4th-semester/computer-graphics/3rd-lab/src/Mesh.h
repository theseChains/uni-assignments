#ifndef MESH_H
#define MESH_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

class Mesh
{
public:
	Mesh(float* vertices, int verticesSize, int* indices, int indicesSize, int numberOfVertices);
	Mesh(float* vertices, int verticesSize, int numberOfVertices, int offset);

	unsigned int getVAO() const;
	unsigned int getVBO() const;
	unsigned int getEBO() const;

private:
	unsigned int m_vao{};
	unsigned int m_vbo{};
	unsigned int m_ebo{};
};

#endif
