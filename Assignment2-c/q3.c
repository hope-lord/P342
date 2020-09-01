/*Create 3x3 matrices M=(a11,a12 … a33) and N=(b11,b12, …, b33) with numbers of your
choice (zeros, negatives and positives but not random numbers) in two separate files. Read
the matrices from the files. Find M x A and M x N.

Taking A from q2.
*/
#include<stdio.h>

int main(){
	float A[]={2,-5.5,8};
	FILE *file_m=fopen("matrix_M.txt","r");
	FILE *file_n=fopen("matrix_N.txt","r");
	float M[3][3],N[3][3];
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			fscanf(file_m,"%f",&M[i][j]);
			fscanf(file_n,"%f",&N[i][j]);
		}
	}
	fclose(file_n);fclose(file_m);
	float MXN[3][3],MXA[3];
	for(int i=0;i<3;i++){
		float sum=0;
		for(int k=0;k<3;k++){
			sum+= M[i][k]*A[k];
		}
		MXA[i]=sum;
	}
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			float sum=0;
			for(int k=0;k<3;k++){
				sum+=M[i][k]*N[k][j];
			}
			MXN[i][j]=sum;
		}
	}
	printf("MXA= [ ");
	for(int i=0;i<3;i++){
		printf("%f ",MXA[i]);
	}
	printf("]\nMXN= \n");

	for(int i=0;i<3;i++){
		printf("[");
		for(int j=0;j<3;j++){
			printf("%f ",MXN[i][j]);
		}
		printf("]\n");
	}
	return 0;
}
/*
Output:
MXA= [ 24.750000 78.400002 -30.700001 ]
MXN=
[24.750000 -51.500000 129.300003 ]
[14.700001 28.000000 67.200005 ]
[62.599998 -71.000000 80.400002 ]
*/