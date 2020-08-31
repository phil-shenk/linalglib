#include "linalglib.h"
#include <stdio.h>

int main(void)
{
	vec4 v1 = {0.4, 0.3, 0.2, 0.1};
	vec4 v2 = {0.1, 0.2, 0.3, 0.4};
	float s	= -3.0f;
	printf("v1: ");
	print_v4(v1);
	printf("v2: ");
	print_v4(v2);

	vec4 scaled = scale(s,v1);
	print_v4(scaled);

	vec4 sum = add(v1, v2);
	print_v4(sum);

	vec4 diff = subtract(v1,v2);
	print_v4(diff);

	float mag = magnitude(v1);
	printf("%f\n\n",mag);

	vec4 normalized = normalize(v1);
	print_v4(normalized);

	float dotProd = dot(v1,v2);
	printf("%f\n\n",dotProd);

	vec4 crossProd = cross(v1,v2);
	print_v4(crossProd);

	printf("done :)\n\n");

}
