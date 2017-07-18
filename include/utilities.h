#ifndef INCLUDE_UTILITIES_H_
#define INCLUDE_UTILITIES_H_

#include <cmath>
#include <vector>

namespace DRAGON {

double Interpol1D(double x, double xa, double xb, double ya, double yb);

void copy_vector_with_units(const std::vector<double>& v_old,
		std::vector<double>& v_new, double units = 1.0);

} /* namespace DRAGON */

#endif /* INCLUDE_UTILITIES_H_ */
