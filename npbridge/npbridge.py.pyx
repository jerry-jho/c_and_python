import numpy as np
import torch
import os

dtypes = [
    np.int32,
    np.float32
]

cdef public _py_from_int_list(int * list_ptr,int list_size):
    int_list = [list_ptr[x] for x in range(list_size)]
    return int_list

cdef public _py_from_array(char * data_ptr,int data_size,shape,int dtype_index):
    cdef bytes buf = data_ptr[:data_size]
    np_flat_array = np.frombuffer(buf,dtype=dtypes[dtype_index])
    np_array = np_flat_array.reshape(shape)
    th_array = torch.from_numpy(np_array)

    if os.environ.get('PY_FORCE_CPU','0') == '1':
        print("[Info] PY_FORCE_CPU is set, CUDA is disabled")
    else:
        if torch.cuda.is_available():
            th_array = th_array.cuda()
            print("[Info] CUDA Array in %s" % torch.cuda.get_device_name(0))
        else:
            print("[Warning] CUDA is not available, fall back to CPU")
    return th_array
    

cdef public int _py_to_array(th_array,char * data_ptr,int data_size):
    th_array = th_array.cpu()
    np_array = th_array.numpy()
    buf = np_array.tobytes()
    for i,b in enumerate(buf):
        if i < data_size:
            data_ptr[i] = b 
        else:
            return 1
    return 0

cdef public py_print(x):
    print(x)

cdef extern from "py_va_args.h":
    object py_va_args(int n,...)
    
cdef extern from "stdarg.h":
    ctypedef void* va_list
    void va_start(va_list,int)
    void va_end(va_list)
    object va_arg(va_list,object)
    

cdef public py_call(const char * funcname,int argc,...):
    cdef bytes py_funcname = funcname
    fname = py_funcname.decode("utf-8")
    #print(fname)
    func = eval(fname)
    cdef va_list vl
    va_start(vl,argc)
    args = py_va_args(argc,vl)
    va_end(vl)
    #print(args)
    return func(*args)
    
cdef public int py_to_bool(x):
    if not x:
        return 0
    return 1

