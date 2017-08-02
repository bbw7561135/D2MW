#ifndef MODELS_GRAVITATIONAL_POTENTIAL_H_
#define MODELS_GRAVITATIONAL_POTENTIAL_H_

#include "mathutils.h"

namespace Ferriere07 {

/**
 * Class to compute the galactic gravitational potential
 */
class GravitationalPotential {
public:
	/**
	 * Default constructor
	 */
	GravitationalPotential() {
	}

	/**
	 * Destructor
	 */
	virtual ~GravitationalPotential() {
	}

	/**
	 * Compute the gravitational potential
	 * @param r r-position in pc
	 * @param z z-position in pc
	 * @return gravitational potential in (km/s)^2
	 */
	double get(const double& r, const double& z) const;

protected:
	double C1 = 8.887e3;
	double C2 = 3.e3;
	double C3 = 0.325;
	double a1 = 6.5e3;
	double a2 = 0.7e3;
	double a3 = 12e3;
	double b1 = 0.26e3;
	double rh = 210e3;
};

} /* namespace Ferriere07 */

#endif /* MODELS_GRAVITATIONAL_POTENTIAL_H_ */
