from Linear import forward_substitution,backward_substitution,lu_and_det
from UTILITY import copy,get_file


def polynomial(x,coeff):
    n=len(coeff)
    sum=0
    for i in range(n):
        sum+= (coeff[i]*x**i)
    return sum

class FIT:
    def __init__(self,file_name, degree, yerr=False):
        self.fit_done=0
        self.degree=degree
        self.yerr=yerr
        data = get_file(file_name)
        self.matrix = []
        self.xx = []
        self.yy = []
        self.ww = []
        self.sum_x=0
        self.sum_x2=0
        self.sum_xy=0
        self.sum_y=0
        self.sum_y2=0
        self.yx_vec = [0 for _ in range(degree + 1)]
        x_vec = [0 for _ in range(2 * degree + 1)]
        for i in data:
            x = i[0]
            y = i[1]
            self.sum_x += x
            self.sum_x2 += x*x
            self.sum_xy += x*y
            self.sum_y += y
            self.sum_y2 += y*y
            if not self.yerr:
                w = 1
            else:
                w = 1 / i[2] ** 2
            self.xx.append(x)
            self.yy.append(y)
            self.ww.append(w)
            for j in range(2 * degree + 1):
                if j < degree + 1: self.yx_vec[j] += (w * y * x ** j)
                x_vec[j] += (w * x ** j)
        for i in range(degree + 1):
            self.matrix.append([])
            for j in range(degree + 1):
                self.matrix[i].append(x_vec[i + j])
        self.N=len(self.xx)
        self.__avg_calculation()
        self.__solve()


    def __avg_calculation(self):
        self.mean_x=self.sum_x/self.N
        self.mean_y=self.sum_y/self.N

    def __solve(self):
        A=copy(self.matrix)
        b=copy(self.yx_vec)
        self.delta = lu_and_det(A, b)  # lu_and_det function decomposes Ar to LU and calculates the determinant
        if self.delta == 0:
            print("The Determinant of operator is zero. Hence No unique solution is possible.")
        else:
            b = forward_substitution(A, b)
            self.coeff = backward_substitution(A, b)

    def __fit_error(self):
        self.chi2=0
        self.r=(self.sum_xy-(self.N*self.mean_x*self.mean_y))/\
               (self.sum_x2-self.N*self.mean_x**2)**0.5/\
               (self.sum_y2-self.N*self.mean_y**2)**0.5

        for i in range(self.N): self.chi2+= ((self.yy[i]-polynomial(self.xx[i],self.coeff))**2*self.ww[i])
        
        print((self.yy[0]-self.xx[0]*self.coeff[1]-self.coeff[0])**2)
        sigma_y = (self.chi2/(self.N-self.degree-1))**0.5
        self.err=[]
        for i in range(self.degree+1):
            ee = sigma_y*(self.matrix[i][i]/self.delta)**0.5
            self.err.append(ee)
        self.err.reverse()
		print("Error part is correct only for straight line.")

    def errors(self):
        if self.fit_done==0:
            self.fit_done=1
            self.__fit_error()
        return self.err

    def parameters(self):
        return self.coeff


    def __str__(self):
        self.errors()
        n=len(self.coeff)
        string = "dof = %d\n" % (self.N - n)
        string += "Corr. coeff = %0.6e\n"%self.r
        string+="chi2 = %0.6e\n"%(self.chi2)

        for i in range(n):
            string+="a%d= %0.6e +/- %0.6e\n"%(i,self.coeff[i],self.err[i])
        return string






