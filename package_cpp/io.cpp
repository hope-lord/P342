#include<iostream>
#include<vector>
#include<complex>
using namespace std;

void get_file(FILE *f,int LIMIT,vector<vector<double>> *ar,vector<double> *br=NULL){
	double a;
	for(int i=0;i<LIMIT;i++){
		vector<double> m;
		for(int j=0;j<LIMIT;j++){
			fscanf(f,"%lf",&a);
			m.push_back(a);
		}
		ar->push_back(m);
		if (br!=NULL){
			fscanf(f,"%lf",&a);
			br->push_back(a);
		}
		//cout<<"Here\n";
	}
}

/*-------------------------------------------------------------*/

void display_cmplx(complex<double> a){
    complex<double> z=0;
    if(imag(a)<0) cout<<real(a)<<imag(a)<<"j";
    else if(imag(a)==0) cout<<real(a)<<"+"<<imag(a*z)<<"j";
    else cout<<real(a)<<"+"<<imag(a)<<"j";
}

/*------------------------------------------------------------*/

void display_cmplx(vector<complex<double>> &ar){
	int no=ar.size();
	cout<<"[";
	for(int i=0;i<no;i++){
		display_cmplx(ar[i]);
        cout<<"  ";	
    }
	cout<<"\b\b]\n";
}

/*----------------------------------------------------*/

void display_matrix(vector<vector<double>> &ar){
	int row=ar.size();
	int column=ar[0].size();
	cout<<"[";
	for(int i=0;i<column;i++){
		cout<<"[";
		for(int j=0;j<row;j++){
			printf("%0.4f ",ar[i][j]);
			}
		if(i<row-1)cout<<"\b]\n";
		else cout<<"\b]]\n";
	}
}

/*-------------------------------------------------------------*/

void display_vector(vector<double> &ar){
	int no=ar.size();
	cout<<"[";
	for(int i=0;i<no;i++)
		printf("%0.4f ",ar[i]);	
	cout<<"\b]\n";
}

/*------------------------------------------------------------------*/

void print_to_file(FILE *f,vector<vector<double>> vec){
	int n=vec.size();
	for(int j=0;j<vec[0].size();j++){
		for(int i=0;i<n;i++){
			if(i<n-1) fprintf(f,"%lf ",vec[i][j]);
			else fprintf(f,"%lf\n",vec[i][j]);
		}
	}
	fclose(f);
}