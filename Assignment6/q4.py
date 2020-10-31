
from integrate import monte_carlo


f4=lambda x:4/(1+x**2)

file=open("monecarlo_data.txt","w")


for i in range(1,2000):
    p,q=monte_carlo(f4,[(0,1)],None,i*10)
    file.write("%d %f\n"%(10*i,p))
file.close()

