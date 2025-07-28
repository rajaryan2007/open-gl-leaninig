#include "Camera.h"

Camera::Camera(glm::vec3 position)
    : Position(position), Front(glm::vec3(0.0f, 0.0f, -1.0f)),
    Up(glm::vec3(0.0f, 1.0f, 0.0f)), Yaw(-90.0f), Pitch(0.0f), Fov(45.0f)
{
    updateCameraVectors();
}

glm::mat4 Camera::GetViewMatrix() {
    return glm::lookAt(Position, Position + Front, Up);
}

void Camera::ProcessKeyboard(float deltaTime, bool forward, bool backward, bool left, bool right) {
    float cameraSpeed = 2.5f * deltaTime;
    if (forward)
        Position += cameraSpeed * Front;
    if (backward)
        Position -= cameraSpeed * Front;
    if (left)
        Position -= glm::normalize(glm::cross(Front, Up)) * cameraSpeed;
    if (right)
        Position += glm::normalize(glm::cross(Front, Up)) * cameraSpeed;
}

void Camera::ProcessMouseMovement(float xoffset, float yoffset) {
    float sensitivity = 0.1f;
    xoffset *= sensitivity;
    yoffset *= sensitivity;

    Yaw += xoffset;
    Pitch += yoffset;

    if (Pitch > 89.0f) Pitch = 89.0f;
    if (Pitch < -89.0f) Pitch = -89.0f;

    updateCameraVectors();
}

void Camera::ProcessMouseScroll(float yoffset) {
    Fov -= yoffset;
    if (Fov < 1.0f) Fov = 1.0f;
    if (Fov > 45.0f) Fov = 45.0f;
}

void Camera::updateCameraVectors() {
    glm::vec3 front;
    front.x = cos(glm::radians(Yaw)) * cos(glm::radians(Pitch));
    front.y = sin(glm::radians(Pitch));
    front.z = sin(glm::radians(Yaw)) * cos(glm::radians(Pitch));
    Front = glm::normalize(front);
}
