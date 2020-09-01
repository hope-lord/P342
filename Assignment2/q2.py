#Create two vectors of type A=(a1,a2,a3) and B=(b1,b2,b3) with numbers of your choice (but
#       not random numbers) in the code itself. Find A+B and A.B (dot product).

A=[2,-5.5,8]
B=[3,0,2.8]
A_plus_B=[0,0,0]
A_dot_B=0
k=0
#print([(i,j) for i,j in zip(A,B)])
for (i,j) in zip(A,B):
    A_plus_B[k]=i+j
    A_dot_B+= i*j
    k+=1
print("A+B= ",A_plus_B)
print(f"A.B= {A_dot_B}")

#Output:
#A+B=  [5, -5.5, 10.8]
#A.B= 28.4
