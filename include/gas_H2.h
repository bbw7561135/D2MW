#ifndef INCLUDE_GAS_H2_H_
#define INCLUDE_GAS_H2_H_

namespace DRAGON {

class H2_Ferriere07: public Galaxy {
public:
	H2_Ferriere07();
	std::string description() const override;
	std::shared_ptr<Galaxy> clone() override;
	double get(const Vector3d& pos) const override;
private:
	Ferriere07::H2 gas;
};

} /* namespace DRAGON */

#endif /* INCLUDE_GAS_H2_H_ */
