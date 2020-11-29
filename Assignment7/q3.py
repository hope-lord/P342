from ode import shooter,print_to_file,rk4
e = 2.71828

def f(y,x):
    dydx=y[1]
    ddydxx=1+y[1]
    return [dydx,ddydxx]

dt=0.02
N=1/dt #N= no of points between 0 and 1
guess1=0
guess2=2
x1, y1=rk4(f, [1, guess1], 0, 1, N)
print(f"For guess {guess1} , y(1)= {y1[0][-1]}")
print_to_file("data_files/q3_guess1.txt",x1,*y1)


x2,y2=rk4(f,[1,guess2],0,1,N)
print(f"For guess {guess2} , y(1)= {y2[0][-1]}")
print_to_file("data_files/q3_guess2.txt",x2,*y2)


x,y= shooter(f, 1, 2 * (e - 1),guess1, guess2, 0, 1, N, 1e-6)
print_to_file("data_files/q3_final.txt",x,*y)

print("After shooter method")
print("Numerically y'(0)= %.6f"%y[1][0])

#Output
'''
For guess 0 , y(1)= 1.7182818248945615
For guess 3 , y(1)= 6.873127299578245
After shooter method
Numerically y'(0)= 0.999998
'''