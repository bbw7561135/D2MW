#include "ISRF.h"

namespace DRAGON {

double RadiationField_Delahaye10::get(const Vector3d& pos, const double& energy) const {
	double value = 0;
	for (auto i : BBs) {
		value += i.spectrum(energy);
	}
	return value;
}

double RadiationField_Vernetto16::get(const Vector3d& pos, const double& energy) const {
	auto r = pos.getR();
	return isrf.energy_density(r, pos.z, energy);
}

} /* namespace DRAGON */
