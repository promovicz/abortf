/*
 * abortf - Printing variants of abort
 *
 * Copyright (C) 2020-2021 Ingo Albrecht <copyright@promovicz.org>
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
