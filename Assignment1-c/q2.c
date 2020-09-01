//factorial n! say for n=10 or 15, check and trap negative integers
#include<stdio.h>

int main(){
	int n;long long int mul=1;
	printf("Give the integer.\n");
	scanf("%d",&n);
	if(n<0) printf("Give the non-negative integer.\n");
	else{
		int i=1;
		while(i<=n){
			mul*=i;
			i++;
		}
		printf("%d! = %lld \n",n,mul);
	}
	return 0;
}