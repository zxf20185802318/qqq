#include "stm32f10x.h"
#include "led.h"
#include "delay.h"
#include "sys.h"
#include "usart.h"
#include "time.h"

int main()
{
	u16 a=0;
	u8 b=1;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	delay_init();
	LED_Init();
	TIM3_PWM_Init(899,0);
	while(1)
	{
	  delay_ms(20);
		if(b)
			a++;
		else
			a--;
	
   if(a>200)
   b=0;
   if(a==0)
   b=1;		 
	TIM_SetCompare2(TIM3,a);
	
	}
	
}
