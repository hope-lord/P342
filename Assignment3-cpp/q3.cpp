#include<iostream>
using namespace std;
#define LIMIT 3

void swap(float &a,float &b){
	float t=a;a=b;b=t;
}
bool partial_pivot(float ar[][LIMIT],float br[][LIMIT]){
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
						swap(br[j][t],br[i][t]);
					}
					i=LIMIT;
				}
			}
		}
	}
	return true;
}

void gauss_jordan(float a[][LIMIT],float br[][LIMIT]){
	float ar[LIMIT][LIMIT];
	for(int i=0;i<LIMIT;i++){
		for(int j=0;j<LIMIT;j++){ar[i][j]=a[i][j];}
	}
	for(int i=0;i<LIMIT;i++){
		bool c=partial_pivot(ar,br);
		if(!c) {cout<<"WARNING: DETERMINANT IS 0."<<endl;return;}
		float pivot=ar[i][i];
		for(int j=0;j<LIMIT;j++){ar[i][j]/=pivot;br[i][j]/=pivot;}
		for(int j=0;j<LIMIT;j++){
			if(i==j or ar[j][i]==0)continue;
			else{
				float fact=ar[j][i];
				for(int t=0;t<LIMIT;t++){
					ar[j][t]-=fact*ar[i][t];
					br[j][t]-=fact*br[i][t];
				}
			}
		}
	}
}
void multiplication(float ar[][LIMIT],float br[][LIMIT]){
	cout<<"Matrix Multiplication=\n[";
	for(int i=0;i<LIMIT;i++){
		cout<<"[";
		for(int j=0;j<LIMIT;j++){
			float sum=0;
			for(int t=0;t<LIMIT;t++){
				sum+=ar[i][t]*br[t][j];
			}
			cout<<sum<<" ";
		}
		if (i==LIMIT-1)cout<<"]]\n";
		else cout<<"]\n";
	}
}
int main(){
	float ar[LIMIT][LIMIT],
	Inv[][LIMIT]={{1,0,0},{0,1,0},{0,0,1}};
	FILE* f=fopen("q3.txt","r");
	for(int i=0;i<LIMIT;i++){
		for(int j=0;j<LIMIT;j++){
			fscanf(f,"%f",&ar[i][j]);
		}
	}
	fclose(f);
	cout<<"Inverse of given matrix=\n[";
	gauss_jordan(ar,Inv);
	for(int i=0;i<LIMIT;i++){
		cout<<"[";
		for(int j=0;j<LIMIT;j++){
			cout<<Inv[i][j]<<" ";
		}
		if (i==LIMIT-1)cout<<"]]\n";
		else cout<<"]\n";
	}
	
	multiplication(ar,Inv);
}
/*
Output:
Inverse of given matrix=
[[-3 3 -7 ]
[1 1 0 ]
[1 0 1 ]]
Matrix Multiplication=
[[1 0 0 ]
[0 1 0 ]
[0 0 1 ]]
*/