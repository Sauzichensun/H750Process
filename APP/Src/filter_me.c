/*滤波器设计函数*/
#include "main.h"
#include "filter_me.h"
#include "filter_coeffs.h"
#include "comvab.h"
#include "arm_math.h"
#include "arm_const_structs.h"


/*BandPass*/
#define NUM_STAGES 16 // 32阶 16个二阶节
#define BLOCK_SIZE 32 // 每次处理32个数据
float pCoeffs[5*NUM_STAGES];
float pState[4*NUM_STAGES];
// 缓冲数组
float input_buffer[BLOCK_SIZE];
float output_buffer[BLOCK_SIZE];
//实例化带通滤波器
arm_biquad_casd_df1_inst_f32 S_bandpass;


// --- 滤波器初始化函数 ---
// 在程序启动时调用一次，负责设置滤波器
void filter_init(void)
{
    // 初始化滤波器实例，pState 数组会被自动清零
    arm_biquad_cascade_df1_init_f32(&S_bandpass, NUM_STAGES, pCoeffs, pState);
}

void bandpass_filter(float *adc_data,float len,float *out_filter)
{
    //循环处理每一块
    for(uint16_t i=0;i<len/BLOCK_SIZE;i++)
    {
        float *input_block_ptr = &adc_data[i*BLOCK_SIZE];
        float *output_block_ptr = &out_filter[i*BLOCK_SIZE];
        arm_biquad_cascade_df1_f32(&S_bandpass, input_block_ptr, output_block_ptr,BLOCK_SIZE);
    }
}   



