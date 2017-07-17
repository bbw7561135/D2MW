#include "d2mw.h"

using namespace DRAGON;

/* Get gas distribution */
int main() {
	D2MW mw;
	mw.set_HI("Moskalenko2002");
	//mw.set_HI("Nakanishi2003");
	auto HI = mw.create_HI();
	for (double x = 0 * kpc; x < 20 * kpc; x += 0.5 * kpc) {
		std::cout << x / kpc << " " << HI->get(Vector3d(x, 0, 0)) * cm3 << "\n";
	}
	return 0;
}
