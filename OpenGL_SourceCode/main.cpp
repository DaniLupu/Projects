//
//  main.cpp
//  OpenGL Advances Lighting
//
//  Created by CGIS on 28/11/16.
//  Copyright � 2016 CGIS. All rights reserved.
//

#define GLEW_STATIC
#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/matrix_inverse.hpp"
#include "glm/gtc/type_ptr.hpp"

#include "Shader.hpp"
#include "Model3D.hpp"
#include "Camera.hpp"
#include "SkyBox.hpp"

#include <iostream>

int glWindowWidth = 1800;
int glWindowHeight = 1000;
int retina_width, retina_height;
GLFWwindow* glWindow = NULL;

const unsigned int SHADOW_WIDTH = 2048;
const unsigned int SHADOW_HEIGHT = 2048;

glm::mat4 model;
GLuint modelLoc;
glm::mat4 view;
GLuint viewLoc;
glm::mat4 projection;
GLuint projectionLoc;
glm::mat3 normalMatrix;
GLuint normalMatrixLoc;
glm::mat4 lightRotation;

glm::vec3 lightDir;
GLuint lightDirLoc;
glm::vec3 lightColor;
GLuint lightColorLoc;

gps::Camera myCamera(
				glm::vec3(0.050501f, 0.385293f, 1.499985f),
				glm::vec3(0.0f, 0.0f, 0.0f),
				glm::vec3(0.0f, 1.0f, 0.0f));
float cameraSpeed = 0.05f;


bool mouseInit = true;
float yaw = -90.0f;
float pitch = 0.0f;
float lastX = 400;
float lastY = 300;
float zoom = 45.0f;


float gateTranslateY = 0.0f;
float gateTranslateZ = 0.0f;
float carTranslateY = 0.0f;
float carTranslateZ = 0.0f;
float wheelsAngle = 0.0f;
float lightTranslateY = 0.014030f;
float lightTranslateZ = 0.316356f;
float lightTranslateY2 = 0.011777f;
float lightTranslateZ2 = 0.316356f;
glm::vec3 headLight = glm::vec3(0.693480f, lightTranslateY, lightTranslateZ);
glm::vec3 headLight2 = glm::vec3(0.756687f, lightTranslateY2, lightTranslateZ2);
glm::vec3 streetLamp1 = glm::vec3(0.842325f, 0.053083f, -1.981996f);
glm::vec3 streetLamp2 = glm::vec3(0.236671f, 0.095939f, 0.048921f);
int presentationFlag = 0;
int shiftFlag = 0;
float lightIntensity = 0.0f;
int lightFlag = 0;
float fogIntensity = 0.2f;


bool pressedKeys[1024];
float angleY = 0.0f;
GLfloat lightAngle;

gps::Model3D lightCube;
gps::Model3D screenQuad;
gps::Model3D scene;
gps::Model3D car;
gps::Model3D frontWheels;
gps::Model3D backWheels;
gps::Model3D gate;
gps::Model3D streetLamp;

gps::Shader myCustomShader;
gps::Shader lightShader;
gps::Shader screenQuadShader;
gps::Shader depthMapShader;

gps::SkyBox mySkyBox;
gps::Shader skyboxShader;


std::vector<const GLchar*> faces;

GLuint shadowMapFBO;
GLuint depthMapTexture;

bool showDepthMap;

GLenum glCheckError_(const char *file, int line) {
	GLenum errorCode;
	while ((errorCode = glGetError()) != GL_NO_ERROR)
	{
		std::string error;
		switch (errorCode)
		{
		case GL_INVALID_ENUM:                  error = "INVALID_ENUM"; break;
		case GL_INVALID_VALUE:                 error = "INVALID_VALUE"; break;
		case GL_INVALID_OPERATION:             error = "INVALID_OPERATION"; break;
		case GL_STACK_OVERFLOW:                error = "STACK_OVERFLOW"; break;
		case GL_STACK_UNDERFLOW:               error = "STACK_UNDERFLOW"; break;
		case GL_OUT_OF_MEMORY:                 error = "OUT_OF_MEMORY"; break;
		case GL_INVALID_FRAMEBUFFER_OPERATION: error = "INVALID_FRAMEBUFFER_OPERATION"; break;
		}
		std::cout << error << " | " << file << " (" << line << ")" << std::endl;
	}
	return errorCode;
}
#define glCheckError() glCheckError_(__FILE__, __LINE__)

