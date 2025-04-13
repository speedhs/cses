from collections import Counter
n = int(input())
l = list(map(int, input().split()))
ans = 0
for i in range(1,len(l)):
    if l[i]<l[i-1]:
        ans+=l[i-1]-l[i]
        l[i] = l[i-1]
print(ans)
