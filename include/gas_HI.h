#ifndef INCLUDE_GAS_HI_H_
#define INCLUDE_GAS_HI_H_

#include "galaxy.h"
#include "mks.h"
#include "models/gas_Ferriere2007.h"

namespace DRAGON {

/**
 * Class to implement the Ferriere2007 model for HI
 */
class HI_Ferriere07: public Galaxy {
public:
	/**
	 * Class Constructor
	 */
	HI_Ferriere07() {
	}

	/**
	 * Get the reference for the Ferriere2007 model
	 * @return string containing a reference
	 */
	std::string description() const override {
		return "HIFerriere07";
	}

	/**
	 * Get the pointer of this instance
	 */
	std::shared_ptr<Galaxy> clone() const override {
		return std::make_shared<HI_Ferriere07>(*this);
	}

	/**
	 * Gas density at the given position
	 * @param pos Galactic 3D position
	 * @return number density of HI
	 */
	double get(const Vector3d& pos) const override;

private:
	Ferriere07::HI gas; /* A class containing the Ferriere07 model */
};

/**
 * Class to implement the Nakanishi03 model for HI
 */
class HI_Nakanishi03: public Galaxy {
public:
	/**
	 * Class Constructor
	 */
	HI_Nakanishi03() {
	}

	/**
	 * Get the reference for the Nakanishi03 model
	 * @return string containing a reference
	 */
	std::string description() const override {
		return "HI_Nakanishi03";
	}

	/**
	 * Get the pointer of this instance
	 */
	std::shared_ptr<Galaxy> clone() const override {
		return std::make_shared<HI_Nakanishi03>(*this);
	}

	/**
	 * Gas density at the given position
	 * @param pos Galactic 3D position
	 * @return number density of HI
	 */
	double get(const Vector3d& pos) const override;

private:
	double h_0 = 1.06 * pc;
	double n_0 = 0.94 / cm3;
};

} /* namespace DRAGON */

#endif /* INCLUDE_GAS_HI_H_ */
