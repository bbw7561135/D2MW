#include "gas_HII.h"

namespace DRAGON {

/*** HII_Ferriere07 ***/

double HII_Ferriere07::get(const Vector3d& pos) const {
	return gas.density(pos);
}
} /* namespace DRAGON */
