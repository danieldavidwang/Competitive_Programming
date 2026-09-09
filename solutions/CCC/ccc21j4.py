books = input()

def get_cnt(books : str) -> list:
    cnt = [0, 0, 0]
    for book in books:
        if book == 'L':
            cnt[0] += 1
        elif book == 'M':
            cnt[1] += 1
        else:
            cnt[2] += 1
    return cnt

L_total_cnt, M_total_cnt, S_total_cnt= get_cnt(books)

larges = get_cnt(books[:L_total_cnt])
mediums = get_cnt(books[L_total_cnt:L_total_cnt+M_total_cnt])
smalls = get_cnt(books[L_total_cnt+M_total_cnt:])

singleSwap = min(larges[1], mediums[0]) + min(larges[2], smalls[0]) + min(mediums[2], smalls[1])

s = 0
if larges[1] < mediums[0]:
    s = larges[1]
else:
    s = mediums[0]
larges[1] -= s
mediums[0] -= s
larges[0] += s
mediums[1] += s

if larges[2] < smalls[0]:
    s = larges[2]
else:
    s = smalls[0]
larges[2] -= s
smalls[0] -= s
larges[0] += s
smalls[2] += s

if mediums[2] < smalls[1]:
    s = mediums[2]
else:
    s = smalls[1]
mediums[2] -= s
smalls[1] -= s
mediums[1] += s
smalls[2] += s

doubleSwap = 2* (larges[1] + larges[2])
print(singleSwap+doubleSwap)