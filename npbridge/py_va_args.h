#ifndef _PY_VA_ARGS_H
#define _PY_VA_ARGS_H

#include <Python.h>
#include "stdarg.h"

PyObject * py_va_args(int n,va_list argp);

#endif
