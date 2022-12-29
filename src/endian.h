#include "mathlib_config.h"

/* From https://stackoverflow.com/questions/8978935/detecting-endianness */
#if defined(__BYTE_ORDER__)&&(__BYTE_ORDER__ == __ORDER_BIG_ENDIAN__)
#  define BIG_ENDI
#  undef LITTLE_ENDI
#else
#ifdef WORDS_BIGENDIAN
#  define BIG_ENDI
#  undef LITTLE_ENDI
#else
#  define LITTLE_ENDI
#  undef BIG_ENDI
#endif
#endif

#ifdef BIG_ENDI
#define HIGH_HALF 0
#define  LOW_HALF 1
#else 
#ifdef LITTLE_ENDI
#define HIGH_HALF 1
#define  LOW_HALF 0
#endif
#endif

#define ABS(x)   ((x) <  0  ? -(x) : (x))
