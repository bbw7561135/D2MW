#ifndef INCLUDE_GAS_HII_H_
#define INCLUDE_GAS_HII_H_

#include "galaxy.h"
#include "mks.h"
#include "models/gas_Ferriere2007.h"

extern "C" double ymw16_ne(double x_pc, double y_pc, double z_pc);

namespace DRAGON {

/**
 * Class to implement the Ferriere2007 model for HII
 */
class HII_Ferriere07: public Galaxy {
public:
	/**
	 * Class Constructor
	 */
	HII_Ferriere07() {
	}

	/**
	 * Get the reference for the Ferriere07 model
	 * @return string containing a reference
	 */
	std::string description() const override {
		return "HIIFerriere07";
	}

	/**
	 * Get the pointer of this instance
	 */
	std::shared_ptr<Galaxy> clone() const override {
		return std::make_shared<HII_Ferriere07>(*this);
	}

	/**
	 * Get the HII density at the given position
	 * @param pos Galactic 3D position
	 * @return gas density
	 */
	double get(const Vector3d& pos) const override;
private:
	Ferriere07::HII gas;
};

/**
 * Class to implement the Cordes1991 model for HII
 */
class HII_Cordes91: public Galaxy {
public:
	/**
	 * Class Constructor
	 */
	HII_Cordes91() {
		set_params();
	}

	/**
	 * Get the reference for the Cordes91 model
	 * @return string containing a reference
	 */
	std::string description() const override {
		return "HII_Cordes91";
	}

	/**
	 * Get the pointer of this instance
	 */
	std::shared_ptr<Galaxy> clone() const override {
		return std::make_shared<HII_Cordes91>(*this);
	}

	/**
	 * Get the HII density at the given position
	 * @param pos Galactic 3D position
	 * @return gas density
	 */
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

/**
 * Class to implement the YMW16 model for HII
 * @see https://arxiv.org/abs/1610.09448
 */
class HII_YMW16: public Galaxy {
public:
	/**
	 * Class Constructor
	 */
	HII_YMW16() {
	}

	/**
	 * Get the reference for the YMW16 model
	 * @return string containing a reference
	 */
	std::string description() const override {
		return "Yao, Manchester and Wang, ApJ, 835, 29 (2017)";
	}

	/**
	 * Get the pointer of this instance
	 */
	std::shared_ptr<Galaxy> clone() const override {
		return std::make_shared<HII_YMW16>(*this);
	}

	/**
	 * Get the HII density at the given position
	 * @param pos Galactic 3D position
	 * @return gas density
	 */
	double get(const Vector3d& pos) const override;
};

} /* namespace DRAGON */

#endif /* INCLUDE_GAS_HII_H_ */
