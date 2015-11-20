import ADC_PRU as ADC
import numpy as np
import matplotlib.pyplot as plt

clk='10k'

#Set clock properly and set up array for 1s of data
nsamples=0
if clk=='10k':
    ADC.set_clk(160) #Optional, default
    nsamples=10000
elif clk=='100k':
    ADC.set_clk(16)
    nsamples=100000
else:
    print 'Unknown frequency'
    exit()
vals = np.empty(nsamples,np.intc)

raw_input("Press Enter:")
ADC.read(vals)

#Plot and save
fig=plt.figure()
t=np.arange(0,1,1.0/nsamples)
plt.plot(t,vals*1.8/4095)
plt.ylabel('Voltage (V)')
plt.xlabel('Time (s)')
plt.title(clk)
fig.savefig("out.png")
