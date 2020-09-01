/*Create two vectors of type A=(a1,a2,a3) and B=(b1,b2,b3) with numbers of your choice (but
       not random numbers) in the code itself. Find A+B and A.B (dot product).
*/
#include<stdio.h>

int main(){
	float A[]={2,-5.5,8};
	float B[]={3,0,2.8};
	float A_plus_B[3];
	float A_dot_B=0;
	for(int i=0;i<3;i++){
		A_plus_B[i]=A[i]+B[i];
		A_dot_B+= A[i]*B[i];
	}
	printf("A+B= [%f,%f,%f]\n",A_plus_B[0],A_plus_B[1],A_plus_B[2]);
	printf("A.B= %f\n",A_dot_B);
	return 0;
}
/*
Output:
A+B= [5.000000,-5.500000,10.800000]
A.B= 28.400000
*/