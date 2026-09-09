fib = [0, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811]

def all_partitions(string):
    for point in range(1 << (len(string)-1)):
        res = []
        prev = 0
        for i in range(len(string)-1):
            if (1<<i) & point != 0:
                res.append(string[prev:(i+1)])
                prev = i+1
        res.append(string[prev:])
        yield res

def isFib(num):
    i = 0
    while(num >= fib[i]):
        if (num == fib[i]): return True
        i += 1
    return False

T = int(input())
gud = True

for i in range(T):
    N = input()
    if (len(N) == 1):
        print("NO")
        continue
    for partition in all_partitions(N):
        # print(partition)
        gud = True
        if (len(partition) == 1): continue
        for i in range(len(partition)):
            # print(partition[i])
            # print(isFib(int(partition[i])))
            if (isFib(int(partition[i])) == False): 
                gud = False
                continue
        if (gud):
            print("YES")
            break
    if not (gud): print("NO")