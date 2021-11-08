from collections import deque

graph = [
    [],
    [2, 3, 4],
    [1, 5, 6],
    [1],
    [1, 7],
    [2, 8],
    [2, 8],
    [4],
    [5, 6]
]
visited = [False] * len(graph)
stack = []


deq = deque()
visited = [False] * len(graph)

deq.appendleft(1)
visited[1] = True

print(1)

while len(deq) > 0:
    current_node = deq.pop()
    for neighbor in graph[current_node]:
        if visited[neighbor] == False:
            print(neighbor)
            deq.appendleft(neighbor)
            visited[neighbor] = True
