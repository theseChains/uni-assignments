#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

enum class Movement
{
	forward,
	backward,
	left,
	right
};

namespace cfg
{
	inline constexpr float yaw{ -90.0f };
	inline constexpr float pitch{ 0.0f };
	inline constexpr float speed{ 2.5f };
	inline constexpr float sensitivity{ 0.1f };
	inline constexpr float zoom{ 75.0f };
}

class Camera
{
private:
	void updateCameraVectors();

public:
	Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), 
			glm::vec3 worldUp = glm::vec3(0.0f, 1.0f, 0.0f), float yaw = cfg::yaw, 
			float pitch = cfg::pitch);
	Camera(float xPos, float yPos, float zPos, float xUp, float yUp, float zUp, 
			float yaw = cfg::yaw, float pitch = cfg::pitch);

	glm::mat4 getLookAtMatrix();
	void processKeyboard(Movement direction, float deltaTime);
	void processMouseMovement(float xOffset, float yOffset, bool constraintPitch = true);
	void processMouseScroll(float yOffset);

	float getZoom() const;
	float getSensitivity() const;

	glm::vec3 getPosition() const;
	glm::vec3 getFront() const;

	void changeYaw(float changeValue);

private:
	glm::vec3 m_position{};
	glm::vec3 m_front{};
	glm::vec3 m_worldUp{};
	glm::vec3 m_up{};
	glm::vec3 m_right{};

	float m_movementSpeed{};
	float m_sensitivity{};
	float m_zoom{};
	float m_yaw{};
	float m_pitch{};
};

#endif
