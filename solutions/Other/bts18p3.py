lineone = list(map(int,input().split()))
servers = list(map(int,input().split()))
quality = 0 
for x in range(lineone[1]): 
  a = servers.index(max(servers)) 
  quality += servers[a]

  if servers[a] > 0: 
    servers[a] -= 1 
print (quality )