#ifndef _LINALGLIB_H_
#define _LINALGLIB_H_

typedef struct
{
	float x;
	float y;
	float z;
	float w;
} vec4;

/*
 * matrix where each column is a vec4 (column-major)
 */
typedef struct
{
	vec4 x;
	vec4 y;
	vec4 z;
	vec4 w;
} mat4;

void print_v4(vec4 v);

vec4 scale_v4(float s, vec4 v);

vec4 add_v4(vec4 v1, vec4 v2);

vec4 subtract_v4(vec4 v1, vec4 v2);

float magnitude_v4(vec4 v);

vec4 normalize_v4(vec4 v);

float dot_v4(vec4 v1, vec4 v2);

vec4 cross_v4(vec4 v1, vec4 v2);

/* matrix operations */


void print_m4(mat4 m);
mat4 scale_m4(float s, mat4 m);
mat4 add_m4(mat4 m1, mat4 m2);
mat4 subtract_m4(mat4 m1, mat4 m2);
mat4 multiply_m4(mat4 m1, mat4 m2);
mat4 invert_m4(mat4 m);
mat4 transpose_m4(mat4 m);
mat4 multiply_m4v4(mat4 m, vec4 v);


#endif
