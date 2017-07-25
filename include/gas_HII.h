#ifndef INCLUDE_GAS_HII_H_
#define INCLUDE_GAS_HII_H_

#include "galaxy.h"
#include "models/gas_Ferriere2007.h"

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

class HII_Cordes91: public Galaxy {
public:
	HII_Cordes91() {
		set_params();
	}
	std::string description() const override {
		return "HII_Cordes91";
	}
	std::shared_ptr<Galaxy> clone() const override {
		return std::make_shared<HII_Cordes91>(*this);
	}
	double get(const Vector3d& pos) const override;
private:
	double fne1;
	double H1;
	double A1;
	double fne2;
	double H2;
	double A2;
	double R2;
	void set_params();
};

} /* namespace DRAGON */

#endif /* INCLUDE_GAS_HII_H_ */
