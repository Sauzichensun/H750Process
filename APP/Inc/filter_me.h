#ifndef __FILTER_ME_H
#define __FILTER_ME_H

/*��ͨ�˲�����IIR��*/
void filter_init(void);//�˲�����ʼ��
void bandpass_filter(float *adc_data,float len,float *out_filter);//��ͨ�˲���ִ��

#endif

