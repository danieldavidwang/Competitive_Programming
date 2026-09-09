import sys
n = int(sys.stdin.readline())
adj = [[] for x in range(n+1)]
dp = [0 for x in range(n+1)]
dp[n] = 1
while True:
  d = list(map(int, sys.stdin.readline().split())) 
  if (d[0] == 0): break
  adj[d[1]].append(d[0])
for i in range(n, -1, -1):
    for j in range(len(adj[i])):
        dp[adj[i][j]] += dp[i]
print(dp[1])