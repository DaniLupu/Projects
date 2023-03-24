#include "Camera.hpp"

namespace gps {

    //Camera constructor
    Camera::Camera(glm::vec3 cameraPosition, glm::vec3 cameraTarget, glm::vec3 cameraUp) {
        //TODO
        this->cameraPosition = cameraPosition;
        this->cameraTarget = cameraTarget;
        this->cameraUpDirection = cameraUp;

        this->cameraFrontDirection = glm::normalize(cameraTarget - cameraPosition);  // z-axis
        // corss product of two vectors get another perpenticular on both
        this->cameraRightDirection = glm::normalize(glm::cross(cameraFrontDirection, cameraUpDirection));

    }

    //return the view matrix, using the glm::lookAt() function
    glm::mat4 Camera::getViewMatrix() {
        //TODO
        //camera position, target position, the up direction 
        return glm::lookAt(cameraPosition, (cameraPosition + cameraFrontDirection), cameraUpDirection);
    }

    //update the camera internal parameters following a camera move event
    void Camera::move(MOVE_DIRECTION direction, float speed) {
        switch (direction)
        {
        case MOVE_FORWARD:
            cameraPosition += cameraFrontDirection * speed;
            break;
        case MOVE_BACKWARD:
            cameraPosition -= cameraFrontDirection * speed;
            break;
        case MOVE_RIGHT:
            cameraPosition += cameraRightDirection * speed;
            break;
        case MOVE_LEFT:
            cameraPosition -= cameraRightDirection * speed;
            break;
        }
    }

    void Camera::rotate(float pitch, float yaw) {
        glm::vec3 auxVector;
        auxVector.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
        auxVector.y = sin(glm::radians(pitch));
        auxVector.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
        cameraFrontDirection = glm::normalize(auxVector);
        cameraRightDirection = glm::normalize(glm::cross(cameraFrontDirection, cameraUpDirection));
    }

    void Camera::getCoord() {
        printf("Camera Position: x=%f y=%f z=%f\n", cameraPosition.x, cameraPosition.y, cameraPosition.z);
        printf("Camera Front: x=%f y=%f z=%f\n", cameraFrontDirection.x, cameraFrontDirection.y, cameraFrontDirection.z);
    }

    void Camera::goUp() {
        cameraPosition.y += 0.025;
    }

    void Camera::goDown() {
        cameraPosition.y -= 0.025;
    }

    void Camera::presentScene() {
        //cameraPosition.x = 0.280208f;
        //cameraPosition.y = 0.385293f;
        //cameraPosition.z = 1.510801f;
        cameraPosition.x = 0.050501f;
        cameraPosition.y = 0.385293f;
        cameraPosition.z = 1.499985f;
    }

    void Camera::goForwardPresentation() {
        if (cameraPosition.z >= -2.2f) {
            cameraPosition.z -= 0.01f;
            cameraPosition.x += 0.0008f;
        }
    }

    void Camera::goForwardFaster() {
        if (cameraPosition.z >= -2.2f) {
            cameraPosition.z -= 0.03f;
            cameraPosition.x += 0.0024f;
        }
    }

    void Camera::frontDirectionPresentation() {
        //cameraFrontDirection.x = 0.202752f;
        //cameraFrontDirection.y = -0.182236f;
        //cameraFrontDirection.z = -0.962124f;
        cameraFrontDirection.x = 0.117908f;
        cameraFrontDirection.y = -0.102793f;
        cameraFrontDirection.z = -0.975420f;
    }

    void Camera::rotateFrontDirection() {
        if (cameraPosition.z <= -0.050014f) {
            cameraFrontDirection.x += 0.04;
        }
    }

    void Camera::directionEndPresentation() {
        cameraFrontDirection.x = 0.010471f;
        cameraFrontDirection.y = -0.012217f;
        cameraFrontDirection.z = -0.999871f;
    }

    glm::vec3 Camera::getCameraPos() {
        return cameraPosition;
    }
}