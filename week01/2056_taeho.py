from sys import stdin
from collections import deque

n = int(stdin.readline())
graph = {node: {} for node in range(1, n+1)}
degrees = {node : 0 for node in range(1, n+1)}
result = {node : 0 for node in range(1, n+1)}
q = deque()
for i in range(1, n+1):
    data = list(map(int, stdin.readline().split()))
    time = data[0]
    pre_node_count = data[1]
    pre_nodes = data[2:]
    degrees[i] = pre_node_count
    result[i] = time
    for node in pre_nodes:
        graph[node][i] = time
        

for i in range(1, n+1) :
    if degrees[i] == 0 :
        q.append(i)


for _ in range(n):
    if not q:
        break
    
    cur_idx = q.popleft()
    
    for adj_idx, adj_time in graph[cur_idx].items():
        result[adj_idx] = max(result[adj_idx], result[cur_idx] + adj_time)
        degrees[adj_idx] -= 1
        if degrees[adj_idx] == 0 :
            q.append(adj_idx)

print(max(result.values()))