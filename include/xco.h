#ifndef INCLUDE_XCO_H_
#define INCLUDE_XCO_H_

#include "galaxy.h"
#include "mks.h"

namespace DRAGON {

/**
 * Class to implement the Constant model for XCO
 */
class XCO_constant: public Galaxy {
public:
	/**
	 * Class Constructor
	 */
	XCO_constant(const double& value_) : value(value_) {
	}

	/**
	 * Get the reference for the XCO model
	 * @return string containing a reference
	 */
	std::string description() const override {
		return "none";
	}

	/**
	 * Get the pointer of this instance
	 */
	std::shared_ptr<Galaxy> clone() const override {
		return std::make_shared<XCO_constant>(*this);
	}

	/**
	 * XCO normalization factor (wrt to 10^20) at the given position
	 * @param pos Galactic 3D position
	 * @return XCO norm
	 */
	double get(const Vector3d& pos) const override {
		return value;
	}

private:
	double value; /* The constant value for XCO */
};

/**
 * Class to implement the Arimoto96 model for XCO
 */
class XCO_Arimoto96: public Galaxy {
public:
	/**
	 * Class Constructor
	 */
	XCO_Arimoto96() {
	}

	/**
	 * Get the reference for the XCO model
	 * @return string containing a reference
	 */
	std::string description() const override {
		return "Arimoto96";
	}

	/**
	 * Get the pointer of this instance
	 */
	std::shared_ptr<Galaxy> clone() const override {
		return std::make_shared<XCO_Arimoto96>(*this);
	}

	/**
	 * XCO normalization factor (wrt to 10^20) at the given position
	 * @remark Eq 3 in Ferriere+07
	 * @param pos Galactic 3D position
	 * @return XCO norm
	 */
	double get(const Vector3d& pos) const override;
};

/**
 * Class to implement the Arimoto96 model for XCO
 */
class XCO_Ackermann10: public Galaxy {
public:
	/**
	 * Class Constructor
	 */
	XCO_Ackermann10() {
	}

	/**
	 * Get the reference for the XCO model
	 * @return string containing a reference
	 */
	std::string description() const override {
		return "Ackermann10";
	}

	/**
	 * Get the pointer of this instance
	 */
	std::shared_ptr<Galaxy> clone() const override {
		return std::make_shared<XCO_Ackermann10>(*this);
	}

	/**
	 * XCO normalization factor (wrt to 10^20) at the given position
	 * @param pos Galactic 3D position
	 * @return XCO norm
	 */
	double get(const Vector3d& pos) const override;
};

/**
 * Class to implement the Arimoto96 model for XCO
 */
class XCO_Evoli12: public Galaxy {
public:
	/**
	 * Class Constructor
	 * @param inner Value for XCO in the inner Galaxy
	 * @param outer Value for XCO in the outer Galaxy
	 * @param border Distance of the border between inner and outer regions
	 */
	XCO_Evoli12(const double& inner, const double& outer, const double& border) {
		inner_value = inner;
		outer_value = outer;
		border_position = border;
	}

	/**
	 * Class Constructor with reference values
	 */
	XCO_Evoli12() {
		inner_value = 1;
		outer_value = 1;
		border_position = 3 * kpc;
	}

	/**
	 * Get the reference for the XCO model
	 * @return string containing a reference
	 */
	std::string description() const override {
		return "Evoli12";
	}

	/**
	 * Get the pointer of this instance
	 */
	std::shared_ptr<Galaxy> clone() const override {
		return std::make_shared<XCO_Evoli12>(*this);
	}

	/**
	 * XCO normalization factor (wrt to 10^20) at the given position
	 * @param pos Galactic 3D position
	 * @return XCO norm
	 */
	double get(const Vector3d& pos) const override;

private:
	double inner_value;
	double outer_value;
	double border_position;
};

} /* namespace DRAGON */

#endif /* INCLUDE_XCO_H_ */
