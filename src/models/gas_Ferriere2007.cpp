#include "models/gas_Ferriere2007.h"

namespace Ferriere07 {

double Gas::density(double x, double y, double z) const {
	double value = 0;
	if (fabs(x) < inner_radius && fabs(y) < inner_radius && fabs(z) < inner_radius)
		value = cmz(x, y, z) + bulge(x, y, z);
	else
		value = disk(x, y, z);
	return std::max(value, 1e-10 / cm3);
}

double Gas::x3(double x, double y, double z) const {
	double value = x * cos_beta1 * cos_thetad1;
	value += -y * (sin_alpha1 * sin_beta1 * cos_thetad1 - cos_alpha1 * sin_thetad1);
	value += -z * (cos_alpha1 * sin_beta1 * cos_thetad1 + sin_alpha1 * sin_thetad1);
	return value;
}

double Gas::y3(double x, double y, double z) const {
	double value = -x * cos_beta1 * cos_thetad1;
	value += y * (sin_alpha1 * sin_beta1 * sin_thetad1 + cos_alpha1 * cos_thetad1);
	value += z * (cos_alpha1 * sin_beta1 * sin_thetad1 - sin_alpha1 * cos_thetad1);
	return value;
}

double Gas::z3(double x, double y, double z) const {
	double value = x * sin_beta1;
	value += y * sin_alpha1 * cos_beta1;
	value += z * cos_alpha1 * cos_beta1;
	return value;
}

double HI::cmz(double x, double y, double z) const {
	double xb = x - xc;
	double yb = y - yc;
	double x2 = xb * cos_thetac + yb * std::sin(thetac);
	double y2 = -xb * std::sin(thetac) + yb * cos_thetac;

	double value = 8.8;
	value *= std::exp(-pow4((std::sqrt(pow2(x2) + pow2(2.5 * y2)) - Xc) / Lc));
	value *= std::exp(-pow2(z / HcI));
	return value;
}
double HI::bulge(double x, double y, double z) const {
	double x3_ = x3(x, y, z);
	double y3_ = y3(x, y, z);
	double z3_ = z3(x, y, z);

	double value = 0.34;
	value *= std::exp(-pow(((sqrt(pow2(x3_) + pow2((3.1 * y3_))) - Xd) / (Ld)), 4));
	value *= std::exp(-pow2((z3_ / HdI)));
	return value;
}
double HI::disk(double x, double y, double z) const {
	double r_sun = 8.5e3;
	double r = std::sqrt(x * x + y * y);
	double alpha = (r < r_sun) ? 1 : r / r_sun;
	double H1 = 127 * alpha;
	double H2 = 318 * alpha;
	double H3 = 403 * alpha;

	double n_c = 0.340 / alpha / alpha;
	double exp1 = std::exp(-pow2(z / H1));
	double exp2 = std::exp(-pow2(z / H2));
	double exp3 = std::exp(-fabs(z) / H3);
	n_c *= 0.859 * exp1 + 0.047 * exp2 + 0.094 * exp3;

	double n_w = 0.226 / alpha;
	n_w *= (1.745 - 1.289 / alpha) * std::exp(-pow2(z / H1)) +
			(0.473 - 0.070 / alpha) * std::exp(-pow2(z / H2)) +
			(0.283 - 0.142 / alpha) * std::exp(-std::fabs(z) / H3);

	return n_c + n_w;
}

double H2::cmz(double x, double y, double z) const {
	double xb = x - xc;
	double yb = y - yc;
	double x2 = xb * cos_thetac + yb * sin_thetac;
	double y2 = -xb * sin_thetac + yb * cos_thetac;

	double value = 150.0;
	value *= std::exp(-pow4((std::sqrt(pow2(x2) + pow2(2.5 * y2)) - Xc) / Lc));
	value *= std::exp(-pow2(z / Hc2));
	return value;
}

double H2::bulge(double x, double y, double z) const {
	double x3_ = x3(x, y, z);
	double y3_ = y3(x, y, z);
	double z3_ = z3(x, y, z);

	double value = 4.8;
	value *= exp(-pow(((sqrt(pow(x3_, 2) + pow((3.1 * y3_), 2)) - Xd) / (Ld)), 4));
	value *= exp(-pow((z3_ / Hd), 2));
	return value;
}

double H2::disk(double x, double y, double z) const {
	return 0;
}

double HII::cmz(double x, double y, double z) const {
	double r_pc = std::sqrt(pow2(x) + pow2(y));
	double y_3 = -10;
	double z_3 = -20;

	double P1 = 8.0;
	P1 *= exp(-(pow2(x) + pow2(y - y_3)) / pow2(L3)) * exp(-(pow2(z - z_3)) / pow2(H3));

	double P2 = 8.0 * 0.009;
	P2 *= exp(-(pow2(r_pc - L2)) / (pow2(L2) / 4.));
	P2 *= pow2(sech(z / H2));

	double P3 = 8.0 * 0.005;
	P3 *= std::cos(M_PI * r_pc / 2. / L1);
	P3 *= pow2(sech(z / H1));

	return P1 + P2 + P3;;
}

double HII::bulge(double x, double y, double z) const {
	return 0;
}

double HII::disk(double x, double y, double z) const {
	return 0;
}

} /* namespace Ferriere07 */
