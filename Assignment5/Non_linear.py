def derivative(f, x, args=None, h=0.0001): #derivative
    if args != None: return (polynomial(x + h, args) - polynomial(x - h, args)) / (2 * h)
    return (f(x + h) - f(x - h)) / (2 * h)
#----------------************************--------------------#
def d_derivative(f, x, args=None, h=0.0001): #double derivative
    if args != None: return (polynomial(x + h, args) + polynomial(x - h, args) - 2 * polynomial(x, args))/h ** 2
    return (f(x + h) + f(x - h) - 2 * f(x)) / h ** 2
#----------------************************--------------------#
def polynomial(x,list):
    n = len(list)
    sum = 0
    for i in range(n): sum += list[i] * x ** (n - 1 - i)
    return sum
#----------------************************--------------------#
def make_bracket(f,a,b,factor):#bracketting the root
    i=0
    if a>b: a,b=b,a
    while i<15 and f(a)*f(b)>0:
        i+=1
        if abs(f(a)) < abs(f(b)): a -= (b - a) * factor
        else: b += (b - a) * factor
    if f(a)*f(b)>0:
        print("Give proper a & b.")
        return None,None
    elif f(a)*f(b)==0:
        if f(a)==0: return a,a
        else: return b,b
    else:
        return a,b
#----------------************************--------------------#
def bisection(func,a,b,factor,epsi): #bisection method and factor is for bracketting
    f=open("bisection.txt","w")
    a,b=make_bracket(func,a,b,factor)
    if a==None and b==None: return None  #bracketing was not possible
    elif a==b: return b  #a or b hits the root
    else:
        c=(a+b)/2;i=0
        while(i<200 and b-a>epsi and func(c)!=0):
            f.write(f"{i+1} {abs(b - a)}\n")
            i+=1
            if func(c)*func(a)>0: a=c
            else: b=c
            c=(a+b)/2
        f.write(f"{i + 1} {abs(b - a)}\n")
        if i==50: print("The limit has reached.")
        f.close()
        return c
#----------------************************--------------------#
def regula_falsi(func,a,b,factor,epsi):#regula falsi method
    f=open("regulafalsi.txt","w")
    a,b=make_bracket(func,a,b,factor)
    if a==None and b==None: return None #bracketing was not possible
    elif a==b: return b  #a or b hits the root
    else:
        c= (func(b)*a-b*func(a))/(func(b)-func(a));i=0
        #min(abs(c-a),abs(b-a))<epsi to stop loop
        while (i < 200 and min(abs(b - c), abs(a - c))>epsi and func(c) != 0):
            f.write(f"{i+1} {min(abs(b - c),abs(a-c))}\n")
            i+=1
            if func(c)*func(a)>0: a=c
            else: b=c
            c = (func(b) * a - b * func(a)) / (func(b) - func(a))
        f.write(f"{i + 1} {min(abs(b - c), abs(a - c))}\n")
        if i==200: print("The limit has reached.")
        f.close()
        return c
#----------------************************--------------------#
def newton_raphson(f,x0,epsl):
    file=open("newton.txt","w")
    if f(x0)==0: return x0
    fp=derivative(f,x0)
    if fp==0:
        print("Re-enter proper x_0")
        return
    x1=x0-f(x0)/fp
    i=0
    while abs(x1-x0)>epsl and f(x1)!=0 and i<200:
        file.write(f"{i+1} {abs(x1 - x0)}\n")
        i+=1
        x0=x1
        fp=derivative(f, x0)
        if fp == 0:
            print("Re-enter proper x_0")
            return
        x1 = x0 - f(x0) / fp
    file.write(f"{i + 1} {abs(x1 - x0)}\n")
    file.close()
    return x1
#----------------************************--------------------#
def laguerre(list,a0,epsl):
    t = len(list)
    root=[]
    while len(root)<t: #no of roots is same as degree
        n=len(list)-1
        if polynomial(a0,list)==0:root.append(a0) # a0 bangs on a root
        else:
            if len(list)==2: #when the polynomial becomes linear
                root.append(-list[1]/list[0])
                return root
            G=derivative(polynomial,a0,list)/polynomial(a0,list)
            H=G**2-d_derivative(polynomial,a0,list)/polynomial(a0,list)
            ll=((n-1)*(n*H-G**2))**0.5
            if abs(G+ll)>abs(G-ll): a=n/(G+ll)
            elif abs(G+ll)==0:
                print("Re-enter proper x_0.")
                return 0
            else: a=n/(G-ll)
            a0-=a
            j=0
            while abs(a)>epsl and polynomial(a0,list)!=0 and j<50: #finding the root using G and H
                j+=1
                G = derivative(polynomial,a0,list) / polynomial(a0,list)
                H = G ** 2 - d_derivative(polynomial,a0,list) / polynomial(a0,list)
                ll = ((n - 1) * (n * H - G**2)) ** 0.5
                if abs(G + ll) > abs(G - ll):a = n / (G + ll)
                elif abs(G + ll) == 0:
                    print("Re-enter proper x_0.")
                    return 0
                else:a = n / (G - ll)
                a0-=a
            if j==50: print("LIMIT HAS REACHED")
            root.append(a0)
        if len(root) != 0: #synthetic division
            new_list = [list[0]]
            last_root = root[len(root) - 1]
            for i in range(1, len(list) - 1):
                new_list.append(last_root * new_list[-1] + list[i])
            list = new_list
    return root
#----------------************************--------------------#
