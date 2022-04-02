/*************************************************************************
	> File Name: nan.h
	> Author: weijie.yuan
	> Mail: weijie.yuan@aispeech.com
	> Created Time: 2022年04月02日 星期六 14时58分11秒
 ************************************************************************/

#ifndef __NAN__H
#define __NAN__H

#ifdef __cplusplus
extern "C" {
#endif

// reference: http://demon.tw/copy-paste/c-nan.html

#ifdef _FPCLASS_SNAN
#include <math.h>
#define NaN sqrt(-1)
#define IsNaN(x) _isnan(x)
#else
#define NaN (0.0 / 0.0)
#define IsNaN(x) ((x) != (x))
#endif

#ifdef __cplusplus
}
#endif

#endif
