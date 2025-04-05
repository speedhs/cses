from collections import Counter
n = int(input())
l = input().split()
og = [int(x) for x in range(1,n+1)]
map = Counter(l)
for c in og:
    if str(c) not in map:
        print(c)
        break
