/*Find the average distance between two points on a 
(a) straight line made of discrete N (=6) points:
*/
#include<stdio.h>
#include<stdlib.h>
int main(){
	float arr[]={1,2,3,4,5,6};
	float num_sum=0;
	float sum=0;
	for(int i=0;i<6;i++){
		for(int j=0;j<6;j++){
			sum+= abs(arr[j]-arr[i]);
			num_sum++;
		}
	}
	printf("Avg. Dist=%f\n",sum/num_sum);
	return 0;
}
/*
Output:
Avg. Dist=1.944444
*/