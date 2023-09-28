#ifndef __SYS__H
#define __SYS__H

// GCC version >= v2.96
#define LIKELY(x)  		__builtin_expect(!!(x), 1)
#define UNLIKELY(x)		__builtin_expect(!!(x), 0)

#endif
