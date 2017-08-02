#ifndef INCLUDE_MODELS_GAS_FERRIERE2007_H_
#define INCLUDE_MODELS_GAS_FERRIERE2007_H_

#include <algorithm>
#include <cmath>
#include "mathutils.h"

namespace Ferriere07 {

/*
 * Galactic gravitational potential
 * @see Wolfire+1995
 */
class GravitationalPotential {
protected:
	double C1 = 8.887e3;
	double C2 = 3.e3;
	double C3 = 0.325;
	double a1 = 6.5e3;
	double a2 = 0.7e3;
	double a3 = 12e3;
	double b1 = 0.26e3;
	double rh = 210e3;

public:
	/*
	 * Default constructor
	 */
	GravitationalPotential() {
	}

	/*
	 * Destructor
	 */
	virtual ~GravitationalPotential() {
	}

	/*
	 * Compute the gravitational potential
	 * @param r r-position in pc
	 * @param z z-position in pc
	 * @return gravitational potential in (km/s)^2
	 *
	 */
	double get(const double& r, const double& z) const;
};

class Gas {
protected:
	double inner_radius = 3e3;
	double xc = -50;
	double yc = 50;
	double thetac = deg2rad(70.);
	double Xc = 125;
	double Lc = 137;
	double Hc2 = 18;
	double HcI = 54;
	double L3 = 145;
	double H3 = 26;
	double L2 = 3700;
	double H2 = 140;
	double L1 = 17000;
	double H1 = 950;
	double alpha1 = deg2rad(13.5);
	double beta1 = deg2rad(20.);
	double thetad1 = deg2rad(48.5);
	double alphavh = deg2rad(21.);
	double Xd = 1200;
	double Ld = 438;
	double Hd = 42;
	double HdI = 120;
	double Lvh = 162;
	double Hvh = 90;
	double XcoFactor = 1.0 / 0.5;
	double cos_thetac = std::cos(thetac);
	double sin_thetac = std::sin(thetac);
	double cos_beta1 = std::cos(beta1);
	double cos_thetad1 = std::cos(thetad1);
	double sin_alpha1 = std::sin(alpha1);
	double sin_beta1 = std::sin(beta1);
	double cos_alpha1 = std::cos(alpha1);
	double sin_thetad1 = std::sin(thetad1);
	double cos_alphavh = std::cos(alphavh);
	double sin_alphavh = std::sin(alphavh);

public:
	Gas() {
	}
	virtual ~Gas() {
	}
	virtual double cmz(double x, double y, double z) const {
		return 0;
	}
	virtual double bulge(double x, double y, double z) const {
		return 0;
	}
	virtual double disk(double x, double y, double z) const {
		return 0;
	}
	double density(double x, double y, double z) const;
	double x3(double x, double y, double z) const;
	double y3(double x, double y, double z) const;
	double z3(double x, double y, double z) const;
};

class H2: public Gas {
public:
	H2() {
	}
	double cmz(double x, double y, double z) const override;
	double bulge(double x, double y, double z) const override;
	double disk(double x, double y, double z) const override;
};

class HI: public Gas {
public:
	HI() {
	}
	double cmz(double x, double y, double z) const override;
	double bulge(double x, double y, double z) const override;
	double disk(double x, double y, double z) const override;
};

class HII: public Gas {
public:
	/*
	 * Default Constructor
	 */
	HII() {
	}

	/*
	 * Compute the total space-averaged density of HII in the CMZ
	 * @param x x-position in pc
	 * @param y y-position in pc
	 * @param z z-position in pc
	 * @return density in cm-3
	 */
	double cmz(double x, double y, double z) const override;

	/*
	 * Compute the total space-averaged density of HII in the bulge
	 * @param x x-position in pc
	 * @param y y-position in pc
	 * @param z z-position in pc
	 * @return density in cm-3
	 */
	double bulge(double x, double y, double z) const override;

	/*
	 * Compute the total space-averaged density of HII in the disk (not implemented)
	 * @param x x-position in pc
	 * @param y y-position in pc
	 * @param z z-position in pc
	 * @return density in cm-3
	 */
	double disk(double x, double y, double z) const override;
private:
	/*
	 * Compute the HII space-averaged density of the WIM
	 * @param x x-position in pc
	 * @param y y-position in pc
	 * @param z z-position in pc
	 * @return density in cm-3
	 */
	double wim(double x, double y, double z) const;

	/*
	 * Compute the HII space-averaged density of the VHIM
	 * @param x x-position in pc
	 * @param y y-position in pc
	 * @param z z-position in pc
	 * @return density in cm-3
	 */
	double vhim(double x, double y, double z) const;

	/*
	 * Compute the HII space-averaged density of the HIM
	 * @param x x-position in pc
	 * @param y y-position in pc
	 * @param z z-position in pc
	 * @return density in cm-3
	 */
	double him(double x, double y, double z) const;

	GravitationalPotential phi;
};

} /* namespace Ferriere07 */

#endif /* INCLUDE_MODELS_GAS_FERRIERE2007_H_ */

