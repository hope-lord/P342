#q1 and q2
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
def gauss_jordan(arr,br):
    ar=arr[:];b=br[:]
    n=len(ar)
    if(n!=len(b)):
        print("Invalid input")
        return
    for i in range(n):
        a=partial_pivot(ar,b)
        if not a:
            return a
        b[i]/=ar[i][i]
        ar[i] = [ar[i][t] / ar[i][i] for t in range(n)]
        for j in range(n):
            if i==j or ar[j][i]==0:
                continue
            else:
                b[j]-=b[i]*ar[j][i]
                ar[j] = [ar[j][t] - ar[i][t] * ar[j][i] for t in range(n)]
    return b

def read_file(file_name):
    operator=[]
    vec=[]
    with open(file_name,"r") as f:
        a=f.readlines()
        for i in a:
            x=i.split("\n")[0].split(" ")
            n=len(x)
            operator.append([float(x[j]) for j in range(n-1)])
            vec.append(float(x[n-1]))
    return operator,vec
#q1
print("For q1 ",end='')
op,vec=read_file("q1.txt")
print("Solution=",gauss_jordan(op,vec),"\n")
#q2
print("For q2 ",end='')
op,vec=read_file("q2.txt")
print("Solution=",gauss_jordan(op,vec))

#Output
'''
For q1 Solution= [3.0, 1.0, -2.0]

For q2 Solution= [-2.0, -2.0, 1.0]
'''