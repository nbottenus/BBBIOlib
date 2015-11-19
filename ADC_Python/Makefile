ADC: 
	cython ADC.pyx
	gcc -shared -pthread -fPIC -fwrapv -O2 -Wall -fno-strict-aliasing -I/usr/include/python2.7 -lpython2.7 -o ADC.so ./ADC.c -L ../BBBio_lib -lBBBio -lm
