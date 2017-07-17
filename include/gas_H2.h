#ifndef INCLUDE_GAS_H2_H_
#define INCLUDE_GAS_H2_H_

#include "galaxy.h"
#include "models/gasFerriere2007.h"

namespace DRAGON {

class H2_Ferriere07: public Galaxy {
public:
	H2_Ferriere07() {
	}
	std::string description() const override {
		return "H2_Ferriere07";
	}
	std::shared_ptr<Galaxy> clone() const override {
		return std::make_shared<H2_Ferriere07>(*this);
	}
	double get(const Vector3d& pos) const override;
private:
	Ferriere07::H2 gas;
};

} /* namespace DRAGON */

#endif /* INCLUDE_GAS_H2_H_ */
