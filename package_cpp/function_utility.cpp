#include<iostream>
#include<vector>
#include<complex>
using namespace std;

static vector<double> null_vector1;
static vector<complex<double>> null_vector2;

/*--------------------------------------------------*/

double polynomial(double x,vector<double> &list){
    int n=list.size();
    double sum = 0;
    for(int i=0;i<n;i++) sum += list[i] * pow(x ,(n - 1 - i));
    return sum;
}

/*-------------------------------------------*/

complex<double> polynomial(complex<double> x,vector<complex<double>> &list){
    int n=list.size();
    complex<double> sum = 0;
    for(int i=0;i<n;i++) sum += list[i] * pow(x ,(n - 1 - i));
    return sum;
}

/*-------------------------------------------------------------------------------*/

double derivative(double (*f)(double),double x,double h=0.00001){
    return (f(x+h)-f(x-h))/(2*h);
}

/*----------------------------------------------------------------------------*/

double derivative(double (*f)(double,vector<double>&),double x,vector<double> &list,double h=0.00001){
    return (f(x+h,list)-f(x-h,list))/(2*h);
}

/*-------------------------------------------------------------------------------*/
complex<double> derivative(complex<double> (*f)(complex<double>),complex<double> x,double h=0.00001){
    return (f(x+h)-f(x-h))/(2*h);
}

/*-------------------------------------------------------------------------------*/

complex<double> derivative(complex<double> (*f)(complex<double>,vector<complex<double>>&),complex<double> x,vector<complex<double>> &list,double h=0.00001){
    return (f(x+h,list)-f(x-h,list))/(2*h);
}

/*----------------------------------------------------------------------------*/

double d_derivative(double (*f)(double),double x,double h=0.00001){
    return (f(x+h)+f(x-h)-2*f(x))/(h*h);
}

/*----------------------------------------------------------------------------*/

double d_derivative(double (*f)(double,vector<double>&),double x,vector<double> &list,double h=0.00001){
    return (f(x+h,list)+f(x-h,list)-2*f(x,list))/(h*h);
}

/*-------------------------------------------------------------------------------*/

complex<double> d_derivative(complex<double> (*f)(complex<double>),complex<double> x,double h=0.00001){
    return (f(x+h)+f(x-h)-f(x)-f(x))/(h*h);
}

/*----------------------------------------------------------------------------*/

complex<double> d_derivative(complex<double> (*f)(complex<double>,vector<complex<double>>&),complex<double> x,vector<complex<double>> &list,double h=0.00001){
    return (f(x+h,list)+f(x-h,list)-f(x,list)-f(x,list))/(h*h);
}

/*-------------------------------------------------------------------------------*/


