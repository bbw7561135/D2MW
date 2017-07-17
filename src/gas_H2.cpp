#include "gas_H2.h"

namespace DRAGON {

/*** H2_Ferriere07 ***/

double H2_Ferriere07::get(const Vector3d& pos) const {
	return gas.density(pos);
}

} /* namespace DRAGON */
