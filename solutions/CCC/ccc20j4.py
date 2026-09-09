T = input()
S = input()

shiftedS = S
sLen = len(S)

for i in range(sLen):
    if shiftedS in T:
        break
    else:
        shiftedS = shiftedS[1:sLen] + shiftedS[0]
if shiftedS in T:
    print("yes")
else:
    print("no")