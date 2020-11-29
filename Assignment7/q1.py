from ode import euler_forward,print_to_file
from math import log
import matplotlib.pylab as plt
e = 2.71828

f1=lambda y,x: y*log(y)/x
f2=lambda y,x:6-2*y/x

dt=0.1
N=(12-2)/dt
x,y1=euler_forward(f1,e,2,12,N) #dt=0.1
print_to_file("data_files/q1_a.txt",x,y1)


N=(13-3)/dt
x,y1=euler_forward(f2,1,3,13,N) #dt=0.1
print_to_file("data_files/q1_b.txt", x, y1)


