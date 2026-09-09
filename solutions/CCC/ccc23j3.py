def main():
    maximums =[]
    list = [0, 0, 0, 0, 0]
    index = 0
    n = int(input())
    for j in range(n):
        information = input()
        for chr in information:
            if chr == "Y":
                list[index] = list[index] + 1
            index = index + 1
        index = 0
    max = list[0]
    for k in range(5):
        if list[k] == max:
            maximums.append(k)
        elif list[k] > max:
            maximums = []
            maximums.append(k)
            max = list[k]
    maximumswithformatting = maximums[:-1]
    for l in maximumswithformatting:
            print(l + 1, end = ",")
    print(maximums[-1] + 1)
main()