#include "py_va_args.h"


PyObject * py_va_args(int n,va_list argp) {
    PyObject* t = PyTuple_New(n);
    PyObject* a;
    int i;
    for (i=0;i<n;++i) {
        a = va_arg(argp,PyObject*);
        PyTuple_SetItem(t,i,a);
    }
    return t;
}