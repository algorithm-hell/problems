import heapq as hq
from sys import maxsize

def solution(n, paths, gates, summits):
    graph = {node: {} for node in range(1, n+1)}
    summits = set(summits)
    answer = [maxsize, maxsize]
    for path in paths:
        s, e, w = path
        graph[s][e] = w
        graph[e][s] = w
    
    def dijckstra():
        nonlocal answer
        distance = {node: maxsize for node in range(1, n+1)}
        heap = []
        for gate in gates:
            hq.heappush(heap, [0, gate])
            distance[gate] = 0
            
        while heap:
            cur_cost, cur_node = hq.heappop(heap)
            
            if distance[cur_node] < cur_cost:
                continue
            
            if cur_node in summits:
                if answer[1] > cur_cost:
                    answer = [cur_node, cur_cost]
                elif answer[1] == cur_cost and answer[0] > cur_node:
                    answer[0] = cur_node
                elif answer[1] < cur_cost:
                    return 
                continue
            
            for adj_node, adj_cost in graph[cur_node].items():
                cost = max(adj_cost, cur_cost)
                if distance[adj_node] > cost:
                    distance[adj_node] = cost
                    hq.heappush(heap, [cost, adj_node])
    dijckstra()
    return answer