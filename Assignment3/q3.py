#q3
'''Printing False means the determinant of given matrix is zero'''
def partial_pivot(ar,b):
    n=len(ar)
    zero=[0 for _ in range(n)]
    for i in range(n):
        if ar[i][i]==0:
            if ar[i]==zero:
                return False
            j=i+1;t=False
            while j<n and not t:
                if ar[j][i]!=0:
                    ar[j],ar[i]=ar[i],ar[j]
                    b[j], b[i] = b[i], b[j]
                    t=True
    return True

def gauss_jordan(arr):
    ar=arr[:]
    n = len(ar)
    b=[[1 if i==j else 0 for j in range(n)] for i in range(n)]
    if(n!=len(b)):
        print("Invalid input")
        return
    for i in range(n):
        a=partial_pivot(ar,b)
        if not a:
            return a
        b[i]=[b[i][t] / ar[i][i] for t in range(n)]
        ar[i] = [ar[i][t] / ar[i][i] for t in range(n)]
        for j in range(n):
            if i==j or ar[j][i]==0:
                continue
            else:
                b[j]= [b[j][t]-b[i][t]*ar[j][i] for t in range(n)]
                ar[j] = [ar[j][t] - ar[i][t] * ar[j][i] for t in range(n)]
    return b

def matrix_mult(a,b):
    axb=[];m=len(b)
    for i in range(m):
        axb.append([])
        for j in range(m):
            sum=0
            for t in range(len(b)):
                sum+=a[i][t]*b[t][j]
            axb[i].append(sum)
    return axb

matrix=[]
with open("q3.txt","r") as f:
    a=f.readlines()
    for i in a:
        x=i.split("\n")[0].split(" ")
        n=len(x)
        matrix.append([float(x[j]) for j in range(n)])
print("Inverse=",C:=gauss_jordan(matrix))
print("Multiplication=",matrix_mult(C,matrix))
#Output
'''
Inverse= [[-3.0, 3.0, -7.0], [1.0, 1.0, 0.0], [1.0, 0.0, 1.0]]
Multiplication= [[1.0, 0.0, 0.0], [0.0, 1.0, 0.0], [0.0, 0.0, 1.0]]
'''