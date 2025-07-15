#include "renderScreen.hpp"
#include <glad/gl.h>
#include "GLFW/glfw3.h"

renderScreen::renderScreen(const glfwVersionHints &ver, const Point2 &start,
                           const Point2 &dims, std::function<void()> f) {
  this->ver = ver;
  this->start = start;
  this->dims = dims;
  this->f = f;

  return;
}

void renderScreen::render() {
  this -> running = SCREEN_STATUS::RUNNING;
  initialise();
  setVersionHints();
  this->window = makeWindow();

  if (window == NULL) {
    debug::print("Failed to initialise Window!");
    stop();
    return;
  }

  glfwMakeContextCurrent(this->window);
  if (gladLoad() != 0) {
    debug::print("Failed to load glad functions!");
    stop();
    return;
  }

  setGlVeiwPortCallback();
  run();
}

void renderScreen::initialise() {
  if (!glfwInit()) {
    debug::print("GLFW init failed");
    stop();
    return;
  }

  return;
}

void renderScreen::setVersionHints() {
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, ver.major);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, ver.minor);
  glfwWindowHint(GLFW_OPENGL_PROFILE, ver.profile);

  return;
}

GLFWwindow *renderScreen::makeWindow() {
  GLFWwindow *window =
      glfwCreateWindow(dims.x, dims.y, "noTile GLFW Window", NULL, NULL);
  return window;
}

int renderScreen::gladLoad() { return !gladLoadGL(glfwGetProcAddress); }


void frame_buffer_size_callback(GLFWwindow *window, int width, int height) {
  glViewport(0, 0, width, height);
}

void renderScreen::setGlVeiwPortCallback() {
  glfwSetFramebufferSizeCallback(window, frame_buffer_size_callback);
}

void renderScreen::run() {
  while (!glfwWindowShouldClose(this->window)) {
    this->f();
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  stop();
  return;
}

void renderScreen::stop() {
  glfwTerminate();
  this -> running = SCREEN_STATUS::STOPPED;
  debug::print("Terminating session...");
  return;
}

renderScreen::~renderScreen() {
  if(this -> running != SCREEN_STATUS::STOPPED) {
    stop();
  }
}
