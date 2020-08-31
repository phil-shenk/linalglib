#ifndef _LINALGLIB_H_
#define _LINALGLIB_H_

typedef struct
{
	float x;
	float y;
	float z;
	float w;
} vec4;

void print_v4(vec4 v);

vec4 scale(float s, vec4 v);

vec4 add(vec4 v1, vec4 v2);

vec4 subtract(vec4 v1, vec4 v2);

float magnitude(vec4 v);

vec4 normalize(vec4 v);

float dot(vec4 v1, vec4 v2);

vec4 cross(vec4 v1, vec4 v2);



#endif
