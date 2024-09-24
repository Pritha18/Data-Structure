function findFarthestPair(a[], N):
    if N < 2:
        return "Array must have at least two elements"

    # Initialize min_value and max_value to the first element of the array
    min_value = a[0]
    max_value = a[0]
    
    # Iterate over the array to find the max
    for i = 1 to N-1:
        if a[i] > max_value:
            max_value = a[i]
            
    # Iterate over the array to find the min
    for i = 1 to N-1:
        if a[i] < min_value:
            min_value = a[i]
    
    # The farthest pair is the min and max
    return (min_value, max_value, |max_value - min_value|)
