#pragma once
#include <GLFW/glfw3.h>

struct SCREEN_DEFAULTS {
  static constexpr int START_X = 0;
  static constexpr int START_Y = 0;

  static constexpr int DIM_X = 800;
  static constexpr int DIM_Y = 800;

  static constexpr int GLFW_VER_MAJOR = 3;
  static constexpr int GLFW_VER_MINOR = 3;
  static constexpr int GLFW_PROFILE = GLFW_OPENGL_CORE_PROFILE;

  static constexpr bool GLFW_IS_OSX = true;

  static constexpr float CLEAR_COLOR_R = 0.0f;
  static constexpr float CLEAR_COLOR_G = 0.0f;
  static constexpr float CLEAR_COLOR_B = 0.0f;
  static constexpr float CLEAR_COLOR_A = 1.0f;
};
