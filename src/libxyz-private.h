#ifndef _LIBXYZ_PRIVATE_H_
#define _LIBXYZ_PRIVATE_H_

#include <stdbool.h>
#include <xyz/libxyz.h>

static inline void __attribute__ ((always_inline, format(printf,2,3)))
xyz_log_null(struct xyz_ctx *ctx, const char *format, ...) {}

#define xyz_log_cond (ctx, prio, arg...) \
  do { \
    if (xyz_get_log_priority(ctx) >= prio) \
      xyz_log(ctx, prio, __FILE__, __LINE__, __FUNCTION__, ## arg);
  } while (0)


#ifdef ENABLE_LOGGING
# ifdef ENABLE_DEBUG
#   define dbg(ctx, arg...) xyz_log_cond(ctx, LOG_DEBUG, ## arg)
# else
#   define dbg(ctx, arg...) xyz_log_null(ctx, ## arg)
# endif
#endif


#ifndef HAVE_SECURE_GETENV
#endif

#define XYZ_EXPORT __attribute__((visibility("default")))

void xyz_log(struct xyz_ctx *ctx,
  int priority,
  const char *file, int line,
  const char *fn, const char *format, ...)
  __attribute__((format(printf,6,7)));

#endif
