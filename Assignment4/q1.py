import UTILITY as ut
import LU as lu
matrix=ut.get_file("q1.txt")
A=[[matrix[i][j] for j in range(4)] for i in range(4)]
b=[matrix[i][4] for i in range(4)]
value=lu.lu_and_det(A,b) #lu_and_det function decomposes Ar to LU and calculates the determinant
if value==0:
    print("The Determinant of operator is zero. Hence No unique solution is possible.")
else:
    b=lu.forward_substitution(A,b)
    b=lu.backward_substitution(A,b)
    print("Solution=",end='')
    ut.display_vector(b)

#Output
'''
Solution=[1.000 -1.000 1.000 2.000 ]
'''
