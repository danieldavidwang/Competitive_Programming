num = int(input())
list1 = []

for i in range(num):
    list1.append(int(input()))

list1.sort()
for i in range(num):
    print(list1[i])