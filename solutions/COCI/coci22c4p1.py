import sys
input = sys.stdin.readline

n, m = map(int, input().split())
s = input().strip()
word, cnt = 'dkor', [0, 0, 0, 0]
ans = 0

for i, x in enumerate(list(word)):
    cnt[i] += s.count(x)
    ans += cnt[i]*cnt[i]

for a in range(0, m+1):
    for b in range(0, m-a+1):
        for c in range(0, m-a-b+1):
            for d in range(0, m-a-b-c+1):
                val = (cnt[0]+a)**2 + (cnt[1]+b)**2 + (cnt[2]+c)**2 + (cnt[3]+d)**2
                val += 7*(min(cnt[0]+a, (cnt[1]+b)//2, (cnt[2]+c)//2, cnt[3]+d))
                ans = max(ans, val)

print(ans)