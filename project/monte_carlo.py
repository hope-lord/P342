from random import random,seed
from math import pi

seed(505)
a=1
b=1.5
c=2


def vol_ellipsoid(N,*dim):
	inside=0
	if N==30000:f=open("q2_data_files/monte_carlo.txt","w") #for plot with 30000 points
	for _ in range(N):
		el_eq=0
		rand=[]
		for j in dim:
			ran = 2* j*random()-j # generating random numbers between -1 and 1
			rand.append(ran)
			el_eq+=ran**2/j**2
		if el_eq<=1: #if ran1^2/a^2 +ran2^2/b^2 +ran3^2/c^2 <=1 then they are considered inside
			inside+=1
			if N==30000:
				f.write(f"{rand[0]} {rand[1]} {rand[2]}\n")
	
	cuboid_vol = 8*dim[0]*dim[1]*dim[2]#area of cuboid
	if N==30000: f.close()
	return cuboid_vol*inside/N	


vol_theory=4*pi*a*b*c/3
print(f"Exact volume of ellipsoid = {vol_theory}\nMonte-Carlo Values:\n")

f=open("q2_data_files/frac_err.txt","w")
for i in range(25):
	j=2000+2000*i
	vol = vol_ellipsoid(j,a,b,c)
	f.write(f"{j} {vol} {(vol-vol_theory)/vol_theory}\n")
	print(f"With {j} samples = {vol}")
f.close()
	
	
#Output
'''
Exact volume of ellipsoid = 12.56637
Monte-Carlo Values:

With 2000 samples = 12.816
With 4000 samples = 12.39
With 6000 samples = 12.744
With 8000 samples = 12.618
With 10000 samples = 12.336
With 12000 samples = 12.708
With 14000 samples = 12.690857142857142
With 16000 samples = 12.4155
With 18000 samples = 12.552
With 20000 samples = 12.702
With 22000 samples = 12.398181818181818
With 24000 samples = 12.567
With 26000 samples = 12.598153846153846
With 28000 samples = 12.565714285714286
With 30000 samples = 12.5768
With 32000 samples = 12.738
With 34000 samples = 12.624
With 36000 samples = 12.558666666666667
With 38000 samples = 12.63536842105263
With 40000 samples = 12.5532
With 42000 samples = 12.624
With 44000 samples = 12.614181818181818
With 46000 samples = 12.614608695652175
With 48000 samples = 12.598
With 50000 samples = 12.43776


'''
