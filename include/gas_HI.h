#ifndef INCLUDE_GAS_HI_H_
#define INCLUDE_GAS_HI_H_

#include "galaxy.h"
#include "models/gasFerriere2007.h"

namespace DRAGON {

class HI_Ferriere07: public Galaxy {
public:
	HI_Ferriere07() {
	}
	std::string description() const override {
		return "HIFerriere07";
	}
	std::shared_ptr<Galaxy> clone() const override {
		return std::make_shared<HI_Ferriere07>(*this);
	}
	double get(const Vector3d& pos) const override;
private:
	Ferriere07::HI gas;
};

class HI_Nakanishi03: public Galaxy {
public:
	HI_Nakanishi03() {
	}
	std::string description() const override {
		return "HI_Nakanishi03";
	}
	std::shared_ptr<Galaxy> clone() const override {
		return std::make_shared<HI_Nakanishi03>(*this);
	}
	double get(const Vector3d& pos) const override;
private:
	double h_0 = 1.06 * pc;
	double n_0 = 0.94 / cm3;
};


} /* namespace DRAGON */

#endif /* INCLUDE_GAS_HI_H_ */
