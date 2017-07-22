#include "sources.h"

namespace DRAGON {

double Sources_Yusifov2004::get(const Vector3d& pos) const {
	double r = pos.getR();
	double exp_R = std::exp(-b * (r - sun.x) / (R_1 + sun.x));
	double radial = std::pow((r + R_1) / (sun.x + R_1), a);
	double exp_z = std::exp(-fabs(pos.z) / z_0);
	return radial * exp_R * exp_z;
}

double Sources_Ferriere01::get(const Vector3d& pos) const {
	double r =  pos.getR();
	double SnI = 7.3 * std::exp(-(r - sun.x) / 4.5 / kpc - fabs(pos.z) / 0.325 / kpc);
	double SnII = 1.0;
	if (r > 3.7 * kpc)
		SnII = 50.0 * std::exp(-(pow2(r) - pow2(sun.x)) / 46.24 / pow2(kpc));
	else {
		SnII = 177.5 * std::exp(-pow2((r - 3.7) / 2.1 / kpc));
	}
	SnII *= 0.79 * std::exp(-pow2(pos.z / 0.212 / kpc)) + 0.21 * std::exp(-pow2(pos.z / 0.636 / kpc));
	return SnI + SnII;
}

} /* namespace DRAGON */
