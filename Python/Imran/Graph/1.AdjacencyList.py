
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
        
    

# declaring an object of graph class
prithaGraph = Graph()
prithaGraph.addEdge("A", "B")
prithaGraph.addEdge("A", "C")
prithaGraph.addEdge("B", "C")
prithaGraph.addEdge("B", "D")
prithaGraph.addEdge("C", "D")

print(prithaGraph.adjList)