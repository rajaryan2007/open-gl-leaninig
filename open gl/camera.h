#pragma once
#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera {
public:
    glm::vec3 Position;
    glm::vec3 Front;
    glm::vec3 Up;
    float Yaw;
    float Pitch;
    float Fov;

    Camera(glm::vec3 position);

    glm::mat4 GetViewMatrix();
    void ProcessKeyboard(float deltaTime, bool forward, bool backward, bool left, bool right);
    void ProcessMouseMovement(float xoffset, float yoffset);
    void ProcessMouseScroll(float yoffset);

private:
    void updateCameraVectors();
};

#endif
