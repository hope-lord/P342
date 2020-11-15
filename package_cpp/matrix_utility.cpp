#include<iostream>
#include<vector>
#include<complex>
using namespace std;

#ifndef D_t
#define D_t double
#endif
static vector<D_t> null_vector;
static vector<vector<D_t>> null_matrix;


void swap(D_t &a,D_t &b){
	D_t t;
	a=b;
	b=t;
}

/*---------------------------------------------------*/

//This partial pivot is useful in solving linear equations
void partial_pivot_swap(vector<vector<D_t>> &ar,int t,int s,vector<D_t> &br=null_vector,vector<vector<D_t>> &cr=null_matrix){
	int LIMIT=ar.size();
	if (t<0 or t>=LIMIT) return;
	if(s<0 or s>=LIMIT) return;
	vector<D_t> m;
	m=ar[t];
	ar[t]=ar[s];
	ar[s]=m;
	if(cr!=null_matrix){
		m=cr[t];cr[t]=cr[s];cr[s]=m;
	}
	if(br!=null_vector){
		swap(br[s],br[t]);
	}
}

/*---------------------------------------------------*/
bool partial_pivot(vector<vector<D_t>> &ar,vector<D_t> &br=null_vector,vector<vector<D_t>> &cr=null_matrix){
	int LIMIT=ar.size();
	for(int i=0;i<LIMIT;i++){
		if (ar[i][i]==0){
			bool isit=true;
			for(int t=0;t<LIMIT;t++){
				if(0!=ar[i][t])isit=false; 
			}
			if(isit) return (!isit);
			for(int j=i+1;i<LIMIT;i++){
				if(ar[j][i]!=0){
					for(int t=0;t<LIMIT;t++){
						swap(ar[j][t],ar[i][t]);
						if (cr!=null_matrix) swap(cr[j][t],cr[i][t]);
					}
					if (br!=null_vector)swap(br[j],br[i]);
					i=LIMIT;
				}
			}
		}
	}
	return true;
}

/*----------------------------------------------------------------*/

double dot(vector<double> &ar,vector<double> &br){
	int len=ar.size();
	if(len!=br.size()){cout<<"Dimensions are not equal.\n";return 0;}
	double sum=0;
	for(int i=0;i<len;i++) sum+=ar[i]*br[i];
	return sum;
}

/*-------------------------------------------------------------*/

complex<double> dot(vector<complex<double>> &ar,vector<complex<double>> &br){
	int len=ar.size();
	if(len!=br.size()){cout<<"Dimensions are not equal.\n";return 0;}
	complex<double> sum=0;
	for(int i=0;i<len;i++) sum+=ar[i]*br[i];
	return sum;
}

/*--------------------------------------------------------------*/

complex<double> inner_product(vector<complex<double>> &ar,vector<complex<double>> &br){
	vector<complex<double>> ddot;
	for(int i=0;i<ar.size();i++) ddot.push_back(conj(ar[i])) ;
	return dot(ddot,br);
}
/*---------------------------------------------------------------*/

vector<vector<D_t>> matrix_mult(vector<vector<D_t>> &a,vector<vector<D_t>> &b){
	vector<vector<D_t>> axb;
	for(int i=0;i<a.size();i++){
		vector<D_t> m;
		for(int j=0;j<b[0].size();j++){
			D_t sum=0;
			for(int k=0;k<b.size();k++)sum+=a[i][k]*b[k][j];
			m.push_back(sum);
		}
		axb.push_back(m);
	}
	return axb;
}

/*-------------------------------------------------------------*/

vector<D_t> matrix_mult(vector<vector<D_t>> &a,vector<D_t> &b){
	vector<D_t> axb;
	for(int i=0;i<a.size();i++) axb.push_back(dot(a[i],b));
	return axb;
}

/*-------------------------------------------------------------*/

