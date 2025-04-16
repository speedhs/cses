n = int(input())
l = list(map(int, input().split()))
c = {}

ans = 0
for i in range(n):
    if l[i] not in c:
        c[l[i]]=1
        ans+=1
    else:
        continue
print(ans)
