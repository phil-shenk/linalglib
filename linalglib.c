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
 * the identity, useful to have
 */
mat4 identity(void){
	mat4 result = {
		{1,0,0,0},
		{0,1,0,0},
		{0,0,1,0},
		{0,0,0,1}
	};
	return result;
}

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

/*
 * scale the matrix m by scalar s
 */
mat4 scale_m4(float s, mat4 m){
	mat4 result = {
		{ s*m.x.x, s*m.x.y, s*m.x.z, s*m.x.w },
		{ s*m.y.x, s*m.y.y, s*m.y.z, s*m.y.w },
		{ s*m.z.x, s*m.z.y, s*m.z.z, s*m.z.w },
		{ s*m.w.x, s*m.w.y, s*m.w.z, s*m.w.w }
	};

	return result;
}

/*
 * add two matrices, return m1+m2
 */
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

/*
 * subtract two matrices, return m1 - m2
 */
mat4 subtract_m4(mat4 m1, mat4 m2){
	mat4 result = {
		{ m1.x.x-m2.x.x, m1.x.y-m2.x.y, m1.x.z-m2.x.z, m1.x.w-m2.x.w },
		{ m1.y.x-m2.y.x, m1.y.y-m2.y.y, m1.y.z-m2.y.z, m1.y.w-m2.y.w },
		{ m1.z.x-m2.z.x, m1.z.y-m2.z.y, m1.z.z-m2.z.z, m1.z.w-m2.z.w },
		{ m1.w.x-m2.w.x, m1.w.y-m2.w.y, m1.w.z-m2.w.z, m1.w.w-m2.w.w }
	};
	return result;
}

/* 
 * multiply two matrices, return m1*m2
 * note: this is not element-wise multiplication
 */
