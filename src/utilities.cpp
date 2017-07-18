#include "utilities.h"

namespace DRAGON {

void copy_vector_with_units(const std::vector<double>& v_old,
		std::vector<double>& v_new, double units) {
	std::transform(v_old.begin(), v_old.end(), std::back_inserter(v_new),
			[units](double a) -> double {return a * units;});
}

} /* namespace DRAGON */
