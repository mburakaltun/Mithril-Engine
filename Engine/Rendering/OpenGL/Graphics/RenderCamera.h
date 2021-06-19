#pragma once
#include <glm/glm.hpp>
#include <iostream>
#include <math.h>

//Camera class. Handles view matrix logic and preocesses input.
enum class direction {
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT,
	UP,
	DOWN
};

class RenderCamera {
public:
	using vec3 = glm::vec3;
	using mat4 = glm::mat4;
	RenderCamera();
	RenderCamera(const vec3& Pos, const float yaw, const float pitch, const float fov, const float cameraSpeed);
	
	void SetPosition(float x, float y, float z);
	void SetHeading(float yaw, float pitch);

	mat4 GetViewMatrix() const;
	const mat4& GetProjectionMatrix() const;
	const vec3& GetPosition() const;
	
	float getFov() const;
	void SetFov(float fov);
	void SetProjectionParameters(float fov, float aspectRation, float nearPlane, float farPlane);
	void SetProjectionAspectRatio(float aspectRatio);
private:

	float m_movementSensitivity;
	float m_mouseSensitivity;
	float m_cameraYaw;
	float m_cameraPitch;

	float m_aspectRatio;
	float m_nearPlane;
	float m_farPlane;
	float m_fov;

	vec3 m_cameraPos;
	mutable vec3 m_cameraFront;
	mutable vec3 m_cameraRight;
	mutable vec3 m_cameraUp;
	vec3 m_worldUp;

	mat4 m_viewMatrix;
	mat4 m_projection;

	void updateCameraVectors() const; //updates up, right and front vectors
};