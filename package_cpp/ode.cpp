#include<iostream>
#include<vector>
using namespace std;


vector<vector<double>> rk2(double(*f)(double,double),double y0,double x0,double xstop,long int N=1000){
    double h = (xstop - x0) / N;
    vector<double> result;
    result.push_back(y0);
    vector<double> x;
    x.push_back(x0);
    while (std::abs(x0-xstop)>=std::abs(h)){
        int n=result.size();
        double d=f(result[-1],x0);
        double k1_by_2=h/2*d;
        double yn=result[n-1]+k1_by_2;
        d=f(yn,x0+h/2);
        double k2=h*d;
        yn=result[n-1]+k2;
        result.push_back(yn);
        x0+=h;
        x.push_back(x0);
    }
    vector<vector<double>> c{x,result};
    return c;
}
/*-----------------------------------------------------------------------*/
vector<vector<double>> rk2(double(*f)(double,double,vector<double>&),double y0,double x0,double xstop,vector<double> &args,long int N=1000){
    double h = (xstop - x0) / N;
    vector<double> result;
    result.push_back(y0);
    vector<double> x;
    x.push_back(x0);
    while (std::abs(x0-xstop)>=std::abs(h)){
        int n=result.size();
        double d=f(result[-1],x0,args);
        double k1_by_2=h/2*d;
        double yn=result[n-1]+k1_by_2;
        d=f(yn,x0+h/2,args);
        double k2=h*d;
        yn=result[n-1]+k2;
        result.push_back(yn);
        x0+=h;
        x.push_back(x0);
    }
    vector<vector<double>> c{x,result};
    return c;
}
/*-----------------------------------------------------------------------*/

/*-----------------------------------------------------------------------*/

void one_to_many(vector<double>& y0,vector<vector<double>>& y){
    int n=y0.size();
    for(int i=0;i<n;i++){
        y[i].push_back(y0[i]);
    }
}

vector<double> mul(double h,vector<double> &a){
    vector<double> b;
    for(int i=0;i<a.size();i++)
        b.push_back(a[i]*h);
    return b;
}

vector<double> add(vector<double> &a,vector<double> &b){
    vector<double> c;
    for(int i=0;i<a.size();i++)
        c.push_back(a[i]+b[i]);
    return c;
}


vector<vector<double>> rk2(vector<double>(*f)(vector<double> &,double),vector<double> &y0,double x0,double xstop,long int N=1000){
    double h = (xstop - x0) / N;
    int n=y0.size();
    vector<vector<double>> final_result;
    vector<double>e;
    for(int i=0;i<n;i++)
        final_result.push_back(e);
    one_to_many(y0,final_result);
    vector<double> result;
    for(int i=0;i<n;i++)
        result.push_back(y0[i]);
    vector<double> x;
    x.push_back(x0);
    while (std::abs(x0-xstop)>=std::abs(h)){
        vector<double> d=f(result,x0);
        vector<double> k1_by_2=mul(h/2,d);
        vector<double> yn=add(result,k1_by_2);
        d=f(yn,x0+h/2);
        vector<double> k2=mul(h,d);
        yn=add(result,k2);
        result=yn;
        one_to_many(yn,final_result);
        x0+=h;
        x.push_back(x0);
    }
    final_result.insert(final_result.begin(),x);
    return final_result;
}

/*-----------------------------------------------------------------------*/
vector<vector<double>> rk2(vector<double>(*f)(vector<double> &,double,vector<double> &),vector<double> &y0,double x0,double xstop,vector<double> &args,long int N=1000){
    double h = (xstop - x0) / N;
    int n=y0.size();
    vector<vector<double>> final_result;
    vector<double>e;
    for(int i=0;i<n;i++)
        final_result.push_back(e);
    one_to_many(y0,final_result);
    vector<double> result;
    for(int i=0;i<n;i++)
        result.push_back(y0[i]);
    vector<double> x;
    x.push_back(x0);
    while (std::abs(x0-xstop)>=std::abs(h)){
        vector<double> d=f(result,x0,args);
        vector<double> k1_by_2=mul(h/2,d);
        vector<double> yn=add(result,k1_by_2);
        d=f(yn,x0+h/2,args);
        vector<double> k2=mul(h,d);
        yn=add(result,k2);
        result=yn;
        one_to_many(yn,final_result);
        x0+=h;
        x.push_back(x0);
    }
    final_result.insert(final_result.begin(),x);
    return final_result;
}

/*-----------------------------------------------------------------------*/

/*-----------------------------------------------------------------------*/

