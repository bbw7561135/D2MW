#ifndef INCLUDE_D2MW_H_
#define INCLUDE_D2MW_H_

#include <cassert>
#include <memory>
#include <string>
#include "galaxy.h"
#include "gas_HI.h"
#include "gas_HII.h"
#include "gas_H2.h"

namespace DRAGON {

class D2MW {
public:
	D2MW() {
	}
	virtual ~D2MW() {
	}
	void set_HI(const std::string& name) {
		HI_model = name;
	}
	void set_HII(const std::string& name) {
		HII_model = name;
	}
	void set_H2(const std::string& name) {
		H2_model = name;
	}
	std::shared_ptr<Galaxy> create_HI();
	std::shared_ptr<Galaxy> create_HII();
	std::shared_ptr<Galaxy> create_H2();
private:
	std::string HI_model = "Ferriere2007";
	std::string HII_model = "Ferriere2007";
	std::string H2_model = "Ferriere2007";
	std::shared_ptr<Galaxy> HI;
	std::shared_ptr<Galaxy> HII;
	std::shared_ptr<Galaxy> H2;
};

} /* namespace DRAGON */

#endif /* INCLUDE_D2MW_H_ */
