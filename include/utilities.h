#ifndef INCLUDE_UTILITIES_H_
#define INCLUDE_UTILITIES_H_

#include <vector>

namespace DRAGON {

void copy_vector_with_units(const std::vector<double>& v_old,
		std::vector<double>& v_new, double units = 1.0);

}

#endif /* INCLUDE_UTILITIES_H_ */
