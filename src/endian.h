#include "mathlib_config.h"

/* From https://stackoverflow.com/questions/8978935/detecting-endianness */
#if defined(__BYTE_ORDER__)&&(__BYTE_ORDER__ == __ORDER_BIG_ENDIAN__)
#  ifndef BIG_ENDI
#  define BIG_ENDI
#  endif
#  undef LITTLE_ENDI
#else
#ifdef WORDS_BIGENDIAN
#  ifndef BIG_ENDI
#  define BIG_ENDI
#  endif
#  undef LITTLE_ENDI
#else
#  ifndef LITTLE_ENDI
#  define LITTLE_ENDI
#  endif
#  undef BIG_ENDI
#endif
#endif

#ifdef BIG_ENDI
#undef HIGH_HALF
#define HIGH_HALF 0
#undef LOW_HALF
#define  LOW_HALF 1
#else 
#ifdef LITTLE_ENDI
#undef HIGH_HALF
#define HIGH_HALF 1
#undef LOW_HALF
#define  LOW_HALF 0
#endif
#endif

#define ABS(x)   ((x) <  0  ? -(x) : (x))
