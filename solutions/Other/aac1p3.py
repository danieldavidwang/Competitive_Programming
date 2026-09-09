n, h = map(int, input().split())
res = [0] * n
is_comp = False

if n % 2 == 0 and h % 2 == 0:  
    for i in range(h, n, 2):
        res[i] = 1
    is_comp = True
elif n % 2 == 1 and h % 2 == 1:  
    for i in range(h + 1, n, 2):
        res[i] = 1
    is_comp = True

if is_comp:
    print(" ".join(map(str, res)))
else:
    print(-1)