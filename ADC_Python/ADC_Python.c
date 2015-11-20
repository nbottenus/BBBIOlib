#include <stdio.h>
#include <stdlib.h>
#include "../BBBio_lib/BBBiolib.h"
#include "ADC_Python.h"

/* Do nothing */
int main(void)
{
	return 0;	
}

/*
init_ADC() - Initialize hardware to perform ADC sampling

clk_div = 160 sets the rate to 10 kHz. 
Use the ADC_CALC tool (make ADC_CALC) to choose other parameters
*/
void init_ADC(void)
{
	iolib_init();
	const int clk_div = 160;
	BBBIO_ADCTSC_module_ctrl(BBBIO_ADC_WORK_MODE_TIMER_INT, clk_div);
}

/*
sample_ADC(nvals,ADC_vals) - Take nvals samples and place into ADC_vals array at the predetermined rate
*/
void sample_ADC(int nvals, unsigned int * ADC_vals)
{
	const int open_dly = 0;
	const int sample_dly = 1;
	BBBIO_ADCTSC_channel_ctrl(BBBIO_ADC_AIN0, BBBIO_ADC_STEP_MODE_SW_CONTINUOUS, open_dly, sample_dly, \
				BBBIO_ADC_STEP_AVG_1, ADC_vals, nvals);
	BBBIO_ADCTSC_channel_enable(BBBIO_ADC_AIN0);
	BBBIO_ADCTSC_work(nvals);
}
