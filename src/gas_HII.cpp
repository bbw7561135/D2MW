#include "gas_HII.h"

namespace DRAGON {

/*** HII_Ferriere07 ***/

double HII_Ferriere07::get(const Vector3d& pos) const {
	return gas.density(pos);
}

/*** HII_Cordes91 ***/

void HII_Cordes91::set_params() {
	fne1 = 0.025;
	H1 = 1.00;
	A1 = 20.0;
	fne2 = 0.200;
	H2 = 0.15;
	A2 = 2.0;
	R2 = 4.0;
}

double HII_Cordes91::get(const Vector3d& pos) const {
	double r = pos.getR();
	double ne1 = fne1 * exp(-fabs(pos.z) / H1) * exp(-pow(r / A1, 2.0));
	double ne2 = fne2 * exp(-fabs(pos.z) / H2) * exp(-pow((r - R2) / A2, 2.0));
	return ne1 + ne2;
}

} /* namespace DRAGON */
