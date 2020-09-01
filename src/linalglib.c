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
vec4 scale_v4(float s, vec4 v)
{
	vec4 result = {s*v.x, s*v.y, s*v.z, s*v.w};
	return result;
}

/*
 * add 2 vectors
 */
vec4 add_v4(vec4 v1, vec4 v2)
{
	vec4 result = {v1.x+v2.x, v1.y+v2.y, v1.z+v2.z, v1.w+v2.w};
	return result;
}

/*
 *  subtract 2 vectors v1 - v2
 */
vec4 subtract_v4(vec4 v1, vec4 v2)
{
	vec4 result = {v1.x-v2.x, v1.y-v2.y, v1.z-v2.z, v1.w-v2.w};
	return result;
}

/*
 * magnitude / norm of vector
 */
float magnitude_v4(vec4 v)
{
	return sqrt(v.x*v.x + v.y*v.y + v.z*v.z + v.w*v.w);
}

/*
 * normalize vector
 */
vec4 normalize_v4(vec4 v)
{
	vec4 result = scale_v4((1.0/magnitude_v4(v)), v);
	return result;
}

/*
 * dot product of 2 vectors
 */
float dot_v4(vec4 v1, vec4 v2)
{
	return v1.x*v2.x + v1.y*v2.y + v1.z*v2.z + v1.w*v2.w;
}

/*
 * cross product of 2 vectors
 */
vec4 cross_v4(vec4 v1, vec4 v2)
{
	vec4 result = {v1.y*v2.z - v1.z*v2.y, v1.z*v2.x - v1.x*v2.z, v1.x*v2.y - v1.y*v2.x, 0.0};
	return result;
}

/********************
 * MATRIX OPERATIONS
 *******************/

/*
 * print out mat4
 */
void print_m4(mat4 m){
	printf( "[ %0.2f, %0.2f, %0.2f, %0.2f, ]\n"
		"[ %0.2f, %0.2f, %0.2f, %0.2f, ]\n"
		"[ %0.2f, %0.2f, %0.2f, %0.2f, ]\n"
		"[ %0.2f, %0.2f, %0.2f, %0.2f, ]\n\n",
		  m.x.x, m.y.x, m.z.x, m.w.x,
		  m.x.y, m.y.y, m.z.y, m.w.y,
		  m.x.z, m.y.z, m.z.z, m.w.z,
		  m.x.w, m.y.w, m.z.w, m.w.w);

}


mat4 scale_m4(float s, mat4 m){
	mat4 result = {
		{ s*m.x.x, s*m.x.y, s*m.x.z, s*m.x.w },
		{ s*m.y.x, s*m.y.y, s*m.y.z, s*m.y.w },
		{ s*m.z.x, s*m.z.y, s*m.z.z, s*m.z.w },
		{ s*m.w.x, s*m.w.y, s*m.w.z, s*m.w.w }
	};

	return result;
}

/*blocks of code, possibly useful for transpose
  	{	{ m.x.x, m.y.x, m.z.x, m.w.x },
		{ m.x.y, m.y.y, m.z.y, m.w.y },
		{ m.x.z, m.y.z, m.z.z, m.w.z },
		{ m.x.w, m.y.w, m.z.w, m.w.w }};
		
	mat4 result = {
		{ m1.x.x, m1.x.y, m1.x.z, m1.x.w },
		{ m1.y.x, m1.y.y, m1.y.z, m1.y.w },
		{ m1.z.x, m1.z.y, m1.z.z, m1.z.w },
		{ m1.w.x, m1.w.y, m1.w.z, m1.w.w }
	};

*/
//this looks like the transpose of the printout.
mat4 result = {{1,5,9,13},{2,6,10,14},{3,7,11,15},{4,8,12,16}};
		
