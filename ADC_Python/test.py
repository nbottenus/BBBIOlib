import time as time
import ADC as ADC

N=10
for i in range(0,N):
    t1=time.time()
    val=ADC.read()
    t2=time.time()
    print (t2-t1)