mat4 multiply_m4(mat4 m1, mat4 m2){
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

/*
 * returns the inverse of an invertible matrix m
 * based on Cramer's rule
 * i.e. the fact that the inverse is the adjugate matrix scaled by the inverse of the determinant
 * where the adjugate matrix is the transpose of the matrix of cofactors
 * where the cofactors are the (i,j) minors times (-1)^(i+j)
 * (i.e. multiply the matrix of minors by a checkerboard of -1 and +1)
 * where the (i,j) minor is obtained by deleting the ith row and jth column
 * and taking the determinant of what is left
 */
mat4 invert_m4(mat4 m){
	// matrix of minors
	mat4 minor = minor_m4(m);
	mat4 cofactor = cofactor_from_minors_m4(minor);
	mat4 adjugate = transpose_m4(cofactor);
	float determinant = determinant_with_minors_m4(minor, m);
	float oneOverDeterminant = 1/determinant;	
	mat4 m_inv = scale_m4(oneOverDeterminant, adjugate);
	return m_inv;
}

/*
 * return the matrix containing all of the minors of the matrix m
 * the (i,j) minor is obtained by removing the i row and j column,
 * and taking the determinant of the remaining sub-matrix
 * I didn't type this code by hand, I generated it using a script
 * that I made here: #TODO insert link
 */
mat4 minor_m4(mat4 m){
	//matrix of minor
	mat4 result = {
	{ //det of col 0 row 0
	m.y.y*m.z.z*m.w.w + m.y.z*m.z.w*m.w.y + m.y.w*m.z.y*m.w.z
	 - m.w.y*m.z.z*m.y.w - m.w.z*m.z.w*m.y.y - m.w.w*m.z.y*m.y.z
	,
	//det of col 0 row 1
	m.y.x*m.z.z*m.w.w + m.y.z*m.z.w*m.w.x + m.y.w*m.z.x*m.w.z
	 - m.w.x*m.z.z*m.y.w - m.w.z*m.z.w*m.y.x - m.w.w*m.z.x*m.y.z
	,
	//det of col 0 row 2
	m.y.x*m.z.y*m.w.w + m.y.y*m.z.w*m.w.x + m.y.w*m.z.x*m.w.y
	 - m.w.x*m.z.y*m.y.w - m.w.y*m.z.w*m.y.x - m.w.w*m.z.x*m.y.y
	,
	//det of col 0 row 3
	m.y.x*m.z.y*m.w.z + m.y.y*m.z.z*m.w.x + m.y.z*m.z.x*m.w.y
	 - m.w.x*m.z.y*m.y.z - m.w.y*m.z.z*m.y.x - m.w.z*m.z.x*m.y.y
	
	},
	{ //det of col 1 row 0
	m.x.y*m.z.z*m.w.w + m.x.z*m.z.w*m.w.y + m.x.w*m.z.y*m.w.z
	 - m.w.y*m.z.z*m.x.w - m.w.z*m.z.w*m.x.y - m.w.w*m.z.y*m.x.z
	,
	//det of col 1 row 1
	m.x.x*m.z.z*m.w.w + m.x.z*m.z.w*m.w.x + m.x.w*m.z.x*m.w.z
	 - m.w.x*m.z.z*m.x.w - m.w.z*m.z.w*m.x.x - m.w.w*m.z.x*m.x.z
	,
	//det of col 1 row 2
	m.x.x*m.z.y*m.w.w + m.x.y*m.z.w*m.w.x + m.x.w*m.z.x*m.w.y
	 - m.w.x*m.z.y*m.x.w - m.w.y*m.z.w*m.x.x - m.w.w*m.z.x*m.x.y
	,
	//det of col 1 row 3
	m.x.x*m.z.y*m.w.z + m.x.y*m.z.z*m.w.x + m.x.z*m.z.x*m.w.y
	 - m.w.x*m.z.y*m.x.z - m.w.y*m.z.z*m.x.x - m.w.z*m.z.x*m.x.y
	
	},
	{ //det of col 2 row 0
	m.x.y*m.y.z*m.w.w + m.x.z*m.y.w*m.w.y + m.x.w*m.y.y*m.w.z
	 - m.w.y*m.y.z*m.x.w - m.w.z*m.y.w*m.x.y - m.w.w*m.y.y*m.x.z
	,
	//det of col 2 row 1
	m.x.x*m.y.z*m.w.w + m.x.z*m.y.w*m.w.x + m.x.w*m.y.x*m.w.z
	 - m.w.x*m.y.z*m.x.w - m.w.z*m.y.w*m.x.x - m.w.w*m.y.x*m.x.z
	,
	//det of col 2 row 2
	m.x.x*m.y.y*m.w.w + m.x.y*m.y.w*m.w.x + m.x.w*m.y.x*m.w.y
	 - m.w.x*m.y.y*m.x.w - m.w.y*m.y.w*m.x.x - m.w.w*m.y.x*m.x.y
	,
	//det of col 2 row 3
	m.x.x*m.y.y*m.w.z + m.x.y*m.y.z*m.w.x + m.x.z*m.y.x*m.w.y
	 - m.w.x*m.y.y*m.x.z - m.w.y*m.y.z*m.x.x - m.w.z*m.y.x*m.x.y
	
	},
	{ //det of col 3 row 0
	m.x.y*m.y.z*m.z.w + m.x.z*m.y.w*m.z.y + m.x.w*m.y.y*m.z.z
	 - m.z.y*m.y.z*m.x.w - m.z.z*m.y.w*m.x.y - m.z.w*m.y.y*m.x.z
	,
	//det of col 3 row 1
	m.x.x*m.y.z*m.z.w + m.x.z*m.y.w*m.z.x + m.x.w*m.y.x*m.z.z
	 - m.z.x*m.y.z*m.x.w - m.z.z*m.y.w*m.x.x - m.z.w*m.y.x*m.x.z
	,
	//det of col 3 row 2
	m.x.x*m.y.y*m.z.w + m.x.y*m.y.w*m.z.x + m.x.w*m.y.x*m.z.y
	 - m.z.x*m.y.y*m.x.w - m.z.y*m.y.w*m.x.x - m.z.w*m.y.x*m.x.y
	,
	//det of col 3 row 3
	m.x.x*m.y.y*m.z.z + m.x.y*m.y.z*m.z.x + m.x.z*m.y.x*m.z.y
	 - m.z.x*m.y.y*m.x.z - m.z.y*m.y.z*m.x.x - m.z.z*m.y.x*m.x.y
	
	}
	};

	return result;
}

/*
 * returns the matrix containing the cofactors of m
 * where the cofactor is the minor * (-1)^(i+j)
 * *NOTE* this version requires the minors as an input to optimize
 * when it is used in conjunction with determinant_with_minors_m4
 */
mat4 cofactor_from_minors_m4(mat4 minors){
	mat4 result = {
		{    minors.x.x, -1*minors.x.y,    minors.x.z, -1*minors.x.w },
		{ -1*minors.y.x,    minors.y.y, -1*minors.y.z,    minors.y.w },
		{    minors.z.x, -1*minors.z.y,    minors.z.z, -1*minors.z.w },
		{ -1*minors.w.x,    minors.w.y, -1*minors.w.z,    minors.w.w }
	};
	return result;
}

//#TODO: make a version of cofactor_m4 that calculates minors within the function
// not really necessary for now, it would just be an unnecessary call to use such
// a version of the function in the invert_m4

/*
 * take the determinant of matrix m, using pre-calculated matrix of minors
 * (pre-calculated minors to optimize use in conjunction with cofactor calculation)
 */
float determinant_with_minors_m4(mat4 minors, mat4 m){
	float det = m.x.x*minors.x.x - m.y.x*minors.y.x + m.z.x*minors.z.x - m.w.x*minors.w.x;
	return det;
}

/*
 * return the transpose of matrix m
 */
mat4 transpose_m4(mat4 m){
	mat4 result = {
		{ m.x.x, m.y.x, m.z.x, m.w.x },
		{ m.x.y, m.y.y, m.z.y, m.w.y },
		{ m.x.z, m.y.z, m.z.z, m.w.z },
		{ m.x.w, m.y.w, m.z.w, m.w.w }
	};
	return result;
}

/*
 * multiply a matrix m by a vector v
 */
vec4 multiply_m4v4(mat4 m, vec4 v){
	vec4 result =  
		{ m.x.x*v.x + m.y.x*v.y + m.z.x*v.z + m.w.x*v.w ,
		  m.x.y*v.x + m.y.y*v.y + m.z.y*v.z + m.w.y*v.w ,
		  m.x.z*v.x + m.y.z*v.y + m.z.z*v.z + m.w.z*v.w ,
		  m.x.w*v.x + m.y.w*v.y + m.z.w*v.z + m.w.w*v.w };
	return result;
}

/*
 * returns translation matrix to translate by (x,y,z)
 */
mat4 translation(float x, float y, float z)
{
	mat4 result = {
		{1,0,0,0},
		{0,1,0,0},
		{0,0,1,0},
		{x,y,z,1}
	};
	return result;
}

/*
 * returns scaling matrix
 * scales W.R.T. ORIGIN by (Bx, By, Bz)
 */
mat4 scaling(float Bx, float By, float Bz)
{
	mat4 result = {
		{Bx, 0, 0, 0},
		{0, By, 0, 0},
		{0, 0, Bz, 0},
		{0, 0, 0, 1}
	};
	return result;
}

/*
 * rotates by theta radians about z-axis
 */
mat4 z_rotation(float theta)
{
	mat4 result = {
		{cos(theta), sin(theta), 0, 0},
		{-1*sin(theta), cos(theta), 0, 0},
		{0, 0, 1, 0},
		{0, 0, 0, 1}
	};
	return result;
}

/*
 * rotates by theta radians about x-axis
 */
mat4 x_rotation(float theta)
{
	mat4 result = {
		{1, 0, 0, 0},
		{0, cos(theta), sin(theta), 0},
		{0, -1*sin(theta), cos(theta), 0},
		{0, 0, 0, 1}
	};
	return result;
}

/*
 * rotates by theta radians about y-axis
 */
mat4 y_rotation(float theta)
{
	mat4 result = {
		{cos(theta), 0, -1*sin(theta), 0},
		{0, 1, 0, 0},
		{sin(theta), 0, cos(theta), 0},
		{0, 0, 0, 1}
	};
	return result;
}

/*
 * rotate by theta radians about the vector <ax,ay,az> centered about the origin
 * returns the matrix that will perform this rotation
 */
mat4 arb_rotation_origin(float theta, float ax, float ay, float az)
{
	vec4 a = {ax,ay,az,0};
	a = normalize_v4(a);
	ax = a.x;
	ay = a.y;
	az = a.z;
	float d = sqrt(az*az + ay*ay);
	// #TODO: use some tolerance instead of checking for strict equality
	// (this may break for super small values of d)
	if(d==0){
		return x_rotation(theta);
	}
	mat4 Rx = {
		{1,0,0,0},
		{0,az/d,ay/d,0},
		{0,-ay/d,az/d,0},
		{0,0,0,1}
	};
	mat4 Ry = {
		{d,0,-ax,0},
		{0,1,0,0},
		{ax,0,d,0},
		{0,0,0,1}
	};
	mat4 Rz = z_rotation(theta);
	return multiply_m4(
		transpose_m4(Rx),   multiply_m4(
		Ry,                 multiply_m4(
		Rz,                 multiply_m4(
		transpose_m4(Ry),
		Rx
		))));
}

/* 
 * rotate about an arbitrary line through the object's center of mass, in world frame
 * returns the matrix that will perform this rotation
 */
mat4 arb_rotation_com_world(mat4 ctm, float theta, float ax, float ay, float az){
	mat4 init_ctm = ctm;
	// figure out where the COM of the supplied ctm is
	// o = objectOrigin
	vec4 o = {0.0,0.0,0.0,1};
	o = multiply_m4v4(init_ctm, o);

	// translation to origin
	mat4 toOrigin = translation(-o.x, -o.y, -o.z);
	
	// arbitrary world-space rotation centered about origin
	mat4 rotAtOrigin = arb_rotation_origin(theta, ax, ay, az);

	// translate object back from origin
	mat4 fromOrigin = translation(o.x, o.y, o.z);

	// result = toOrigin, then rotAtOrigin, then fromOrigin
	// i.e. fromOrigin*rotAtOrigin*toOrigin
	mat4 result = multiply_m4(fromOrigin, multiply_m4(rotAtOrigin, multiply_m4(toOrigin, ctm)));
	return result;
}



/*
 * look at point
 * returns model-view matrix based on camera position and orientation
 */
mat4 look_at(vec4 eyePoint, vec4 atPoint, vec4 upVector)
{
	float x = eyePoint.x;
	float y = eyePoint.y;
	float z = eyePoint.z;

	vec4 n = normalize_v4(subtract_v4(atPoint, eyePoint));
	float nx = n.x;
	float ny = n.y;
	float nz = n.z;

	vec4 u = normalize_v4(cross_v4(upVector, n));
	float ux = u.x;
	float uy = u.y;
	float uz = u.z;

	vec4 v = normalize_v4(cross_v4(n, u));
	float vx = v.x;
	float vy = v.y;
	float vz = v.z;

	mat4 model_view_matrix = {
		{ux, vx, nx, 0},
		{uy, vy, ny, 0},
		{uz, vz, nz, 0},
		{	1*(- x*ux - y*uy - z*uz),
			1*(- x*vx - y*vy - z*vz),
			1*(- x*nx - y*ny - z*nz),
			(1)}
	};
	return model_view_matrix;
}

/* 
 * return the orthographic projection matrix with the given field-of-view parameters
 */
mat4 ortho(float left, float right, float bottom, float top, float near, float far)
{
	mat4 projection_matrix = {
		{2.0/(right-left), 0,0,0},
		{0,2.0/(top-bottom),0,0},
		{0,0,2.0/(near-far),0},
		{-1.0*(right+left)/(right-left), -1.0*(top+bottom)/(top-bottom), -1.0*(near+far)/(far-near), 1.0}
	};
	return projection_matrix;
}

/* 
 * return the frustum matrix for the given field-of-view parameters
 */
mat4 frustum(float left, float right, float bottom, float top, float near, float far)
{
	mat4 projection_matrix = {
		{2.0*near/(right-left), 0,0,0},
		{0,2.0*near/(top-bottom),0,0},
		{(right+left)/(right-left), (top+bottom)/(top-bottom), 1.0*(far+near)/(far-near), 1.0},
		{0,0,-2.0*(far*near)/(far-near),0}
	};
	return projection_matrix;
}

/*
 * return the perspective-projection matrix for the given field-ov-view parameters
 */
mat4 perspective(float fovy, float aspect, float near, float far){
	float top = near*tan(fovy);
	float right = top*aspect;

	mat4 projection_matrix = {
		{near/right, 0, 0, 0},
		{0, near/top, 0, 0},
		{0, 0, (-1*far + near)/(far-near), -1},
		{0, 0,-2*far*near/(far-near),0}
	};
	return projection_matrix;

}
