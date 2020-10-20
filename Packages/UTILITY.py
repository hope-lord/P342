def get_file(file_name):
    matrix=[]
    with open(file_name,"r") as file:
        f=file.readlines()
        for i in f:
           a=i.split("\n")[0].split(" ")
           matrix.append([float(j) for j in a])
    return matrix
#partial_pivot_swap swaps t row and s row and does not check zero at any position
def partial_pivot_swap(ar,t,s,b=None):
    n = len(ar)
    if t<0 or t>=n: return
    if s<0 or s>=n: return
    ar[s], ar[t] = ar[t], ar[s]
    if b != None:
        b[s], b[t] = b[t], b[s]
#partial_pivot swap only when the diagonal element is zero to a below row when same column element is non-zero
def partial_pivot(ar,b):
    n=len(ar)
    zero=[0 for _ in range(n)]
    for i in range(n):
        if ar[i][i]==0:
            if ar[i]==zero:
                return False
            j=i+1
            while j<n :
                if ar[j][i]!=0:
                    ar[j],ar[i]=ar[i],ar[j]
                    b[j], b[i] = b[i], b[j]
                    j=n
                j+=1
    return True
def display_vector(c):
    n=len(c)
    print("[", end='')
    for j in range(n):
        print("%0.3f " % c[j], end='')  # rounding the values upto third decimal place
    print("]")
def display_matrix(c):
    n=len(c)
    m=len(c[0])
    print("[", end='')
    for i in range(n):
        print("[", end='')if i==0 else print(" [",end='')
        for j in range(m):
            print("%0.3f "%c[i][j],end='')  # rounding the values upto fifth decimal place
        print("\b]") if i < n-1 else print("\b]]")
def dot(a,b):#dot product of vectors
    n=len(a)
    if(len(b)==n):
        sum=0
        for i in range(n):
            sum+=a[i]*b[i]
        return sum
def matrix_mult(a,b):
    axb=[];m=len(b)
    n=len(a)
    if (len(b) != m):
        print("Invalid multiplication.")
        return
    if type(b[0])==list:
        axb=[]
        l=len(b[0])
        for i in range(n):
            axb.append([])
            for j in range(l):
                sum = 0
                for t in range(m):
                    sum += a[i][t] * b[t][j]
                axb[i].append(sum)
        return axb
    else:
        axb=[]
        for i in range(n):
            axb.append(dot(a[i],b))
        return axb
def copy(A):
    if type(A[0])==list: return [[j for j in A[i]] for i in range(len(A))]
    else: return [i for i in A]