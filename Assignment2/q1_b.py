#Find the average distance between two points on a
#(b) 6 by 6 two-dimensional grid (no diagonal connections):

arr=[]
num_sum=0
sum=0
for j in range(6):
    for i in range(6):
        arr.append([i,j])
#print(arr[0][0],arr[0][1])
for i in range(36):
    for j in range(36):
        x = abs(arr[j][0] - arr[i][0])
        y = abs(arr[j][1] - arr[i][1])
        sum+= y+x
        num_sum+=1
print(f"Avg. Distance= {sum/num_sum}")

#output
#Avg. Distance= 3.888888888888889