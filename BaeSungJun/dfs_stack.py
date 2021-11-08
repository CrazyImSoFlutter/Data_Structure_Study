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

stack.append(1)
print(1)
visited[1] = True

while len(stack) > 0:
    current_node = None
    for node in graph[stack[-1]]:
        if visited[node] == False:
            current_node = node
            break

    if current_node == None:
        stack.pop()
    else:
        visited[current_node] = True
        stack.append(current_node)
        print(current_node)
