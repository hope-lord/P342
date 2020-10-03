from Non_linear import*
from math import log,sin,cos

f1=lambda x: log(x)-sin(x)
f=lambda x:-x-cos(x)

##############      q.1(b)
print("For 1(a). f(x)=log(x)-sin(x)   ",end='')
a=1.5
b=2.5
print("guess=",a,",",b,"\n")
print("Root by Bisection method=",bisection(f1,a,b,1.5,0.000001))
print("Regula_falsi method =",regula_falsi(f1,a,b,1.5,0.000001))
print("Root by Newton Raphson method=",newton_raphson(f1,a,0.000001))

##############      q.1(b)
print("\nFor 1(b). f(x)=-x-cos(x)    ",end='')
a=-2
b=0
print("guess=",a,",",b,"\n")
print("Root by Bisection method=",bisection(f,a,b,1.5,0.000001))
print("Regula_falsi method =",regula_falsi(f,a,b,1.5,0.000001))
print("Root by Newton Raphson method=",newton_raphson(f,a,0.000001))

##############      q.1(b)
print("\nFor 2. p(x)= x^4 - 3x^3 - 7x^2 + 27x -18   guess=0\n")
print("Roots are=",laguerre([1,-3,-7,27,-18],0,0.000001))

#Output
'''
For 1(a). f(x)=log(x)-sin(x)   guess= 1.5 , 2.5

Root by Bisection method= 2.219107151031494
Regula_falsi method = 2.2191071418525734
Root by Newton Raphson method= 2.219107148913746

For 1(b). f(x)=-x-cos(x)    guess= -2 , 0

Root by Bisection method= -0.7390847206115723
Regula_falsi method = -0.7390850409794396
Root by Newton Raphson method= -0.7390851332151607

For 2. p(x)= x^4 - 3x^3 - 7x^2 + 27x -18   guess=0

Roots are= [1.0, 1.9999999999999996, 3.0000000000000004, -3.0]
'''