#sum over 1+1/2 + 1/3 + ... till the sum does not change by more than 0.001
sum=0
n=1
while 1/n >0.001:
        sum+=(1/n)
        n+=1

print(f"Sum = {sum}")