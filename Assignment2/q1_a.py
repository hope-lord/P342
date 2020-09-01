#Find the average distance between two points on a
#(a) straight line made of discrete N (=6) points:

arr=[1,2,3,4,5,6]
num_sum=0
sum=0
for i in range(6):
    for j in range(6):
        sum+=abs(arr[j]-arr[i])
        num_sum+=1
print(f"Avg. Distance= {sum/num_sum}")
#Output:
#Avg. Distance= 1.9444444444444444
#  o o o o o o