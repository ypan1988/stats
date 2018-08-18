#ifndef STATSLABS_STATS_LM_H_
#define STATSLABS_STATS_LM_H_

struct lmfit {
 public:
  lmfit(const Matrix<double, 2> &x, const Matrix<double, 1> &y)
      : x_(x), y_(y) {
    init();
  }

  lmfit(const Matrix<double, 2> &x, const Matrix<double, 2> &y)
      : x_(x), y_(y) {
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

#endif // STATSLABS_STATS_LM_H_
