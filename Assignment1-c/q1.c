//add 1+2+3+ ... 100 WITHOUT using the formula n(n+1)/2
#include<stdio.h>


int main(){
	int n=100;
	int sum=0;
	int i=1;
	while(i<=n){
		sum=sum+i;
		i++;
	}
	
	printf("sum = %d \n",sum);

	return 0;
}