void windowResizeCallback(GLFWwindow* window, int width, int height) {
	fprintf(stdout, "window resized to width: %d , and height: %d\n", width, height);
	//TODO	
}

void keyboardCallback(GLFWwindow* window, int key, int scancode, int action, int mode) {
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);

	if (key == GLFW_KEY_M && action == GLFW_PRESS)
		showDepthMap = !showDepthMap;

	if (key >= 0 && key < 1024)
	{
		if (action == GLFW_PRESS)
			pressedKeys[key] = true;
		else if (action == GLFW_RELEASE)
			pressedKeys[key] = false;
	}

	if (pressedKeys[GLFW_KEY_X]) {
		myCamera.getCoord();
		printf("gatey=%f gatez=%f\n", gateTranslateY, gateTranslateZ);
		printf("cary=%f carz=%f\n", carTranslateY, carTranslateZ);
	}

	if (pressedKeys[GLFW_KEY_I]) {
		if (presentationFlag == 0)
			presentationFlag = 1;
		else if (presentationFlag == 1)
			presentationFlag = 0;

		if (presentationFlag == 0) {
			gateTranslateY = 0.0f;
			gateTranslateZ = 0.0f;
			carTranslateY = 0.0f;
			carTranslateZ = 0.0f;
			wheelsAngle = 0.0f;
			lightTranslateY = 0.014030f;
			lightTranslateZ = 0.316356f;
			lightTranslateY2 = 0.011777f;
			lightTranslateZ2 = 0.316356f;

			myCamera.presentScene();
			myCamera.directionEndPresentation();
		}
		else if (presentationFlag == 1) {
			gateTranslateY = 0.0f;
			gateTranslateZ = 0.0f;
			carTranslateY = 0.0f;
			carTranslateZ = 0.0f;
			wheelsAngle = 0.0f;
			lightTranslateY = 0.014030f;
			lightTranslateZ = 0.316356f;
			lightTranslateY2 = 0.011777f;
			lightTranslateZ2 = 0.316356f;

			myCamera.presentScene();
		}
	}

	if (pressedKeys[GLFW_KEY_LEFT_SHIFT]) {
		if (shiftFlag == 1)
			shiftFlag = 0;
		else if (shiftFlag == 0)
			shiftFlag = 1;

		if (shiftFlag == 1)
			cameraSpeed = 0.15f;
		else
			cameraSpeed = 0.05f;
	}

	if (pressedKeys[GLFW_KEY_K]) {
		if (lightFlag == 0)
			lightFlag = 1;
		else if (lightFlag == 1)
			lightFlag = 0;
	}
}

void mouseCallback(GLFWwindow* window, double xpos, double ypos) {
	if (mouseInit)
	{
		lastX = xpos;
		lastY = ypos;
		mouseInit = false;
	}

	float xoffset = xpos - lastX;
	float yoffset = lastY - ypos;
	lastX = xpos;
	lastY = ypos;

	float sensitivity = 0.1f;
	xoffset *= sensitivity;
	yoffset *= sensitivity;

	yaw += xoffset;
	pitch += yoffset;

	if (pitch > 89.0f)
		pitch = 89.0f;
	if (pitch < -89.0f)
		pitch = -89.0f;

	if(presentationFlag == 0)
		myCamera.rotate(pitch, yaw);
}

gps::MOVE_DIRECTION mouseScrollDirection;

void scrollCallback(GLFWwindow* window, double xoffset, double yoffset)
{
	zoom -= (float)yoffset; // amount scrolled vertically

	if (zoom < 1.0f)
		zoom = 1.0f;
	if (zoom > 45.0f)
		zoom = 45.0f;

	if (xoffset < yoffset)
		mouseScrollDirection = gps::MOVE_BACKWARD;
	else
		mouseScrollDirection = gps::MOVE_FORWARD;

	myCamera.move(mouseScrollDirection, 0.1f);
}

