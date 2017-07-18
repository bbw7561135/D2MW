#include "d2mw.h"

namespace DRAGON {

std::shared_ptr<Galaxy> D2MW::create_HI() {
	if (HI_model == "Ferriere2007") {
		HI = std::make_shared<HI_Ferriere07>();
	} else {
		assert(HI_model == "Ferriere07");
	}
	//std::cout << HI->description() << "\n";
	return HI->clone();
}

std::shared_ptr<Galaxy> D2MW::create_HII() {
	if (HII_model == "Ferriere2007") {
		HII = std::make_shared<HII_Ferriere07>();
	} else if (HII_model == "Cordes1991") {
		HII = std::make_shared<HII_Cordes91>();
	} else {
		assert(HII_model == "Ferriere2007");
	}
	//std::cout << HII->description() << "\n";
	return HII->clone();
}

std::shared_ptr<Galaxy> D2MW::create_H2() {
	if (H2_model == "Ferriere2007") {
		H2 = std::make_shared<H2_Ferriere07>();
	} else if (H2_model == "Bronfmann1988") {
		H2 = std::make_shared<H2_Bronfman88>();
	} else {
		assert(H2_model == "Ferriere2007");
	}
	//std::cout << H2->description() << "\n";
	return H2->clone();
}

} /* namespace DRAGON */
