import sys; input = sys.stdin.readline
T = int(input())
games = int(input())
scores = [0,0,0,0]
allGames = [(0, 1), (0, 2), (0, 3), (1, 2), (1, 3), (2, 3)]
for i in range(games):
    a, b, sc, scc = map(int, input().split())
    if (sc > scc): scores[a-1] += 3
    elif (scc > sc): scores[b-1] += 3
    else: 
        scores[a-1] += 1
        scores[b-1] += 1
    if (a-1, b-1) in allGames: allGames.remove((a-1, b-1))
    else: allGames.remove((b-1, a-1))

ans = 0

def solve(scores, doed):
    global ans
    if len(doed) == 0:
        if scores[T-1] > max(scores[:T-1]+scores[T:]):
            ans += 1
        return None
    do = doed.pop(0)
    scores[do[0]] += 3
    solve(scores[:], doed[:])
    scores[do[0]] -= 3
    scores[do[1]] += 3
    solve(scores[:], doed[:])
    scores[do[0]] += 1
    scores[do[1]] -= 2
    solve(scores[:], doed[:])
    return None


solve(scores, allGames)
print(ans)