vector<vector<double>> rk4(double(*f)(double,double),double y0,double x0,double xstop,long int N=1000){
    double h=(xstop-x0)/N;
    vector<double> result{y0};
    vector<double> x{x0};
    while (std::abs(x0 - xstop) >= std::abs(h)){
        int n=result.size();
        //finding k1 and k1/2
        double d = f(result[n-1], x0);
        double k1=h* d;
        double k1_by_2 = h / 2 * d;
        double k1_by_6=h / 6* d;
        //finding k2 and k2/2
        double yn = result[n-1]+ k1_by_2;
        d = f(yn, x0 + h / 2);
        double k2 = h* d;
        double k2_by_2=h/2*d;
        double k2_by_3=h/3*d;
        //finding k3
        yn = result[n-1]+ k2_by_2;
        d = f( yn, x0 + h / 2);
        double k3 = h* d;
        double k3_by_3= h/3* d;
        //finding k4
        yn = result[n-1]+ k3;
        d = f (yn, x0+h);
        double k4 = h* d;
        double k4_by_6=h/6*d;
        //finding the correct yn
        yn=result[n-1]+k1_by_6+k2_by_3+k3_by_3+k4_by_6;
        result.push_back(yn);
        x0 += h;
        x.push_back(x0);
    }
    vector<vector<double>> c{x,result};
    return c;
}
/*-----------------------------------------------------------------------*/
vector<vector<double>> rk4(double(*f)(double,double,vector<double>&),double y0,double x0,double xstop,vector<double>& args,long int N=1000){
    double h=(xstop-x0)/N;
    vector<double> result{y0};
    vector<double> x{x0};
    while (std::abs(x0 - xstop) >= std::abs(h)){
        int n=result.size();
        //finding k1 and k1/2
        double d = f(result[n-1], x0,args);
        double k1=h* d;
        double k1_by_2 = h / 2 * d;
        double k1_by_6=h / 6* d;
        //finding k2 and k2/2
        double yn = result[n-1]+ k1_by_2;
        d = f(yn, x0 + h / 2,args);
        double k2 = h* d;
        double k2_by_2=h/2*d;
        double k2_by_3=h/3*d;
        //finding k3
        yn = result[n-1]+ k2_by_2;
        d = f( yn, x0 + h / 2,args);
        double k3 = h* d;
        double k3_by_3= h/3* d;
        //finding k4
        yn = result[n-1]+ k3;
        d = f (yn, x0+h,args);
        double k4 = h* d;
        double k4_by_6=h/6*d;
        //finding the correct yn
        yn=result[n-1]+k1_by_6+k2_by_3+k3_by_3+k4_by_6;
        result.push_back(yn);
        x0 += h;
        x.push_back(x0);
    }
    vector<vector<double>> c{x,result};
    return c;
}

/*-----------------------------------------------------------------------*/

vector<vector<double>> rk4(vector<double>(*f)(vector<double>&,double),vector<double>& y0,double x0,double xstop,long int N=1000){
    double h=(xstop-x0)/N;
    int n=y0.size();
    vector<vector<double>> final_result;
    vector<double> e;
    for(int i=0;i<n;i++)
        final_result.push_back(e);
    one_to_many(y0,final_result);
    vector<double> result;
    for(int i=0;i<n;i++)
        result.push_back(y0[i]);
    vector<double> x;
    x.push_back(x0);
    while (std::abs(x0 - xstop) >= std::abs(h)){
        //finding k1 and k1/2
        vector<double> d = f(result, x0);
        vector<double> k1=mul(h,d);
        vector<double> k1_by_2 = mul(h / 2 , d);
        vector<double> k1_by_6=mul(h / 6, d);
        //finding k2 and k2/2
        vector<double> yn = add(result, k1_by_2);
        d = f(yn, x0 + h / 2);
        vector<double> k2 = mul(h, d);
        vector<double> k2_by_2=mul(h/2,d);
        vector<double> k2_by_3=mul(h/3,d);
        //finding k3
        yn = add(result, k2_by_2);
        d = f( yn, x0 + h / 2);
        vector<double> k3 = mul(h, d);
        vector<double> k3_by_3= mul(h/3, d);
        //finding k4
        yn = add(result, k3);
        d = f (yn, x0+h);
        vector<double> k4 = mul(h, d);
        vector<double> k4_by_6=mul(h/6,d);
        //finding the correct yn
        yn=add(result,k1_by_6);
        yn=add(yn,k2_by_3);
        yn=add(yn,k3_by_3);
        yn=add(yn,k4_by_6);
        result=yn;
        one_to_many(yn,final_result);
        x0 += h;
        x.push_back(x0);
    }
    final_result.insert(final_result.begin(),x);
    return final_result;
}



vector<vector<double>> rk4(vector<double>(*f)(vector<double>&,double,vector<double>&),vector<double>& y0,double x0,double xstop,vector<double>& args,long int N=1000){
    double h=(xstop-x0)/N;
    int n=y0.size();
    vector<vector<double>> final_result;
    vector<double> e;
    for(int i=0;i<n;i++)
        final_result.push_back(e);
    one_to_many(y0,final_result);
    vector<double> result;
    for(int i=0;i<n;i++)
        result.push_back(y0[i]);
    vector<double> x;
    x.push_back(x0);
    while (std::abs(x0 - xstop) >= std::abs(h)){
        //finding k1 and k1/2
        vector<double> d = f(result, x0,args);
        vector<double> k1=mul(h,d);
        vector<double> k1_by_2 = mul(h / 2 , d);
        vector<double> k1_by_6=mul(h / 6, d);
        //finding k2 and k2/2
        vector<double> yn = add(result, k1_by_2);
        d = f(yn, x0 + h / 2,args);
        vector<double> k2 = mul(h, d);
        vector<double> k2_by_2=mul(h/2,d);
        vector<double> k2_by_3=mul(h/3,d);
        //finding k3
        yn = add(result, k2_by_2);
        d = f( yn, x0 + h / 2,args);
        vector<double> k3 = mul(h, d);
        vector<double> k3_by_3= mul(h/3, d);
        //finding k4
        yn = add(result, k3);
        d = f (yn, x0+h,args);
        vector<double> k4 = mul(h, d);
        vector<double> k4_by_6=mul(h/6,d);
        //finding the correct yn
        yn=add(result,k1_by_6);
        yn=add(yn,k2_by_3);
        yn=add(yn,k3_by_3);
        yn=add(yn,k4_by_6);
        result=yn;
        one_to_many(yn,final_result);
        x0 += h;
        x.push_back(x0);
    }
    final_result.insert(final_result.begin(),x);
    return final_result;
}


/*-----------------------------------------------------------------------*/

/*-----------------------------------------------------------------------*/

/*-----------------------------------------------------------------------*/

/*-----------------------------------------------------------------------*/

/*-----------------------------------------------------------------------*/

/*-----------------------------------------------------------------------*/

/*-----------------------------------------------------------------------*/

/*-----------------------------------------------------------------------*/