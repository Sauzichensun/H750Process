/*�˲�����ƺ���*/
#include "main.h"
#include "filter_me.h"
#include "filter_coeffs.h"
#include "comvab.h"
#include "arm_math.h"
#include "arm_const_structs.h"


/*BandPass*/
#define NUM_STAGES 16 // 32�� 16�����׽�
#define BLOCK_SIZE 32 // ÿ�δ���32������
float pCoeffs[5*NUM_STAGES];
float pState[4*NUM_STAGES];
// ��������
float input_buffer[BLOCK_SIZE];
float output_buffer[BLOCK_SIZE];
//ʵ������ͨ�˲���
arm_biquad_casd_df1_inst_f32 S_bandpass;


// --- �˲�����ʼ������ ---
// �ڳ�������ʱ����һ�Σ����������˲���
void filter_init(void)
{
    // ��ʼ���˲���ʵ����pState ����ᱻ�Զ�����
    arm_biquad_cascade_df1_init_f32(&S_bandpass, NUM_STAGES, pCoeffs, pState);
}

void bandpass_filter(float *adc_data,float len,float *out_filter)
{
    //ѭ������ÿһ��
    for(uint16_t i=0;i<len/BLOCK_SIZE;i++)
    {
        float *input_block_ptr = &adc_data[i*BLOCK_SIZE];
        float *output_block_ptr = &out_filter[i*BLOCK_SIZE];
        arm_biquad_cascade_df1_f32(&S_bandpass, input_block_ptr, output_block_ptr,BLOCK_SIZE);
    }
}   



