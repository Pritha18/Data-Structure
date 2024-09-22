function isValidPermutation(permutation, N):
    stack = empty stack
    index = 0  # Index to track the current number in the permutation
    
    # Iterate over the numbers from 0 to N-1
    for i from 0 to N-1:
        stack.push(i)  # Push the current number onto the stack
        
        # While the top of the stack matches the next number in the permutation
        while not stack.isEmpty() and stack.top() == permutation[index]:
            stack.pop()  # Pop the matching number
            index += 1  # Move to the next number in the permutation

    # If we've successfully matched the entire permutation, return true
    # If all numbers in the permutation were matched, it's valid
    if index == N:
        return true
    
    # we are in this line cause index == N failed
    # means permutation array is not finished
    # means permutation array is not matched by pushed input
    return false
