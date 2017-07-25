#ifndef INCLUDE_GAS_H2_H_
#define INCLUDE_GAS_H2_H_

#include <algorithm>
#include <vector>

#include "galaxy.h"
#include "interpolator.h"
#include "models/gas_Ferriere2007.h"
#include "utilities.h"

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

class H2_Nakanishi06: public Galaxy {
public:
	H2_Nakanishi06() {
	}
	std::string description() const override {
		return "H2_Nakanishi06";
	}
	std::shared_ptr<Galaxy> clone() const override {
		return std::make_shared<H2_Nakanishi06>(*this);
	}
	double get(const Vector3d& pos) const override;
};

class H2_Bronfman88: public Galaxy {
public:
	H2_Bronfman88() {
		init();
	}
	std::string description() const override {
		return "H2_Bronfman88";
	}
	std::shared_ptr<Galaxy> clone() const override {
		return std::make_shared<H2_Bronfman88>(*this);
	}
	double get(const Vector3d& pos) const override;
private:
	void init();
	std::vector<double> R;
	std::vector<double> n0;
	std::vector<double> Z0;
	std::vector<double> Zh;
};

} /* namespace DRAGON */

#endif /* INCLUDE_GAS_H2_H_ */
