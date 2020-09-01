//sum over 1+1/2 + 1/3 + ... till the sum does not change by more than 0.001
#include<stdio.h>

int main(){
	double n=1;
	double sum=0;
	while(1/n >0.001){
		sum=sum+1/n;
		n++;
	}
	
	printf("sum = %lf \n",sum);

	return 0;
}