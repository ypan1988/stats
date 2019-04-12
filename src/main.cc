#include <iostream>

#include "slab/matrix.h"
#include "slab/stats.h"

int main() {
  std::cout << slab::rnorm(10, 0, 1) << std::endl;

  return 0;
}
