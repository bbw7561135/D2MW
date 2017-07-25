#include "models/isrf_Vernetto2016.h"
#define max_num_of_char_in_a_line 512

namespace Vernetto16 {

ISRF_grid::ISRF_grid() {
	std::vector<double> v1 = { 0.0, 0.2, 0.5, 1., 1.5, 2., 2.5, 3., 3.5, 4., 4.5, 5., 5.5, 6., 6.5, 7., 7.5, 8., 8.5,
			9., 9.5, 10.0, 11.0, 12.0, 14.0, 16.0, 18.0, 20.0, 25.0, 30.0 };
	copy_vector_with_units(v1, R, kpc);

	std::vector<double> v2 = { 0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.8, 1.0, 1.2, 1.5, 2.0, 2.5, 3.0, 4.0, 5.0, 6.0, 8.0,
			10.0, 12.0, 15.0, 20.0, 25.0, 30.0 };
	copy_vector_with_units(v2, Z, kpc);

	read_energy_axis();
	read_grid();
}

double ISRF_grid::energy_density(const double& r, const double& z, const double& photon_energy) const {
	if (r < R.front() || r > R.back() || fabs(z) < Z.front() || fabs(z) > Z.back() || photon_energy < energy.front()
			|| photon_energy > energy.back()) {
		return 0;
	} else {
		size_t i = std::upper_bound(R.begin(), R.end(), r) - R.begin() - 1;
		double r_unit = (r - R.at(i)) / (R.at(i + 1) - R.at(i));

		size_t j = std::upper_bound(Z.begin(), Z.end(), fabs(z)) - Z.begin() - 1;
		double z_unit = (fabs(z) - Z.at(j)) / (Z.at(j + 1) - Z.at(j));

		size_t k = std::upper_bound(energy.begin(), energy.end(), photon_energy) - energy.begin() - 1;
		double energy_unit = (photon_energy - energy.at(k)) / (energy.at(k + 1) - energy.at(k));

		double target[2] = { r_unit, z_unit };
		double v_0[4] = { get_grid(i, j, k), get_grid(i, j + 1, k), get_grid(i + 1, j + 1, k), get_grid(i + 1, j, k) };
		double v_1[4] = { get_grid(i, j, k + 1), get_grid(i, j + 1, k + 1), get_grid(i + 1, j + 1, k + 1), get_grid(
				i + 1, j, k + 1) };
		double target_prime = energy_unit;
		double v_prime[2] = { Interpolator<double>::Bilinear(target, v_0), Interpolator<double>::Bilinear(target, v_1) };

		return Interpolator<double>::Linear(target_prime, v_prime) / pow2(photon_energy);
	}
}

std::string ISRF_grid::create_filename(double r, double z) const {
	std::ostringstream ss;
	ss << "data/Vernetto16/spectrum";
	ss << "_r" << std::setfill('0') << std::setw(3) << r * 10;
	ss << "_z" << std::setfill('0') << std::setw(3) << z * 10;
	ss << ".dat";
	return ss.str();
}

double ISRF_grid::get_grid(size_t ir, size_t iz, size_t ienergy) const {
	return grid.at(ienergy + iz * energy.size() + ir * energy.size() * Z.size());
}

void ISRF_grid::read_grid() {
	for (auto i : R)
		for (auto j : Z) {
			auto filename = create_filename(i / kpc, j / kpc);
			fill_grid(filename);
		}
	assert(R.size() * Z.size() * energy.size() == grid.size());
}

void ISRF_grid::fill_grid(const std::string& filename) {
	std::ifstream file_to_read(filename.c_str());
	file_to_read.ignore(max_num_of_char_in_a_line, '\n');
	assert(file_to_read.is_open());
	std::vector<double> v;
	while (!file_to_read.eof()) {
		double col_0, energy_density;
		file_to_read >> col_0 >> energy_density;
		if (!file_to_read.eof()) {
			v.push_back(energy_density * eV / cm3);
		}
	}
	file_to_read.close();
	std::reverse_copy(v.begin(), v.end(), std::back_inserter(grid));
}

void ISRF_grid::read_energy_axis() {
	std::ifstream file_to_read("data/Vernetto16/spectrum_r000_z000.dat");
	file_to_read.ignore(max_num_of_char_in_a_line, '\n');
	assert(file_to_read.is_open());
	while (!file_to_read.eof()) {
		double wavelenght, col_1;
		file_to_read >> wavelenght >> col_1;
		if (!file_to_read.eof()) {
			energy.push_back(h_c / (wavelenght * micron));
		}
	}
	file_to_read.close();
	std::reverse(std::begin(energy), std::end(energy));
}

} /* namespace Vernetto16 */
