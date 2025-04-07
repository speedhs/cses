n = int(input())
if n>1 and n<4:
    print("NO SOLUTION")
else:
    l1 = []
    l2 = []
    for i in range(1,n+1):
        if i%2==0:
            l2.append(str(i))
        else:
            l1.append(str(i))
    print(" ".join(l2+l1))