void processMovement()
{
	if (pressedKeys[GLFW_KEY_Q]) {
		angleY -= 1.0f;		
	}

	if (pressedKeys[GLFW_KEY_E]) {
		angleY += 1.0f;		
	}

	if (pressedKeys[GLFW_KEY_J]) {
		lightAngle -= 1.0f;		
	}

	if (pressedKeys[GLFW_KEY_L]) {
		lightAngle += 1.0f;
	}

	if (pressedKeys[GLFW_KEY_W]) {
		if(presentationFlag == 0)
			myCamera.move(gps::MOVE_FORWARD, cameraSpeed);		
	}

	if (pressedKeys[GLFW_KEY_S]) {
		if (presentationFlag == 0)
			myCamera.move(gps::MOVE_BACKWARD, cameraSpeed);		
	}

	if (pressedKeys[GLFW_KEY_A]) {
		if (presentationFlag == 0)
			myCamera.move(gps::MOVE_LEFT, cameraSpeed);		
	}

	if (pressedKeys[GLFW_KEY_D]) {
		if (presentationFlag == 0)
			myCamera.move(gps::MOVE_RIGHT, cameraSpeed);		
	}

	if (pressedKeys[GLFW_KEY_SPACE]) {
		if (presentationFlag == 0)
			myCamera.goUp();
	}

	if (pressedKeys[GLFW_KEY_LEFT_CONTROL]) {
		if (presentationFlag == 0)
			myCamera.goDown();
	}

	if (pressedKeys[GLFW_KEY_P]) {
		if (presentationFlag == 0) {
			/*if (gateTranslateY <= 0.4 && gateTranslateZ >= -0.108 && carTranslateY <= -0.076 && carTranslateZ <= -0.76) {
				gateTranslateY += 0.005f;
				gateTranslateZ -= 0.00135f;
			}*/

			if (carTranslateY >= -0.38 && carTranslateZ >= -3.799997) {
				wheelsAngle -= 0.25;
				carTranslateZ -= 0.02;
				carTranslateY -= 0.002;
			}
		}
	}

	if (pressedKeys[GLFW_KEY_O]) {
		if (presentationFlag == 0)
			wheelsAngle -= 0.25f;
	}

	if (pressedKeys[GLFW_KEY_R]) {
		if (presentationFlag == 0) {
			if (gateTranslateY > 0.0f && gateTranslateZ < 0.0) {
				gateTranslateY -= 0.01f;
				gateTranslateZ += 0.0027f;
			}

			if (carTranslateY <= -0.0f && carTranslateZ <= 0.0f) {
				wheelsAngle += 1.2;
				carTranslateZ += 0.08;
				carTranslateY += 0.008;
			}
		}
	}

	if (presentationFlag == 1) {
		fogIntensity = 0.2f;
		if (myCamera.getCameraPos().z <= -0.330802f && myCamera.getCameraPos().z >= -1.630013f)
			lightFlag = 1;
		else
			lightFlag = 0;

		if (shiftFlag == 0) {
			myCamera.goForwardPresentation();

			if (myCamera.getCameraPos().z <= 0.630802f) {
				if (gateTranslateY <= 0.4 && gateTranslateZ >= -0.108 && carTranslateY <= -0.076 && carTranslateZ <= -0.76) {
					gateTranslateY += 0.005f;
					gateTranslateZ -= 0.00135f;
				}

				if (carTranslateY >= -0.38 && carTranslateZ >= -3.799997) {
					wheelsAngle -= 0.25;
					carTranslateZ -= 0.02;
					carTranslateY -= 0.002;
				}
			}
		}
		else if (shiftFlag == 1) {
			myCamera.goForwardFaster();

			if (myCamera.getCameraPos().z <= 0.630802) {
				if (gateTranslateY <= 0.4 && gateTranslateZ >= -0.108 && carTranslateY <= -0.076 && carTranslateZ <= -0.76) {
					gateTranslateY += 0.015f;
					gateTranslateZ -= 0.00405f;
				}

				if (carTranslateY >= -0.38 && carTranslateZ >= -3.799997) {
					wheelsAngle -= 0.75;
					carTranslateZ -= 0.06;
					carTranslateY -= 0.006;
				}
			}
		}
			
		myCamera.frontDirectionPresentation();
		//myCamera.rotateFrontDirection();

		if (myCamera.getCameraPos().z <= -2.2f) {
			presentationFlag = 0;

			gateTranslateY = 0.0f;
			gateTranslateZ = 0.0f;
			carTranslateY = 0.0f;
			carTranslateZ = 0.0f;
			wheelsAngle = 0.0f;
			lightTranslateY = 0.014030f;
			lightTranslateZ = 0.316356f;
			lightTranslateY2 = 0.011777f;
			lightTranslateZ2 = 0.316356f;

			myCamera.presentScene();
			myCamera.directionEndPresentation();
		}
		//myCamera.move(gps::MOVE_FORWARD, cameraSpeed);
	}

	if (presentationFlag == 0) {
		if (myCamera.getCameraPos().z <= -1.171211f && myCamera.getCameraPos().z >= -3.659143f && 
			myCamera.getCameraPos().y <= 0.6f && myCamera.getCameraPos().y >= 0.0f &&
			myCamera.getCameraPos().x <= 1.103f && myCamera.getCameraPos().x >= 0.0f ||
			carTranslateY <= -0.076 && carTranslateZ <= -0.76) {
			if (gateTranslateY <= 0.4 && gateTranslateZ >= -0.108) {
				gateTranslateY += 0.005f;
				gateTranslateZ -= 0.00135f;
			}
		}
		else {
			if (gateTranslateY > 0.0f && gateTranslateZ < 0.0) {
				gateTranslateY -= 0.005f;
				gateTranslateZ += 0.00135f;
			}
		}
	}

	if (lightFlag == 1)
		lightIntensity = 0.3f;
	else if (lightFlag == 0)
		lightIntensity = 0.0f;

	if (glfwGetKey(glWindow, GLFW_KEY_1))
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
	}

	if (glfwGetKey(glWindow, GLFW_KEY_2))
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}

	if (glfwGetKey(glWindow, GLFW_KEY_3))
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	}

	if (glfwGetKey(glWindow, GLFW_KEY_B))
	{
		fogIntensity += 0.005f;
	}

	if (glfwGetKey(glWindow, GLFW_KEY_N))
	{
		fogIntensity -= 0.005f;
	}

	if (glfwGetKey(glWindow, GLFW_KEY_V))
	{
		fogIntensity = 0.2f;
	}
}

