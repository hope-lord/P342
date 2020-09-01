#Create 3x3 matrices M=(a11,a12 … a33) and N=(b11,b12, …, b33) with numbers of your
#choice (zeros, negatives and positives but not random numbers) in two separate files. Read
#the matrices from the files. Find M x A and M x N.

#Taking A from q2

A=[2,-5.5,8]
f1=open("matrix_M.txt","r"); f2=open("matrix_N.txt","r")
a=f1.readlines();b=f2.readlines()
f1.close() ;f2.close()
M=[];N=[];t=0

for i in range(3):
    M.append([]);N.append([])
    x=a[i].split("\n");c=x[0].split(" ")
    y=b[i].split("\n");d=y[0].split(" ")
    n=len(c)
    for j in range(n):
            M[i].append(float(c[j]))
            N[i].append(float(d[j]))
MXN=[]
for i in range(3):
    MXN.append([])
    for j in range(3):
        sum=0
        for k in range(3):
            sum+= M[i][k]*N[k][j]
        MXN[i].append(sum)

MXA=[]
for i in range(3):
    sum=0
    for k in range(3):
         sum+= M[i][k]*A[k]
    MXA.append(sum)
print("M XA = ",MXA)
print("M XN = ", MXN)


#Output
#M XA =  [24.75, 78.39999999999999, -30.7]
#M XN =  [[24.75, -51.5, 129.3], [14.7, 28.0, 67.19999999999999], [62.6, -71.0, 80.4]]
