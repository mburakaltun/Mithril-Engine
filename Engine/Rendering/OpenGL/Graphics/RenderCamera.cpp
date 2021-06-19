#include "RenderCamera.h"
#include <glm/gtc/matrix_transform.hpp>

RenderCamera::RenderCamera()
{
	m_fov = 60.0;
	m_aspectRatio = 1.0f;
	m_nearPlane = 0.1f;
	m_farPlane = 1000.0f;

	m_cameraYaw = -90.0f;
	m_cameraPitch = 0.0f;
	m_movementSensitivity = 3.5f;
	m_mouseSensitivity = 0.1f;

	m_cameraPos = vec3(0.0f, 0.0f, 0.0f);
	m_cameraUp = vec3(0.0f, 1.0f, 0.0f);
	m_worldUp = m_cameraUp;
}

void RenderCamera::SetPosition(float x, float y, float z)
{
	m_cameraPos.x = x;
	m_cameraPos.y = y;
	m_cameraPos.z = z;
}

void RenderCamera::SetHeading(float yaw, float pitch)
{
	m_cameraYaw = yaw;
	m_cameraPitch = pitch;
}

void RenderCamera::updateCameraVectors() const
{
	m_cameraFront.x = cos(glm::radians(m_cameraYaw)) * cos(glm::radians(m_cameraPitch));
	m_cameraFront.y = sin(glm::radians(m_cameraPitch));
	m_cameraFront.z = sin(glm::radians(m_cameraYaw)) * cos(glm::radians(m_cameraPitch));
	m_cameraFront = normalize(m_cameraFront); //up, right and front vectors must be normalized.
	// also re-calculate the Right and Up vector

	m_cameraRight = normalize(cross(m_cameraFront, m_worldUp));
	m_cameraUp = normalize(cross(m_cameraRight, m_cameraFront));
}

glm::mat4 RenderCamera::GetViewMatrix() const
{
	updateCameraVectors(); //updating front, up and right vectors accordingly
	return glm::lookAt(m_cameraPos, m_cameraPos + m_cameraFront, m_cameraUp);
}

const glm::mat4& RenderCamera::GetProjectionMatrix() const
{
	return m_projection;
}

const glm::vec3& RenderCamera::GetPosition() const
{
	return m_cameraPos;
}

void RenderCamera::SetFov(float fov)
{
	m_fov = fov;
}

float RenderCamera::getFov() const
{
	return m_fov;
}

void RenderCamera::SetProjectionParameters(float fov, float aspectRatio, float nearPlane, float farPlane)
{
	m_fov = fov;
	m_aspectRatio = aspectRatio;
	m_nearPlane = nearPlane;
	m_farPlane = farPlane;

	m_projection = glm::perspective(glm::radians(fov), aspectRatio, m_nearPlane, m_farPlane);
}

void RenderCamera::SetProjectionAspectRatio(float aspectRatio)
{
	m_aspectRatio = aspectRatio;
	m_projection = glm::perspective(glm::radians(m_fov), m_aspectRatio, m_nearPlane, m_farPlane);
}
