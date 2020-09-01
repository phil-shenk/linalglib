#include "linalglib.h"
#include <stdio.h>

int main(void)
{
	vec4 v1 = {0.4, 0.3, 0.2, 0.1};
	vec4 v2 = {0.1, 0.2, 0.3, 0.4};
	float s	= -3.0f;

	mat4 m1 = {{1,5,9,13},{2,6,10,14},{3,7,11,15},{4,8,12,16}};
	mat4 m2 = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};

	printf("s:%f\n",s);
	printf("v1: ");
	print_v4(v1);
	printf("v2: ");
	print_v4(v2);

	printf("s*v1:");
	vec4 scaled = scale_v4(s,v1);
	print_v4(scaled);

	vec4 sum = add_v4(v1, v2);
	print_v4(sum);

	vec4 diff = subtract_v4(v1,v2);
	print_v4(diff);

	float mag = magnitude_v4(v1);
	printf("%f\n\n",mag);

	vec4 normalized = normalize_v4(v1);
	print_v4(normalized);

	float dotProd = dot_v4(v1,v2);
	printf("%f\n\n",dotProd);

	vec4 crossProd = cross_v4(v1,v2);
	print_v4(crossProd);

	printf("done with vectors :)\n\n");

	printf("matrices:\n\n");
	printf("m1:\n");
	print_m4(m1);
	printf("m2:\n");
	print_m4(m2);

	printf("s*m1:\n");
	mat4 mscaled = scale_m4(s, m1);
	print_m4(mscaled);


	printf("m1+m2:\n");
	mat4 msum = add_m4(m1, m2);
	print_m4(msum);

	printf("m1-m2:\n");
	mat4 mdiff = subtract_m4(m1, m2);
	print_m4(mdiff);
	
	printf("m1*m2:\n");
	mat4 prod = multiply_m4(m1, m2);
	print_m4(prod);

	printf("m1^-1 (inverse):\n");
	mat4 inv = invert_m4(m1);
	print_m4(inv);

	printf("m^T (transpose):\n");
	mat4 tpose = transpose_m4(m1);
	print_m4(tpose);

	printf("m1*v1:\n");
	mat4 vmprod = multiply_m4v4(m1, v1);
	print_m4(vmprod);


}
