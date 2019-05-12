#include "py.h"

class g_init {

public:
    g_init() {
        Py_Initialize();
        PyInit_py();
    }
    ~g_init() {
        Py_Finalize();
    }
};

g_init __global_init;

