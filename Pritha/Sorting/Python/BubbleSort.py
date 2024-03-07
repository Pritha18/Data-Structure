
import random

def bubbleSortAsc(pritha):
    n = len(pritha) # length of the array
    
    # traveling the array from index 0 to n - 2
    for i in range(n-1):
        for j in range(n-1-i):
            if pritha[j] > pritha[j + 1]:
                temp = pritha[j]
                pritha[j] = pritha[j+1]
                pritha[j+1] = temp
                
    return pritha



def create_list_custom(length, max_value, item=None, item_index=None):
    random_list = [random.randint(0,max_value) for i in range(length)]
    
    if item != None:
        random_list.insert(item_index,item)
    
    return random_list

customList = create_list_custom(10,1000,10,6)

sortedArray = bubbleSortAsc(customList)

print("Sorted array is: ", sortedArray)