#include <stdio.h>

//map indices of 3x3 matrices to 4x4 with a removed row and col
//i.e. input desired row/col of 3x3 remnant matrix and return
//the indices for the 4x4 matrix elements that you want
int map3x3to4x4(int i3, int removedIndex)
{
	int i4 = i3;
	if(i3 >= removedIndex){
		i4++;
	}
	return i4;
}

int main(void)
{
	char n[4] = {'x','y','z','w'};

	printf("//matrix of minor\n");
	printf("mat4 result = {\n");
	//iterate over columns of output matrix (m.COL.row)
	for(int col=0; col<4; col++){
		printf("{ ");
		//iterate over rows/entries of each col (m.col.ROW)
		for(int row=0; row<4; row++){
			//print m_row_col
			//i.e. the determinant of M 
			//where the current row and col are removed
		
			//char (0-3 x-w) of elements of determinant
			//cm = determinant COL MAP
			//rm = determinant ROW MAP
			char cm[9];
			char rm[9];
			for(int dcol=0; dcol<3; dcol++){
				//get corresp 4x4 col. index for this 3x3 determinant
				int c = map3x3to4x4(dcol, col);
				for(int drow=0; drow<3; drow++){
					//get corresp 4x4 row index for 3x3 det.
					int r = map3x3to4x4(drow, row);
					cm[dcol*3+drow] = n[c];
					rm[dcol*3+drow] = n[r];
				}
			}		
			//now detColMap and detRowMap now contain the 'x-w' char 
			//for the corresponding element of the determinant
			//so here i print the determinant
			printf("//det of col %d row %d \n",col,row);
			printf( "m.%c.%c*m.%c.%c*m.%c.%c + "
				"m.%c.%c*m.%c.%c*m.%c.%c + "
				"m.%c.%c*m.%c.%c*m.%c.%c \n - "
				"m.%c.%c*m.%c.%c*m.%c.%c - "
				"m.%c.%c*m.%c.%c*m.%c.%c - "
				"m.%c.%c*m.%c.%c*m.%c.%c\n",
				cm[0],rm[0],cm[4],rm[4],cm[8],rm[8],
				cm[1],rm[1],cm[5],rm[5],cm[6],rm[6],
				cm[2],rm[2],cm[3],rm[3],cm[7],rm[7],
				cm[6],rm[6],cm[4],rm[4],cm[2],rm[2],
				cm[7],rm[7],cm[5],rm[5],cm[0],rm[0],
				cm[8],rm[8],cm[3],rm[3],cm[1],rm[1]
				);

			if(row<3){
				printf(", ");
			}
			printf("\n");
		}
		printf("}");
		//dont make comma on last line
		if(col<3){
			printf(",");
		}
		printf("\n");
	}	
	printf("};\n");
	
	int z = map3x3to4x4(2,1);
	printf("%d\n", z);
		
	z = map3x3to4x4(2,3);
	printf("%d\n", z);
}

//z = map3x3to4x4(2,3);
//printf("%d", z)

/*
 *
	mat4 result = {
                { m1.x.x-m2.x.x, m1.x.y-m2.x.y, m1.x.z-m2.x.z, m1.x.w-m2.x.w },
                { m1.y.x-m2.y.x, m1.y.y-m2.y.y, m1.y.z-m2.y.z, m1.y.w-m2.y.w },
                { m1.z.x-m2.z.x, m1.z.y-m2.z.y, m1.z.z-m2.z.z, m1.z.w-m2.z.w },
                { m1.w.x-m2.w.x, m1.w.y-m2.w.y, m1.w.z-m2.w.z, m1.w.w-m2.w.w }
        };
*/
