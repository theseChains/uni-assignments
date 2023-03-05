#include "Camera.h"

#include <cmath>

void Camera::updateCameraVectors()
{
	// new front vector
	glm::vec3 front{};
	front.x = std::cos(glm::radians(m_yaw)) * std::cos(glm::radians(m_pitch));
	front.y = std::sin(glm::radians(m_pitch));
	front.z = std::sin(glm::radians(m_yaw)) * std::cos(glm::radians(m_pitch));
	m_front = glm::normalize(front);
	// new right and up vectors
	m_right = glm::normalize(glm::cross(m_front, m_worldUp));
	m_up = glm::normalize(glm::cross(m_right, m_front));
}

Camera::Camera(glm::vec3 position, glm::vec3 worldUp, float yaw, float pitch)
	: m_position{ position },
	m_front{ glm::vec3{ 0.0f, 0.0f, -1.0f } },
	m_worldUp{ worldUp },
	m_movementSpeed{ cfg::speed },
	m_sensitivity{ cfg::sensitivity },
	m_zoom{ cfg::zoom },
	m_yaw{ yaw },
	m_pitch{ pitch }
{
	// here we initialize the m_up and m_right vectors
	updateCameraVectors();
}

Camera::Camera(float xPos, float yPos, float zPos, float xUp, float yUp, float zUp, float yaw, float pitch)
	: m_position{ glm::vec3{ xPos, yPos, zPos } },
	m_front{ glm::vec3{ 0.0f, 0.0f, -1.0f } },
	m_worldUp{ glm::vec3{ xUp, yUp, zUp } },
	m_movementSpeed{ cfg::speed },
	m_sensitivity{ cfg::sensitivity },
	m_zoom{ cfg::zoom },
	m_yaw{ yaw },
	m_pitch{ pitch }
{
	updateCameraVectors();
}

glm::mat4 Camera::getLookAtMatrix()
{
	return glm::lookAt(m_position, m_position + m_front, m_up);
}

void Camera::processKeyboard(Movement direction, float deltaTime)
{
	float velocity{ m_movementSpeed * deltaTime };
	if (direction == Movement::forward)
		m_position += m_front * velocity;
	if (direction == Movement::backward)
		m_position -= m_front * velocity;
	if (direction == Movement::left)
		m_position -= m_right * velocity;
	if (direction == Movement::right)
		m_position += m_right * velocity;
}

void Camera::processMouseMovement(float xOffset, float yOffset, bool constraintPitch)
{
	xOffset *= cfg::sensitivity;
	yOffset *= cfg::sensitivity;

	m_yaw += xOffset;
	m_pitch += yOffset;

	if (constraintPitch)
	{
		if (m_pitch > 89.0f)
			m_pitch = 89.0f;
		if (m_pitch < -89.0f)
			m_pitch = -89.0f;
	}

	// update camera vectors using euler angles
	updateCameraVectors();
}

void Camera::processMouseScroll(float yOffset)
{
	m_zoom -= yOffset;
	if (m_zoom > 90.0f)
		m_zoom = 90.0f;
	if (m_zoom < 1.0f)
		m_zoom = 1.0f;
}

float Camera::getZoom() const
{
	return m_zoom;
}

float Camera::getSensitivity() const
{
	return m_sensitivity;
}

glm::vec3 Camera::getPosition() const
{
	return m_position;
}

glm::vec3 Camera::getFront() const
{
	return m_front;
}

void Camera::changeYaw(float changeValue)
{
	m_yaw += changeValue;
}
