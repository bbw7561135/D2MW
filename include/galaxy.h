#ifndef INCLUDE_GALAXY_H_
#define INCLUDE_GALAXY_H_

#include <memory>
#include <string>
#include "vector3.h"

namespace DRAGON {

/*
 * Galaxy basic class with minimal member functions and attributes
 */
class Galaxy {
public:
	/*
	 * virtual destructor
	 */
	virtual ~Galaxy() {
	}

	/*
	 * virtual function to get the reference to the model
	 */
	virtual std::string description() const = 0;

	/*
	 * virtual function to get the pointer to the instance
	 */
	virtual std::shared_ptr<Galaxy> clone() const = 0;

	/*
	 * virtual function to get a scalar as a function of position
	 * @param pos Galactic 3D position
	 * @return 0 (if not override)
	 */
	virtual double get(const Vector3d& pos) const {
		return 0;
	}

	/*
	 * virtual function to get a scalar as a function of position and scalar quantity
	 * @param pos Galactic 3D position
	 * @param scalar A scalar quantity (e.g., frequency or energy)
	 * @return 0 (if not override)
	 */
	virtual double get(const Vector3d& pos, const double& scalar) const {
		return 0;
	}
protected:
	std::string model;
	inline void set_model_name(const std::string& m) {
		model = m;
	}
};

} /* namespace DRAGON */

#endif /* INCLUDE_GALAXY_H_ */
