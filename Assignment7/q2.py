from ode import rk4,print_to_file

e = 2.71828

def f(y,x):
    dydx=y[1]
    ddydxx=1-x-y[1]
    return [dydx,ddydxx]

dt=0.1
N=5/dt

#finding solution for 0 to 5
x1, y1 = rk4(f, [2,1], 0, 5, N)  # dt=0.1
print_to_file("data_files/q2_part1.txt",x1,*y1)

# finding soln for 0 to -5
x2, y2 = rk4(f, [2,1], 0, -5, N) #dt=0.1
print_to_file("data_files/q2_part2.txt",x2,*y2)