#pragma once

#include "debug.hpp"
#include <functional>
#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include "defaults.hpp"

typedef enum {
  STOPPED, 
  RUNNING, 
} SCREEN_STATUS;

struct Point2 {
  int x; int y;
};

struct glfwVersionHints {
  int major; int minor; int profile; int isOsX;
};

class renderScreen {
public:
  renderScreen(
               const glfwVersionHints& ver =glfwVersionHints{SCREEN_DEFAULTS::GLFW_VER_MAJOR, SCREEN_DEFAULTS::GLFW_VER_MINOR, SCREEN_DEFAULTS::GLFW_PROFILE, SCREEN_DEFAULTS::GLFW_IS_OSX}, 
               const Point2& start = Point2{SCREEN_DEFAULTS::START_X, SCREEN_DEFAULTS::START_Y}, 
               const Point2& dims = Point2{SCREEN_DEFAULTS::DIM_X, SCREEN_DEFAULTS::DIM_Y},
               std::function<void()> f = []{}
  );

  void render();

  ~renderScreen(); 

private:
  GLFWwindow* window;
  glfwVersionHints ver;
  Point2 start; 
  Point2 dims;
  std::function<void()> f;
  SCREEN_STATUS running = SCREEN_STATUS::STOPPED;

  void initialise();
  void setVersionHints();
  GLFWwindow* makeWindow();
  int gladLoad();
  void setGlVeiwPortCallback();
  void run();
  void stop();
};