bool initOpenGLWindow()
{
	if (!glfwInit()) {
		fprintf(stderr, "ERROR: could not start GLFW3\n");
		return false;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_SRGB_CAPABLE, GLFW_TRUE);
	glfwWindowHint(GLFW_SAMPLES, 4);

	glWindow = glfwCreateWindow(glWindowWidth, glWindowHeight, "OpenGL Shader Example", NULL, NULL);
	if (!glWindow) {
		fprintf(stderr, "ERROR: could not open window with GLFW3\n");
		glfwTerminate();
		return false;
	}

	glfwSetWindowSizeCallback(glWindow, windowResizeCallback);
	glfwSetKeyCallback(glWindow, keyboardCallback);
	glfwSetCursorPosCallback(glWindow, mouseCallback);
	glfwSetScrollCallback(glWindow, scrollCallback);
	glfwSetInputMode(glWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	glfwMakeContextCurrent(glWindow);

	glfwSwapInterval(1);

	glewExperimental = GL_TRUE;
	glewInit();

	// get version info
	const GLubyte* renderer = glGetString(GL_RENDERER); // get renderer string
	const GLubyte* version = glGetString(GL_VERSION); // version as a string
	printf("Renderer: %s\n", renderer);
	printf("OpenGL version supported %s\n", version);

	//for RETINA display
	glfwGetFramebufferSize(glWindow, &retina_width, &retina_height);

	myCamera.directionEndPresentation();

	return true;
}

void initOpenGLState()
{
	glClearColor(0.3, 0.3, 0.3, 1.0);
	glViewport(0, 0, retina_width, retina_height);

	glEnable(GL_DEPTH_TEST); // enable depth-testing
	glDepthFunc(GL_LESS); // depth-testing interprets a smaller value as "closer"
	//glEnable(GL_CULL_FACE); // cull face
	glCullFace(GL_BACK); // cull back face
	glFrontFace(GL_CCW); // GL_CCW for counter clock-wise

	glEnable(GL_FRAMEBUFFER_SRGB);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void initObjects() {
	lightCube.LoadModel("objects/cube/cube.obj");
	screenQuad.LoadModel("objects/quad/quad.obj");
	scene.LoadModel("objects/pgscene/pg_scene.obj");
	car.LoadModel("objects/car/car.obj");
	frontWheels.LoadModel("objects/frontWheels/front_wheels.obj");
	backWheels.LoadModel("objects/backWheels/back_wheels.obj");
	gate.LoadModel("objects/gate/gate.obj");
	streetLamp.LoadModel("objects/streetLamp/streetLamp.obj");
}

void initShaders() {
	myCustomShader.loadShader("shaders/shaderStart.vert", "shaders/shaderStart.frag");
	myCustomShader.useShaderProgram();
	lightShader.loadShader("shaders/lightCube.vert", "shaders/lightCube.frag");
	lightShader.useShaderProgram();
	screenQuadShader.loadShader("shaders/screenQuad.vert", "shaders/screenQuad.frag");
	screenQuadShader.useShaderProgram();
	depthMapShader.loadShader("shaders/depthMap.vert", "shaders/depthMap.frag");
	depthMapShader.useShaderProgram();
}

void initUniforms() {
	myCustomShader.useShaderProgram();

	model = glm::mat4(1.0f);
	modelLoc = glGetUniformLocation(myCustomShader.shaderProgram, "model");
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

	view = myCamera.getViewMatrix();
	viewLoc = glGetUniformLocation(myCustomShader.shaderProgram, "view");
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
	
	normalMatrix = glm::mat3(glm::inverseTranspose(view*model));
	normalMatrixLoc = glGetUniformLocation(myCustomShader.shaderProgram, "normalMatrix");
	glUniformMatrix3fv(normalMatrixLoc, 1, GL_FALSE, glm::value_ptr(normalMatrix));
	
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	projectionLoc = glGetUniformLocation(myCustomShader.shaderProgram, "projection");
	glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));

	//set the light direction (direction towards the light)
	lightDir = glm::vec3(0.0f, 1.0f, 1.0f);
	lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	lightDirLoc = glGetUniformLocation(myCustomShader.shaderProgram, "lightDir");	
	glUniform3fv(lightDirLoc, 1, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));

	//set light color
	lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //white light
	lightColorLoc = glGetUniformLocation(myCustomShader.shaderProgram, "lightColor");
	glUniform3fv(lightColorLoc, 1, glm::value_ptr(lightColor));

	lightShader.useShaderProgram();
	glUniformMatrix4fv(glGetUniformLocation(lightShader.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));

}

