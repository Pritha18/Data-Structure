import heapq
import random
import time
import matplotlib.pyplot as plt

class Node:
    def __init__(self, vertex, cost):
        self.vertex = vertex
        self.cost = cost

    # Operator overloading for min heap
    def __lt__(self, other):
        return self.cost < other.cost
    

class Graph:
    def __init__(self):
        self.adjacency = {}

    def addEdge(self, source, destination, weight):
        if source not in self.adjacency:
            self.adjacency[source] = []

        if destination not in self.adjacency:
            self.adjacency[destination] = []

        self.adjacency[source].append(Node(destination, weight))
        self.adjacency[destination].append(Node(source, weight))
        
    def dijkstra(self, startVertex, vertexList, k):
        relaxations = {vertex: 0 for vertex in vertexList}
        distanceFromSource = {vertex: float('inf') for vertex in vertexList}
        result = {}
        weightedList = []
        
        heapq.heappush(weightedList, Node(startVertex, 0))
        distanceFromSource[startVertex] = 0

        while weightedList:
            currentNode = heapq.heappop(weightedList)
            curVertex = currentNode.vertex
            cost = currentNode.cost

            for neighbourNode in self.adjacency[curVertex]:
                neighbour = neighbourNode.vertex
                neighbourDistance = neighbourNode.cost

                if relaxations[neighbour] >= k:
                    continue

                # path relaxation
                if distanceFromSource[curVertex] + neighbourDistance < distanceFromSource[neighbour]:
                    distanceFromSource[neighbour] = distanceFromSource[curVertex] + neighbourDistance
                    heapq.heappush(weightedList, Node(neighbour, distanceFromSource[neighbour]))

                    relaxations[neighbour] += 1

                    # path
                    newPath = result.get(curVertex, ([], None))[0][:]
                    newPath.append(neighbour)
                    result[neighbour] = (newPath, distanceFromSource[neighbour])

        for vertex in vertexList:
            if vertex != startVertex and vertex not in result:
                result[i] = ([], -1)


        return result

    def bellmanFord(self, startVertex, vertexList, k):
        distanceFromSource = {vertex: float('inf') for vertex in vertexList}
        distanceFromSource[startVertex] = 0
        result = {}

        for _ in range(k):
            for vertex in vertexList:
                for neighbourNode in self.adjacency[vertex]:
                    neighbour = neighbourNode.vertex
                    neighbourDistance = neighbourNode.cost

                    if distanceFromSource[vertex] + neighbourDistance < distanceFromSource[neighbour]:
                        distanceFromSource[neighbour] = distanceFromSource[vertex] + neighbourDistance
                        result[neighbour] = (result.get(vertex, ([], float('inf')))[0] + [neighbour], distanceFromSource[neighbour])


        for vertex in vertexList:
            path = result.get(vertex, ([], float('inf')))[0]
            result[vertex] = (path, distanceFromSource[vertex])

        return result


# Example usage
def displayDistancePath(startVertex, vertexList, result):
	print("source is: ", startVertex, ". showing distance from source")
	print("Vertex\tDistance\tPath")
	for vertex in vertexList:
		path, distance = result.get(vertex, ([], 0))
		print(f"{vertex}\t{distance}\t\t{' '.join(map(str, path)) if path else '-'}")


def generateRandomWeightedGraph(numNodes, maxWeight):
    graph = Graph()
    
    for i in range(1, numNodes + 1):
        for j in range(1, numNodes + 1):
            if i != j:
                weight = random.randint(1, maxWeight)
                graph.addEdge(i, j, weight)
    
    return graph

def measureExecutionTime(graphSizes, maxWeight):
    dijkstraExecutionTimes = []
    bellmanFordExecutionTimes = []
    print("Showing experiment data and Measuring execution time:")
    for size in graphSizes:
        graph = generateRandomWeightedGraph(size, maxWeight)
        vertexList = list(graph.adjacency.keys())
        startVertex = 1
        k = random.randint(1, size - 2)

        print("\nDijkstra:")
        startTime = time.time()
        resultDijkstra = graph.dijkstra(startVertex, vertexList, k)
        endTime = time.time()
        executionTime = endTime - startTime
        dijkstraExecutionTimes.append(executionTime)
        displayDistancePath(startVertex, vertexList, resultDijkstra)
        print(f"Graph size: {size}, Execution time: {executionTime:.6f} seconds")

        print("\nBellman Ford:")
        startTime = time.time()
        resultBellmanFord = graph.bellmanFord(startVertex, vertexList, k)
        endTime = time.time()
        executionTime = endTime - startTime
        bellmanFordExecutionTimes.append(executionTime)
        displayDistancePath(startVertex, vertexList, resultBellmanFord)
        print(f"Graph size: {size}, Execution time: {executionTime:.6f} seconds")
    	
    print("\n\n")
    return (dijkstraExecutionTimes, bellmanFordExecutionTimes)


# Measuring execution time
graphSizes = [10, 20, 50, 100]
maxWeight = 100
executionTimes =  measureExecutionTime(graphSizes, maxWeight)

# Unpack the execution times
dijkstraExecutionTimes, bellmanFordExecutionTimes = executionTimes

# Plotting
plt.figure(figsize=(10, 6))
plt.plot(graphSizes, dijkstraExecutionTimes, marker='o', label='Dijkstra')
plt.plot(graphSizes, bellmanFordExecutionTimes, marker='o', label='Bellman-Ford')
plt.title('Execution Time Comparison')
plt.xlabel('Graph Size')
plt.ylabel('Execution Time (seconds)')
plt.grid(True)
plt.legend()
plt.show()
