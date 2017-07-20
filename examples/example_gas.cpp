/**
 * @file example_gas.cpp
 * @date 18 Jul 2017
 * @brief File containing an example for computing gas models.
 */

#include <iostream>
#include <iomanip>

#include "d2mw.h"

using namespace DRAGON;

/**
 * @example example_gas.cpp
 * In this example the number density of HI, H2 and HII (in \f$cm^{-3}\f$)
 * is computed as a function of the Galactocentric distance R (in kpc).
 *
 * @remark Options available for HI: Ferriere2007,
 * @remark Options available for HII: Ferriere2007 (only bulge), Cordes1991, ...
 * @remark Options available for H2: Ferriere2007, Bronfmann1988
 *
 * @see https://arxiv.org/abs/1607.07886
 */
int main() {
	D2MW mw;
	mw.set_HI("Ferriere2007");
	mw.set_H2("Bronfmann1988");
	mw.set_XCO("Evoli2012");
	mw.set_HII("Cordes1991");

	auto HI = mw.create_HI();
	auto H2 = mw.create_H2();
	auto HII = mw.create_HII();
	auto XCO = mw.create_XCO();

	const double z = 0;
	std::cout << "# r [kpc] - n_HI [cm-3] - n_HII [cm-3] - n_H2 [cm-3] \n";
	std::cout << std::scientific << std::setprecision(3);
	for (double x = 0 * kpc; x < 20 * kpc; x += 0.1 * kpc) {
		auto pos = Vector3d(x, 0, z);
		std::cout << x / kpc << " ";
		std::cout << HI->get(pos) * cm3 << " ";
		std::cout << XCO->get(pos) * H2->get(pos) * cm3 << " ";
		std::cout << HII->get(pos) * cm3 << " ";
		std::cout << "\n";
	}
	return 0;
}
