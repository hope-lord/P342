from integrate import*
from math import exp,pi


#q3
f3=lambda x: exp(-x**2)

mid=midpoint(f3,0,1,2) #defult precision is 0.001
trap=trapezoidal(f3, 0, 1, 2)  #defult precision is 0.001
simp=simpson(f3,0,1,12) #defult precision is 0.001

print("Integral by midpoint= ",mid)
print("Integral by trapezoidal= ",trap)
print("Integral by simpson= ",simp)


#Output
'''
Integral by midpoint=  0.7471308777479975
Integral by trapezoidal=  0.7464612610366896
Integral by simpson=  0.7468553797909873

'''