#ifndef INCLUDE_INTEGRATOR_H_
#define INCLUDE_INTEGRATOR_H_

#include <cmath>
#include <iostream>
#include <gsl/gsl_integration.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_monte.h>
#include <gsl/gsl_monte_miser.h>

#include "mks.h"
#include "galaxy.h"

#define NDIM 2

static double f(double *x, size_t dim, void * params) {
	DRAGON::Galaxy *Q = (DRAGON::Galaxy *) params;
	double f = x[0] * Q->get(Vector3d(x[0], 0, x[1]));
	return f;
}

class Int2D {
public:
	Int2D(DRAGON::Galaxy *Galaxy) :
			galaxy(Galaxy) {
		gsl_rng_env_setup();
		T = gsl_rng_default;
		r = gsl_rng_alloc(T);
	}
	double get_integral(double max_r, double max_z) {
		gsl_monte_miser_state *s = gsl_monte_miser_alloc(NDIM);
		gsl_monte_function G = { &f, NDIM, galaxy };
		double xl[NDIM] = { 0, -max_z };
		double xu[NDIM] = { max_r, max_z };
		gsl_monte_miser_integrate(&G, xl, xu, NDIM, calls, r, s, &res, &err);
		gsl_monte_miser_free(s);
		if (err / res > 0.1)
			std::cerr << "Error in numerical 2D integral is high : " << err / res << "\n";
		return res;
	}
	virtual ~Int2D() {
		gsl_rng_free(r);
	}
private:
	DRAGON::Galaxy *galaxy;
	double res = 0, err = 0;
	const gsl_rng_type *T;
	gsl_rng *r;
	size_t calls = 500000;
};

#endif /* INCLUDE_INTEGRATOR_H_ */
