#ifndef INCLUDE_GALAXY_H_
#define INCLUDE_GALAXY_H_

#include <memory>
#include <string>
#include "vector3.h"

namespace DRAGON {

class Galaxy {
public:
	virtual ~Galaxy() {
	}
	virtual std::string description() const = 0;
	virtual std::shared_ptr<Galaxy> clone() const = 0;
	virtual double get(const Vector3d& pos) const = 0;
protected:
	std::string model;
	inline void set_model_name(const std::string& m) {
		model = m;
	}
};

} /* namespace DRAGON */

#endif /* INCLUDE_GALAXY_H_ */
