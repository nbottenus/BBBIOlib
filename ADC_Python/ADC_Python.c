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
*/
void init_ADC(void)
{
	iolib_init();
	set_clk_div(160);
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

/*
set_clk_div(clk_div) - Set the clock divider (based on ADC_CALC tool)

160 = 10 kHz
16 = 100 kHz

Use the ADC_CALC tool (make ADC_CALC) to choose other parameters
Open_delay = 0, Average = 1, Sample_delay = 1
*/
void set_clk_div(int clk_div)
{
	BBBIO_ADCTSC_module_ctrl(BBBIO_ADC_WORK_MODE_TIMER_INT, clk_div);
}
