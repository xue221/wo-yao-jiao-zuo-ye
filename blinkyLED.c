#include "stm32f10x.h"
#include"delay.h"

int main(void)
{
	// #1.初始化IO引脚
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA , ENABLE);
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Pin=GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_4 | GPIO_Pin_6;
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_2MHz;
	GPIO_Init(GPIOA,&GPIO_InitStruct);
	
	
	// #2.初始化按钮
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB , ENABLE);
	GPIO_InitTypeDef GPIO_Struct;
	GPIO_Struct.GPIO_Pin=GPIO_Pin_1;
	GPIO_Struct.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_Init(GPIOB,&GPIO_Struct);
	
	uint8_t now = 1 ;
	uint8_t previous , current;
	previous = 1;
    
	while(1)
	{
		current = GPIO_ReadInputDataBit( GPIOB , GPIO_Pin_1);
	    if(current == 0 && previous == 1)
            {
				Delay(10);
				if(GPIO_ReadInputDataBit( GPIOB , GPIO_Pin_1) == 0){
					if(now==1)
						{
							now = 0;
						}else if(now == 0){
							now = 1;
						}
						
					while(GPIO_ReadInputDataBit( GPIOB , GPIO_Pin_1) == 0){}	
				 }
			}
			previous = current;
		    if(now == 1){
				GPIO_WriteBit(GPIOA,GPIO_Pin_0,Bit_SET);
				Delay(500);
				GPIO_WriteBit(GPIOA,GPIO_Pin_0,Bit_RESET);
				GPIO_WriteBit(GPIOA,GPIO_Pin_1,Bit_SET);
				Delay(500);
				GPIO_WriteBit(GPIOA,GPIO_Pin_1,Bit_RESET);
				GPIO_WriteBit(GPIOA,GPIO_Pin_4,Bit_SET);
				Delay(500);
				GPIO_WriteBit(GPIOA,GPIO_Pin_4,Bit_RESET);
				GPIO_WriteBit(GPIOA,GPIO_Pin_6,Bit_SET);
				Delay(500);
				GPIO_WriteBit(GPIOA,GPIO_Pin_6,Bit_RESET);
			
			}else if(now == 0){
				GPIO_WriteBit(GPIOA,GPIO_Pin_6,Bit_SET);
				Delay(500);
				GPIO_WriteBit(GPIOA,GPIO_Pin_6,Bit_RESET);
				GPIO_WriteBit(GPIOA,GPIO_Pin_4,Bit_SET);
				Delay(500);
				GPIO_WriteBit(GPIOA,GPIO_Pin_4,Bit_RESET);
				GPIO_WriteBit(GPIOA,GPIO_Pin_1,Bit_SET);
				Delay(500);
				GPIO_WriteBit(GPIOA,GPIO_Pin_1,Bit_RESET);
				GPIO_WriteBit(GPIOA,GPIO_Pin_0,Bit_SET);
				Delay(500);
				GPIO_WriteBit(GPIOA,GPIO_Pin_0,Bit_RESET);
			 }
	
	}
}
