from UTILITY import partial_pivot_swap
def LU(A,b=None):
    row_rotations=0 #it counts no of row swaps
    n=len(A)
    i=0;s=0;t=False
    while i<n :
        if not t:s=i
        new_row=A[i][:]
        j=0
        while j<n:
            if i>j:
                sum=0
                for k in range(j):sum+=A[i][k]*A[k][j]
                A[i][j]=(A[i][j]-sum)/A[j][j]
                j+=1
            elif i==j:
                sum = 0
                for k in range(i):sum += A[i][k] * A[k][j]
                A[i][j]-= sum
                if A[i][j]!=0:
                    j+=1
                    t=False
                else: #if u_ii goes to zero
                    j=n
                    A[i]=new_row #undo the previous changes for the row
                    t=True
            else:
                sum = 0
                for k in range(i):sum += A[i][k] * A[k][j]
                A[i][j] -= sum
                j+=1
        if not t: i+=1
        else:#as the u_ii was zero so we need to swap this row with below rows as long as u_ii!=0 or row<n
            s+=1
            if s==n: return -1 #hence the determinant is zero
            partial_pivot_swap(A,i,s,b)
            row_rotations+=1
    return row_rotations
def lu_and_det(A,b=None): #b is not required for determinant. but b wiil be involved in partial pivoting
    p=LU(A,b) #so calling b is to do the LU decomposition once
    mult=1
    if p==-1: return 0
    for i in range(len(A)):
        mult*=A[i][i]
    return mult*(-1)**p
def forward_substitution(A,b):
    n=len(A)
    for i in range(n):#the forward part
        sum=0
        for j in range(i):
            sum+=A[i][j]*b[j]
        b[i]-=sum
    return b
def backward_substitution(A,b):
    n=len(A)
    i = n - 1
    while (i > -1):#the backward part
        sum = 0
        for j in range(i + 1, n):
            sum += A[i][j] * b[j]
        b[i] -= sum
        b[i] /= A[i][i]
        i -= 1
    return b
