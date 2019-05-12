#ifndef _PY_H
#define _PY_H

#include <Python.h>
#include "npbridge.py.h"


typedef PyObject * py;

#define py_from_int_list(x) _py_from_int_list((x),(int)(sizeof(x)/sizeof(int)))

#define PY_INT   0
#define PY_FLOAT 1

#define py_from_array(c,size,shape,t) _py_from_array((char *)(c),(size),(shape),(t))
#define py_to_array(a,c,size) _py_to_array((a),(char *)(c),(size))

#endif

