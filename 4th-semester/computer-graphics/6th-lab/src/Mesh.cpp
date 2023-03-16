#include "Mesh.h"

Mesh::Mesh(float* vertices, int verticesSize, int* indices, int indicesSize, int numberOfElements)
{
	glGenVertexArrays(1, &m_vao);
	glGenBuffers(1, &m_vbo);
	glGenBuffers(1, &m_ebo);

	glBindVertexArray(m_vao);

	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	glBufferData(GL_ARRAY_BUFFER, verticesSize, vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicesSize, indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, numberOfElements, GL_FLOAT, GL_FALSE,
			numberOfElements * sizeof(float), reinterpret_cast<void*>(0));
	glEnableVertexAttribArray(0);
}

Mesh::Mesh(float* vertices, int verticesSize, int numberOfVertices, int offset)
{
	glGenVertexArrays(1, &m_vao);
	glGenBuffers(1, &m_vbo);

	glBindVertexArray(m_vao);

	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	glBufferData(GL_ARRAY_BUFFER, verticesSize, vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, numberOfVertices, GL_FLOAT, GL_FALSE,
			offset * sizeof(float), reinterpret_cast<void*>(0));
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, numberOfVertices, GL_FLOAT, GL_FALSE,
			offset * sizeof(float), reinterpret_cast<void*>(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	if (offset == 8)
	{
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE,
				offset * sizeof(float), reinterpret_cast<void*>(6 * sizeof(float)));
		glEnableVertexAttribArray(2);
	}
}

unsigned int Mesh::getVAO() const
{
	return m_vao;
}

unsigned int Mesh::getVBO() const
{
	return m_vbo;
}

unsigned int Mesh::getEBO() const
{
	return m_ebo;
}
