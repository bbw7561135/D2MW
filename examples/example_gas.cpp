#include <iostream>
#include <iomanip>

#include "d2mw.h"

using namespace DRAGON;

/* Get gas distribution */
int main() {
	D2MW mw;
	mw.set_HI("Ferriere2007");
	auto HI = mw.create_HI();

	mw.set_H2("Ferriere2007");
	auto H2 = mw.create_H2();

	mw.set_HII("Ferriere2007");
	auto HII = mw.create_HII();

	const double z = 0;
	std::cout << std::scientific << std::setprecision(3);
	for (double x = 0 * kpc; x < 20 * kpc; x += 0.5 * kpc) {
		std::cout << x / kpc << " ";
		std::cout << HI->get(Vector3d(x, 0, z)) / (1. / cm3) << " ";
		std::cout << HII->get(Vector3d(x, 0, z)) / (1. / cm3) << " ";
		std::cout << H2->get(Vector3d(x, 0, z)) / (1. / cm3) << " ";
		std::cout << "\n";
	}
	return 0;
}
