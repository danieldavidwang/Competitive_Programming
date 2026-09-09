ans = 0
cur = 0

i = int(input())
n = int(input())
j = int(input())
diff = [0]*(i+1)

for I in range(j):
    x1, x2, k = map(int, input().split())
    diff[x1-1] = diff[x1-1] + k
    diff[x2] = diff[x2] - k

for I in range(i):
    cur = cur + diff[I]
    if (cur <= n): ans = ans + 1

print(ans)