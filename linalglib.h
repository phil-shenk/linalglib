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
mat4 minor_m4(mat4 m);
mat4 cofactor_from_minors_m4(mat4 m);
float determinant_with_minors_m4(mat4 minors, mat4 m);
mat4 transpose_m4(mat4 m);
vec4 multiply_m4v4(mat4 m, vec4 v);

/* constants */
mat4 identity();

/* transformations */
mat4 translation(float x, float y, float z);
mat4 scaling(float Bx, float By, float Bz);
mat4 z_rotation(float theta);
mat4 x_rotation(float theta);
mat4 y_rotation(float theta);
/* arbitrary rotation about a line through the origin */
mat4 arb_rotation_origin(float theta, float ax, float ay, float az);
/* arbitrary rotation about a line throuth the objects center of mass, in world frame */
mat4 arb_rotation_com_world(mat4 ctm, float theta, float ax, float ay, float az);

/* look at point */
mat4 look_at(vec4 eyePoint, vec4 atPoint, vec4 upVector);

/* orthographic */
mat4 ortho(float left, float right, float bottom, float top, float near, float far);

/* frustum */
mat4 frustum(float left, float right, float bottom, float top, float near, float far);

mat4 perspective(float fovy, float aspect, float near, float far);
#endif
