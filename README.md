## Printing and formatting versions of abort

This is a [clib](https://clibs.org/) library offering variants of `abort()`.

It aims to be compatible with libc conventions.

### Features

 * Uses attributes for compile-time format string checking
 * `aborts` will print a message and abort
 * `abortf` will format a message and abort
 * `abortvf` is the varargs version of `abortf`

### Functions provided

```
#include <abortf.h>
extern void aborts(const char *msg);
extern void abortf(const char *fmt, ...);
extern void abortvf(const char *fmt, va_list a);
```
