#ifndef INCLUDE_SOURCES_H_
#define INCLUDE_SOURCES_H_

#include <vector>

#include "galaxy.h"
#include "integrator.h"
#include "mks.h"

namespace DRAGON {

/**
 * Class to implement the Ferriere2001 model for source profile
 */
class Sources_Ferriere01: public Galaxy {
public:
	/**
	 * Class Constructor
	 */
	Sources_Ferriere01() {
	}

	Sources_Ferriere01(const double& rate) :
			galactic_rate(rate) {
		compute_normalization();
	}

	/**
	 * Get the reference for the Ferriere2001 model
	 * @return string containing a reference
	 */
	std::string description() const override {
		return "SNR_Ferriere01";
	}

	/**
	 * Get the pointer of this instance
	 */
	std::shared_ptr<Galaxy> clone() const override {
		return std::make_shared<Sources_Ferriere01>(*this);
	}

	/**
	 * Source surface density rate at the given position
	 * @param pos Galactic 3D position
	 * @return surface density rate
	 */
	double get(const Vector3d& pos) const override;

	void compute_normalization();

private:
	double galactic_rate = 1. / 40. / year;
	double normalization = 1;
	Vector3d sun = Vector3d(8.5 * kpc, 0, 0);
};

/**
 * Class to implement the Yusifov2004 model for source profile
 */
class Sources_Yusifov2004: public Galaxy {
public:
	/**
	 * Class Constructor
	 */
	Sources_Yusifov2004() {
	}

	/**
	 * Get the reference for the Yusifov2004 model
	 * @return string containing a reference
	 */
	std::string description() const override {
		return "Sources_Yusifov2004";
	}

	/**
	 * Get the pointer of this instance
	 */
	std::shared_ptr<Galaxy> clone() const override {
		return std::make_shared<Sources_Yusifov2004>(*this);
	}

	/**
	 * Source surface density rate at the given position
	 * @param pos Galactic 3D position
	 * @return surface density rate
	 */
	double get(const Vector3d& pos) const override;

private:
	Vector3d sun = Vector3d(8.5 * kpc, 0, 0);
	double b = 0;
	double R_1 = 0;
	double z_0 = 0;
	double a = 0;
};

} /* namespace DRAGON */

#endif /* INCLUDE_SOURCES_H_ */
