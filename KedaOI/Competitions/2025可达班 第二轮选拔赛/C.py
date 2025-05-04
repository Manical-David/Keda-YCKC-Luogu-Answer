n = int(input())
a = list(map(int, input().split()))
Max = sum(a)
for i in range(n):
    for j in range(i, n):
        tmp = a.copy()
        for k in range(i, j + 1):
            tmp[k] = 1 - tmp[k]
        ans = sum(tmp)
        Max = max(Max, ans)
print(Max)