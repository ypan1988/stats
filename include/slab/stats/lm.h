//
// Copyright 2019 The Statslabs Authors.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

/// @file lm.h
/// @brief linear model

#ifndef SLAB_STATS_LM_H_
#define SLAB_STATS_LM_H_

_SLAB_BEGIN_NAMESPACE

struct lmfit {
public:
  lmfit(const Matrix<double, 2> &x, const Matrix<double, 1> &y) : x_(x), y_(y) {
    init();
  }

  lmfit(const Matrix<double, 2> &x, const Matrix<double, 2> &y) : x_(x), y_(y) {
    init();
  }

  Matrix<double, 2> coefficients() const { return y_.rows(0, x_.n_cols() - 1); }
  Matrix<double, 2> qr() const { return x_; }

private:
  Matrix<double, 2> x_;
  Matrix<double, 2> y_;

  void init() {
    int info = slab::lapack_gels('N', x_, y_);

    if (info > 0) {
      printf("The diagonal element %i of the triangular factor ", info);
      printf("of X is zero, so that X does not have full rank;\n");
      printf("the least squares solution could not be computed.\n");
    }
  }
};

_SLAB_END_NAMESPACE

#endif // SLAB_STATS_LM_H_
