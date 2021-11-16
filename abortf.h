/*
 * abortf - Printing variants of abort
 *
 * Copyright (C) 2020-2021 Ingo Albrecht <copyright@promovicz.org>
 *
 * This is free and unencumbered software released into the public domain.
 *
 * Anyone is free to copy, modify, publish, use, compile, sell, or
 * distribute this software, either in source code form or as a compiled
 * binary, for any purpose, commercial or non-commercial, and by any
 * means.
 *
 * In jurisdictions that recognize copyright laws, the author or authors
 * of this software dedicate any and all copyright interest in the
 * software to the public domain. We make this dedication for the benefit
 * of the public at large and to the detriment of our heirs and
 * successors. We intend this dedication to be an overt act of
 * relinquishment in perpetuity of all present and future rights to this
 * software under copyright law.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 * For more information, please refer to <http://unlicense.org/>
 */

#ifndef ABORTF_H
#define ABORTF_H

#include <stdarg.h>
#include <stdlib.h>

/* use attributes to enable format checking */
#if defined(__GNUC__) || defined(__clang__)
#define FUN_FORMAT(arch, fmtindex, argindex)        \
  __attribute__((format(arch, fmtindex, argindex)))
#define FUN_NORETURN                            \
  __attribute__((noreturn))
#else
#define FUN_FORMAT(...)
#define FUN_NORETURN
#endif

/** abort printing a fixed message */
FUN_NORETURN
extern void aborts(const char *msg);

/** abort with formatting */
FUN_NORETURN
FUN_FORMAT(printf, 1, 2)
extern void abortf(const char *fmt, ...);

/** abort with formatting */
FUN_NORETURN
FUN_FORMAT(printf, 1, 0)
extern void abortvf(const char *fmt, va_list a);

/* clean up attribute macros */
#ifndef IN_ABORTF
#undef FUN_FORMAT
#undef FUN_NORETURN
#endif

#endif /* !ABORTF_H */
