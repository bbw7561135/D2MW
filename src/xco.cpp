#include "xco.h"

namespace DRAGON {

double XCO_Arimoto96::get(const Vector3d& pos) const {
	const double r = pos.getR();
	return 0.9 * exp(r / 7.1 / kpc);
}

double XCO_Evoli12::get(const Vector3d& pos) const {
	return (pos.getR() < border_position) ? inner_value : outer_value;
}

double XCO_Ackermann10::get(const Vector3d& pos) const {
	const double r_kpc = pos.getR() / kpc;
	if (r_kpc < 2.0)
		return 0.4;
	else if (r_kpc < 5.5)
		return 1.5;
	else if (r_kpc < 7.5)
		return 1.5;
	else if (r_kpc < 10.0)
		return 0.75;
	else if (r_kpc < 12.0)
		return 5.;
	else if (r_kpc < 17.0)
		return 12.;
	else if (r_kpc < 19.0)
		return 60.;
	else
		return 200;
}

} /* namespace DRAGON */
