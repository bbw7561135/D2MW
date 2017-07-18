#include <iostream>
#include <iomanip>

#include "d2mw.h"

using namespace DRAGON;

/* Get gas distribution */
int main() {
	D2MW mw;
	mw.set_HI("Ferriere2007");
	auto HI = mw.create_HI();
	mw.set_H2("Bronfmann1988");
	auto H2 = mw.create_H2();
	mw.set_HII("Cordes1991");
	auto HII = mw.create_HII();

	const double z = 0;
	std::cout << "# r [kpc] - n_HI [cm-3] - n_HII [cm-3] - n_H2 [cm-3] \n";
	std::cout << std::scientific << std::setprecision(3);
	for (double x = 0 * kpc; x < 20 * kpc; x += 0.1 * kpc) {
		auto pos = Vector3d(x, 0, z);
		std::cout << x / kpc << " ";
		std::cout << HI->get(pos) / (1. / cm3) << " ";
		std::cout << H2->get(pos) / (1. / cm3) << " ";
		std::cout << HII->get(pos) / (1. / cm3) << " ";
		std::cout << "\n";
	}
	return 0;
}
