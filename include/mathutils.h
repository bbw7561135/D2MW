#ifndef INCLUDE_MATHUTILS_H_
#define INCLUDE_MATHUTILS_H_

#include <cmath>

#define pow2(A) ((A)*(A))
#define pow3(A) ((A)*(A)*(A))
#define pow4(A) ((A)*(A)*(A)*(A))
#define pow5(A) ((A)*(A)*(A)*(A)*(A))
#define sech(A) (1.0 / std::cosh(A))
#define sech2(A) (1.0 / std::cosh(A) / std::cosh(A))
#define deg2rad(A) (A * M_PI / 180.0)

#endif /* INCLUDE_MATHUTILS_H_ */
