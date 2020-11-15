#include<iostream>
#include<vector>
#include<random>
using namespace std;

double midpoint(double(*f)(double),double a,double b,double f2p_max,double prec=0.001){
    if (a==b) return 0;
    float c=1;
    if (a>b){
        double t=a;a=b;b=t;
        c=-1;
    }
    int N=pow((pow(b-a,3) *std::abs(f2p_max)/24/prec),0.5);
    N=ceil(N);
    if (N==0) N=1;  //if linear function is given
    double h=(b-a)/N;
    double sum=0;
    for(int i=0;i<N;i++){
        double mid_x=a+i*h+h/2;
        sum+=f(mid_x); //as weight=1 for each x_i;
    }
    return c*h*sum;
}

/*----------------------------------------------------------------------------------------------*/

double midpoint(double(*f)(double,vector<double>&),double a,double b,double f2p_max,vector<double> &args,double prec=0.001){
    if (a==b) return 0;
    float c=1;
    if (a>b){
        double t=a;a=b;b=t;
        c=-1;
    }
    int N=pow((pow(b-a,3) *std::abs(f2p_max)/24/prec),0.5);
    N=ceil(N);
    if (N==0) N=1;  //if linear function is given
    double h=(b-a)/N;
    double sum=0;
    for(int i=0;i<N;i++){
        double mid_x=a+i*h+h/2;
        sum+=f(mid_x,args); //as weight=1 for each x_i;
    }
    return c*h*sum;
}

/*------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------*/

double trapezoidal(double(*f)(double),double a,double b,double f2p_max,double prec=0.001){
    if (a==b) return 0;
    float c=1;
    if (a>b){
        double t=a;a=b;b=t;
        c=-1;
    }
    int N=pow((pow(b-a,3) *std::abs(f2p_max)/12/prec),0.5);
    N=ceil(N);
    if (N==0) N=1;  //if linear function is given
    double h=(b-a)/N;
    double sum=0;
    for(int i=0;i<=N;i++){
        int w=2;
        if ((i==0) or (i==N)) w=1; //weight is 1 for first and last
        double xi=a+i*h;
        sum+=w*f(xi);
    }
    return c*h*sum/2;
}

/*-------------------------------------------------------------------------*/
double trapezoidal(double(*f)(double,vector<double> &),double a,double b,double f2p_max,vector<double>& args,double prec=0.001){
    if (a==b) return 0;
    float c=1;
    if (a>b){
        double t=a;a=b;b=t;
        c=-1;
    }
    int N=pow((pow(b-a,3) *std::abs(f2p_max)/12/prec),0.5);
    N=ceil(N);
    if (N==0) N=1;  //if linear function is given
    double h=(b-a)/N;
    double sum=0;
    for(int i=0;i<=N;i++){
        int w=2;
        if ((i==0) or (i==N)) w=1; //weight is 1 for first and last
        double xi=a+i*h;
        sum+=w*f(xi,args);
    }
    return c*h*sum/2;
}

/*-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------*/

double simpson(double(*f)(double),double a,double b,double f4p_max,double prec=0.001){
    if (a==b) return 0;
    float c=1;
    if (a>b){
        double t=a;a=b;b=t;
        c=-1;
    }
    int N=pow((pow(b-a,5) *std::abs(f4p_max)/180/prec),0.25);
    N=ceil(N);
    if (N==0) N=1;  //if linear function is given
    double h=(b-a)/N;
    double sum=0;
    for(int i=0;i<=N;i++){
        int w;
        if (i==0 or i==N) w=1; //weight is 1 for first and last
        else if (i%2==1) w=4; //for odd weight=4
        else w=2; //for even weight=2
        double xi=a+i*h;
        sum+=w*f(xi);
    }
    return c*h*sum/3;
}
/*-------------------------------------------------------------------------*/
double simpson(double(*f)(double,vector<double> &),double a,double b,double f4p_max,vector<double> args,double prec=0.001){
    if (a==b) return 0;
    float c=1;
    if (a>b){
        double t=a;a=b;b=t;
        c=-1;
    }
    int N=pow((pow(b-a,5) *std::abs(f4p_max)/180/prec),0.25);
    N=ceil(N);
    if (N==0) N=1;  //if linear function is given
    double h=(b-a)/N;
    double sum=0;
    for(int i=0;i<=N;i++){
        int w;
        if (i==0 or i==N) w=1; //weight is 1 for first and last
        else if (i%2==1) w=4; //for odd weight=4
        else w=2; //for even weight=2
        double xi=a+i*h;
        sum+=w*f(xi,args);
    }
    return c*h*sum/3;
}

