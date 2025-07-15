#include "comp.h"
#include <iostream>
#include "debug.hpp"
#include "renderScreen.hpp"

int main() {
  debug::print("Test debug log");
  std::cout << "Hello, world!" << std::endl;
  
  renderScreen renderer = renderScreen();
  renderer.render();

  return 0;
}
