#ifndef __MATHS__
#define __MATHS__

#include <stdlib.h>

#include "Constants.h"

inline double
max(double x0, double x1);

inline int
rand_int();

inline float
rand_float();

inline int
rand_int(int l, int h);

inline float
rand_float(int l, float h);


inline double
max(double x0, double x1)
{
	return((x0 > x1) ? x0 : x1);
}


inline int
rand_int()
{
	return (rand());
}


inline float
rand_float(void) {
	return((float)rand_int() * invRAND_MAX);
}


inline int
rand_int(int l, int h) {
	return ((int) (rand_float(0, h - l + 1) + l));
}


inline float
rand_float(int l, float h) {
	return (rand_float() * (h - l) + l);
}


#endif
