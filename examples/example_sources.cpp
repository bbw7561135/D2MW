/**
 * @file example_sources.cpp
 * @date 18 Jul 2017
 * @brief File containing an example for computing source profile.
 */

#include <iostream>
#include <iomanip>

#include "d2mw.h"

using namespace DRAGON;

/**
 * @example example_sources.cpp
 * In this example the number density of HI, H2 and HII (in \f$cm^{-3}\f$)
 * is computed as a function of the Galactocentric distance R (in kpc).
 *
 * @remark Options available for HI  : Ferriere2007,
 *
 * @see https://arxiv.org/abs/1607.07886
 */
int main() {
	D2MW mw;
	mw.set_sources("Ferriere2001");
	double rate = 1. / 30. / year;
	auto Q = mw.create_sources(rate);

	std::cout << "# r [kpc] - Q [cm-3] \n";
	std::cout << std::scientific << std::setprecision(3);
	for (double x = 0 * kpc; x < 20 * kpc; x += 0.1 * kpc) {
		auto pos = Vector3d(x, 0, 0);
		std::cout << x / kpc << " ";
		std::cout << Q->get(pos) * year * pow3(kpc) << " ";
		std::cout << "\n";
	}
	return 0;
}

