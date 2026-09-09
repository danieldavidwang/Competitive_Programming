M = int(input())
f = [0]*101
r = [0]*101
s = [0]*101
t = 0

for i in range(M):
    val = input().split()
    command = val[0]
    n = int(val[1])
    if command == 'S':
        f[n] += t - s[n]
        r[n] = 1
    elif command == "R":
        r[n] = -1
        s[n] = t
    else:
        t += n-2
    t += 1
for j in range(101):
    if r[j] != 0:
        if r[j] > 0:
            print(j, f[j])
        else:
            print(j, r[j])