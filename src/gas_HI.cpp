#include "gas_HI.h"

namespace DRAGON {

double HI_Ferriere07::get(const Vector3d& pos) const {
	auto pos_pc = pos / pc;
	return gas.density(pos_pc.x, pos_pc.y, pos_pc.z) / cm3;
}

double HI_Nakanishi03::get(const Vector3d& pos) const {
	double r_kpc = pos.getR() / kpc;
	double exp_1 = std::exp(-r_kpc / 2.4);
	double exp_2 = std::exp(-pow2((r_kpc - 9.5) / 4.8));
	double densityOnPlane = n_0 * (0.6 * exp_1 + 0.24 * exp_2);
	double scaleHeight = h_0 * (116.3 + 19.3 * r_kpc + 4.1 * pow2(r_kpc) - 0.05 * pow3(r_kpc));
	return densityOnPlane * std::exp(-M_LN2 * pow2(pos.z / scaleHeight));
}

} /* namespace DRAGON */
