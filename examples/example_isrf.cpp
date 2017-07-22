/**
 * @file example_isrf.cpp
 * @date 18 Jul 2017
 * @brief File containing an example for computing ISRF models.
 */

#include <iostream>
#include <iomanip>

#include "d2mw.h"

using namespace DRAGON;

/**
 * @example example_isrf.cpp
 * In this example a ISRF spectrum (in units) at Sun position
 * is computed as a function of frequency.
 *
 * @remark Options available for ISRF  : Ferriere2007,
 *
 * @see https://arxiv.org/abs/1607.07886
 */
int main() {
	D2MW mw;
	mw.set_ISRF("Delahaye2010");
	auto isrf = mw.create_ISRF();

	auto sun = Vector3d(8.5 * kpc, 0, 0);
	std::cout << "# frequency [Hz] - ISRF energy density [eV/cm3] \n";
	std::cout << std::scientific << std::setprecision(3);
	for (double nu = 1e10 * Hz; nu < 1e16 * Hz; nu *= 1.1) {
		auto epsilon = h_planck * nu;
		std::cout << nu / Hz << " ";
		std::cout << epsilon * epsilon * isrf->get(sun, epsilon) / (eV / cm3) << " ";
		std::cout << "\n";
	}
	return 0;
}



