#include "gas_HI.h"

namespace DRAGON {

/*** HI_Ferriere07 ***/

double HI_Ferriere07::get(const Vector3d& pos) const {
	return gas.density(pos);
}

} /* namespace DRAGON */
