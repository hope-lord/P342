# factorial n! say for n=10 or 15, check and trap negative integers
n=int(input("Give the integer "))
mul=1
if n<0:
    print("Give non-negative integer.")
else:
    i=1
    while i<=n:
        mul*=i
        i+=1

    print(f"{n}!= {mul}")