#ifndef SLAB_STATS_MATHLIB_H_
#define SLAB_STATS_MATHLIB_H_

_SLAB_BEGIN_NAMESPACE

/* Random Number Generators */

using ::exp_rand;
using ::get_seed;
using ::norm_rand;
using ::set_seed;
using ::unif_rand;

/* Normal Distribution */

using ::dnorm;
using ::pnorm;
using ::pnorm_both; /* both tails */
using ::qnorm;
using ::rnorm;

/* Uniform Distribution */

using ::dunif;
using ::punif;
using ::qunif;
using ::runif;

/* Gamma Distribution */

using ::dgamma;
using ::pgamma;
using ::qgamma;
using ::rgamma;

using ::lgamma1p;
using ::log1pexp;
using ::log1pmx;
using ::logspace_add;
using ::logspace_sub;
using ::logspace_sum;

/* Beta Distribution */

using ::dbeta;
using ::pbeta;
using ::qbeta;
using ::rbeta;

/* Lognormal Distribution */

using ::dlnorm;
using ::plnorm;
using ::qlnorm;
using ::rlnorm;

/* Chi-squared Distribution */

using ::dchisq;
using ::pchisq;
using ::qchisq;
using ::rchisq;

/* Non-central Chi-squared Distribution */

using ::dnchisq;
using ::pnchisq;
using ::qnchisq;
using ::rnchisq;

/* F Distibution */

using ::df;
using ::pf;
using ::qf;
using ::rf;

/* Student t Distibution */

using ::dt;
using ::pt;
using ::qt;
using ::rt;

/* Binomial Distribution */

using ::dbinom;
using ::dbinom_raw;
using ::pbinom;
using ::qbinom;
using ::rbinom;

/* Multnomial Distribution */

using ::rmultinom;

/* Cauchy Distribution */

using ::dcauchy;
using ::pcauchy;
using ::qcauchy;
using ::rcauchy;

/* Exponential Distribution */

using ::dexp;
using ::pexp;
using ::qexp;
using ::rexp;

/* Geometric Distribution */

using ::dgeom;
using ::pgeom;
using ::qgeom;
using ::rgeom;

/* Hypergeometric Distibution */

using ::dhyper;
using ::phyper;
using ::qhyper;
using ::rhyper;

/* Negative Binomial Distribution */

using ::dnbinom;
using ::pnbinom;
using ::qnbinom;
using ::rnbinom;

using ::dnbinom_mu;
using ::pnbinom_mu;
using ::qnbinom_mu;
using ::rnbinom_mu;

/* Poisson Distribution */

using ::dpois;
using ::dpois_raw;
using ::ppois;
using ::qpois;
using ::rpois;

/* Weibull Distribution */

using ::dweibull;
using ::pweibull;
using ::qweibull;
using ::rweibull;

/* Logistic Distribution */

using ::dlogis;
using ::plogis;
using ::qlogis;
using ::rlogis;

/* Non-central Beta Distribution */

using ::dnbeta;
using ::pnbeta;
using ::qnbeta;
using ::rnbeta;

/* Non-central F Distribution */

using ::dnf;
using ::pnf;
using ::qnf;

/* Non-central Student t Distribution */

using ::dnt;
using ::pnt;
using ::qnt;

/* Studentized Range Distribution */

using ::ptukey;
using ::qtukey;

/* Wilcoxon Rank Sum Distribution */

using ::dwilcox;
using ::pwilcox;
using ::qwilcox;
using ::rwilcox;

/* Wilcoxon Signed Rank Distribution */

using ::dsignrank;
using ::psignrank;
using ::qsignrank;
using ::rsignrank;

/* Gamma and Related Functions */
using ::digamma;
using ::dpsifn;
using ::gammafn;
using ::lgammafn;
using ::lgammafn_sign;
using ::pentagamma;
using ::psigamma;
using ::tetragamma;
using ::trigamma;

using ::beta;
using ::lbeta;

using ::choose;
using ::lchoose;

/* Bessel Functions */

using ::bessel_i;
using ::bessel_i_ex;
using ::bessel_j;
using ::bessel_j_ex;
using ::bessel_k;
using ::bessel_k_ex;
using ::bessel_y;
using ::bessel_y_ex;

_SLAB_END_NAMESPACE

#endif // SLAB_STATS_MATHLIB_H_
