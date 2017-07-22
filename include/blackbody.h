#ifndef INCLUDE_BLACKBODY_H_
#define INCLUDE_BLACKBODY_H_

#include <cmath>
#include "mks.h"

namespace DRAGON {

/*
 * Black body spectrum for ISRF
 */
class BlackBody {
public:
	/*
	 * Constructor for CMB
	 */
	BlackBody() :
			temperature(2.725 * K), norm_wrt_cmb(1) {
	}

	/*
	 * Constructor setting temperature and normalization
	 * @param T Blackbody Temperature
	 * @param norm normalization with respect to CMB
	 */
	BlackBody(const double& T, const double& norm) :
			temperature(T), norm_wrt_cmb(norm) {
	}

	/*
	 * Destructor
	 */
	~BlackBody() {
	}

	double getNormalizationToCmb() const {
		return norm_wrt_cmb;
	}

	void setNormalizationToCmb(double normalizationToCmb) {
		norm_wrt_cmb = normalizationToCmb;
	}

	double getTemperature() const {
		return temperature;
	}

	void setTemperature(double T) {
		temperature = T;
	}

	/*
	 * Get blackbody energy spectrum
	 * @param photon_energy Photon energy
	 * @return differential photon number density
	 */
	double spectrum(double photon_energy) {
		double value = norm_wrt_cmb;
		value *= 8.0 * M_PI * pow2(photon_energy);
		value /= pow3(h_c) * (std::exp(photon_energy / k_boltzmann / temperature) - 1.0);
		return value;
	}

private:
	double temperature;
	double norm_wrt_cmb;
};

} /* namespace DRAGON */

#endif /* INCLUDE_BLACKBODY_H_ */
