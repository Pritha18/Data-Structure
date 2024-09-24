class WeightedQuickUnionByHeightUF:
    def __init__(N):
        parent = [0, 1, 2, ..., N-1]  # Each element is its own root initially
        height = [0, 0, 0, ..., 0]    # Initial height of all trees is 0

    # Find operation: follow links to find the root
    function find(p):
        while p != parent[p]:
            p = parent[p]
        return p

    # Union operation: union two components
    function union(p, q):
        rootP = find(p)
        rootQ = find(q)
        
        if rootP == rootQ:
            return  # Already connected
        
        # Link the shorter tree to the taller one
        if height[rootP] < height[rootQ]:
            parent[rootP] = rootQ
        elif height[rootP] > height[rootQ]:
            parent[rootQ] = rootP
        else:
            # If the heights are the same, make one the root and increment height
            parent[rootQ] = rootP
            height[rootP] += 1
