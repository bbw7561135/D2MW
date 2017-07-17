#include "models/gasFerriere2007.h"

namespace Ferriere07 {

inline double deg2rad(const double& angleInDegree) {
	return angleInDegree * M_PI / 180;
}

Gas::Gas() {
	bulgeParams.X = 1.2 * kpc;
	bulgeParams.L = 438. * pc;
	bulgeParams.H = 42. * pc;
	bulgeParams.HI = 120. * pc;
	bulgeParams.alpha = deg2rad(13.5);
	bulgeParams.beta = deg2rad(20.0);
	bulgeParams.theta = deg2rad(48.5);
	cmzParams.xc = -50. * pc;
	cmzParams.yc = 50. * pc;
	cmzParams.thetac = deg2rad(70.0);
	cmzParams.Xc = 125. * pc;
	cmzParams.Lc = 137. * pc;
	cmzParams.Hc2 = 18. * pc;
	cmzParams.HcI = 54. * pc;
	cmzParams.L3 = 145. * pc;
	cmzParams.H3 = 26. * pc;
	cmzParams.L2 = 3.7 * kpc;
	cmzParams.H2 = 140. * pc;
	cmzParams.L1 = 17. * kpc;
	cmzParams.H1 = 950. * pc;
	cmzParams.Y = -10. * pc;
	cmzParams.Z = -20. * pc;

	sinalpha = sin(bulgeParams.alpha);
	sinbeta = sin(bulgeParams.beta);
	sintheta = sin(bulgeParams.theta);
	cosalpha = sin(bulgeParams.alpha);
	cosbeta = sin(bulgeParams.beta);
	costheta = sin(bulgeParams.theta);
	costhetac = cos(cmzParams.thetac);
	sinthetac = sin(cmzParams.thetac);
}

double Gas::density(const Vector3d& pos) const {
	return (cmz(pos) + bulge(pos) + disk(pos));
}

double H2::cmz(const Vector3d& pos) const {
	double xb = pos.x - cmzParams.xc;
	double yb = pos.y - cmzParams.yc;
	double x2 = xb * costhetac + yb * sinthetac;
	double y2 = -xb * sinthetac + yb * costhetac;

	double H2CMZ_A = exp(-pow(((sqrt(pow2(x2) + 6.25 * pow2(y2)) - cmzParams.Xc) / cmzParams.Lc), 4));
	double H2CMZ_B = exp(-pow2(pos.z / cmzParams.Hc2));

	return XcoFactor * 150.0 * H2CMZ_A * H2CMZ_B;
}

double H2::bulge(const Vector3d& pos) const {
	double X = pos.x * cosbeta * costheta -
			pos.y * (sinalpha * sinbeta * costheta - cosalpha * sintheta) -
			pos.z * (cosalpha * sinbeta * costheta + sinalpha * sintheta);

	double Y = -pos.x * cosbeta * costheta +
			pos.y * (sinalpha * sinbeta * sintheta + cosalpha * costheta) +
			pos.z * (cosalpha * sinbeta * sintheta + sinalpha * costheta);

	double Z = pos.x * sinbeta +
			pos.y * sinalpha * cosbeta +
			pos.z * cosalpha * cosbeta;

	double H2DISK_A = exp(-pow(((sqrt(pow2(X) + pow2(3.1 * Y)) - bulgeParams.X) / bulgeParams.L) ,4));
	double H2DISK_B = exp(-pow2(Z / bulgeParams.H));

	return XcoFactor * 4.8 * H2DISK_A * H2DISK_B;
}

double H2::disk(const Vector3d& pos) const {
	return 0;
}

double HI::cmz(const Vector3d& pos) const {
	double xb = pos.x - cmzParams.xc;
	double yb = pos.y - cmzParams.yc;
	double x2 = xb * costhetac + yb * sinthetac;
	double y2 = -xb * sinthetac + yb * costhetac;

	double HICMZ_A = exp(-pow(((sqrt(pow2(x2) + 6.25 * pow2(y2)) - cmzParams.Xc) / cmzParams.Lc), 4));
	double HICMZ_B = exp(-pow2(pos.z / cmzParams.HcI));

	return 8.8 * HICMZ_A * HICMZ_B;
}

double HI::bulge(const Vector3d& pos) const {
	double X = pos.x * cosbeta * costheta -
			pos.y * (sinalpha * sinbeta * costheta - cosalpha * sintheta) -
			pos.z * (cosalpha * sinbeta * costheta + sinalpha * sintheta);

	double Y = -pos.x * cosbeta * costheta +
			pos.y * (sinalpha * sinbeta * sintheta + cosalpha * costheta) +
			pos.z * (cosalpha * sinbeta * sintheta + sinalpha * costheta);

	double Z = pos.x * sinbeta +
			pos.y * sinalpha * cosbeta +
			pos.z * cosalpha * cosbeta;

	const double HIDISK_A = exp(-pow(((sqrt(pow2(X) + pow2(3.1 * Y)) - bulgeParams.X) / bulgeParams.L) ,4));
	const double HIDISK_B = exp(-pow2(Z / bulgeParams.HI));

	return 0.34 * HIDISK_A * HIDISK_B;
}

double HI::disk(const Vector3d& pos) const {
	double rSun = 8.5 * kpc;
	double r = pos.getR();
	double alpha = (r < rSun) ? 1 : r / rSun;
	double H1 = (127. * pc) * alpha;
	double H2 = (318. * pc) * alpha;
	double H3 = (403. * pc) * alpha;

	double nc = (0.340 / cm3) / alpha / alpha;
	nc *= 0.859 * exp(-pow(pos.z / H1, 2)) + 0.047 * exp(-pow(pos.z / H2, 2)) + 0.094 * exp(-fabs(pos.z) / H3);

	double nw = (0.226 / cm3) / alpha;
	nw *= (1.745 - 1.289 / alpha) * exp(-pow(pos.z / H1, 2)) +
			(0.473 - 0.070 / alpha) * exp(-pow(pos.z / H2, 2)) +
			(0.283 - 0.142 / alpha) * exp(-fabs(pos.z) / H3);

	return nc + nw;
}

double HII::cmz(const Vector3d& pos) const {
	double r = sqrt(pos.x * pos.x + pos.z * pos.z);

	double HIICMZ_A = exp(-(pow2(pos.x) + pow2(pos.y - cmzParams.Y)) / pow2(cmzParams.L3)) * exp(-pow2(pos.z - cmzParams.Z) / pow2(cmzParams.H3));
	double HIICMZ_B = 0.009 * (exp(-pow2(r - cmzParams.L2) / pow2(cmzParams.L2 / 2.0)) * sech2(pos.z / cmzParams.H2));
	double HIICMZ_C = 0.005 * cos(M_PI * r / 2.0 / cmzParams.L1) * sech2(pos.z / cmzParams.H1);

	return (8.0 / cm3) * (HIICMZ_A + HIICMZ_B + HIICMZ_C);
}

double HII::bulge(const Vector3d& pos) const {
	return 0;
}

double HII::disk(const Vector3d& pos) const {
	return 0;
}

} /* namespace Ferriere07 */
