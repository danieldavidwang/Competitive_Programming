xOriginalList = []
yOriginalList = []

N = int(input())

for i in range(N):
    xyPair = input("")
    x = int(xyPair.split(",")[0])
    y = int(xyPair.split(",")[1])
    xOriginalList.append(x)
    yOriginalList.append(y)

xMin = min(xOriginalList)
xMax = max(xOriginalList)
yMin = min(yOriginalList)
yMax = max(yOriginalList)
xBottomLeft = xMin - 1
yBottomLeft = yMin - 1
xTopRight = xMax + 1
yTopRight = yMax + 1

print("{},{}".format(xBottomLeft, yBottomLeft))
print("{},{}".format(xTopRight, yTopRight))