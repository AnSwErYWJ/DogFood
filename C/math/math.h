#ifndef __MATH__H
#define __MATH__H

// reference: http://demon.tw/copy-paste/c-nan.html
#ifdef _FPCLASS_SNAN
#include <math.h>
#define NaN sqrt(-1)
#define IsNaN(x) _isnan(x)
#else
#define NaN (0.0 / 0.0)
#define IsNaN(x) ((x) != (x))
#endif

#endif
