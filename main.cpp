#include "SerialExecutor.h"
#include <iostream>

using namespace facebook;
using namespace hermes;
// Folly header file required
int main() {
  std::cout << "Hello World!\n";
  std::array<int, 1024> values{};

  {
    inspector::detail::SerialExecutor executor("TestExecutor");

    for (int i = 0; i < values.size(); i++) {
      executor.add([=, &values]() { values[i] = i; });
    }
  }

  return 0;
}
