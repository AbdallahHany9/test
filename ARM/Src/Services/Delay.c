
#include "Services/Delay.h"

void Delay_ms(u32 time)
{
	u32 volatile counter=0;
	time=time*1000;
	time=(f32)time/(f32)1.47658;
	while(counter<time)
	{
		counter++;
	}
}
