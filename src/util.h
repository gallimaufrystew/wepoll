#ifndef WEPOLL_UTIL_H_
#define WEPOLL_UTIL_H_

#include <assert.h>
#include <stddef.h>
#include <stdint.h>

#include "internal.h"

#ifndef _SSIZE_T_DEFINED
typedef intptr_t ssize_t;
#endif

#define array_count(a) (sizeof(a) / (sizeof((a)[0])))

/* clang-format off */
#define container_of(ptr, type, member) \
  ((type*) ((uintptr_t) (ptr) - offsetof(type, member)))
/* clang-format on */

#define unused_var(v) ((void) (v))

/* Polyfill `inline` for older versions of msvc (up to Visual Studio 2013) */
#if defined(_MSC_VER) && _MSC_VER < 1900
#define inline __inline
#endif

/* Polyfill `static_assert` for some versions of clang and gcc. */
#if (defined(__clang__) || defined(__GNUC__)) && !defined(static_assert)
#define static_assert(condition, message) typedef __attribute__( \
    (__unused__)) int __static_assert_##__LINE__[(condition) ? 1 : -1]
#endif

#endif /* WEPOLL_UTIL_H_ */
