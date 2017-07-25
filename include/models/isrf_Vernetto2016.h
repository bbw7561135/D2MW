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

/*
 * Class to read and use the Vernetto2016 model
 */
class ISRF_grid {
public:
	/*
	 * Constructor initializes grid and axes
	 */
	ISRF_grid();
	/*
	 * Destructor cleans grid and axes
	 */
	virtual ~ISRF_grid() {
		grid.clear();
		R.clear();
		Z.clear();
		energy.clear();
	}
	/*
	 * Computes the energy density by interpolating grid
	 * @param r Galactic position in cylindrical coordinates
	 * @param z Galacitc position in cylindrical coordinates
	 * @param photon_energy radiation field photon energy
	 * @output energy density [J/m3]
	 */
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
