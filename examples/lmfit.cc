#include "slab/matrix.h"
#include "slab/stats.h"

using namespace std;
using namespace slab;

int main() {
  slab::mat X = {
      {-1.1209000, -0.002846692},
      {-0.9897245,  1.008548567},
      {-1.3746970, -0.990279897},
      {-1.3556451,  1.131772277},
      { 1.9967553, -0.244928878},
      { 0.6958700,  1.186624919},
      { 0.7719680, -1.671536884}
  };

  slab::vec y = {-0.08199919, -1.831365, 0.3588666, 0.8916388, 0.4898011, 0.00001048653, 1.875451};

  slab::lmfit fit(X, y);

  slab::mat coefficients = fit.coefficients();
  coefficients.print("coefficients:");

  slab::mat qr = fit.qr();
  qr.print("qr:");

  return 0;
}