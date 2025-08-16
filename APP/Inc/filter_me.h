#ifndef __FILTER_ME_H
#define __FILTER_ME_H

/*带通滤波器（IIR）*/
void filter_init(void);//滤波器初始化
void bandpass_filter(float *adc_data,float len,float *out_filter);//带通滤波器执行

#endif

