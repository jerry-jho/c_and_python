#include "py.h"

int main(int argc, char *argv[]) {
    int c_arr_0[] = {1,2,3,4,5,6};
    int c_arr_1[] = {7,8,9,10,11,12};
    int c_arr_2[] = {0,0,0,0,0,0};
    
    //convert c array to py list    
    int c_shape[] = {6};
    py shape = py_from_int_list(c_shape);
    
    //convert c array to torch tensor with shape
    py array0 = py_from_array(c_arr_0,sizeof(c_arr_0),shape,PY_INT);
    py array1 = py_from_array(c_arr_1,sizeof(c_arr_1),shape,PY_INT);
    
    //call torch functions. need specify number of arguments
    py array2 = py_call("torch.mul",2,array0,array1);
    
    //convert back and display
    py_to_array(array2,c_arr_2,sizeof(c_arr_2));
    for (int i=0;i<sizeof(c_arr_2)/sizeof(int);++i) {
        printf("%d ",c_arr_2[i]);
    }
}
