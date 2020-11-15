#include<iostream>
#include<vector>
#include"matrix_utility.cpp"
using namespace std;



void gauss_jordan(vector<vector<double>> &ar, vector<double> &br=null_vector,vector<vector<double>> &cr=null_matrix){
	int LIMIT=ar.size();
	for(int i=0;i<LIMIT;i++){
		if (ar[i][i]==0){
			bool c=partial_pivot(ar,br,cr);
			if(!c) {cout<<"WARNING: DETERMINANT IS 0.\n";return;}
		}
		double pivot=ar[i][i];
		if (br!=null_vector) br[i]/=pivot;
		for(int j=0;j<LIMIT;j++){
			ar[i][j]/=pivot;
			if (cr!=null_matrix) cr[i][j]/=pivot;
		}
		for(int j=0;j<LIMIT;j++){
			if(i==j or ar[j][i]==0)continue;
			else{
				double fact=ar[j][i];
				for(int t=0;t<LIMIT;t++){
					ar[j][t]-=fact*ar[i][t];
					if (cr!=null_matrix) cr[j][t]-=fact*cr[i][t];
				}
				if(br!=null_vector)br[j]-=fact*br[i];
			}
		}
	}
}

/*-------------------------------------------*/


int LU(vector<vector<double>> &ar,vector<double> &br=null_vector,vector<vector<double>> &cr=null_matrix){
	if (ar.size()!=ar[0].size()){cout<<"The operator matrix is not square one\n";return -1;}
	if(br!=null_vector) {
		if (br.size()!=ar.size()){cout<<"The Dimensions are not equal.\n";return -1;}
	}
	if(cr!=null_matrix) {
		if (cr.size()!=ar.size()){cout<<"The Dimensions are not equal.\n";return -1;}
		if(cr[0].size()!=ar.size()){cout<<"The Dimensions are not equal.\n";return -1;}
	}
	int LIMIT=ar.size();
	int row_rotations=0;
	int i=0;int s=0;bool t=false;
    
	while(i<LIMIT){
		if(!t) s=i;
		vector<double> new_row;
		new_row=ar[i];
		int j=0;
		while(j<LIMIT){
			if(i>j){
				double sum=0;
				for(int k=0;k<j;k++)sum+=ar[i][k]*ar[k][j];
				ar[i][j]=(ar[i][j]-sum)/ar[j][j];
				j++;
			}
			else if(i==j){
				double sum=0;
				for(int k=0;k<j;k++)sum+=ar[i][k]*ar[k][j];
				ar[i][i]-=sum;
				if (ar[i][i]!=0){
					j++;t=false;
				}
				else{
					j=LIMIT;
					t=true;
					ar[i]=new_row;
				}
			}
			else{
				double sum=0;
				for(int k=0;k<i;k++)sum+=ar[i][k]*ar[k][j];
				ar[i][j]-=sum;
				j++;
			}
		}
		if(!t) i++;
		else{
			s++;
			if(s==LIMIT) return -1;
			partial_pivot_swap(ar,i,s,br,cr);
			row_rotations++;
		}
	}
	return row_rotations;
}

/*--------------------------------------------*/

//br or cr is not requird for calculation of determinant but br will have to undergo partial_pivoting
double lu_and_det(vector<vector<double>> &ar,vector<double> &br=null_vector,vector<vector<double>> &cr=null_matrix){
	int LIMIT=ar.size();
	int p=LU(ar,br,cr);
	if(p==-1) return 0;
	double mult=1;
	for(int i=0;i<LIMIT;i++) mult*=ar[i][i];
	if(p%2==0) return mult;
	else return -mult;
}

/*-----------------------------------------------------------*/

void forward_substitution(vector<vector<double>> &ar,vector<double> &br){
	int LIMIT=ar.size();
    for(int i=0;i<LIMIT;i++){
        double sum=0;
        for(int j=0;j<i;j++) sum+=ar[i][j]*br[j];
        br[i]-=sum;
	}
}

/*---------------------------------------------------------------*/

void backward_substitution(vector<vector<double>> &ar,vector<double> &br){
	int LIMIT=ar.size();
    int i = LIMIT - 1;
    while (i > -1){
        double sum = 0;
        for(int j=i+1;j<LIMIT;j++) sum += ar[i][j] * br[j];
        br[i] -= sum;
        br[i] /= ar[i][i];
        i--;
	}
}

/*--------------------------------------------------------------------*/

vector<double> solve(vector<vector<double>> &ar,vector<double> &br){
	double s=lu_and_det(ar,br);
	if(s==0)cout<<"Determinant of the operator is zero. Hence no unique solution possible\n";
	else{
		forward_substitution(ar,br);
		backward_substitution(ar,br);
	}
	return br;
}

/*-----------------------------------------------------------------------*/

vector<vector<double>> inv_lu(vector<vector<double>> &ar){
	int LIMIT=ar.size();
    vector<vector<double>> inv;
	for(int i=0;i<LIMIT;i++) {
		vector<double> m;
		for(int j=0;j<LIMIT;j++){
			if(i==j) m.push_back(1);
			else m.push_back(0);
		}
		inv.push_back(m);
	}
	double s=lu_and_det(ar,null_vector,inv);
	if(s==0) cout<<"Determinant of the operator is zero. Hence no unique solution possible\n";
	else{
	    for(int i=0;i<LIMIT;i++){
			vector<double> column;
	    	for(int j=0;j<LIMIT;j++)column.push_back(inv[j][i]);
    		forward_substitution(ar,column);
            backward_substitution(ar,column);
		    for(int j=0;j<LIMIT;j++)inv[j][i]=column[j];
	    }
    }
	return inv;
}

/*--------------------------------------------------------------------*/
vector<vector<double>> inv(vector<vector<double>> &ar){
	int LIMIT=ar.size();
    vector<vector<double>> inv;
	for(int i=0;i<LIMIT;i++) {
		vector<double> m;
		for(int j=0;j<LIMIT;j++){
			if(i==j) m.push_back(1);
			else m.push_back(0);
		}
		inv.push_back(m);
	}
	gauss_jordan(ar,null_vector,inv);
	return inv;
}

/*---------------------------------------------------------------------*/