mat4 add_m4(mat4 m1, mat4 m2)
{
	mat4 result = {
		{ m1.x.x+m2.x.x, m1.x.y+m2.x.y, m1.x.z+m2.x.z, m1.x.w+m2.x.w },
		{ m1.y.x+m2.y.x, m1.y.y+m2.y.y, m1.y.z+m2.y.z, m1.y.w+m2.y.w },
		{ m1.z.x+m2.z.x, m1.z.y+m2.z.y, m1.z.z+m2.z.z, m1.z.w+m2.z.w },
		{ m1.w.x+m2.w.x, m1.w.y+m2.w.y, m1.w.z+m2.w.z, m1.w.w+m2.w.w }
	};
	return result;
}


mat4 subtract_m4(mat4 m1, mat4 m2){
	mat4 result = {
		{ m1.x.x-m2.x.x, m1.x.y-m2.x.y, m1.x.z-m2.x.z, m1.x.w-m2.x.w },
		{ m1.y.x-m2.y.x, m1.y.y-m2.y.y, m1.y.z-m2.y.z, m1.y.w-m2.y.w },
		{ m1.z.x-m2.z.x, m1.z.y-m2.z.y, m1.z.z-m2.z.z, m1.z.w-m2.z.w },
		{ m1.w.x-m2.w.x, m1.w.y-m2.w.y, m1.w.z-m2.w.z, m1.w.w-m2.w.w }
	};
	return result;
}


mat4 multiply_m4(mat4 m1, mat4 m2){
	//matrix multiplication 
	mat4 result = {
		{ m1.x.x*m2.x.x + m1.y.x*m2.x.y + m1.z.x*m2.x.z + m1.w.x*m2.x.w, 
		m1.x.y*m2.x.x + m1.y.y*m2.x.y + m1.z.y*m2.x.z + m1.w.y*m2.x.w, 
		m1.x.z*m2.x.x + m1.y.z*m2.x.y + m1.z.z*m2.x.z + m1.w.z*m2.x.w, 
		m1.x.w*m2.x.x + m1.y.w*m2.x.y + m1.z.w*m2.x.z + m1.w.w*m2.x.w
		 },
		{ m1.x.x*m2.y.x + m1.y.x*m2.y.y + m1.z.x*m2.y.z + m1.w.x*m2.y.w, 
		m1.x.y*m2.y.x + m1.y.y*m2.y.y + m1.z.y*m2.y.z + m1.w.y*m2.y.w, 
		m1.x.z*m2.y.x + m1.y.z*m2.y.y + m1.z.z*m2.y.z + m1.w.z*m2.y.w, 
		m1.x.w*m2.y.x + m1.y.w*m2.y.y + m1.z.w*m2.y.z + m1.w.w*m2.y.w
		 },
		{ m1.x.x*m2.z.x + m1.y.x*m2.z.y + m1.z.x*m2.z.z + m1.w.x*m2.z.w, 
		m1.x.y*m2.z.x + m1.y.y*m2.z.y + m1.z.y*m2.z.z + m1.w.y*m2.z.w, 
		m1.x.z*m2.z.x + m1.y.z*m2.z.y + m1.z.z*m2.z.z + m1.w.z*m2.z.w, 
		m1.x.w*m2.z.x + m1.y.w*m2.z.y + m1.z.w*m2.z.z + m1.w.w*m2.z.w
		 },
		{ m1.x.x*m2.w.x + m1.y.x*m2.w.y + m1.z.x*m2.w.z + m1.w.x*m2.w.w, 
		m1.x.y*m2.w.x + m1.y.y*m2.w.y + m1.z.y*m2.w.z + m1.w.y*m2.w.w, 
		m1.x.z*m2.w.x + m1.y.z*m2.w.y + m1.z.z*m2.w.z + m1.w.z*m2.w.w, 
		m1.x.w*m2.w.x + m1.y.w*m2.w.y + m1.z.w*m2.w.z + m1.w.w*m2.w.w
		 }
	};

	return result;
}


mat4 invert_m4(mat4 m){
	return result;
}


mat4 transpose_m4(mat4 m){
	return result;
}


mat4 multiply_m4v4(mat4 m, vec4 v){
	return result;
}

