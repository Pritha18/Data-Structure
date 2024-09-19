


class Graph:
    def __init__(self):
        self.adjList = {}

    def addEdge(self, u, v):
        if u not in self.adjList:
            self.adjList[u] = []
        if v not in self.adjList:
            self.adjList[v] = []
        self.adjList[u].append(v)
        self.adjList[v].append(u)  # Add edge in both directions for undirected graph
        
    def dfsPathFinding(self, startNode, endNode):
        stack = [(startNode, [startNode])]  # Initialize stack with (current_node, path) tuple
        visited = set()  # Initialize set to keep track of visited nodes
        
        while stack:
            current_node, path = stack.pop()  # Pop the top element from the stack
            visited.add(current_node)  # Mark the current node as visited
            
            # If the current node is the end node, return the path
            if current_node == endNode:
                return path
            
            # Push neighboring nodes onto the stack if they haven't been visited
            if current_node in self.adjList:
                for neighbor in self.adjList[current_node]:
                    if neighbor not in visited:
                        # Append neighbor and updated path to stack
                        stack.append((neighbor, path + [neighbor]))
                        
        
        # If no path is found, return None
        return None
    

# Example usage
graph = Graph()
graph.addEdge("A", "B")
graph.addEdge("A", "C")
graph.addEdge("B", "D")
graph.addEdge("B", "E")
graph.addEdge("C", "F")
graph.addEdge("E", "F")

startNode = "A"
endNode = "F"

# DFS
pathDFS = graph.dfsPathFinding(startNode, endNode)

if pathDFS:
    print(f"DFS Path from {startNode} to {endNode}: {' -> '.join(pathDFS)}")
else:
    print(f"No DFS path found from {startNode} to {endNode}")