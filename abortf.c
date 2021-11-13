
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "abortf.h"

FUN_NORETURN
void aborts(const char *msg) {
  fputs(msg, stderr);
  fflush(stderr);
  abort();
}

FUN_NORETURN
FUN_FORMAT(printf, 1, 2)
void abortf(const char *fmt, ...) {
  va_list a;
  va_start(a, fmt);
  vfprintf(stderr, fmt, a);
  va_end(a);
  fflush(stderr);
  abort();
}

FUN_NORETURN
FUN_FORMAT(printf, 1, 0)
void abortvf(const char *fmt, va_list a) {
  vfprintf(stderr, fmt, a);
  fflush(stderr);
  abort();
}
