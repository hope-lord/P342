from Non_linear import newton_raphson,call_func

def mul(a,lst):
    return [a*i for i in lst]
def add(*lst):
    return [sum(i) for i in zip(*lst)]
def get_column(i,lst2d):
    return [j[i] for j in lst2d]

#---------------*********************--------------------#

def euler_forward(f,y0,x0,xstop,N=1000,args=None):
    h = (xstop - x0) / N
    if type(y0) != list: y0 = [y0]
    result = [y0];c=[x0]
    while abs(x0 - xstop) >= abs(h):
        d = call_func(f, args, result[-1], x0)
        if type(d) != list: d = [d]
        k1 = mul(h , d)
        yn = add(result[-1], k1)
        result.append(yn)
        x0+=h
        c.append(x0)
    return result,c

#---------------------******************---------------------#

##The function to get the y(x+h)
def func(t,args):
    # args=[f,y0,x,h,arg,i]
    cop=[_ for _ in args[1]]
    i=args[5]
    cop[i]=t
    c=call_func(args[0],args[4],cop,args[2]+args[3])
    if type(c) != tuple and type(c) != list: c = [c]
    return -t+args[1][i]+args[3]*c[i]
    #d=call_func(args[0],args[4],args[1],args[2]+args[3])

#--------------------**********************----------------------------#

def euler_backward(f,y0,x0,xstop,N=1000,args=None):
    h=(xstop-x0)/N
    if type(y0)!=tuple and type(y0)!=list: y0=[y0]
    result=[y0]
    xpar=[x0]
    while(abs(xstop-x0)>=abs(h)):
        list_of_args=[f,result[-1],x0,h,args,0]
        newtonn=[]
        for i in range(len(y0)):
            list_of_args[5]=i
            sol=newton_raphson(func,result[-1][i],0.0001,list_of_args)
            newtonn.append(sol)

        #result.append(result[-1]+h*call_func(f,args,newton,x0+h))
        d=call_func(f,args,newtonn,x0+h)
        if type(d) != tuple and type(d) != list: d = [d]
        d1=mul(h,d)
        d2=add(d1,result[-1])
        result.append(d2)
        x0+=h
        xpar.append(x0)
    return result,xpar

#-----------------------**********************------------------------#

def rk2(f,y0,x0,xstop,N=1000,args=None):
    h = (xstop - x0) / N
    if type(y0)!=list and type(y0)!=tuple: y0=[y0]
    result=[y0];c=[x0]
    while abs(x0-xstop)>=abs(h):
        d=call_func(f,args,result[-1],x0)
        if type(d) != list and type(d)!=tuple: d = [d]
        k1_by_2=mul(h/2,d)
        yn=add(result[-1],k1_by_2)
        d=call_func(f,args,yn,x0+h/2)
        if type(d)!=list: d=[d]
        k2=mul(h,d)
        yn=add(result[-1],k2)
        result.append(yn)
        x0+=h
        c.append(x0)
    return result,c

#------------------------***********************----------------------#

def predictor_corrector(f,y0,x0,xstop,N=1000,args=None):
    h = (xstop - x0) / N
    if type(y0) != list: y0 = [y0]
    result = [y0];c=[x0]
    while abs(x0 - xstop) >= abs(h):
        d = call_func(f, args, result[-1], x0)
        if type(d) != list and type(d)!=tuple: d = [d]
        k1 = mul(h , d)
        yp = add(result[-1], k1) #predicted
        d = call_func(f, args, yp, x0+h)
        if type(d) != list: d = [d]
        k2_p=mul(h, d)
        k_into_2=add(k2_p, k1)  # h(f(y0,x0) +f(y1_p,x0+h)
        k= mul(0.5, k_into_2)
        yc=add(result[-1], k) #corrected
        result.append(yc)
        x0+=h
        c.append(x0)
    return result,c

#--------------------------************************----------------------------#

def rk4(f,y0,x0,xstop,N=1000,args=None):
    h=(xstop-x0)/N
    if type(y0) != list and type(y0) != tuple: y0 = [y0]
    result = [y0]
    c = [x0]
    while abs(x0 - xstop) >= abs(h):
        #finding k1 and k1/2
        d = call_func(f, args, result[-1], x0)
        if type(d) != list and type(d) != tuple: d = [d]
        k1=mul(h, d)
        k1_by_2 = mul(h / 2, d)
        k1_by_6=mul(h / 6, d)
        #finding k2 and k2/2
        yn = add(result[-1], k1_by_2)
        d = call_func(f, args, yn, x0 + h / 2)
        if type(d) != list: d = [d]
        k2 = mul(h, d)
        k2_by_2=mul(h/2,d)
        k2_by_3=mul(h/3,d)
        #finding k3
        yn = add(result[-1], k2_by_2)
        d = call_func(f, args, yn, x0 + h / 2)
        if type(d) != list: d = [d]
        k3 = mul(h, d)
        k3_by_3= mul(h/3, d)
        #finding k4
        yn = add(result[-1], k3)
        d = call_func(f, args, yn, x0+h)
        if type(d) != list: d = [d]
        k4 = mul(h, d)
        k4_by_6=mul(h/6,d)
        #finding the correct yn
        yn=add(result[-1],k1_by_6,k2_by_3,k3_by_3,k4_by_6)
        result.append(yn)
        x0 += h
        c.append(x0)
    return result, c

#----------------------********************-----------------------#


def predict_boundary(f,y0,yp0,a,b,N,args):
    return rk4(f,[y0,yp0],a,b,N,args)

def dirichlet_boundary(f,ya,yb,a,b,choice1,choice2,epsilon=0.0001,N=1000,args=None):
    p,q=predict_boundary(f,ya,choice1,a,b,N,args)
    c1=p[-1][0]
    if abs(c1-yb)<=epsilon: return p,q
    p,q=predict_boundary(f,ya,choice2,a,b,N,args)
    c2=p[-1][0]
    if abs(c2-yb)<=epsilon: return p, q
    if (c1-yb)*(c2-yb)>0 or c1==c2:
        print("The choices are not good")
        return None
    choice=(yb-c1)*(choice2-choice1)/(c2-c1) + choice1
    p,q=predict_boundary(f,ya,choice,a,b,N,args)
    c=p[-1][0]
    if abs(c - yb) <= epsilon: return p, q
    if (c1 - yb) * (c - yb) > 0 : return dirichlet_boundary(f,ya,yb,a,b,choice,choice2,epsilon,N,args)
    else: dirichlet_boundary(f,ya,yb,a,b,choice1,choice,epsilon,N,args)
    


#-----------------------**********************-----------------------------#
def main():
    import matplotlib.pylab as plt
    import numpy as np
    f=lambda y,x: [np.sin(x)]

    y,x=euler_backward(f,[-1],0,20,1000)
    y=get_column(0,y)
    print(x[-1])
    #plt.plot(x,-np.cos(x),"b-",label="Analytic")
    plt.plot(x,y,"r-",label="My fit")
    #plt.xlim(0,6)
    plt.legend().set_draggable(True)
    plt.show()

if __name__=="__main__":
    main()
