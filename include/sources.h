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

	/**
	 * Compute the source rate normalization such that
	 * the 2D integral gives the galactic rate
	 */
	void compute_normalization();

private:
	double galactic_rate = 1. / 40. / year;
	double normalization = 1;
	Vector3d sun = Vector3d(8.5 * kpc, 0, 0);
};

/**
 * Class to implement the Yusifov2004 model for source profile
 */
class Sources_Yusifov04: public Galaxy {
public:
	/**
	 * Class Constructor
	 */
	Sources_Yusifov04() {
	}

	/*
	 * Class Constructor including parameters and rate
	 */
	Sources_Yusifov04(const double& rate, const double& a_, const double& b_, const double& R_1_, const double& z_0_) :
			galactic_rate(rate), a(a_), b(b_), R_1(R_1_), z_0(z_0_) {
		compute_normalization();
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
		return std::make_shared<Sources_Yusifov04>(*this);
	}

	/**
	 * Source surface density rate at the given position
	 * @param pos Galactic 3D position
	 * @return surface density rate
	 */
	double get(const Vector3d& pos) const override;

	/**
	 * Compute the source rate normalization such that
	 * the 2D integral gives the galactic rate
	 */
	void compute_normalization();

private:
	double galactic_rate = 1. / 40. / year;
	double normalization = 1;
	Vector3d sun = Vector3d(8.5 * kpc, 0, 0);
	double a = 1.64;
	double b = 4.01;
	double R_1 = 0.55 * kpc;
	double z_0 = 0.2 * kpc;
};

} /* namespace DRAGON */

#endif /* INCLUDE_SOURCES_H_ */
