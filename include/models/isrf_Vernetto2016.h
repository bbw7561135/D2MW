#ifndef INCLUDE_MODELS_ISRF_VERNETTO2016_H_
#define INCLUDE_MODELS_ISRF_VERNETTO2016_H_

#include <cassert>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>

#include "interpolator.h"
#include "mks.h"
#include "utilities.h"

namespace Vernetto16 {

class ISRF_grid {
public:
	ISRF_grid();
	virtual ~ISRF_grid() {
	}
	double energy_density(const double& r, const double& z, const double& photon_energy) const;
private:
	std::vector<double> grid;
	std::vector<double> R;
	std::vector<double> Z;
	std::vector<double> energy;
	double get_grid(size_t i, size_t j, size_t k) const;
	void read_energy_axis();
	void read_grid();
	void fill_grid(const std::string& filename);
	std::string create_filename(double R, double z) const;
};

} /* namespace Vernetto16 */

#endif /* INCLUDE_MODELS_ISRF_VERNETTO2016_H_ */
