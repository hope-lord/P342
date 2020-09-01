/*Find the average distance between two points on a 
(b) 6 by 6 two-dimensional grid (no diagonal connections):
*/
#include<stdio.h>
#include<stdlib.h>
int main(){
	float arr[36][2];
	float num_sum=0;
	float sum=0;
	for(int j=0;j<6;j++){
		for(int i=0;i<6;i++){
			arr[6*j+i][0]=i;
			arr[6*j+i][1]=j;
		}
	}
	for(int i=0;i<36;i++){
		for(int j=0;j<36;j++){
			float x=abs(arr[j][0]-arr[i][0]);
			float y=abs(arr[j][1]-arr[i][1]);
			sum+=y+x;
			num_sum++;
		}
	}
	printf("Avg. Dist = %f\n",sum/num_sum);
	return 0;
}
/*
Output:
Avg. Dist = 3.888889
*/