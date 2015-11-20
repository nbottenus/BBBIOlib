"""
test.py - Simple demonstration of sampling rate using the PRU library for the ADC

Takes 10k samples at 10kHz, returned in a numpy array, and displays the time taken. Repeats 10 times
"""

import time as time
import numpy as np
import ADC_PRU as ADC

N=10
num_vals=10000

ADC.set_clk(160) #Optional, 160 is default (10kHz), 16=100 kHz

np_vals=np.empty(num_vals,dtype=np.intc)
for i in range(0,N):
    t1=time.time()
    ADC.read(np_vals)
    t2=time.time()
    print (t2-t1)