void initFBO() {
	//TODO - Create the FBO, the depth texture and attach the depth texture to the FBO
	//generate FBO ID
	glGenFramebuffers(1, &shadowMapFBO);
	
	//create depth texture for FBO
	glGenTextures(1, &depthMapTexture);
	glBindTexture(GL_TEXTURE_2D, depthMapTexture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT,
		SHADOW_WIDTH, SHADOW_HEIGHT, 0, GL_DEPTH_COMPONENT, GL_FLOAT, NULL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	float borderColor[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);

	//attach texture to FBO
	glBindFramebuffer(GL_FRAMEBUFFER, shadowMapFBO);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, depthMapTexture,
		0);

	glDrawBuffer(GL_NONE);
	glReadBuffer(GL_NONE);

	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

glm::mat4 computeLightSpaceTrMatrix() {
	//TODO - Return the light-space transformation matrix

	glm::mat4 lightView = glm::lookAt(lightDir, glm::vec3(0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	const GLfloat near_plane = 0.1f, far_plane = 5.0f;
	glm::mat4 lightProjection = glm::ortho(-1.0f, 1.0f, -1.0f, 1.0f, near_plane, far_plane);
	
	glm::mat4 lightSpaceTrMatrix = lightProjection * lightView;

	return lightSpaceTrMatrix;
}

void drawObjects(gps::Shader shader, bool depthPass) {
		
	shader.useShaderProgram();
	
	model = glm::rotate(glm::mat4(1.0f), glm::radians(angleY), glm::vec3(0.0f, 1.0f, 0.0f));
	glUniformMatrix4fv(glGetUniformLocation(shader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));

	// do not send the normal matrix if we are rendering in the depth map
	if (!depthPass) {
		normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
		glUniformMatrix3fv(normalMatrixLoc, 1, GL_FALSE, glm::value_ptr(normalMatrix));
	}

	model = glm::mat4(1.0f);
	model = glm::translate(model, glm::vec3(carTranslateY, 0.0f, carTranslateZ));
	glUniform3fv(glGetUniformLocation(myCustomShader.shaderProgram, "headLight"), 1, glm::value_ptr(glm::vec3(view * model * glm::vec4(headLight, 1.0f))));

	model = glm::mat4(1.0f);
	model = glm::translate(model, glm::vec3(carTranslateY, 0.0f, carTranslateZ));
	glUniform3fv(glGetUniformLocation(myCustomShader.shaderProgram, "headLight2"), 1, glm::value_ptr(glm::vec3(view * model * glm::vec4(headLight2, 1.0f))));

	glUniform1f(glGetUniformLocation(myCustomShader.shaderProgram, "lightIntensity"), lightIntensity);
	glUniform1f(glGetUniformLocation(myCustomShader.shaderProgram, "fogIntensity"), fogIntensity);

	scene.Draw(shader);
	streetLamp.Draw(shader);

	model = glm::mat4(1.0f);
	glUniform3fv(glGetUniformLocation(myCustomShader.shaderProgram, "streetLamp1"), 1, glm::value_ptr(glm::vec3(view * model * glm::vec4(streetLamp1, 1.0f))));
	glUniform3fv(glGetUniformLocation(myCustomShader.shaderProgram, "streetLamp2"), 1, glm::value_ptr(glm::vec3(view * model * glm::vec4(streetLamp2, 1.0f))));

	//car.Draw(shader);
	//wheels.Draw(shader);
	//gate.Draw(shader);

	model = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, -1.0f, 0.0f));
	model = glm::scale(model, glm::vec3(0.5f));
	glUniformMatrix4fv(glGetUniformLocation(shader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));

	// do not send the normal matrix if we are rendering in the depth map
	if (!depthPass) {
		normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
		glUniformMatrix3fv(normalMatrixLoc, 1, GL_FALSE, glm::value_ptr(normalMatrix));
	}

}

void renderScene() {

	// depth maps creation pass
	//TODO - Send the light-space transformation matrix to the depth map creation shader and
	//		 render the scene in the depth map

	depthMapShader.useShaderProgram();

	glUniformMatrix4fv(glGetUniformLocation(depthMapShader.shaderProgram, "lightSpaceTrMatrix"),
		1,
		GL_FALSE,
		glm::value_ptr(computeLightSpaceTrMatrix()));

	glViewport(0, 0, SHADOW_WIDTH, SHADOW_HEIGHT);
	glBindFramebuffer(GL_FRAMEBUFFER, shadowMapFBO);
	glClear(GL_DEPTH_BUFFER_BIT);

	drawObjects(depthMapShader, false);

	glBindFramebuffer(GL_FRAMEBUFFER, 0);

	// render depth map on screen - toggled with the M key

	if (showDepthMap) {
		glViewport(0, 0, retina_width, retina_height);

		glClear(GL_COLOR_BUFFER_BIT);

		screenQuadShader.useShaderProgram();

		//bind the depth map
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, depthMapTexture);
		glUniform1i(glGetUniformLocation(screenQuadShader.shaderProgram, "depthMap"), 0);

		glDisable(GL_DEPTH_TEST);
		screenQuad.Draw(screenQuadShader);
		glEnable(GL_DEPTH_TEST);
	}
	else {

		// final scene rendering pass (with shadows)

		glViewport(0, 0, retina_width, retina_height);

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		myCustomShader.useShaderProgram();

		view = myCamera.getViewMatrix();
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
				
		lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
		glUniform3fv(lightDirLoc, 1, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));

		//bind the shadow map
		glActiveTexture(GL_TEXTURE3);
		glBindTexture(GL_TEXTURE_2D, depthMapTexture);
		glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "shadowMap"), 3);

		//depthMapShader.useShaderProgram();

		glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "lightSpaceTrMatrix"),
			1,
			GL_FALSE,
			glm::value_ptr(computeLightSpaceTrMatrix()));

		drawObjects(myCustomShader, false);

		//#########################################################################################
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(gateTranslateY, 0.0f, gateTranslateZ));
		glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));

		gate.Draw(myCustomShader);

		model = glm::mat4(1.0f);
		glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));



		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(carTranslateY, 0.0f, carTranslateZ));

		glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
		car.Draw(myCustomShader);

		model = glm::translate(model, glm::vec3(0.73729f, 0.0047f, 0.55f));
		model = glm::rotate(model, wheelsAngle, glm::vec3(0.10346f, -0.001016f, -0.01023f));
		model = glm::translate(model, glm::vec3(-0.73729f, -0.0047f, -0.55f));

		glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
		frontWheels.Draw(myCustomShader);

		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(carTranslateY, 0.0f, carTranslateZ));

		model = glm::translate(model, glm::vec3(0.753565, 0.0047f, 0.715f));
		model = glm::rotate(model, wheelsAngle, glm::vec3(0.10346f, -0.001016f, -0.01023f));
		model = glm::translate(model, glm::vec3(-0.753565f, -0.0047f, -0.715f));

		glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
		backWheels.Draw(myCustomShader);

		model = glm::mat4(1.0f);
		glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));

		//draw a white cube around the light

		lightShader.useShaderProgram();

		glUniformMatrix4fv(glGetUniformLocation(lightShader.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));


		model = lightRotation;
		model = glm::translate(model, 1.0f * lightDir);
		model = glm::scale(model, glm::vec3(0.001f, 0.001f, 0.001f));
		glUniformMatrix4fv(glGetUniformLocation(lightShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));

		lightCube.Draw(lightShader);


		mySkyBox.Load(faces);
		skyboxShader.loadShader("shaders/skyboxShader.vert", "shaders/skyboxShader.frag");
		skyboxShader.useShaderProgram();
		view = myCamera.getViewMatrix();
		glUniformMatrix4fv(glGetUniformLocation(skyboxShader.shaderProgram, "view"), 1, GL_FALSE,
		glm::value_ptr(view));

		projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
		glUniformMatrix4fv(glGetUniformLocation(skyboxShader.shaderProgram, "projection"), 1, GL_FALSE,
		glm::value_ptr(projection));

		mySkyBox.Draw(skyboxShader, view, projection);

	}
}

void cleanup() {
	glDeleteTextures(1,& depthMapTexture);
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	glDeleteFramebuffers(1, &shadowMapFBO);
	glfwDestroyWindow(glWindow);
	//close GL context and any other GLFW resources
	glfwTerminate();
}

int main(int argc, const char * argv[]) {

	if (!initOpenGLWindow()) {
		glfwTerminate();
		return 1;
	}

	initOpenGLState();
	initObjects();
	initShaders();
	initUniforms();
	initFBO();

	glCheckError();

	faces.push_back("skybox/right.tga");
	faces.push_back("skybox/left.tga");
	faces.push_back("skybox/top.tga");
	faces.push_back("skybox/bottom.tga");
	faces.push_back("skybox/back.tga");
	faces.push_back("skybox/front.tga");

	while (!glfwWindowShouldClose(glWindow)) {
		processMovement();
		renderScene();		

		glfwPollEvents();
		glfwSwapBuffers(glWindow);
	}

	cleanup();

	return 0;
}
