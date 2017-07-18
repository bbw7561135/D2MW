#include "gas_H2.h"

namespace DRAGON {

/*** H2_Ferriere07 ***/

double H2_Ferriere07::get(const Vector3d& pos) const {
	return gas.density(pos);
}

/*** H2_Bronfman88 ***/

void H2_Bronfman88::init() {
	std::vector<double> v1 = { 0.00, 2.25, 2.75, 3.25, 3.75, 4.25, 4.75, 5.25, 5.75, 6.25,
			6.75, 7.25, 7.75, 8.25, 8.75, 9.25, 9.75, 10.25 };
	copy_vector_with_units(v1, R, kpc); // B88 / Table 3 / col 1

	std::vector<double> v2 = { 0.00, 1.5, 3.3, 5.8, 5.5, 8.4, 9.0, 9.6, 8.6, 9.1, 7.9,
			9.2, 7.7, 5.0, 3.6, 4.8, 1.7, 0.0 };
	copy_vector_with_units(v2, n0, 1. / cm3); // B88 / Table 3 / col 4

	std::vector<double> v3 = { 39, 39, 36, 0, -8, 1, -10, -1, -4, -19, -22, -14, -9, -4, 13, -4, -20, -20 };
	copy_vector_with_units(v3, Z0, pc); // B88 / Table 3 / col 7

	std::vector<double> v4 = { 77, 77, 80, 61, 65, 71, 72, 82, 83, 73, 63, 58, 72, 80, 66, 23, 147, 147 };
	copy_vector_with_units(v4, Zh, pc); // B88 / Table 3 / col 10
}

double H2_Bronfman88::get(const Vector3d& pos) const {
	double r = pos.getR();
	double value = 0.0;
	if (r < R.back()) {
		size_t i = std::lower_bound (R.begin(), R.end(), r) - R.begin();
		double n0_ = Interpol1D(r, R[i], R[i+1], n0[i], n0[i+1]);
		double Z0_ = Interpol1D(r, R[i], R[i+1], Z0[i], Z0[i+1]);
		double Zh_ = Interpol1D(r, R[i], R[i+1], Zh[i], Zh[i+1]);
		value = n0_ * std::exp(-std::log(2) * pow2((pos.z - Z0_) / Zh_));
	}
	return std::max(value, 0.);
}

} /* namespace DRAGON */
