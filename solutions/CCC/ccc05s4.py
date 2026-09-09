l = int(input())
for x in range(l):
  n = int(input())
  adj = {}
  visited = {}
  nodes = []
  for i in range(n):
    r = input()
    if (i != 0):
      try:
        adj[nodes[i-1]].append(r)
      except:
        adj[nodes[i-1]] = [r]
    nodes.append(r)
    visited[r] = False
  try:
    adj[r].append(nodes[0])
  except:
    adj[r] = [nodes[0]]
  q = [r]
  visited[r] = True
  ans = 0
  while q:
    for i in range(len(q)):
      c = q.pop(0)
      for j in adj[c]:
        if not (visited[j]):
          q.append(j)
          visited[j] = True
    ans = ans + 1
  ans = ans-1
  print(n*10-(ans)*20, '\n')