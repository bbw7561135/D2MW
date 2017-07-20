#ifndef INCLUDE_D2MW_H_
#define INCLUDE_D2MW_H_

#include <cassert>
#include <iostream>
#include <memory>
#include <string>
#include "galaxy.h"
#include "gas_HI.h"
#include "gas_HII.h"
#include "gas_H2.h"
#include "xco.h"

namespace DRAGON {

/**
 * Main class to implement D2MW
 */
class D2MW {
public:
	/*
	 * Class constructor
	 */
	D2MW() {
	}

	/*
	 * Virtual class destructor
	 */
	virtual ~D2MW() {
	}

	/*
	 * Set HI model
	 * @param name Model name
	 */
	void set_HI(const std::string& name) {
		HI_model = name;
	}

	/*
	 * Set HII model
	 * @param name Model name
	 */
	void set_HII(const std::string& name) {
		HII_model = name;
	}

	/*
	 * Set H2 model
	 * @param name Model name
	 */
	void set_H2(const std::string& name) {
		H2_model = name;
	}

	/*
	 * Set X_CO model name
	 * @param name Model name
	 */
	void set_XCO(const std::string& name) {
		XCO_model = name;
	}

	/*
	 * Create pointer to HI class
	 */
	std::shared_ptr<Galaxy> create_HI();

	/*
	 * Create pointer to HII class
	 */
	std::shared_ptr<Galaxy> create_HII();

	/*
	 * Create pointer to H2 class
	 */
	std::shared_ptr<Galaxy> create_H2();

	/*
	 * Create pointer to XCO class
	 */
	std::shared_ptr<Galaxy> create_XCO();

private:
	std::string HI_model = "Ferriere2007";
	std::string HII_model = "Ferriere2007";
	std::string H2_model = "Ferriere2007";
	std::string XCO_model = "Evoli2012";
	std::shared_ptr<Galaxy> HI;
	std::shared_ptr<Galaxy> HII;
	std::shared_ptr<Galaxy> H2;
	std::shared_ptr<Galaxy> XCO;
};

} /* namespace DRAGON */

#endif /* INCLUDE_D2MW_H_ */
