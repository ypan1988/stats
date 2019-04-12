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

/// @file distn.h
/// @brief distn

#ifndef SLAB_STATS_DISTN_H_
#define SLAB_STATS_DISTN_H_

_SLAB_BEGIN_NAMESPACE

Matrix<double, 1> rnorm(std::size_t n, double mu, double sigma) {
  Matrix<double, 1> res(n);
  for (std::size_t i = 0; i != n; ++i) {
    res(i) = rnorm(mu, sigma);
  }

  return res;
}

Matrix<double, 1> rnorm(std::size_t n, const Matrix<double, 1> &mu,
                        const Matrix<double, 1> &sigma) {
  Matrix<double, 1> res(n);
  for (std::size_t i = 0; i != n; ++i) {
    res(i) = rnorm(mu(i % mu.size()), sigma(i % sigma.size()));
  }

  return res;
}

_SLAB_END_NAMESPACE

#endif // SLAB_STATS_DISTN_H_