import time
import random
import matplotlib.pyplot as plt

class DirectedWeightedGraph:

    def __init__(self):
        self.adj = {}
        self.weights = {}

    def are_connected(self, node1, node2):
        for neighbour in self.adj[node1]:
            if neighbour == node2:
                return True
        return False

    def adjacent_nodes(self, node):
        return self.adj[node]

    def add_node(self, node):
        self.adj[node] = []

    def add_edge(self, node1, node2, weight):
        if node2 not in self.adj[node1]:
            self.adj[node1].append(node2)
        self.weights[(node1, node2)] = weight

    def w(self, node1, node2):
        if self.are_connected(node1, node2):
            return self.weights[(node1, node2)]

    def number_of_nodes(self):
        return len(self.adj)

def init_d(G):
    n = G.number_of_nodes()
    d = [[float("inf") for j in range(n)] for i in range(n)]
    for i in range(n):
        for j in range(n):
            if G.are_connected(i, j):
                d[i][j] = G.w(i, j)
        d[i][i] = 0
    return d

#Assumes G represents its nodes as integers 0,1,...,(n-1)
def unknown(G):
    n = G.number_of_nodes()
    d = init_d(G)
    for k in range(n):
        for i in range(n):
            for j in range(n):
                if d[i][j] > d[i][k] + d[k][j]: 
                    d[i][j] = d[i][k] + d[k][j]
    return d

# test codes
def generateRandomWeightedGraph(numNodes, maxWeight, allowNegativeWeights=False):
    G = DirectedWeightedGraph()
    for i in range(numNodes):
        G.add_node(i)
    for i in range(numNodes):
        for j in range(numNodes):
            if i != j:
                weight = random.randint(-maxWeight, maxWeight) if allowNegativeWeights else random.randint(1, maxWeight)
                G.add_edge(i, j, weight)
    return G

def testPOsitiveAndNegativeEdgeWeights():
    print("Testing on graphs with positive and negative edge weights:")
    for i in range(2):
        print(f"Experiment {i + 1}:")
        G = generateRandomWeightedGraph(5, 10, allowNegativeWeights=(i == 1))
        print("Graph:")
        print(G.adj)
        print("Shortest Paths:")
        print(unknown(G))
        print()

def measureExecutionTime(graphSizes, maxWeight):
    executionTimes = []
    print("Measuring execution time:")
    for size in graphSizes:
        G = generateRandomWeightedGraph(size, maxWeight)
        startTime = time.time()
        unknown(G)
        endTime = time.time()
        executionTime = endTime - startTime
        executionTimes.append(executionTime)
        print(f"Graph size: {size}, Execution time: {executionTime:.6f} seconds")
    print()
    return executionTimes

# Testing on graphs with positive and negative edge weights
testPOsitiveAndNegativeEdgeWeights()

# Measuring execution time
graphSizes = [10, 20, 50, 100, 200, 350, 500]
maxWeight = 100
executionTimes =  measureExecutionTime(graphSizes, maxWeight)

# Plot the comparison of execution time versus graph sizes
plt.plot(graphSizes, executionTimes, marker='o', linestyle='-')
plt.title('Execution Time vs. Graph Sizes')
plt.xlabel('Graph Size (Number of Vertices)')
plt.ylabel('Execution Time (Seconds)')
plt.grid(True)
plt.show()