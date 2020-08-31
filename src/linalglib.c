#include "linalglib.h"
#include <stdio.h>
#include <math.h>

/*
 * print vec4 to stdout
 */
void print_v4(vec4 v)
{
	printf("[ %.2f %.2f %.2f %.2f ]\n\n", v.x, v.y, v.z, v.w);
}

/*
 * scalar * vector multiplication
 */
vec4 scale(float s, vec4 v)
{
	vec4 result = {s*v.x, s*v.y, s*v.z, s*v.w};
	return result;
}

/*
 * add 2 vectors
 */
vec4 add(vec4 v1, vec4 v2)
{
	vec4 result = {v1.x+v2.x, v1.y+v2.y, v1.z+v2.z, v1.w+v2.w};
	return result;
}

/*
 *  subtract 2 vectors v1 - v2
 */
vec4 subtract(vec4 v1, vec4 v2)
{
	vec4 result = {v1.x-v2.x, v1.y-v2.y, v1.z-v2.z, v1.w-v2.w};
	return result;
}

/*
 * magnitude / norm of vector
 */
float magnitude(vec4 v)
{
	return sqrt(v.x*v.x + v.y*v.y + v.z*v.z + v.w*v.w);
}

/*
 * normalize vector
 */
vec4 normalize(vec4 v)
{
	vec4 result = scale((1.0/magnitude(v)), v);
	return result;
}

/*
 * dot product of 2 vectors
 */
float dot(vec4 v1, vec4 v2)
{
	return v1.x*v2.x + v1.y*v2.y + v1.z*v2.z + v1.w*v2.w;
}

/*
 * cross product of 2 vectors
 */
vec4 cross(vec4 v1, vec4 v2)
{
	vec4 result = {v1.y*v2.z - v1.z*v2.y, v1.z*v2.x - v1.x*v2.z, v1.x*v2.y - v1.y*v2.x, 0.0};
	return result;
}
