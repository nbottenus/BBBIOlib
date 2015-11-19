cdef extern from "ADC_Python.c":

    void init_ADC()

    unsigned int * sample_ADC()

import numpy as np
init_ADC()

def read():
    N=10000;
    val = sample_ADC()
    np_vals=np.empty([N,1],dtype=int)
    for i in range(0,N):
        np_vals[i]=val[i]
    return np_vals

