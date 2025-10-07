
#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

void _CYCLIC ProgramCyclic(void)
{
	if(enable)
	{
		if(counter == 1000)
		{
			speed = 60;
		}
		if(counter == 1100)
		{
			speed = 0;
			counter = 0;
		}
		counter = counter + 1;
		
		regulator.e = speed - motor.w;
		FB_Regulator(&regulator);
		
		motor.u = regulator.u;
		FB_Motor(&motor);
		
		motor2.u = speed * motor2.ke;
		FB_Motor(&motor2);
	}
}
