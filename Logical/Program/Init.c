
#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

void _INIT ProgramInit(void)
{
	motor.dt = 0.02;
	motor.ke = 0.32;
	motor.Tm = 0.2;
	motor.u = 0;
	
	motor2.dt = 0.02;
	motor2.ke = 0.32;
	motor2.Tm = 0.2; 
	motor2.u = 0;

	regulator.dt = 0.01;
	regulator.k_i = 4.3;
	regulator.k_p = 0.36;
	regulator.max_abs_value = 27.0;
	
	
	
	
	speed = 0;
	counter = 0;
	enable = 1;
}
