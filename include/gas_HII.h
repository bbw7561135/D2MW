#ifndef INCLUDE_GAS_HII_H_
#define INCLUDE_GAS_HII_H_

#include "galaxy.h"
#include "models/gasFerriere2007.h"

namespace DRAGON {

class HII_Ferriere07: public Galaxy {
public:
	HII_Ferriere07() {
	}
	std::string description() const override {
		return "HIIFerriere07";
	}
	std::shared_ptr<Galaxy> clone() const override {
		return std::make_shared<HII_Ferriere07>(*this);
	}
	double get(const Vector3d& pos) const override;
private:
	Ferriere07::HII gas;
};

} /* namespace DRAGON */

#endif /* INCLUDE_GAS_HII_H_ */
