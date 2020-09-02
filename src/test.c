#include "linalglib.h"
#include <stdio.h>

int main(void)
{
	vec4 v1 = {1,2,3,4};
	vec4 v2 = {5,6,7,8};
	mat4 m1 = {
		{1,-5,9,13},
		{2,6,-10,14},
		{3,7,11,15},
		{4,8,12,-16}
	};
	mat4 m2 = {
		{4,8,12,16},
		{3,7,11,15},
		{2,6,10,14},
		{1,5,9,13}
	};
	float s = 3.0;

	vec4 stimesv = scale_v4(s,v1);
	print_v4(stimesv);

	vec4 v1plusv2 = add_v4(v1,v2);
	print_v4(v1plusv2);

	vec4 v1minusv2 = subtract_v4(v1,v2);
	print_v4(v1minusv2);

	float magv1 = magnitude_v4(v1);
	printf("%f\n\n",magv1);

	vec4 normalizev1 = normalize_v4(v1);
	print_v4(normalizev1);

	float v1dotv2 = dot_v4(v1,v2);
	printf("%f\n\n",v1dotv2);

	vec4 v1crossv2 = cross_v4(v1,v2);
	print_v4(v1crossv2);


	mat4 stimesm = scale_m4(s,m1);
	print_m4(stimesm);
	
	mat4 m1plusm2 = add_m4(m1,m2);
	print_m4(m1plusm2);

	mat4 m1minusm2 = subtract_m4(m1,m2);
	print_m4(m1minusm2);

	mat4 m1timesm2 = multiply_m4(m1,m2);
	print_m4(m1timesm2);

	mat4 m1inverse = invert_m4(m1);
	print_m4(m1inverse);

	mat4 m1transpose = transpose_m4(m1);
	print_m4(m1transpose);

	vec4 m1timesv1 = multiply_m4v4(m1,v1);
	print_v4(m1timesv1);

	printf("done :)\n\n");

}
