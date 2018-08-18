#include <cstdio>

#include "slab/matrix.h"
#include "slab/stats.h"

using namespace std;

int main() {
  double shape1, shape2, prob;

  printf("Enter first shape parameter: ");
  scanf("%lf", &shape1);

  printf("Enter second shape parameter: ");
  scanf("%lf", &shape2);

  printf("Enter probability level: ");
  scanf("%lf", &prob);

  printf("Critical value is %lf\n", slab::qbeta(prob, shape1, shape2, 1, 0));

  return 0;
}