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
	} else if (HII_model == "YMW16") {
		HII = std::make_shared<HII_YMW16>();
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

std::shared_ptr<Galaxy> D2MW::create_XCO() {
	if (XCO_model == "Evoli2012") {
		XCO = std::make_shared<XCO_Evoli12>();
	} else {
		assert(XCO_model == "Evoli2012");
	}
	return XCO->clone();
}

std::shared_ptr<Galaxy> D2MW::create_ISRF() {
	if (ISRF_model == "Vernetto2016") {
		ISRF = std::make_shared<RadiationField_Vernetto16>();
	} else if (ISRF_model == "Delahaye2010") {
		ISRF = std::make_shared<RadiationField_Delahaye10>();
	} else {
		assert(ISRF_model == "Vernetto2016");
	}
	return ISRF->clone();
}

std::shared_ptr<Galaxy> D2MW::create_sources(const double& rate) {
	if (sources_model == "Ferriere2001") {
		Q = std::make_shared<Sources_Ferriere01>(rate);
	} else if (sources_model == "Yusifov2004") {
		Q = std::make_shared<Sources_Yusifov04>(rate, 1.64, 4.01, 0.55 * kpc, 0.2 * kpc);
	} else if (sources_model == "Lorimer2006") {
		Q = std::make_shared<Sources_Yusifov04>(rate, 1.9, 5.0, 0, 0.2 * kpc);
	} else {
		assert(sources_model == "Ferriere2001");
	}
	return Q->clone();
}

} /* namespace DRAGON */
