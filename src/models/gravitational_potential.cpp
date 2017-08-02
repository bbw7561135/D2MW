#include "models/gravitational_potential.h"

namespace Ferriere07 {

double GravitationalPotential::get(const double& r, const double& z) const {
	double P1 = C1 / std::sqrt(pow2(r) + pow2(a1 + std::sqrt(pow2(z) + pow2(b1))));
	double P2 = C2 / (a2 + std::sqrt(pow2(r) + pow2(z)));
	double L = std::sqrt(1. + (pow2(a3) + pow2(r) + pow2(z)) / pow2(rh));
	double P3 = -C3 * std::log((L - 1) / (L + 1));
	return -pow2(225.) * (P1 + P2 + P3);
}

} /* namespace Ferriere07 */



