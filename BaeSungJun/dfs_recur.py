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

def dfs(graph, node, visited):
    print(node)
    visited[node] = True

    for neighbor in graph[node]:
        if visited[neighbor] == False:
            dfs(graph, neighbor, visited)

dfs(graph, 1, visited)
