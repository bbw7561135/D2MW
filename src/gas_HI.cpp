#include "gas_HI.h"

namespace DRAGON {

/*** HI_Ferriere07 ***/

double HI_Ferriere07::get(const Vector3d& pos) const {
	auto pos_pc = pos / pc;
	return gas.density(pos_pc.x, pos_pc.y, pos_pc.z) / cm3;
}

} /* namespace DRAGON */
