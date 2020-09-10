import UTILITY as ut
import LU as lu
matrix=ut.get_file("q2.txt")
A=[[matrix[i][j] for j in range(4)] for i in range(4)]
n=len(A)
inv_mat=[[1 if i==j else 0 for j in range(n)]for i in range(n)]
value = lu.lu_and_det(A, inv_mat) #lu_and_det function decomposes A to LU if possible and returns the determinant
if value == 0:
    print("The Determinant of operator is zero. Hence Inverse does not exist.")
else:
    print("Determinant=%0.4f. So Inverse exists." % value)
    print("Inverse=")
    for i in range(n):
        column = [inv_mat[j][i] for j in range(n)]
        column = lu.forward_substitution(A, column)
        column= lu.backward_substitution(A,column)
        for j in range(n): inv_mat[j][i] = column[j]
    ut.display_matrix(inv_mat)


#output
'''
Determinant=-36.0000. So Inverse exists.
Inverse=
[[-0.250 1.667 -1.833 0.333]
[0.083 -0.667 0.833 0.000]
[0.167 -0.333 -0.333 0.000]
[-0.083 0.667 0.167 0.000]]
'''