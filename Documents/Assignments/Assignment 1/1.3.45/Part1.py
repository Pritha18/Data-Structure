function causesUnderflow(operations):
    stack_size = 0  # Tracks the current number of elements in the stack

    for each operation in operations:
        if operation == "push":
            stack_size += 1  # Push adds one element to the stack
        else if operation == "pop":
            stack_size -= 1  # Pop removes one element from the stack
            
            # If the stack is empty and you try to pop, underflow occurs
            if stack_size < 0:
                return true  # Underflow detected

    return false  # No underflow
