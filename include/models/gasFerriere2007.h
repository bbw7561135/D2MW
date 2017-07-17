#ifndef INCLUDE_MODELS_GASFERRIERE2007_H_
#define INCLUDE_MODELS_GASFERRIERE2007_H_

#include "mks.h"
#include "vector3.h"

namespace Ferriere07 {

struct BulgeParams {
	double X;
	double L;
	double H;
	double HI;
	double alpha;
	double beta;
	double theta;
};

struct CmzParams {
	double xc;
	double yc;
	double thetac;
	double Xc;
	double Lc;
	double Hc2;
	double HcI;
	double L3;
	double H3;
	double L2;
	double H2;
	double L1;
	double H1;
	double Y;
	double Z;
};

class Gas {
protected:
	BulgeParams bulgeParams;
	CmzParams cmzParams;

	double sinalpha;
	double sinbeta;
	double sintheta;
	double sinthetac;
	double cosalpha;
	double cosbeta;
	double costheta;
	double costhetac;

public:
	Gas();

	virtual ~Gas() {
	}
	double density(const Vector3d &pos) const;

	virtual double cmz(const Vector3d &pos) const {
		return 0;
	}
	virtual double bulge(const Vector3d &pos) const {
		return 0;
	}
	virtual double disk(const Vector3d &pos) const {
		return 0;
	}
};

class H2: public Gas {
public:
	H2() : Gas(), XcoFactor(1.0 / 0.5) {
	}
	double cmz(const Vector3d &pos) const override;
	double bulge(const Vector3d &pos) const override;
	double disk(const Vector3d &pos) const override;
private:
	double XcoFactor;
};

class HI: public Gas {
public:
	HI() : Gas() {
	}
	double cmz(const Vector3d &pos) const override;
	double bulge(const Vector3d &pos) const override;
	double disk(const Vector3d &pos) const override;
};

class HII: public Gas {
public:
	HII() : Gas() {
	}
	double cmz(const Vector3d &pos) const override;
	double bulge(const Vector3d &pos) const override;
	double disk(const Vector3d &pos) const override;
};

} /* namespace Ferriere07 */

#endif /* INCLUDE_MODELS_GASFERRIERE2007_H_ */
