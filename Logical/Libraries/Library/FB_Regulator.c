
#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
	#include "Library.h"
#ifdef __cplusplus
	};
#endif
/* TODO: Add your comment here */
void FB_Regulator(struct FB_Regulator* inst)
{	
	inst->integrator.dt = inst->dt;
	
	REAL a = inst->e * inst->k_p;
	REAL b = inst->e * inst->k_i;
	
	a = a > inst->max_abs_value ? inst->max_abs_value : a;
	a = a < -inst->max_abs_value ? -inst->max_abs_value : a;
	
	inst->integrator.in = b + inst->last_sum;
	FB_Integrator(&inst->integrator);
	
	inst->sum = a + inst->integrator.out;
	inst->u = inst->sum;
	inst->u = inst->u > inst->max_abs_value ? inst->max_abs_value : inst->u;
	inst->u = inst->u < -inst->max_abs_value ? -inst->max_abs_value : inst->u;
	
	inst->last_sum = inst->u - inst->sum;
}
