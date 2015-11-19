#include <stdio.h>
#include <stdlib.h>
#include "../BBBio_lib/BBBiolib.h"
#include "ADC_Python.h"
#define NVALS 10000

unsigned int ADC_vals[NVALS] ={0};

int main(void)
{
	return 0;	
}

void init_ADC(void)
{
	iolib_init();
	const int clk_div = 160;
	const int open_dly = 0;
	const int sample_dly = 1;
	BBBIO_ADCTSC_module_ctrl(BBBIO_ADC_WORK_MODE_TIMER_INT, clk_div);
	BBBIO_ADCTSC_channel_ctrl(BBBIO_ADC_AIN0, BBBIO_ADC_STEP_MODE_SW_CONTINUOUS, open_dly, sample_dly, \
				BBBIO_ADC_STEP_AVG_1, ADC_vals, NVALS);
}

unsigned int * sample_ADC(void)
{

	BBBIO_ADCTSC_channel_enable(BBBIO_ADC_AIN0);
	BBBIO_ADCTSC_work(NVALS);
	return ADC_vals; 
}
