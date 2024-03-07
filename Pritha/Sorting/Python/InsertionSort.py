import random

def insertionSortAsc(pritha):
    n = len(pritha) # length of the array
    
    # traveling the array from index 1 to n - 1
    for i in range(1 , n):
        holePosition = i
        holePositionValue = pritha[i]
        j = i - 1
        while j >= 0 and pritha[j] > holePositionValue:
                pritha[j + 1] = pritha[j]
                holePosition = j
                j -= 1
        pritha[holePosition] = holePositionValue

    return pritha
        
def create_list_custom(length, max_value, item=None, item_index=None):
    random_list = [random.randint(0,max_value) for i in range(length)]
    
    if item != None:
        random_list.insert(item_index,item)
    
    return random_list

customList = create_list_custom(10,1000,10,6)

sortedArray = insertionSortAsc(customList)

print("Sorted array is: ", sortedArray)