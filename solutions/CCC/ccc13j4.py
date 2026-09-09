T = int(input())
C = int(input())
v = []
for i in range(C): v.append(int(input()))

v.sort()
add = cnt = 0
while (cnt < len(v) and add <= T):
    add += v[cnt]
    cnt += 1
if (add > T):
    print(cnt-1)
else:
    print(cnt)