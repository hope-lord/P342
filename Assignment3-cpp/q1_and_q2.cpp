#include<iostream>
using namespace std;
#define LIMIT 3

void swap(float &a,float &b){
	float t=a;a=b;b=t;
}
bool partial_pivot(float ar[][LIMIT],float br[]){
	float zero[]={0,0,0};
	for(int i=0;i<LIMIT;i++){
		if (ar[i][i]==0){
			bool isit=true;
			for(int t=0;t<LIMIT;t++){
				if(zero[t]!=ar[i][t])isit=false; 
			}
			if(isit) return (!isit);
			for(int j=i+1;i<LIMIT;i++){
				if(ar[j][i]!=0){
					for(int t=0;t<LIMIT;t++){
						swap(ar[j][t],ar[i][t]);
					}
					swap(br[j],br[i]);
					i=LIMIT;
				}
			}
		}
	}
	return true;
}

void gauss_jordan(float a[][LIMIT],float br[]){
	float ar[LIMIT][LIMIT];
	for(int i=0;i<LIMIT;i++){
		for(int j=0;j<LIMIT;j++){ar[i][j]=a[i][j];}
	}
	for(int i=0;i<LIMIT;i++){
		bool c=partial_pivot(ar,br);
		if(!c) {cout<<"WARNING: DETERMINANT IS 0."<<endl;return;}
		float pivot=ar[i][i];
		br[i]/=pivot;
		for(int j=0;j<LIMIT;j++){ar[i][j]/=pivot;}
		for(int j=0;j<LIMIT;j++){
			if(i==j or ar[j][i]==0)continue;
			else{
				float fact=ar[j][i];
				for(int t=0;t<LIMIT;t++){
					ar[j][t]-=fact*ar[i][t];
				}
				br[j]-=fact*br[i];
			}
		}
	}
	for(int i=0;i<LIMIT;i++){
		cout<<br[i]<<" ";
	}
}
int main(){
	float ar1[LIMIT][LIMIT],ar2[LIMIT][LIMIT];
	float br1[LIMIT],br2[LIMIT];
	FILE* f1=fopen("q1.txt","r");
	FILE* f2=fopen("q2.txt","r");
	for(int i=0;i<LIMIT;i++){
		for(int j=0;j<LIMIT;j++){
			fscanf(f1,"%f",&ar1[i][j]);
			fscanf(f2,"%f",&ar2[i][j]);
		}
		fscanf(f1,"%f",&br1[i]);
		fscanf(f2,"%f",&br2[i]);
	}
	fclose(f1);fclose(f2);
	cout<<"For q1 Solution=[";
	gauss_jordan(ar1,br1);
	cout<<"]\n";

	cout<<"For q2 Solution=[";
	gauss_jordan(ar2,br2);
	cout<<"]\n";
	return 0;
}
/*
Output:
For q1 Solution=[3 1 -2 ]
For q2 Solution=[-2 -2 1 ]
*/