function find_common_name(A, B, C):
    # Step 1: Sort the three lists
    sort(A)   # O(N log N)
    sort(B)   # O(N log N)
    sort(C)   # O(N log N)

    # Step 2: Initialize pointers
    i = 0
    j = 0
    k = 0

    # Step 3: Use a merge-like process to find common elements
    while i < N and j < N and k < N:
        if A[i] == B[j] and B[j] == C[k]:
            return A[i]  # Return the first common name
        elif A[i] < B[j]:
            i += 1
        elif B[j] < C[k]:
            j += 1
        else:
            k += 1

    # Step 4: If no common name is found
    return None
