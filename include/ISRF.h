#ifndef INCLUDE_ISRF_H_
#define INCLUDE_ISRF_H_

#include <iostream>
#include <memory>
#include <vector>

#include "blackbody.h"
#include "galaxy.h"
#include "mks.h"
#include "models/isrf_Vernetto2016.h"
#include "vector3.h"

namespace DRAGON {

class RadiationField_Galprop54: public Galaxy {
public:
	RadiationField_Galprop54() {
	}
	virtual std::string description() const override {
		return "Galprop54";
	}
	virtual std::shared_ptr<Galaxy> clone() const override {
		return std::make_shared<RadiationField_Galprop54>(*this);
	}
	virtual double get(const Vector3d& pos, const double& frequency) const override {
		return 1;
	}
};

class RadiationField_Delahaye10: public Galaxy {
public:
	RadiationField_Delahaye10() {
	}
	virtual std::string description() const override {
		return "Delahaye2010";
	}
	virtual std::shared_ptr<Galaxy> clone() const override {
		return std::make_shared<RadiationField_Delahaye10>(*this);
	}
	virtual double get(const Vector3d& pos, const double& frequency) const override;

private:
	std::vector<BlackBody> BBs = { BlackBody(), BlackBody(33.07 * K, 4.5e-5), BlackBody(313.32 * K, 1.2e-9), BlackBody(
			 3249.3 * K, 7.03e-13), BlackBody(6150.4 * K, 3.39e-14), BlackBody(23209.0 * K, 8.67e-17) };
};

class RadiationField_Vernetto16: public Galaxy {
public:
	RadiationField_Vernetto16() {
	}
	virtual std::string description() const override {
		return "Vernetto2016";
	}
	virtual std::shared_ptr<Galaxy> clone() const override {
		return std::make_shared<RadiationField_Vernetto16>(*this);
	}
	virtual double get(const Vector3d& pos, const double& frequency) const override;
private:
	Vernetto16::ISRF_grid isrf;
};

} /* namespace DRAGON */

#endif /* INCLUDE_ISRF_H_ */
