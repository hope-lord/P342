from math import sin,cos,pi
from random import uniform,seed
seed(5006978)
def print_to_file(file_name,*lst):
	f=open(file_name,"w")
	for i in zip(*lst):
		n=len(i)-1
		for j in range(n+1):
			if j<n:f.write("%0.6e "%i[j])
			else: f.write("%0.6e\n"%i[j])
	f.close()

def walk(N): #N is no of walks
	x=[0]
	y=[0]
	for i in range(N): 
		thta=uniform(0,2*pi)
		dx= cos(thta)
		dy= sin(thta)
		x.append(x[-1]+dx)
		y.append(y[-1]+dy)
	return x,y


rms_root_n = []

for i in range(1,6):
	disp_x=0 #total x displacement
	disp_y=0 #total y displacement
	disp_square=0  #total square distance 
	dist=0 #total distance
	data=[]
	for j in range(500):    #Going 1000*i steps 500 times
		x,y = walk(1000*i) #no of steps in the walk = 1000*i 
		if j<5: #appending the first 5 walks
			data.append(x)
			data.append(y)
		disp_x+=x[-1]
		disp_y+=y[-1]
		disp_square += x[-1]**2 + y[-1]**2  
		dist += (x[-1]**2 + y[-1]**2)**0.5
		
	print_to_file("q1_data_files/walk_%d.txt"%(i*1000),*data)	
	
	#results 
	print("For step length %d"%(1000*i))
	rms=(disp_square/500)**0.5  
	rms_root_n.append(rms)
	print("R_rms = %0.5f"%rms)
	print("Average x displacement = %0.3f"%(disp_x/500))
	print("Average y displacement = %0.3f"%(disp_y/500))
	print("Average distance = %f "%(dist/500))
	print()	

#print 
length=[(1000*i)**0.5 for i in range(1,6)]
print_to_file("q1_data_files/rms_vs_root_n.txt",length,rms_root_n)

#Output
'''
For step length 1000
R_rms = 31.92220
Average x displacement = 1.460
Average y displacement = -0.073
Average distance = 28.665941 

For step length 2000
R_rms = 44.23039
Average x displacement = 1.189
Average y displacement = 0.298
Average distance = 39.445467 

For step length 3000
R_rms = 54.01022
Average x displacement = 0.860
Average y displacement = -0.575
Average distance = 47.372855 

For step length 4000
R_rms = 61.28665
Average x displacement = 0.013
Average y displacement = -2.309
Average distance = 54.371815 

For step length 5000
R_rms = 70.51129
Average x displacement = -0.408
Average y displacement = 0.775
Average distance = 62.460982 

'''


