import heapq

def heuristic(n):
    H_dist = {'A': 11,'B': 6,'C': 99,'D': 1,'E': 7,'G': 0,'F':12}
    return H_dist[n]

def astar(graph, start, goal):
    visited = {}
    heap = [(0, start, [])]
    heapq.heapify(heap)
    while heap:
        (cost, node, path) = heapq.heappop(heap)
        if node == goal:
            return path + [node], cost
        if node in visited:
            continue
        visited[node] = True
        for neighbor, weight in graph[node].items():
            if neighbor not in visited:
                heapq.heappush(heap, (cost + weight + heuristic(neighbor), neighbor, path + [node]))
    return None, None

graph_nodes = {'A': {'B':2,'E': 3},
               'B': {'A': 2, 'C': 1, 'G': 9},
               'C': {'B': 1},
               'D': {'E': 6, 'G': 1},
               'E': {'A': 3, 'D': 6},
               'G': {'B': 9, 'D': 1}}

start_node = 'A'
goal_node = 'G'

graph1={
    'A':{'B':6,'F':3},
    'B':{'C':3,'F':2},
    'C':{},
    'F':{},
}
path, cost = astar(graph1, start_node, graph_nodes)

if path is None:
    print("No path found")
else:
    print("Minimum cost path:", path)
    print("Cost of the path:", cost)
