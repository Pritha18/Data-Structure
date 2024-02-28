
import sys

def selectionSortAsc(pritha):
    n = len(pritha) # length of the array
    
    # traveling the array from index 0 to n - 1
    for i in range(n):
        minValue = sys.maxsize
        minIndex = 0
        
        for j in range(i, n):
            if pritha[j] < minValue:
                minValue = pritha[j];
                minIndex = j;
                
        
        temp = pritha[i];
        pritha[i] = minValue;
        pritha[minIndex] = temp;
    
    return pritha
        

sortedArray = selectionSortAsc([7, 3, 12, 6, 9])

print("Sorted array is: ", sortedArray)