/*-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------*/

vector<double> monte_carlo(double(*f)(double),double a,double b,long long int N=1e6) {
    double sum=0;
    double sum2=0;
    double inv_pdf=b-a; //inverse pdf
    if (inv_pdf==0){ 
        vector<double> c{0,0};    
        return c;
    }
    std::default_random_engine generator;
    std::uniform_real_distribution<double> distribution(a,b);
    for(int i=0;i<N;i++){
        double value=f(distribution(generator));
        sum+=value;
        sum2 += pow(value,2);
    }
    vector<double> c{inv_pdf*sum/N, pow((sum2/N/inv_pdf - pow((sum/N/inv_pdf),2)),0.5)};    
    return c;
}

/*-------------------------------------------------------------------------*/
vector<double> monte_carlo(double(*f)(double,vector<double>&),double a,double b,vector<double> &args,long long int N=1e6) {
    double sum=0;
    double sum2=0;
    double inv_pdf=b-a; //inverse pdf
    if (inv_pdf==0){ 
        vector<double> c{0,0};    
        return c;
    }
    std::default_random_engine generator;
    std::uniform_real_distribution<double> distribution(a,b);
    for(int i=0;i<N;i++){
        double value=f(distribution(generator),args);
        sum+=value;
        sum2 += pow(value,2);
    }
    vector<double> c{inv_pdf*sum/N, pow((sum2/N/inv_pdf - pow((sum/N/inv_pdf),2)),0.5)};    
    return c;
}

/*-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------*/

vector<double> monte_carlo(double(*f)(vector<double>&),vector<double> &a,vector<double> &b,long long int N=1e6) {
    double sum=0;
    double sum2=0;
    double inv_pdf=1; //inverse pdf
    for(int i=0;i<a.size();i++) 
        inv_pdf*=(b[i]-a[i]);//for multivariate function inverse pdf is multiplication of range differences
    
    if (inv_pdf==0){ 
        vector<double> c{0,0};    
        return c;
    }
    std::default_random_engine generator;
    vector<std::uniform_real_distribution<double>> distribution;
    
    for(int i=0;i<a.size();i++){
        std::uniform_real_distribution<double> c(a[i],b[i]);
        distribution.push_back(c);
    }

    for(int i=0;i<N;i++){
        vector<double> x;
        for(int i=0;i<a.size();i++)
            x.push_back(distribution[i](generator));
        
        double value=f(x);
        sum+=value;
        sum2 += pow(value,2);
    }
    vector<double> c{inv_pdf*sum/N, pow((sum2/N/inv_pdf - pow((sum/N/inv_pdf),2)),0.5)};    
    return c;
}

/*-------------------------------------------------------------------------*/
vector<double> monte_carlo(double(*f)(vector<double>&,vector<double>&),vector<double> &a,vector<double> &b,vector<double> &args,long long int N=1e6) {
    double sum=0;
    double sum2=0;
    double inv_pdf=1; //inverse pdf
    for(int i=0;i<a.size();i++) 
        inv_pdf*=(b[i]-a[i]);//for multivariate function inverse pdf is multiplication of range differences
    
    if (inv_pdf==0){ 
        vector<double> c{0,0};    
        return c;
    }
    std::default_random_engine generator;
    vector<std::uniform_real_distribution<double>> distribution;
    
    for(int i=0;i<a.size();i++){
        std::uniform_real_distribution<double> c(a[i],b[i]);
        distribution.push_back(c);
    }

    for(int i=0;i<N;i++){
        vector<double> x;
        for(int i=0;i<a.size();i++)
            x.push_back(distribution[i](generator));
        
        double value=f(x,args);
        sum+=value;
        sum2 += pow(value,2);
    }
    vector<double> c{inv_pdf*sum/N, pow((sum2/N/inv_pdf - pow((sum/N/inv_pdf),2)),0.5)};    
    return c;
}

/*-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------*/



/*-------------------------------------------------------------------------*/