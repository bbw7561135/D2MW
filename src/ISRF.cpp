#include "ISRF.h"

namespace DRAGON {

double RadiationField_Delahaye10::get(const Vector3d& pos, const double& frequency) const {
	double value = 0;
	for (auto i : BBs) {
		value += i.spectrum(frequency);
	}
	return value;
}

} /* namespace DRAGON */
