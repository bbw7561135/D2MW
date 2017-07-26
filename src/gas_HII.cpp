#include "gas_HII.h"

namespace DRAGON {

double HII_Ferriere07::get(const Vector3d& pos) const {
	auto pos_pc = pos / pc;
	return gas.density(pos_pc.x, pos_pc.y, pos_pc.z);
}

void HII_Cordes91::set_params() {
	fne1 = 0.025 / cm3;
	H1 = 1.00 * kpc;
	A1 = 20.0 * kpc;
	fne2 = 0.200 / cm3;
	H2 = 0.15 * kpc;
	A2 = 2.0 * kpc;
	R2 = 4.0 * kpc;
}

double HII_Cordes91::get(const Vector3d& pos) const {
	double r = pos.getR();
	double ne1 = fne1 * exp(-fabs(pos.z) / H1) * exp(-pow(r / A1, 2.0));
	double ne2 = fne2 * exp(-fabs(pos.z) / H2) * exp(-pow((r - R2) / A2, 2.0));
	return ne1 + ne2;
}

double HII_YMW16::get(const Vector3d& pos) const {
	return ymw16_ne(pos.y / pc, pos.x / pc, pos.z / pc) / cm3;
}

} /* namespace DRAGON */
