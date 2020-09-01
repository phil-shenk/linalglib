#include <stdio.h>

int main(void)
{
	char n[4] = {'x','y','z','w'};

	printf("//matrix multiplication \n");
	printf("mat4 result = {\n");
	//iterate over columns of output matrix (m.COL.row)
	for(int col=0; col<4; col++){
		printf("{ ");
		//iterate over rows/entries of each col (m.col.ROW)
		for(int row=0; row<4; row++){
			//print c_row_col
			//sum over m1_row_N*m2_N_col
			//i.e. m1.N.row*m2.col.N
			for(int N=0; N<4; N++){
				printf("m1.%c.%c*m2.%c.%c", n[N],n[row],n[col],n[N]);
				if(N<3){
					printf(" + ");
				}
			}
			if(row<3){
				printf(", ");
			}
			printf("\n");
		}
		printf(" }");
		//dont make comma on last line
		if(col<3){
			printf(",");
		}
		printf("\n");
	}	
	printf("};\n");
}
/*
	mat4 result = {
                { m1.x.x-m2.x.x, m1.x.y-m2.x.y, m1.x.z-m2.x.z, m1.x.w-m2.x.w },
                { m1.y.x-m2.y.x, m1.y.y-m2.y.y, m1.y.z-m2.y.z, m1.y.w-m2.y.w },
                { m1.z.x-m2.z.x, m1.z.y-m2.z.y, m1.z.z-m2.z.z, m1.z.w-m2.z.w },
                { m1.w.x-m2.w.x, m1.w.y-m2.w.y, m1.w.z-m2.w.z, m1.w.w-m2.w.w }
        };
*/
