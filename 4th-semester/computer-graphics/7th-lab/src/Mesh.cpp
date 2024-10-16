#include "Mesh.h"

Mesh::Mesh(float* vertices, int verticesSize, int numberOfElements)
{
	glGenVertexArrays(1, &m_vao);
	glGenBuffers(1, &m_vbo);

	glBindVertexArray(m_vao);
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);

	glBufferData(GL_ARRAY_BUFFER, verticesSize, vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, numberOfElements, GL_FLOAT, GL_FALSE,
			numberOfElements * sizeof(float), reinterpret_cast<void*>(0));
	glEnableVertexAttribArray(0);
}

unsigned int Mesh::getVAO() const
{
	return m_vao;
}

unsigned int Mesh::getVBO() const
{
	return m_vbo;
}
