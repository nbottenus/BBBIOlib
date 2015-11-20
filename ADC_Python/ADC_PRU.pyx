'''
 ADC_PRU.prx - Cython library for interacting with the PRU ADC function

 Import as a Python module (import ADC_PRU as ADC)
 Module is initialized on import

 read(vals) writes values in place to a numpy array with type intc
 ADC.read(vals)
'''

cdef extern from "ADC_Python.c":
    void init_ADC()
    void sample_ADC(int nvals, unsigned int * ADC_vals)

import numpy as np
cimport numpy as np

init_ADC()

def read(np.ndarray np_vals not None):
    assert np_vals.dtype == np.intc, "Numpy array must be type 'np.intc'"
    cdef int n
    n = np_vals.shape[0]
    cdef np.uint8_t[:] buffer
    buffer = np_vals.view(np.uint8)
    sample_ADC(n,<unsigned int *>&buffer[0])
    return None
